// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

namespace lyah {
	// NOTE: SSE2
	template<>
	LYAH_INLINE vec<2, std::double_t>::vec() : m(_mm_setzero_pd()) {}

	// NOTE: SSE2
	template<>
	LYAH_INLINE vec<2, std::double_t>::vec(std::double_t x, std::double_t y) : m(_mm_set_pd(y, x)) {}

	template<>
	LYAH_CONSTEXPR LYAH_INLINE vec<2, std::double_t>::vec(__m128d m) : m(m) {}

	// NOTE: SSE2
	LYAH_INLINE std::double_t vec<2, std::double_t>::operator [](std::size_t index) const LYAH_NOEXCEPT {
		LYAH_ASSERT(index < 2);

		switch (index) {
			default:
			case 0: return _mm_cvtsd_f64(m);
			case 1: return _mm_cvtsd_f64(_mm_shuffle_pd(m, m, _MM_SHUFFLE(0, 0, 0, 1)));
		}
	}
}