// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

#include "types.hpp"

namespace lyah {
	// NOTE: SSE
	// https://stackoverflow.com/a/18508113
	template<std::size_t M, std::size_t N, std::size_t P>
	LYAH_NODISCARD LYAH_INLINE mat<M, P, std::float_t> LYAH_CALL operator *(mat<M, N, std::float_t> a, mat<N, P, std::float_t> b) {
		__m128 broadcastj = _mm_undefined_ps();
		__m128 aij_bj = _mm_undefined_ps();
		mat<M, P, std::float_t> result;

		for (std::size_t i = 0; i < M; i++) {
			for (std::size_t j = 0; j < P; j++) {
				broadcastj = _mm_set1_ps(a[i][j]);
				aij_bj = _mm_mul_ps(broadcastj, b[j].m);

				result[i].m = _mm_add_ps(result[i].m, aij_bj);
			}
		}

		return result;
	}

	// For 2x2 matrices.
	// NOTE: SSE
	LYAH_NODISCARD LYAH_INLINE mat<2, 2, std::float_t> LYAH_CALL transpose(mat<2, 2, std::float_t> A) {
		const __m128 a = _mm_unpacklo_ps(A[0].m, A[1].m);

		A[0].m = a;
		A[1].m = _mm_movehl_ps(a, a);

		return A;
	}

	// For 2x3 matrices.
	// NOTE: SSE
	/* LYAH_NODISCARD LYAH_INLINE mat<3, 2, std::float_t> LYAH_CALL transpose(mat<2, 3, std::float_t> A) {
		const __m128 a = _mm_unpacklo_ps(A[0].m, A[1].m);
		const __m128 b = _mm_unpackhi_ps(A[0].m, A[1].m);

		mat<3, 2, std::float_t> AT;

		AT[0].m = a;
		AT[1].m = _mm_movehl_ps(a, a);
		AT[2].m = b;

		return AT;
	} */

	// For 3x2 and 4x2 matrices.
	// NOTE: SSE
	/* template<std::size_t N>
	LYAH_NODISCARD LYAH_INLINE mat<2, N, std::float_t> LYAH_CALL transpose(mat<N, 2, std::float_t> A) {
		const __m128 a = _mm_unpacklo_ps(A[0].m, A[1].m);
		const __m128 b = _mm_unpacklo_ps(A[2].m, A[N - 1].m);

		mat<2, N, std::float_t> AT;

		AT[0].m = _mm_movelh_ps(a, b);
		AT[1].m = _mm_movehl_ps(b, a);

		return AT;
	} */

	// For 3x3 matrices.
	// NOTE: SSE
	// http://www.gamedev.net/forums/topic/692392-towards-an-optimal-vex-sse-33float-matrix-transpose/5357850
	LYAH_NODISCARD LYAH_INLINE mat<3, 3, std::float_t> LYAH_CALL transpose(mat<3, 3, std::float_t> A) {
		const __m128 a = _mm_unpacklo_ps(A[0].m, A[1].m);
		const __m128 b = _mm_unpackhi_ps(A[0].m, A[1].m);

		A[0].m = _mm_movelh_ps(a, A[2].m);
		A[1].m = _mm_shuffle_ps(a, A[2].m, _MM_SHUFFLE(3, 1, 3, 2));
		A[2].m = _mm_shuffle_ps(b, A[2].m, _MM_SHUFFLE(3, 2, 1, 0));

		return A;
	}

	// NOTE: SSE
	// https://en.wikipedia.org/wiki/Invertible_matrix#Inversion_of_3_%C3%97_3_matrices
	LYAH_NODISCARD LYAH_INLINE mat<3, 3, std::float_t> LYAH_CALL inverse(mat<3, 3, std::float_t> a) {
		const std::float_t d = determinant(a);

		LYAH_ASSERT(abs(d) >= epsilon<std::float_t>());

		// A =  (ei - fh)   B = -(di - fg)   C =  (dh - eg)
		// D = -(bi - ch)   E =  (ai - cg)   F = -(ah - bg)
		// G =  (bf - ce)   H = -(af - cd)   I =  (ae - bd)

		// ABC = (e  d  d  0) * (i  i  h  0) - (f  f  e  0) * (h  g  g  0)
		// DEF = (b  a  a  0) * (i  i  h  0) - (c  c  b  0) * (h  g  g  0)
		// GHI = (b  a  a  0) * (f  f  e  0) - (c  c  b  0) * (e  d  d  0)

		__m128 m0 = a[0].m;
		__m128 m1 = a[1].m;
		__m128 m2 = a[2].m;

		__m128 ABC_GHI_sign = _mm_set_ps(0.0f, 0.0f, -0.0f, 0.0f);
		__m128 DEF_sign = _mm_set_ps(0.0f, -0.0f, 0.0f, -0.0f);

		__m128 baa = _mm_shuffle_ps(m0, m0, _MM_SHUFFLE(0, 0, 0, 1));
		__m128 ccb = _mm_shuffle_ps(m0, m0, _MM_SHUFFLE(0, 1, 2, 2));
		__m128 edd = _mm_shuffle_ps(m1, m1, _MM_SHUFFLE(0, 0, 0, 1));
		__m128 ffe = _mm_shuffle_ps(m1, m1, _MM_SHUFFLE(0, 1, 2, 2));
		__m128 hgg = _mm_shuffle_ps(m2, m2, _MM_SHUFFLE(0, 0, 0, 1));
		__m128 iih = _mm_shuffle_ps(m2, m2, _MM_SHUFFLE(0, 1, 2, 2));

		__m128 ABC = _mm_sub_ps(_mm_mul_ps(edd, iih), _mm_mul_ps(ffe, hgg));
		__m128 DEF = _mm_sub_ps(_mm_mul_ps(baa, iih), _mm_mul_ps(ccb, hgg));
		__m128 GHI = _mm_sub_ps(_mm_mul_ps(baa, ffe), _mm_mul_ps(ccb, edd));

		ABC = _mm_xor_ps(ABC, ABC_GHI_sign);
		DEF = _mm_xor_ps(DEF, DEF_sign);
		GHI = _mm_xor_ps(GHI, ABC_GHI_sign);

		return 1.0f / d * transpose(mat<3, 3, std::float_t>(
			vec<3, std::float_t>(ABC),
			vec<3, std::float_t>(DEF),
			vec<3, std::float_t>(GHI)
		));
	}
}