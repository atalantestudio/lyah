// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

namespace lyah {
	// NOTE: SSE2
	/* LYAH_NODISCARD LYAH_INLINE std::double_t LYAH_CALL max(vec<2, std::double_t> a) {
		const __m128d hl = _mm_castps_pd(_mm_movehl_ps(_mm_undefined_ps(), _mm_castpd_ps(a.m)));
		const __m128d max = _mm_max_sd(a.m, hl);

		return _mm_cvtsd_f64(max);
	} */

	// NOTE: SSE2
	/* LYAH_NODISCARD LYAH_INLINE std::double_t LYAH_CALL min(vec<2, std::double_t> a) {
		const __m128d hl = _mm_castps_pd(_mm_movehl_ps(_mm_undefined_ps(), _mm_castpd_ps(a.m)));
		const __m128d min = _mm_min_sd(a.m, hl);

		return _mm_cvtsd_f64(min);
	} */

	// NOTE: SSE2
	LYAH_NODISCARD LYAH_INLINE vec<2, std::double_t> LYAH_CALL max(vec<2, std::double_t> a, vec<2, std::double_t> b) {
		a.m = _mm_max_pd(a.m, b.m);

		return a;
	}

	// NOTE: SSE2
	LYAH_NODISCARD LYAH_INLINE vec<2, std::double_t> LYAH_CALL min(vec<2, std::double_t> a, vec<2, std::double_t> b) {
		a.m = _mm_min_pd(a.m, b.m);

		return a;
	}

	// NOTE: SSE2
	LYAH_NODISCARD LYAH_INLINE std::double_t LYAH_CALL sum(vec<2, std::double_t> a) {
		const __m128d sum = _mm_add_sd(a.m, _mm_castps_pd(_mm_movehl_ps(_mm_undefined_ps(), _mm_castpd_ps(a.m))));

		return _mm_cvtsd_f64(sum);
	}
}