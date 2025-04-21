// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

namespace lyah {
	// NOTE: SSE2
	template<std::size_t M, std::size_t N>
	LYAH_NODISCARD LYAH_INLINE mat<M, 2, std::double_t> LYAH_CALL operator *(mat<M, N, std::double_t> a, mat<N, 2, std::double_t> b) {
		__m128d broadcastj = _mm_undefined_pd();
		__m128d aij_bj = _mm_undefined_pd();
		mat<M, 2, std::double_t> result;

		for (std::size_t i = 0; i < M; i++) {
			for (std::size_t j = 0; j < 2; j++) {
				broadcastj = _mm_set1_pd(a[i][j]);
				aij_bj = _mm_mul_pd(broadcastj, b[j].m);

				result[i].m = _mm_add_pd(result[i].m, aij_bj);
			}
		}

		return result;
	}

	// NOTE: SSE2
	LYAH_NODISCARD LYAH_INLINE mat<2, 2, std::double_t> LYAH_CALL transpose(mat<2, 2, std::double_t> A) {
		const __m128d a = _mm_unpackhi_pd(A[0].m, A[1].m);

		A[0].m = _mm_unpacklo_pd(A[0].m, A[1].m);
		A[1].m = a;

		return A;
	}
}