// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

namespace lyah {
	// NOTE: SSE
	LYAH_INLINE vec<2, std::float_t>::vec() : m(_mm_setzero_ps()) {}

	// NOTE: SSE
	LYAH_INLINE vec<2, std::float_t>::vec(std::float_t x, std::float_t y) : m(_mm_set_ps(0.0f, 0.0f, y, x)) {}

	// NOTE: SSE
	LYAH_INLINE vec<2, std::float_t>::vec(std::float_t a) : m(_mm_set1_ps(a)) {}

	// NOTE: SSE
	LYAH_INLINE std::float_t vec<2, std::float_t>::operator [](std::size_t index) const LYAH_NOEXCEPT {
		LYAH_ASSERT(index < 2);

		switch (index) {
			default:
			case 0: return _mm_cvtss_f32(m);
			case 1: return _mm_cvtss_f32(_mm_shuffle_ps(m, m, _MM_SHUFFLE(0, 0, 0, 1)));
		}
	}
}