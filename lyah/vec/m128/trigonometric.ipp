// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

namespace lyah {
	// NOTE: SSE (SVML)
	template<std::size_t C>
	LYAH_INLINE vec<C, std::float_t> LYAH_CALL sin(vec<C, std::float_t> a) {
		a.m = _mm_sin_ps(a.m);

		return a;
	}

	// NOTE: SSE (SVML)
	template<std::size_t C>
	LYAH_INLINE vec<C, std::float_t> LYAH_CALL cos(vec<C, std::float_t> a) {
		a.m = _mm_cos_ps(a.m);
		a.m = _mm_and_ps(a.m, internal::vec_t<C, std::float_t>::hmask());

		return a;
	}

	// NOTE: SSE (SVML)
	LYAH_INLINE vec<4, std::float_t> LYAH_CALL cos(vec<4, std::float_t> a) {
		a.m = _mm_cos_ps(a.m);

		return a;
	}

	// NOTE: SSE (SVML)
	template<std::size_t C>
	LYAH_INLINE vec<C, std::float_t> LYAH_CALL tan(vec<C, std::float_t> a) {
		a.m = _mm_tan_ps(a.m);

		return a;
	}
}