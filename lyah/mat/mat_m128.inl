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
}