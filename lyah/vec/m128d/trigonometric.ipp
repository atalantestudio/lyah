// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

namespace lyah {
	// NOTE: SSE (SVML)
	LYAH_INLINE vec<2, std::double_t> LYAH_CALL sin(vec<2, std::double_t> a) {
		a.m = _mm_sin_pd(a.m);

		return a;
	}

	// NOTE: SSE (SVML)
	LYAH_INLINE vec<2, std::double_t> LYAH_CALL cos(vec<2, std::double_t> a) {
		a.m = _mm_cos_pd(a.m);

		return a;
	}

	// NOTE: SSE (SVML)
	LYAH_INLINE vec<2, std::double_t> LYAH_CALL tan(vec<2, std::double_t> a) {
		a.m = _mm_tan_pd(a.m);

		return a;
	}
}