// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

namespace lyah {
	// TODO: Apply bitmask.
	// NOTE: AVX2
	// https://stackoverflow.com/a/26881190/17136841
	template<std::size_t C>
	LYAH_NODISCARD LYAH_INLINE bool LYAH_CALL operator ==(vec<C, std::int64_t> a, vec<C, std::int64_t> b) {
		const __m256i m = _mm256_cmpeq_epi64(a.m, b.m);
		const std::int32_t mask = _mm256_movemask_epi8(m);

		return mask == -1;
	}

	// TODO: Apply bitmask.
	// NOTE: AVX2
	// https://stackoverflow.com/a/26881190/17136841
	template<std::size_t C>
	LYAH_NODISCARD LYAH_INLINE bool LYAH_CALL operator !=(vec<C, std::int64_t> a, vec<C, std::int64_t> b) {
		const __m256i m = _mm256_cmpeq_epi64(a.m, b.m);
		const std::int32_t mask = _mm256_movemask_epi8(m);

		return mask != -1;
	}

	// NOTE: AVX2
	template<std::size_t C>
	LYAH_NODISCARD LYAH_INLINE vec<C, std::int64_t> LYAH_CALL operator -(vec<C, std::int64_t> a) {
		a.m = _mm256_sub_epi64(_mm256_setzero_si256(), a.m);

		return a;
	}

	// NOTE: AVX2
	template<std::size_t C>
	LYAH_INLINE vec<C, std::int64_t>& LYAH_CALL operator +=(vec<C, std::int64_t>& a, vec<C, std::int64_t> b) {
		a.m = _mm256_add_epi64(a.m, b.m);

		return a;
	}

	// NOTE: AVX2
	template<std::size_t C>
	LYAH_INLINE vec<C, std::int64_t>& LYAH_CALL operator -=(vec<C, std::int64_t>& a, vec<C, std::int64_t> b) {
		a.m = _mm256_sub_epi64(a.m, b.m);

		return a;
	}
}