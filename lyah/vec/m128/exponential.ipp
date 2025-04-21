// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

namespace lyah {
	// NOTE: SSE (SVML)
	template<std::size_t C>
	LYAH_NODISCARD LYAH_INLINE vec<C, std::float_t> LYAH_CALL pow(vec<C, std::float_t> a, vec<C, std::float_t> b) {
		a.m = _mm_pow_ps(a.m, b.m);
		a.m = _mm_and_ps(a.m, internal::vec_t<C, std::float_t>::hmask());

		return a;
	}

	// NOTE: SSE (SVML)
	LYAH_NODISCARD LYAH_INLINE vec<4, std::float_t> LYAH_CALL pow(vec<4, std::float_t> a, vec<4, std::float_t> b) {
		a.m = _mm_pow_ps(a.m, b.m);

		return a;
	}

	// NOTE: SSE
	template<std::size_t C>
	LYAH_NODISCARD LYAH_INLINE vec<C, std::float_t> LYAH_CALL rcp(vec<C, std::float_t> a) {
		a.m = _mm_rcp_ps(a.m);
		a.m = _mm_and_ps(a.m, internal::vec_t<C, std::float_t>::hmask());

		return a;
	}

	// NOTE: SSE
	LYAH_NODISCARD LYAH_INLINE vec<4, std::float_t> LYAH_CALL rcp(vec<4, std::float_t> a) {
		a.m = _mm_rcp_ps(a.m);

		return a;
	}

	// NOTE: SSE
	template<std::size_t C>
	LYAH_NODISCARD LYAH_INLINE vec<C, std::float_t> LYAH_CALL sqrt(vec<C, std::float_t> a) {
		a.m = _mm_sqrt_ps(a.m);

		return a;
	}

	// NOTE: SSE
	template<std::size_t C>
	LYAH_NODISCARD LYAH_INLINE vec<C, std::float_t> LYAH_CALL rsqrt(vec<C, std::float_t> a) {
		a.m = _mm_rsqrt_ps(a.m);
		a.m = _mm_and_ps(a.m, internal::vec_t<C, std::float_t>::hmask());

		return a;
	}

	// NOTE: SSE
	LYAH_NODISCARD LYAH_INLINE vec<4, std::float_t> LYAH_CALL rsqrt(vec<4, std::float_t> a) {
		a.m = _mm_rsqrt_ps(a.m);

		return a;
	}
}