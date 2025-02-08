namespace lyah {
	// NOTE: AVX
	// https://stackoverflow.com/a/64191351
	template<std::size_t C>
	LYAH_NODISCARD LYAH_INLINE bool LYAH_CALL operator ==(vec<C, std::double_t> a, vec<C, std::double_t> b) {
		const __m256d m = _mm256_cmp_pd(a.m, b.m, _CMP_NEQ_OQ);

		return _mm256_movemask_pd(m) == 0;
	}

	// NOTE: AVX
	template<std::size_t C>
	LYAH_NODISCARD LYAH_INLINE bool LYAH_CALL operator !=(vec<C, std::double_t> a, vec<C, std::double_t> b) {
		const __m256d m = _mm256_cmp_pd(a.m, b.m, _CMP_NEQ_OQ);

		return _mm256_movemask_pd(m) != 0;
	}

	// NOTE: AVX
	template<std::size_t C>
	LYAH_NODISCARD LYAH_INLINE vec<C, std::double_t> LYAH_CALL operator -(vec<C, std::double_t> a) {
		a.m = _mm256_xor_pd(a.m, _mm256_set1_pd(-0.0));

		return a;
	}

	// NOTE: AVX
	template<std::size_t C>
	LYAH_INLINE vec<C, std::double_t>& LYAH_CALL operator +=(vec<C, std::double_t>& a, vec<C, std::double_t> b) {
		a.m = _mm256_add_pd(a.m, b.m);

		return a;
	}

	// NOTE: AVX
	template<std::size_t C>
	LYAH_INLINE vec<C, std::double_t>& LYAH_CALL operator -=(vec<C, std::double_t>& a, vec<C, std::double_t> b) {
		a.m = _mm256_sub_pd(a.m, b.m);

		return a;
	}

	// NOTE: AVX
	template<std::size_t C>
	LYAH_INLINE vec<C, std::double_t>& LYAH_CALL operator *=(vec<C, std::double_t>& a, std::double_t b) {
		a.m = _mm256_mul_pd(a.m, _mm256_set1_pd(b));

		return a;
	}

	// NOTE: AVX
	template<std::size_t C>
	LYAH_INLINE vec<C, std::double_t>& LYAH_CALL operator *=(vec<C, std::double_t>& a, vec<C, std::double_t> b) {
		a.m = _mm256_mul_pd(a.m, b.m);

		return a;
	}

	// NOTE: AVX
	template<std::size_t N, std::size_t P>
	LYAH_NODISCARD LYAH_INLINE vec<P, std::double_t> LYAH_CALL operator *(vec<N, std::double_t> a, mat<N, P, std::double_t> b) {
		__m256d broadcasti = _mm256_undefined_pd();
		__m256d ai_bi = _mm256_undefined_pd();
		vec<P, std::double_t> result;

		for (std::size_t i = 0; i < P; i++) {
			broadcasti = _mm256_set1_pd(a[i]);
			ai_bi = _mm256_mul_pd(broadcasti, b[i].m);

			result.m = _mm256_add_pd(result.m, ai_bi);
		}

		return result;
	}

	// NOTE: AVX
	template<std::size_t C>
	LYAH_NODISCARD LYAH_INLINE vec<C, std::double_t> LYAH_CALL operator /(std::double_t a, vec<C, std::double_t> b) {
		b.m = _mm256_div_pd(_mm256_set1_pd(a), b.m);
		b.m = _mm256_and_pd(b.m, internal::vec_t<C, std::double_t>::hmask());

		return b;
	}

	// NOTE: AVX
	LYAH_NODISCARD LYAH_INLINE vec<4, std::double_t> LYAH_CALL operator /(std::double_t a, vec<4, std::double_t> b) {
		b.m = _mm256_div_pd(_mm256_set1_pd(a), b.m);

		return b;
	}

	// NOTE: AVX
	template<std::size_t C>
	LYAH_INLINE vec<C, std::double_t>& LYAH_CALL operator /=(vec<C, std::double_t>& a, vec<C, std::double_t> b) {
		a.m = _mm256_div_pd(a.m, b.m);
		a.m = _mm256_and_pd(a.m, internal::vec_t<C, std::double_t>::hmask());

		return a;
	}

	// NOTE: AVX
	LYAH_INLINE vec<4, std::double_t>& LYAH_CALL operator /=(vec<4, std::double_t>& a, vec<4, std::double_t> b) {
		a.m = _mm256_div_pd(a.m, b.m);

		return a;
	}
}