// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

#pragma once

#include "base.hpp"

namespace lyah {
	namespace internal {
		template<typename I, typename O>
		LYAH_NODISCARD LYAH_CONSTEXPR LYAH_INLINE O LYAH_CALL convert(I m) {
			// should not be here
			LYAH_STATIC_ASSERT(false);
		}

		// Converts the 2 lower 32-bit floats to 2 64-bit floats.
		// NOTE: SSE2
		template<>
		LYAH_NODISCARD LYAH_INLINE __m128d LYAH_CALL convert(__m128 m) {
			return _mm_cvtps_pd(m);
		}

		/*// NOTE: SSE2
		template<>
		LYAH_NODISCARD LYAH_INLINE __m128i LYAH_CALL convert(__m128 m) {
			return _mm_cvttps_epi32(m);
		}*/

		// NOTE: AVX
		template<>
		LYAH_NODISCARD LYAH_INLINE __m256d LYAH_CALL convert(__m128 m) {
			return _mm256_cvtps_pd(m);
		}

		/*template<>
		LYAH_NODISCARD LYAH_INLINE __m256i LYAH_CALL convert(__m128 m) {
			return convert<__m128i, __m256i>(convert<__m128, __m128i>(m));
		}*/

		// NOTE: SSE2
		template<>
		LYAH_NODISCARD LYAH_INLINE __m128 LYAH_CALL convert(__m128d m) {
			return _mm_cvtpd_ps(m);
		}

		/*// NOTE: SSE2
		template<>
		LYAH_NODISCARD LYAH_INLINE __m128i LYAH_CALL convert(__m128d m) {
			const std::int64_t x = static_cast<std::int64_t>(_mm_cvtsd_f64(m));
			const std::int64_t y = static_cast<std::int64_t>(_mm_cvtsd_f64(_mm_unpackhi_pd(m, m)));

			return _mm_set_epi64(y, x);
		}*/

		// NOTE: AVX2
		template<>
		LYAH_NODISCARD LYAH_INLINE __m256i LYAH_CALL convert(__m128i m) {
			return _mm256_cvtepi32_epi64(m);
		}

		// NOTE: AVX
		template<>
		LYAH_NODISCARD LYAH_INLINE __m128 LYAH_CALL convert(__m256d m) {
			return _mm256_cvtpd_ps(m);
		}

		// Converts 4 64-bit integers to 4 32-bit integers.
		// NOTE: AVX
		// https://stackoverflow.com/a/69408295/17136841
		template<>
		LYAH_NODISCARD LYAH_INLINE __m128i LYAH_CALL convert(__m256i m) {
			const __m256 a = _mm256_castsi256_ps(m);
			const __m128 h = _mm256_extractf128_ps(a, 1);
			const __m128 l = _mm256_castps256_ps128(a);

			return _mm_castps_si128(_mm_shuffle_ps(l, h, _MM_SHUFFLE(2, 0, 2, 0)));
		}
	}
}