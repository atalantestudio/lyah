// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

#pragma once

#include "mat/mat.hpp"

namespace lyah {
	template<typename T>
	struct mat<2, 2, T> {
		LYAH_NODISCARD LYAH_INLINE static mat<2, 2, T> LYAH_CALL identity() {
			return {
				static_cast<T>(1), static_cast<T>(0),
				static_cast<T>(0), static_cast<T>(1),
			};
		}

		vec<2, T> m[2];

		LYAH_NODISCARD LYAH_INLINE mat() : m{} {}

		LYAH_NODISCARD LYAH_INLINE mat(
			T m00, T m01,
			T m10, T m11
		) : m{
			{m00, m01},
			{m10, m11},
		} {}

		LYAH_NODISCARD LYAH_INLINE mat(vec<2, T> m0, vec<2, T> m1) : m{m0, m1} {}

		template<typename U>
		LYAH_NODISCARD LYAH_INLINE explicit mat(mat<2, 2, U> a) : m{vec<2, T>(a.m[0]), vec<2, T>(a.m[1])} {}

		LYAH_NODISCARD LYAH_CONSTEXPR LYAH_INLINE const vec<2, T>& LYAH_CALL operator [](std::size_t index) const LYAH_NOEXCEPT {
			LYAH_ASSERT(index < 2);

			return m[index];
		}

		LYAH_NODISCARD LYAH_CONSTEXPR LYAH_INLINE vec<2, T>& LYAH_CALL operator [](std::size_t index) LYAH_NOEXCEPT {
			LYAH_ASSERT(index < 2);

			return m[index];
		}
	};
}