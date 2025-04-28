// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

namespace lyah {
	// NOTE: SSE
	// http://www.codersnotes.com/notes/maths-lib-2016
	// https://geometrian.com/programming/tutorials/cross-product/index.php
	LYAH_NODISCARD LYAH_INLINE vec<3, std::float_t> LYAH_CALL cross(vec<3, std::float_t> a, vec<3, std::float_t> b) {
		const __m128 c = _mm_mul_ps(b.m, _mm_shuffle_ps(a.m, a.m, _MM_SHUFFLE(3, 1, 0, 2)));
		const __m128 d = _mm_mul_ps(a.m, _mm_shuffle_ps(b.m, b.m, _MM_SHUFFLE(3, 1, 0, 2)));
		const __m128 m = _mm_sub_ps(c, d);

		a.m = _mm_shuffle_ps(m, m, _MM_SHUFFLE(3, 1, 0, 2));

		return a;
	}
}