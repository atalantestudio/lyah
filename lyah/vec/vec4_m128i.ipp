// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

namespace lyah {
	// NOTE: SSE2
	LYAH_INLINE vec<4, std::int32_t>::vec() : m(_mm_setzero_si128()) {}

	// NOTE: SSE2
	LYAH_INLINE vec<4, std::int32_t>::vec(std::int32_t x, std::int32_t y, std::int32_t z, std::int32_t w) : m(_mm_set_epi32(w, z, y, x)) {}

	// NOTE: SSE2
	LYAH_INLINE vec<4, std::int32_t>::vec(std::int32_t a) : m(_mm_set1_epi32(a)) {}

	// NOTE: SSE2
	LYAH_INLINE std::int32_t vec<4, std::int32_t>::operator [](std::size_t index) const LYAH_NOEXCEPT {
		LYAH_ASSERT(index < 4);

		switch (index) {
			default:
			case 0: return _mm_cvtsi128_si32(m);
			case 1: return _mm_cvtsi128_si32(_mm_shuffle_epi32(m, _MM_SHUFFLE(0, 0, 0, 1)));
			case 2: return _mm_cvtsi128_si32(_mm_shuffle_epi32(m, _MM_SHUFFLE(0, 0, 0, 2)));
			case 3: return _mm_cvtsi128_si32(_mm_shuffle_epi32(m, _MM_SHUFFLE(0, 0, 0, 3)));
		}
	}
}