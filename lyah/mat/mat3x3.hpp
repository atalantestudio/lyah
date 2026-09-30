// Copyright 2025 Atalante Studio.
// Distributed under the MIT License.

#pragma once

#include "lyah/mat/mat.hpp"

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

		// NOTE: Rotates around the Z axis.
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

		LYAH_NODISCARD LYAH_INLINE mat() :
			m{}
		{}

		LYAH_NODISCARD LYAH_INLINE mat(T m00, T m01, T m02, T m10, T m11, T m12, T m20, T m21, T m22) :
			m{{m00, m01, m02}, {m10, m11, m12}, {m20, m21, m22}}
		{}

		LYAH_NODISCARD LYAH_INLINE mat(vec<3, T> m0, vec<3, T> m1, vec<3, T> m2) :
			m{m0, m1, m2}
		{}

		/// Constructs a 3x3 matrix from a quaternion.
		LYAH_NODISCARD mat(quat<T> a);

		template<typename U>
		LYAH_NODISCARD LYAH_INLINE explicit mat(mat<3, 3, U> a) :
			m{vec<3, T>(a.m[0]), vec<3, T>(a.m[1]), vec<3, T>(a.m[2])}
		{}

		LYAH_NODISCARD LYAH_CONSTEXPR LYAH_INLINE const vec<3, T>& LYAH_CALL operator[](std::size_t index) const LYAH_NOEXCEPT {
			LYAH_ASSERT(index < 3);

			return m[index];
		}

		LYAH_NODISCARD LYAH_CONSTEXPR LYAH_INLINE vec<3, T>& LYAH_CALL operator[](std::size_t index) LYAH_NOEXCEPT {
			LYAH_ASSERT(index < 3);

			return m[index];
		}

		vec<3, T> m[3];
	};

	/// See https://www.euclideanspace.com/maths/geometry/rotations/conversions/quaternionToMatrix.
	template<typename T>
	LYAH_NODISCARD LYAH_INLINE mat<3, 3, T>::mat(quat<T> a) {
		static constexpr T _1 = static_cast<T>(1);

		a *= static_cast<T>(1.41421356237);

		const T xx = a.x * a.x;
		const T xy = a.x * a.y;
		const T xz = a.x * a.z;
		const T xw = a.x * a.w;
		const T yy = a.y * a.y;
		const T yz = a.y * a.z;
		const T yw = a.y * a.w;
		const T zz = a.z * a.z;
		const T zw = a.z * a.w;

		m[0] = {_1 - yy - zz, xy - zw,      xz + yw     };
		m[1] = {xy + zw,      _1 - xx - zz, yz - xw     };
		m[2] = {xz - yw,      yz + xw,      _1 - xx - yy};
	}

	template<std::size_t M, typename T>
	LYAH_NODISCARD LYAH_INLINE bool LYAH_CALL operator==(mat<M, 3, T> a, mat<M, 3, T> b) {
		return a[0] == b[0] && a[1] == b[1] && a[2] == b[2];
	}

	template<std::size_t M, typename T>
	LYAH_NODISCARD LYAH_INLINE bool LYAH_CALL operator!=(mat<M, 3, T> a, mat<M, 3, T> b) {
		return a[0] != b[0] || a[1] != b[1] || a[2] != b[2];
	}

	template<std::size_t M, typename T>
	LYAH_NODISCARD LYAH_INLINE mat<M, 3, T> LYAH_CALL operator-(mat<M, 3, T> a) {
		a[0] = -a[0];
		a[1] = -a[1];
		a[2] = -a[2];

		return a;
	}

	template<std::size_t M, typename T>
	LYAH_INLINE mat<M, 3, T>& LYAH_CALL operator+=(mat<M, 3, T>& a, mat<M, 3, T> b) {
		a[0] += b[0];
		a[1] += b[1];
		a[2] += b[2];

		return a;
	}

	template<std::size_t M, typename T>
	LYAH_INLINE mat<M, 3, T>& LYAH_CALL operator-=(mat<M, 3, T>& a, mat<M, 3, T> b) {
		a[0] -= b[0];
		a[1] -= b[1];
		a[2] -= b[2];

		return a;
	}

	template<std::size_t M, typename T>
	LYAH_INLINE mat<M, 3, T>& LYAH_CALL operator*=(mat<M, 3, T>& a, T b) {
		a[0] *= b;
		a[1] *= b;
		a[2] *= b;

		return a;
	}

	template<typename T>
	LYAH_INLINE mat<3, 3, T>& LYAH_CALL operator*=(mat<3, 3, T>& A, mat<3, 3, T> B) {
		/*const vec<3, T> a0 = A[0];
		const vec<3, T> a1 = A[1];
		const vec<3, T> a2 = A[2];
		const vec<3, T> b0 = B[0];
		const vec<3, T> b1 = B[1];
		const vec<3, T> b2 = B[2];

		A[0] = fma(b2, vec<3, T>(a0.z), fma(b1, vec<3, T>(a0.y), b0 * a0.x));
		A[1] = fma(b2, vec<3, T>(a1.z), fma(b1, vec<3, T>(a1.y), b0 * a1.x));
		A[2] = fma(b2, vec<3, T>(a2.z), fma(b1, vec<3, T>(a2.y), b0 * a2.x));*/

		const T a00 = A[0][0];
		const T a01 = A[0][1];
		const T a02 = A[0][2];
		const T a10 = A[1][0];
		const T a11 = A[1][1];
		const T a12 = A[1][2];
		const T a20 = A[2][0];
		const T a21 = A[2][1];
		const T a22 = A[2][2];

		const T b00 = B[0][0];
		const T b01 = B[0][1];
		const T b02 = B[0][2];
		const T b10 = B[1][0];
		const T b11 = B[1][1];
		const T b12 = B[1][2];
		const T b20 = B[2][0];
		const T b21 = B[2][1];
		const T b22 = B[2][2];

		const T b00_b01_b02 = b00 - b01 - b02;
		const T b11_b10_b12 = b11 - b10 - b12;
		const T b22_b20_b21 = b22 - b20 - b21;
		const T p1 = (a01 + b01) * (a00 + b10);
		const T p2 = (a02 + b02) * (a00 + b20);
		const T p3 = (a02 + b12) * (a01 + b21);
		const T p7 = (a11 + b01) * (a10 + b10);
		const T p8 = (a12 + b02) * (a10 + b20);
		const T p9 = (a12 + b12) * (a11 + b21);
		const T p13 = (a21 + b01) * (a20 + b10);
		const T p14 = (a22 + b02) * (a20 + b20);
		const T p15 = (a22 + b12) * (a21 + b21);
		const T p19 = b01 * b10;
		const T p20 = b02 * b20;
		const T p21 = b12 * b21;

		A[0] = fma(A[0], {b00_b01_b02 - a01 - a02, b11_b10_b12 - a00 - a02, b22_b20_b21 - a00 - a01}, {p1 + p2 - p19 - p20, p1 + p3 - p19 - p21, p2 + p3 - p20 - p21});
		A[1] = fma(A[1], {b00_b01_b02 - a11 - a12, b11_b10_b12 - a10 - a12, b22_b20_b21 - a10 - a11}, {p7 + p8 - p19 - p20, p7 + p9 - p19 - p21, p8 + p9 - p20 - p21});
		A[2] = fma(A[2], {b00_b01_b02 - a21 - a22, b11_b10_b12 - a20 - a22, b22_b20_b21 - a20 - a21}, {p13 + p14 - p19 - p20, p13 + p15 - p19 - p21, p14 + p15 - p20 - p21});

		return A;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE T LYAH_CALL determinant(mat<3, 3, T> a) {
		return dot(a[0], cross(a[1], a[2]));
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE mat<3, 3, T> LYAH_CALL inverse(mat<3, 3, T> A) {
		static constexpr T e = static_cast<T>(1e-4);

		const T d = determinant(A);

		LYAH_ASSERT(abs(d) >= e);

		A = {
			  A[1][1] * A[2][2] - A[2][1] * A[1][2],
			-(A[0][1] * A[2][2] - A[2][1] * A[0][2]),
			  A[0][1] * A[1][2] - A[1][1] * A[0][2],
			-(A[1][0] * A[2][2] - A[2][0] * A[1][2]),
			  A[0][0] * A[2][2] - A[2][0] * A[0][2],
			-(A[0][0] * A[1][2] - A[1][0] * A[0][2]),
			  A[1][0] * A[2][1] - A[2][0] * A[1][1],
			-(A[0][0] * A[2][1] - A[2][0] * A[0][1]),
			  A[0][0] * A[1][1] - A[1][0] * A[0][1],
		};

		return A / d;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE mat<3, 3, T> LYAH_CALL transpose(mat<3, 3, T> A) {
		std::swap(A[0][1], A[1][0]);
		std::swap(A[0][2], A[2][0]);
		std::swap(A[1][2], A[2][1]);

		return A;
	}
}