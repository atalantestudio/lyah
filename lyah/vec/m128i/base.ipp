// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

namespace lyah {
	// TODO: Apply bitmask.
	// NOTE: SSE2
	// https://stackoverflow.com/a/26881190/17136841
	template<std::size_t C>
	LYAH_NODISCARD LYAH_INLINE bool LYAH_CALL operator ==(vec<C, std::int32_t> a, vec<C, std::int32_t> b) {
		const __m128i m = _mm_cmpeq_epi32(a.m, b.m);
		const std::int32_t mask = _mm_movemask_epi8(m);

		return mask == 0xffff;
	}

	// TODO: Apply bitmask.
	// NOTE: SSE2
	// https://stackoverflow.com/a/26881190/17136841
	template<std::size_t C>
	LYAH_NODISCARD LYAH_INLINE bool LYAH_CALL operator !=(vec<C, std::int32_t> a, vec<C, std::int32_t> b) {
		const __m128i m = _mm_cmpeq_epi32(a.m, b.m);
		const std::int32_t mask = _mm_movemask_epi8(m);

		return mask != 0xffff;
	}

	// NOTE: SSE2
	template<std::size_t C>
	LYAH_NODISCARD LYAH_INLINE vec<C, std::int32_t> LYAH_CALL operator -(vec<C, std::int32_t> a) {
		a.m = _mm_sub_epi32(_mm_setzero_si128(), a.m);

		return a;
	}

	// NOTE: SSE2
	template<std::size_t C>
	LYAH_INLINE vec<C, std::int32_t>& LYAH_CALL operator +=(vec<C, std::int32_t>& a, vec<C, std::int32_t> b) {
		a.m = _mm_add_epi32(a.m, b.m);

		return a;
	}

	// NOTE: SSE2
	template<std::size_t C>
	LYAH_INLINE vec<C, std::int32_t>& LYAH_CALL operator -=(vec<C, std::int32_t>& a, vec<C, std::int32_t> b) {
		a.m = _mm_sub_epi32(a.m, b.m);

		return a;
	}

	// NOTE: SSE2/SSE4.1
	// https://stackoverflow.com/a/17268337/17136841
	// https://github.com/vectorclass/version2/blob/f4617df57e17efcd754f5bbe0ec87883e0ed9ce6/vectori128.h#L3108
	template<std::size_t C>
	LYAH_INLINE vec<C, std::int32_t>& LYAH_CALL operator *=(vec<C, std::int32_t>& a, vec<C, std::int32_t> b) {
		#if LYAH_INT32_MAX_INSTRUCTION_SET < LYAH_INSTRUCTION_SET_SSE4_1
			const __m128i m0 = _mm_mul_epu32(a.m, b.m);

			const __m128i m1l = _mm_shuffle_epi32(a.m, _MM_SHUFFLE(3, 3, 1, 1));
			const __m128i m1r = _mm_shuffle_epi32(b.m, _MM_SHUFFLE(3, 3, 1, 1));
			const __m128i m1 = _mm_mul_epu32(m1l, m1r);

			const __m128i l = _mm_unpacklo_epi32(m0, m1);
			const __m128i h = _mm_unpackhi_epi32(m0, m1);

			a.m = _mm_unpacklo_epi64(l, h);
		#else
			a.m = _mm_mullo_epi32(a.m, b.m);
		#endif

		return a;
	}
}