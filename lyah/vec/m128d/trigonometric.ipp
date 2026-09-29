// Copyright 2025 Atalante Studio.
// Distributed under the MIT License.

namespace lyah {
	// NOTE: SSE (SVML)
	LYAH_INLINE vec<2, std::double_t> LYAH_CALL sin(vec<2, std::double_t> a) {
		#if defined(LYAH_SVML)
			a.m = _mm_sin_pd(a.m);
		#else
			std::double_t p[2];

			_mm_store_pd(p, a.m);

			p[0] = std::sin(p[0]);
			p[1] = std::sin(p[1]);

			a.m = _mm_load_pd(p);
		#endif

		return a;
	}

	// NOTE: SSE (SVML)
	LYAH_INLINE vec<2, std::double_t> LYAH_CALL cos(vec<2, std::double_t> a) {
		#if defined(LYAH_SVML)
			a.m = _mm_cos_pd(a.m);
		#else
			std::double_t p[2];

			_mm_store_pd(p, a.m);

			p[0] = std::cos(p[0]);
			p[1] = std::cos(p[1]);

			a.m = _mm_load_pd(p);
		#endif

		return a;
	}

	// NOTE: SSE (SVML)
	LYAH_INLINE vec<2, std::double_t> LYAH_CALL tan(vec<2, std::double_t> a) {
		#if defined(LYAH_SVML)
			a.m = _mm_tan_pd(a.m);
		#else
			std::double_t p[2];

			_mm_store_pd(p, a.m);

			p[0] = std::tan(p[0]);
			p[1] = std::tan(p[1]);

			a.m = _mm_load_pd(p);
		#endif

		return a;
	}
}