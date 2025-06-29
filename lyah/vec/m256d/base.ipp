// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

namespace lyah {
	// NOTE: AVX
	// https://stackoverflow.com/a/64191351
	template<std::size_t C>
	LYAH_NODISCARD LYAH_INLINE bool LYAH_CALL operator ==(vec<C, std::double_t> a, vec<C, std::double_t> b) {
		static LYAH_CONSTEXPR_CPP26 const std::int32_t bitMask = static_cast<std::int32_t>(pow(2.0f, static_cast<std::float_t>(C))) - 1;

		const __m256d m = _mm256_cmp_pd(a.m, b.m, _CMP_NEQ_OQ);
		const std::int32_t mask = _mm256_movemask_pd(m) & bitMask;

		return mask == 0;
	}

	// NOTE: AVX
	template<std::size_t C>
	LYAH_NODISCARD LYAH_INLINE bool LYAH_CALL operator !=(vec<C, std::double_t> a, vec<C, std::double_t> b) {
		static LYAH_CONSTEXPR_CPP26 const std::int32_t bitMask = static_cast<std::int32_t>(pow(2.0f, static_cast<std::float_t>(C))) - 1;

		const __m256d m = _mm256_cmp_pd(a.m, b.m, _CMP_NEQ_OQ);
		const std::int32_t mask = _mm256_movemask_pd(m) & bitMask;

		return mask != 0;
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

		for (std::size_t i = 0; i < P; i += 1) {
			broadcasti = _mm256_set1_pd(a[i]);
			ai_bi = _mm256_mul_pd(broadcasti, b[i].m);

			result.m = _mm256_add_pd(result.m, ai_bi);
		}

		return result;
	}

	// NOTE: AVX
	template<std::size_t C>
	LYAH_INLINE vec<C, std::double_t>& LYAH_CALL operator /=(vec<C, std::double_t>& a, vec<C, std::double_t> b) {
		a.m = _mm256_div_pd(a.m, b.m);

		return a;
	}
}