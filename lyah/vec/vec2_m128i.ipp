// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

namespace lyah {
	// NOTE: SSE2
	LYAH_INLINE vec<2, std::int64_t>::vec() :
		m(_mm_setzero_si128())
	{}

	// NOTE: SSE2
	LYAH_INLINE vec<2, std::int64_t>::vec(std::int64_t x, std::int64_t y) :
		m(_mm_set_epi64x(y, x))
	{}

	// NOTE: SSE2
	LYAH_INLINE vec<2, std::int64_t>::vec(std::int64_t a) :
		m(_mm_set1_epi64x(a))
	{}

	// NOTE: SSE2
	LYAH_INLINE std::int64_t vec<2, std::int64_t>::operator [](std::size_t index) const LYAH_NOEXCEPT {
		LYAH_ASSERT(index < 2);

		switch (index) {
			default:
			case 0: return _mm_cvtsi128_si64(m);
			case 1: return _mm_cvtsi128_si64(_mm_unpackhi_epi64(m, m));
		}
	}
}