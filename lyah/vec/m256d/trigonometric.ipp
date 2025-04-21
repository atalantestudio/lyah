// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

namespace lyah {
	// NOTE: AVX (SVML)
	template<std::size_t C>
	LYAH_INLINE vec<C, std::double_t> LYAH_CALL sin(vec<C, std::double_t> a) {
		a.m = _mm256_sin_pd(a.m);

		return a;
	}

	// NOTE: AVX (SVML)
	template<std::size_t C>
	LYAH_INLINE vec<C, std::double_t> LYAH_CALL cos(vec<C, std::double_t> a) {
		a.m = _mm256_cos_pd(a.m);
		a.m = _mm256_and_pd(a.m, internal::vec_t<C, std::double_t>::hmask());

		return a;
	}

	// NOTE: AVX (SVML)
	LYAH_INLINE vec<4, std::double_t> LYAH_CALL cos(vec<4, std::double_t> a) {
		a.m = _mm256_cos_pd(a.m);

		return a;
	}

	// NOTE: AVX (SVML)
	template<std::size_t C>
	LYAH_INLINE vec<C, std::double_t> LYAH_CALL tan(vec<C, std::double_t> a) {
		a.m = _mm256_tan_pd(a.m);

		return a;
	}
}