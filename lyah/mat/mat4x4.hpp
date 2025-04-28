// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

#pragma once

#include "mat/mat.hpp"

namespace lyah {
	template<typename T>
	struct mat<4, 4, T> {
		LYAH_NODISCARD LYAH_INLINE static mat<4, 4, T> LYAH_CALL identity() {
			return {
				static_cast<T>(1), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0),
				static_cast<T>(0), static_cast<T>(1), static_cast<T>(0), static_cast<T>(0),
				static_cast<T>(0), static_cast<T>(0), static_cast<T>(1), static_cast<T>(0),
				static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(1),
			};
		}

		LYAH_NODISCARD LYAH_INLINE static mat<4, 4, T> LYAH_CALL translation(vec<3, T> a) {
			return {
				static_cast<T>(1), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0),
				static_cast<T>(0), static_cast<T>(1), static_cast<T>(0), static_cast<T>(0),
				static_cast<T>(0), static_cast<T>(0), static_cast<T>(1), static_cast<T>(0),
				a[0],              a[1],              a[2],              static_cast<T>(1),
			};
		}

		// axis is assumed to be normalized.
		// angle is in radians.
		LYAH_NODISCARD LYAH_INLINE static mat<4, 4, T> LYAH_CALL rotation(vec<3, T> axis, T angle) {
			const T cosAngle = cos(angle);
			const T sinAngle = sin(angle);
			const T one_cosAngle = static_cast<T>(1) - cosAngle;

			return {
				axis[0] * axis[0] * one_cosAngle + cosAngle,           axis[0] * axis[1] * one_cosAngle + axis[2] * sinAngle, axis[0] * axis[2] * one_cosAngle - axis[1] * sinAngle, static_cast<T>(0),
				axis[0] * axis[1] * one_cosAngle - axis[2] * sinAngle, axis[1] * axis[1] * one_cosAngle + cosAngle,           axis[1] * axis[2] * one_cosAngle + axis[0] * sinAngle, static_cast<T>(0),
				axis[0] * axis[2] * one_cosAngle + axis[1] * sinAngle, axis[1] * axis[2] * one_cosAngle - axis[0] * sinAngle, axis[2] * axis[2] * one_cosAngle + cosAngle,           static_cast<T>(0),
				static_cast<T>(0),                                     static_cast<T>(0),                                     static_cast<T>(0),                                     static_cast<T>(1),
			};
		}

		LYAH_NODISCARD LYAH_INLINE static mat<4, 4, T> LYAH_CALL scaling(vec<3, T> a) {
			return {
				a[0],              static_cast<T>(0), static_cast<T>(0), static_cast<T>(0),
				static_cast<T>(0), a[1],              static_cast<T>(0), static_cast<T>(0),
				static_cast<T>(0), static_cast<T>(0), a[2],              static_cast<T>(0),
				static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(1),
			};
		}

		// Returns a left-handed matrix.
		LYAH_NODISCARD LYAH_INLINE static mat<4, 4, T> LYAH_CALL orthographic(T left, T right, T bottom, T top, T near, T far) {
			const vec<4, T> m0 = vec<4, T>(static_cast<T>(2), static_cast<T>(0), static_cast<T>(0), -(left + right)) / (right - left);
			const vec<4, T> m1 = vec<4, T>(static_cast<T>(0), static_cast<T>(2), static_cast<T>(0), -(bottom + top)) / (top - bottom);
			const vec<4, T> m2 = vec<4, T>(static_cast<T>(0), static_cast<T>(0), static_cast<T>(2), -(near + far)) / (far - near);
			const vec<4, T> m3 = {static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(1)};

			return {m0, m1, m2, m3};
		}

		// Returns a left-handed matrix.
		LYAH_NODISCARD LYAH_INLINE static mat<4, 4, T> LYAH_CALL lookAt(vec<3, T> eye, vec<3, T> center, vec<3, T> up) {
			const vec<3, T> f = normalized(center - eye);
			const vec<3, T> r = normalized(cross(up, f));
			const vec<3, T> u = cross(f, r);

			return {
				 r[0],         u[0],         f[0],         static_cast<T>(0),
				 r[1],         u[1],         f[1],         static_cast<T>(0),
				 r[2],         u[2],         f[2],         static_cast<T>(0),
				-dot(r, eye), -dot(u, eye), -dot(f, eye),  static_cast<T>(1),
			};
		}

		vec<4, T> m[4];

		LYAH_NODISCARD LYAH_INLINE mat() : m{} {}

		LYAH_NODISCARD LYAH_INLINE mat(
			T m00, T m01, T m02, T m03,
			T m10, T m11, T m12, T m13,
			T m20, T m21, T m22, T m23,
			T m30, T m31, T m32, T m33
		) : m{
			{m00, m01, m02, m03},
			{m10, m11, m12, m13},
			{m20, m21, m22, m23},
			{m30, m31, m32, m33},
		} {}

		LYAH_NODISCARD LYAH_INLINE mat(vec<4, T> m0, vec<4, T> m1, vec<4, T> m2, vec<4, T> m3) : m{m0, m1, m2, m3} {}

		// Returns a rotation matrix computed from a.
		// a is assumed to be normalized.
		LYAH_NODISCARD explicit mat(quat<T> a);

		template<typename U>
		LYAH_NODISCARD LYAH_INLINE explicit mat(mat<4, 4, U> a) : m{vec<4, T>(a.m[0]), vec<4, T>(a.m[1]), vec<4, T>(a.m[2]), vec<4, T>(a.m[3])} {}

		LYAH_NODISCARD LYAH_CONSTEXPR LYAH_INLINE const vec<4, T>& LYAH_CALL operator [](std::size_t index) const LYAH_NOEXCEPT {
			LYAH_ASSERT(index < 4);

			return m[index];
		}

		LYAH_NODISCARD LYAH_CONSTEXPR LYAH_INLINE vec<4, T>& LYAH_CALL operator [](std::size_t index) LYAH_NOEXCEPT {
			LYAH_ASSERT(index < 4);

			return m[index];
		}
	};
}