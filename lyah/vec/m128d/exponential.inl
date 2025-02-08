// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

namespace lyah {
	// NOTE: SSE (SVML)
	LYAH_NODISCARD LYAH_INLINE vec<2, std::double_t> LYAH_CALL pow(vec<2, std::double_t> a, vec<2, std::double_t> b) {
		a.m = _mm_pow_pd(a.m, b.m);

		return a;
	}

	// NOTE: SSE2
	LYAH_NODISCARD LYAH_INLINE vec<2, std::double_t> LYAH_CALL sqrt(vec<2, std::double_t> a) {
		a.m = _mm_sqrt_pd(a.m);

		return a;
	}
}