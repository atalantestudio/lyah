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
	LYAH_INLINE vec<2, std::double_t>& LYAH_CALL operator *=(vec<2, std::double_t>& a, vec<2, std::double_t> b) {
		a.m = _mm_mul_pd(a.m, b.m);

		return a;
	}

	// NOTE: SSE2
	template<std::size_t P>
	LYAH_NODISCARD LYAH_INLINE vec<P, std::double_t> LYAH_CALL operator *(vec<2, std::double_t> a, mat<2, P, std::double_t> b) {
		__m128d broadcasti = _mm_undefined_pd();
		__m128d ai_bi = _mm_undefined_pd();
		vec<P, std::double_t> result;

		for (std::size_t i = 0; i < P; i += 1) {
			broadcasti = _mm_set1_pd(a[i]);
			ai_bi = _mm_mul_pd(broadcasti, b[i].m);

			result.m = _mm_add_pd(result.m, ai_bi);
		}

		return result;
	}

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