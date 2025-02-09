// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

#pragma once

#include "mat/mat.hpp"

namespace lyah {
	template<typename T>
	struct mat<3, 3, T> {
		LYAH_NODISCARD LYAH_INLINE static mat<3, 3, T> LYAH_CALL identity() {
			return {
				static_cast<T>(1), static_cast<T>(0), static_cast<T>(0),
				static_cast<T>(0), static_cast<T>(1), static_cast<T>(0),
				static_cast<T>(0), static_cast<T>(0), static_cast<T>(1),
			};
		}

		LYAH_NODISCARD LYAH_INLINE static mat<3, 3, T> LYAH_CALL translation(vec<2, T> a) {
			return {
				static_cast<T>(1), static_cast<T>(0), static_cast<T>(0),
				static_cast<T>(0), static_cast<T>(1), static_cast<T>(0),
				a[0],              a[1],              static_cast<T>(1),
			};
		}

		LYAH_NODISCARD LYAH_INLINE static mat<3, 3, T> LYAH_CALL rotation(T a) {
			const T c = cos(a);
			const T s = sin(a);

			return {
				c,                -s,                 static_cast<T>(0),
				s,                 c,                 static_cast<T>(0),
				static_cast<T>(0), static_cast<T>(0), static_cast<T>(1),
			};
		}

		LYAH_NODISCARD LYAH_INLINE static mat<3, 3, T> LYAH_CALL scaling(vec<2, T> a) {
			return {
				a[0],              static_cast<T>(0), static_cast<T>(0),
				static_cast<T>(0), a[1],              static_cast<T>(0),
				static_cast<T>(0), static_cast<T>(0), static_cast<T>(1),
			};
		}

		vec<3, T> m[3];

		LYAH_NODISCARD LYAH_INLINE mat() : m{} {}

		LYAH_NODISCARD LYAH_INLINE mat(
			T m00, T m01, T m02,
			T m10, T m11, T m12,
			T m20, T m21, T m22
		) : m{
			{m00, m01, m02},
			{m10, m11, m12},
			{m20, m21, m22},
		} {}

		LYAH_NODISCARD LYAH_INLINE mat(
			vec<3, T> m0,
			vec<3, T> m1,
			vec<3, T> m2
		) : m{
			m0,
			m1,
			m2,
		} {}

		template<typename U>
		LYAH_NODISCARD LYAH_INLINE explicit mat(mat<3, 3, U> a) : m{
			vec<3, T>(a.m[0]),
			vec<3, T>(a.m[1]),
			vec<3, T>(a.m[2]),
		} {}

		LYAH_NODISCARD LYAH_CONSTEXPR LYAH_INLINE const vec<3, T>& LYAH_CALL operator [](std::size_t index) const LYAH_NOEXCEPT {
			LYAH_ASSERT(index < 3);

			return m[index];
		}

		LYAH_NODISCARD LYAH_CONSTEXPR LYAH_INLINE vec<3, T>& LYAH_CALL operator [](std::size_t index) LYAH_NOEXCEPT {
			LYAH_ASSERT(index < 3);

			return m[index];
		}
	};
}