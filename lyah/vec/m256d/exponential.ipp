// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

namespace lyah {
	// NOTE: AVX (SVML)
	template<std::size_t C>
	LYAH_NODISCARD LYAH_INLINE vec<C, std::double_t> LYAH_CALL pow(vec<C, std::double_t> a, vec<C, std::double_t> b) {
		a.m = _mm256_pow_pd(a.m, b.m);

		return a;
	}

	// NOTE: AVX
	template<std::size_t C>
	LYAH_NODISCARD LYAH_INLINE vec<C, std::double_t> LYAH_CALL sqrt(vec<C, std::double_t> a) {
		a.m = _mm256_sqrt_pd(a.m);

		return a;
	}
}