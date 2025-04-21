// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

#pragma once

#include "base.hpp"

namespace lyah {
	namespace internal {
		template<typename T>
		struct quat_t;

		template<>
		struct quat_t<std::float_t> {
			using __m_t = __m128;

			// NOTE: SSE
			static __m_t LYAH_CALL wmask() {
				static const __m_t wmask = _mm_set_ss(-0.0f);

				return wmask;
			}

			// NOTE: SSE
			static __m_t LYAH_CALL cnjmask() {
				static const __m_t cnjmask = _mm_set_ps(-0.0f, -0.0f, -0.0f, 0.0f);

				return cnjmask;
			}
		};

		template<>
		struct quat_t<std::double_t> {
			using __m_t = __m256d;

			// NOTE: AVX
			static __m_t LYAH_CALL wmask() {
				static const __m_t wmask = _mm256_set_pd(0.0, 0.0, 0.0, -0.0);

				return wmask;
			}

			// NOTE: AVX
			static __m_t LYAH_CALL cnjmask() {
				static const __m_t cnjmask = _mm256_set_pd(-0.0, -0.0, -0.0, 0.0);

				return cnjmask;
			}
		};

		template<std::size_t C, typename T>
		struct vec_t;

		template<>
		struct vec_t<2, std::float_t> {
			using __m_t = __m128;
		};

		template<>
		struct vec_t<3, std::float_t> {
			using __m_t = __m128;

			// NOTE: SSE2
			static __m_t LYAH_CALL hmask() {
				static const __m_t hmask = _mm_castsi128_ps(_mm_set_epi32(0, -1, -1, -1));

				return hmask;
			}
		};

		template<>
		struct vec_t<4, std::float_t> {
			using __m_t = __m128;
		};

		template<>
		struct vec_t<2, std::double_t> {
			using __m_t = __m128d;
		};

		template<>
		struct vec_t<3, std::double_t> {
			using __m_t = __m256d;

			// NOTE: AVX
			static __m_t LYAH_CALL hmask() {
				static const __m_t hmask = _mm256_castsi256_pd(_mm256_set_epi64x(0, -1, -1, -1));

				return hmask;
			}
		};

		template<>
		struct vec_t<4, std::double_t> {
			using __m_t = __m256d;
		};
	}
}