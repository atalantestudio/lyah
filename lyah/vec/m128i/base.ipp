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
}