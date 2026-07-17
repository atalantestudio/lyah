// Copyright 2025 Atalante Studio.
// Distributed under the MIT License.

namespace lyah {
	// NOTE: SSE (SVML)
	LYAH_NODISCARD LYAH_INLINE vec<2, std::double_t> LYAH_CALL pow(vec<2, std::double_t> a, vec<2, std::double_t> b) {
		#if defined(LYAH_SVML)
			a.m = _mm_pow_pd(a.m, b.m);
		#else
			std::double_t p[4];

			_mm_store_pd(p + 0, a.m);
			_mm_store_pd(p + 2, b.m);

			p[0] = std::pow(p[0], p[2]);
			p[1] = std::pow(p[1], p[3]);

			a.m = _mm_load_pd(p);
		#endif

		return a;
	}

	// NOTE: SSE2
	LYAH_NODISCARD LYAH_INLINE vec<2, std::double_t> LYAH_CALL sqrt(vec<2, std::double_t> a) {
		a.m = _mm_sqrt_pd(a.m);

		return a;
	}
}