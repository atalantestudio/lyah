// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

#include "types.hpp"

namespace lyah {
	// NOTE: AVX
	// https://stackoverflow.com/a/18508113
	template<std::size_t M, std::size_t N, std::size_t P>
	LYAH_NODISCARD LYAH_INLINE mat<M, P, std::double_t> LYAH_CALL operator *(mat<M, N, std::double_t> a, mat<N, P, std::double_t> b) {
		__m256d broadcastj = _mm256_undefined_pd();
		__m256d aij_bj = _mm256_undefined_pd();
		mat<M, P, std::double_t> result;

		for (std::size_t i = 0; i < M; i++) {
			for (std::size_t j = 0; j < P; j++) {
				broadcastj = _mm256_set1_pd(a[i][j]);
				aij_bj = _mm256_mul_pd(broadcastj, b[j].m);

				result[i].m = _mm256_add_pd(result[i].m, aij_bj);
			}
		}

		return result;
	}

	// For 3x3 matrices.
	// NOTE: AVX
	LYAH_NODISCARD LYAH_INLINE mat<3, 3, std::double_t> LYAH_CALL transpose(mat<3, 3, std::double_t> A) {
		const __m256d a = _mm256_unpacklo_pd(A[0].m, A[1].m);
		const __m256d b = _mm256_unpacklo_pd(A[2].m, A[2].m);
		const __m256d c = _mm256_unpackhi_pd(A[0].m, A[1].m);
		const __m256d d = _mm256_unpackhi_pd(A[2].m, A[2].m);

		A[0].m = _mm256_permute2f128_pd(b, a, _MM_SHUFFLE2(1, 0));
		A[1].m = _mm256_permute2f128_pd(c, d, 0b100000);
		A[2].m = _mm256_permute2f128_pd(a, b, 0b110001);

		return A;
	}

	// For 4x4 matrices.
	// NOTE: AVX
	// https://gist.github.com/nanaHa1003/b13b6d927b7997d5b7c9c72c0fc17a53
	LYAH_NODISCARD LYAH_INLINE mat<4, 4, std::double_t> LYAH_CALL transpose(mat<4, 4, std::double_t> A) {
		const __m256d a = _mm256_unpacklo_pd(A[0].m, A[1].m);
		const __m256d b = _mm256_unpacklo_pd(A[2].m, A[3].m);
		const __m256d c = _mm256_unpackhi_pd(A[0].m, A[1].m);
		const __m256d d = _mm256_unpackhi_pd(A[2].m, A[3].m);

		A[0].m = _mm256_permute2f128_pd(b, a, _MM_SHUFFLE2(1, 0));
		A[1].m = _mm256_permute2f128_pd(d, c, _MM_SHUFFLE2(1, 0));
		A[2].m = _mm256_permute2f128_pd(a, b, 0b110001);
		A[3].m = _mm256_permute2f128_pd(c, d, 0b110001);

		return A;
	}

	// NOTE: AVX2
	// https://en.wikipedia.org/wiki/Invertible_matrix#Inversion_of_3_%C3%97_3_matrices
	LYAH_NODISCARD LYAH_INLINE mat<3, 3, std::double_t> LYAH_CALL inverse(mat<3, 3, std::double_t> a) {
		const std::double_t d = determinant(a);

		LYAH_ASSERT(abs(d) >= epsilon<std::double_t>());

		// A =  (ei - fh)   B = -(di - fg)   C =  (dh - eg)
		// D = -(bi - ch)   E =  (ai - cg)   F = -(ah - bg)
		// G =  (bf - ce)   H = -(af - cd)   I =  (ae - bd)

		// ABC = (e  d  d  0) * (i  i  h  0) - (f  f  e  0) * (h  g  g  0)
		// DEF = (b  a  a  0) * (i  i  h  0) - (c  c  b  0) * (h  g  g  0)
		// GHI = (b  a  a  0) * (f  f  e  0) - (c  c  b  0) * (e  d  d  0)

		__m256d m0 = a[0].m;
		__m256d m1 = a[1].m;
		__m256d m2 = a[2].m;

		__m256d ABC_GHI_sign = _mm256_set_pd(0.0, 0.0, -0.0, 0.0);
		__m256d DEF_sign = _mm256_set_pd(0.0, -0.0, 0.0, -0.0);

		__m256d baa = _mm256_permute4x64_pd(m0, _MM_SHUFFLE(0, 0, 0, 1));
		__m256d ccb = _mm256_permute4x64_pd(m0, _MM_SHUFFLE(0, 1, 2, 2));
		__m256d edd = _mm256_permute4x64_pd(m1, _MM_SHUFFLE(0, 0, 0, 1));
		__m256d ffe = _mm256_permute4x64_pd(m1, _MM_SHUFFLE(0, 1, 2, 2));
		__m256d hgg = _mm256_permute4x64_pd(m2, _MM_SHUFFLE(0, 0, 0, 1));
		__m256d iih = _mm256_permute4x64_pd(m2, _MM_SHUFFLE(0, 1, 2, 2));

		__m256d ABC = _mm256_sub_pd(_mm256_mul_pd(edd, iih), _mm256_mul_pd(ffe, hgg));
		__m256d DEF = _mm256_sub_pd(_mm256_mul_pd(baa, iih), _mm256_mul_pd(ccb, hgg));
		__m256d GHI = _mm256_sub_pd(_mm256_mul_pd(baa, ffe), _mm256_mul_pd(ccb, edd));

		ABC = _mm256_xor_pd(ABC, ABC_GHI_sign);
		DEF = _mm256_xor_pd(DEF, DEF_sign);
		GHI = _mm256_xor_pd(GHI, ABC_GHI_sign);

		return 1.0 / d * transpose(mat<3, 3, std::double_t>(
			vec<3, std::double_t>(ABC),
			vec<3, std::double_t>(DEF),
			vec<3, std::double_t>(GHI)
		));
	}
}