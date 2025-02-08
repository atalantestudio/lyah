// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

#pragma once

#include "base.hpp"

namespace lyah {
	namespace internal {
		template<typename T, typename U>
		LYAH_NODISCARD LYAH_CONSTEXPR LYAH_INLINE U LYAH_CALL convert(T m) {
			// should not be here
			LYAH_ASSERT(false);
		}

		// NOTE: SSE2
		template<>
		LYAH_NODISCARD LYAH_INLINE __m128d LYAH_CALL convert(__m128 m) {
			return _mm_cvtps_pd(m);
		}

		// NOTE: AVX
		template<>
		LYAH_NODISCARD LYAH_INLINE __m256d LYAH_CALL convert(__m128 m) {
			return _mm256_cvtps_pd(m);
		}

		// NOTE: SSE2
		template<>
		LYAH_NODISCARD LYAH_INLINE __m128 LYAH_CALL convert(__m128d m) {
			return _mm_cvtpd_ps(m);
		}

		// NOTE: AVX
		template<>
		LYAH_NODISCARD LYAH_INLINE __m128 LYAH_CALL convert(__m256d m) {
			return _mm256_cvtpd_ps(m);
		}
	}
}