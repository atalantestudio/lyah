// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

namespace lyah {
	// NOTE: AVX
	template<std::size_t C>
	LYAH_NODISCARD LYAH_INLINE vec<C, std::double_t> LYAH_CALL max(vec<C, std::double_t> a, vec<C, std::double_t> b) {
		a.m = _mm256_max_pd(a.m, b.m);

		return a;
	}

	// NOTE: AVX
	template<std::size_t C>
	LYAH_NODISCARD LYAH_INLINE vec<C, std::double_t> LYAH_CALL min(vec<C, std::double_t> a, vec<C, std::double_t> b) {
		a.m = _mm256_min_pd(a.m, b.m);

		return a;
	}

	// NOTE: AVX
	// https://stackoverflow.com/a/13222410
	// https://stackoverflow.com/a/49943540
	template<std::size_t C>
	LYAH_NODISCARD LYAH_INLINE std::double_t LYAH_CALL sum(vec<C, std::double_t> a) {
		const __m128d b = _mm_add_pd(_mm256_castpd256_pd128(a.m), _mm256_extractf128_pd(a.m, 1));
		const __m128d m = _mm_add_sd(b, _mm_unpackhi_pd(b, b));

		return _mm_cvtsd_f64(m);
	}
}