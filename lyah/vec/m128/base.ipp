// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

namespace lyah {
	// NOTE: SSE
	// https://stackoverflow.com/a/6042506
	template<std::size_t C>
	LYAH_NODISCARD LYAH_INLINE bool LYAH_CALL operator ==(vec<C, std::float_t> a, vec<C, std::float_t> b) {
		const __m128 m = _mm_cmpneq_ps(a.m, b.m);

		return _mm_movemask_ps(m) == 0;
	}

	// NOTE: SSE
	// https://stackoverflow.com/a/6042506
	template<std::size_t C>
	LYAH_NODISCARD LYAH_INLINE bool LYAH_CALL operator !=(vec<C, std::float_t> a, vec<C, std::float_t> b) {
		const __m128 m = _mm_cmpneq_ps(a.m, b.m);

		return _mm_movemask_ps(m) != 0;
	}

	// NOTE: SSE
	// https://stackoverflow.com/a/20084034
	template<std::size_t C>
	LYAH_NODISCARD LYAH_INLINE vec<C, std::float_t> LYAH_CALL operator -(vec<C, std::float_t> a) {
		a.m = _mm_xor_ps(a.m, _mm_set1_ps(-0.0f));

		return a;
	}

	// NOTE: SSE
	template<std::size_t C>
	LYAH_INLINE vec<C, std::float_t>& LYAH_CALL operator +=(vec<C, std::float_t>& a, vec<C, std::float_t> b) {
		a.m = _mm_add_ps(a.m, b.m);

		return a;
	}

	// NOTE: SSE
	template<std::size_t C>
	LYAH_INLINE vec<C, std::float_t>& LYAH_CALL operator -=(vec<C, std::float_t>& a, vec<C, std::float_t> b) {
		a.m = _mm_sub_ps(a.m, b.m);

		return a;
	}

	// NOTE: SSE
	template<std::size_t C>
	LYAH_INLINE vec<C, std::float_t>& LYAH_CALL operator *=(vec<C, std::float_t>& a, std::float_t b) {
		a.m = _mm_mul_ps(a.m, _mm_set1_ps(b));

		return a;
	}

	// NOTE: SSE
	template<std::size_t C>
	LYAH_INLINE vec<C, std::float_t>& LYAH_CALL operator *=(vec<C, std::float_t>& a, vec<C, std::float_t> b) {
		a.m = _mm_mul_ps(a.m, b.m);

		return a;
	}

	// NOTE: SSE
	template<std::size_t N, std::size_t P>
	LYAH_NODISCARD LYAH_INLINE vec<P, std::float_t> LYAH_CALL operator *(vec<N, std::float_t> a, mat<N, P, std::float_t> b) {
		__m128 broadcasti = _mm_undefined_ps();
		__m128 ai_bi = _mm_undefined_ps();
		vec<P, std::float_t> result;

		for (std::size_t i = 0; i < P; i++) {
			broadcasti = _mm_set1_ps(a[i]);
			ai_bi = _mm_mul_ps(broadcasti, b[i].m);

			result.m = _mm_add_ps(result.m, ai_bi);
		}

		return result;
	}

	// NOTE: SSE
	template<std::size_t C>
	LYAH_NODISCARD LYAH_INLINE vec<C, std::float_t> LYAH_CALL operator /(std::float_t a, vec<C, std::float_t> b) {
		b.m = _mm_div_ps(_mm_set1_ps(a), b.m);
		b.m = _mm_and_ps(b.m, internal::vec_t<C, std::float_t>::hmask());

		return b;
	}

	// NOTE: SSE
	LYAH_NODISCARD LYAH_INLINE vec<4, std::float_t> LYAH_CALL operator /(std::float_t a, vec<4, std::float_t> b) {
		b.m = _mm_div_ps(_mm_set1_ps(a), b.m);

		return b;
	}

	// NOTE: SSE
	template<std::size_t C>
	LYAH_INLINE vec<C, std::float_t>& LYAH_CALL operator /=(vec<C, std::float_t>& a, vec<C, std::float_t> b) {
		a.m = _mm_div_ps(a.m, b.m);
		a.m = _mm_and_ps(a.m, internal::vec_t<C, std::float_t>::hmask());

		return a;
	}

	// NOTE: SSE
	LYAH_INLINE vec<4, std::float_t>& LYAH_CALL operator /=(vec<4, std::float_t>& a, vec<4, std::float_t> b) {
		a.m = _mm_div_ps(a.m, b.m);

		return a;
	}
}