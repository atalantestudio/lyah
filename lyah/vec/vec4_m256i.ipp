// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

namespace lyah {
	// NOTE: AVX
	LYAH_INLINE vec<4, std::int64_t>::vec() : m(_mm256_setzero_si256()) {}

	// NOTE: AVX
	LYAH_INLINE vec<4, std::int64_t>::vec(std::int64_t x, std::int64_t y, std::int64_t z, std::int64_t w) : m(_mm256_set_epi64x(w, z, y, x)) {}

	// NOTE: AVX
	LYAH_INLINE vec<4, std::int64_t>::vec(std::int64_t a) : m(_mm256_set1_epi64x(a)) {}

	// NOTE: AVX2
	LYAH_INLINE std::int64_t vec<4, std::int64_t>::operator [](std::size_t index) const LYAH_NOEXCEPT {
		LYAH_ASSERT(index < 4);

		switch (index) {
			default:
			case 0: return _mm_cvtsi128_si64(_mm256_castsi256_si128(m));
			case 1: return _mm_cvtsi128_si64(_mm_srli_si128(_mm256_castsi256_si128(m), 8));
			case 2: return _mm_cvtsi128_si64(_mm256_extracti128_si256(m, 1));
			case 3: return _mm_cvtsi128_si64(_mm_srli_si128(_mm256_extracti128_si256(m, 1), 8));
		}
	}
}