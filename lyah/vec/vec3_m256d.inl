// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

namespace lyah {
	// NOTE: AVX
	template<>
	LYAH_INLINE vec<3, std::double_t>::vec() : m(_mm256_setzero_pd()) {}

	// NOTE: AVX
	template<>
	LYAH_INLINE vec<3, std::double_t>::vec(std::double_t x, std::double_t y, std::double_t z) : m(_mm256_set_pd(0.0, z, y, x)) {}

	template<>
	LYAH_CONSTEXPR LYAH_INLINE vec<3, std::double_t>::vec(__m256d m) : m(m) {}

	// NOTE: AVX2
	LYAH_INLINE std::double_t vec<3, std::double_t>::operator [](std::size_t index) const LYAH_NOEXCEPT {
		LYAH_ASSERT(index < 3);

		switch (index) {
			default:
			case 0: return _mm256_cvtsd_f64(m);
			case 1: return _mm256_cvtsd_f64(_mm256_shuffle_pd(m, m, _MM_SHUFFLE(0, 0, 0, 1)));
			case 2: return _mm256_cvtsd_f64(_mm256_permute4x64_pd(m, _MM_SHUFFLE(0, 0, 0, 2)));
		}
	}
}