// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

namespace lyah {
	// NOTE: SSE
	/* template<std::size_t C>
	LYAH_NODISCARD LYAH_INLINE vec<C, std::float_t> LYAH_CALL abs(vec<C, std::float_t> a) {
		const __m128 b = _mm_xor_ps(a.m, _mm_set1_ps(-0.0f));

		a.m = _mm_max_ps(a.m, b);

		return a;
	} */

	// NOTE: SSE
	// https://stackoverflow.com/a/41353450/17136841
	/* template<std::size_t C>
	LYAH_NODISCARD LYAH_INLINE vec<C, std::float_t> LYAH_CALL sign(vec<C, std::float_t> a) {
		const __m128 b = _mm_and_ps(a.m, _mm_set1_ps(-0.0f)); // sign bit
		const __m128 c = _mm_cmpneq_ps(a.m, _mm_setzero_ps()); // != 0 -> NaN
		const __m128 d = _mm_and_ps(c, _mm_set1_ps(1.0f)); // NaN -> 1

		a.m = _mm_or_ps(b, d);

		return a;
	} */

	// NOTE: SSE3
	/* LYAH_NODISCARD LYAH_INLINE std::float_t LYAH_CALL max(vec<2, std::float_t> a) {
		const __m128 hdup = _mm_movehdup_ps(a.m);
		const __m128 max = _mm_max_ss(a.m, hdup);

		return _mm_cvtss_f32(max);
	} */

	// NOTE: SSE3
	/* LYAH_NODISCARD LYAH_INLINE std::float_t LYAH_CALL min(vec<2, std::float_t> a) {
		const __m128 hdup = _mm_movehdup_ps(a.m);
		const __m128 min = _mm_min_ss(a.m, hdup);

		return _mm_cvtss_f32(min);
	} */

	// NOTE: SSE
	template<std::size_t C>
	LYAH_NODISCARD LYAH_INLINE vec<C, std::float_t> LYAH_CALL max(vec<C, std::float_t> a, vec<C, std::float_t> b) {
		a.m = _mm_max_ps(a.m, b.m);

		return a;
	}

	// NOTE: SSE
	template<std::size_t C>
	LYAH_NODISCARD LYAH_INLINE vec<C, std::float_t> LYAH_CALL min(vec<C, std::float_t> a, vec<C, std::float_t> b) {
		a.m = _mm_min_ps(a.m, b.m);

		return a;
	}

	// NOTE: SSE3
	LYAH_NODISCARD LYAH_INLINE std::float_t LYAH_CALL sum(vec<2, std::float_t> a) {
		const __m128 sum = _mm_add_ss(a.m, _mm_movehdup_ps(a.m));

		return _mm_cvtss_f32(sum);
	}

	// NOTE: SSE3
	// https://stackoverflow.com/a/35270026
	template<std::size_t C>
	LYAH_NODISCARD LYAH_INLINE std::float_t LYAH_CALL sum(vec<C, std::float_t> a) {
		const __m128 acc = _mm_add_ps(a.m, _mm_movehdup_ps(a.m));
		const __m128 sum = _mm_add_ss(acc, _mm_movehl_ps(_mm_undefined_ps(), acc));

		return _mm_cvtss_f32(sum);
	}
}