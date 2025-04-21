// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

namespace lyah {
	// NOTE: SSE2
	LYAH_NODISCARD LYAH_INLINE bool LYAH_CALL operator ==(vec<2, std::double_t> a, vec<2, std::double_t> b) {
		const __m128d m = _mm_cmpneq_pd(a.m, b.m);

		return _mm_movemask_pd(m) == 0;
	}

	// NOTE: SSE2
	LYAH_NODISCARD LYAH_INLINE bool LYAH_CALL operator !=(vec<2, std::double_t> a, vec<2, std::double_t> b) {
		const __m128d m = _mm_cmpneq_pd(a.m, b.m);

		return _mm_movemask_pd(m) != 0;
	}

	// NOTE: SSE2
	LYAH_NODISCARD LYAH_INLINE vec<2, std::double_t> LYAH_CALL operator -(vec<2, std::double_t> a) {
		a.m = _mm_xor_pd(a.m, _mm_set1_pd(-0.0));

		return a;
	}

	// NOTE: SSE2
	LYAH_INLINE vec<2, std::double_t>& LYAH_CALL operator +=(vec<2, std::double_t>& a, vec<2, std::double_t> b) {
		a.m = _mm_add_pd(a.m, b.m);

		return a;
	}

	// NOTE: SSE2
	LYAH_INLINE vec<2, std::double_t>& LYAH_CALL operator -=(vec<2, std::double_t>& a, vec<2, std::double_t> b) {
		a.m = _mm_sub_pd(a.m, b.m);

		return a;
	}

	// NOTE: SSE2
	LYAH_INLINE vec<2, std::double_t>& LYAH_CALL operator *=(vec<2, std::double_t>& a, std::double_t b) {
		a.m = _mm_mul_pd(a.m, _mm_set1_pd(b));

		return a;
	}

	// NOTE: SSE2
	LYAH_INLINE vec<2, std::double_t>& LYAH_CALL operator *=(vec<2, std::double_t>& a, vec<2, std::double_t> b) {
		a.m = _mm_mul_pd(a.m, b.m);

		return a;
	}

	// TODO: vec<2, std::double_t> * mat<2, 2, std::double_t>

	// NOTE: SSE2
	LYAH_NODISCARD LYAH_INLINE vec<2, std::double_t> LYAH_CALL operator /(std::double_t a, vec<2, std::double_t> b) {
		b.m = _mm_div_pd(_mm_set1_pd(a), b.m);

		return b;
	}

	// NOTE: SSE2
	LYAH_INLINE vec<2, std::double_t>& LYAH_CALL operator /=(vec<2, std::double_t>& a, vec<2, std::double_t> b) {
		a.m = _mm_div_pd(a.m, b.m);

		return a;
	}
}