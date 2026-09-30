// Copyright 2025 Atalante Studio.
// Distributed under the MIT License.

#pragma once

#include "lyah/mat/mat.hpp"

namespace lyah {
	template<typename T>
	struct mat<4, 4, T> {
		public:
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

		public:
			LYAH_NODISCARD LYAH_INLINE mat() :
				m{}
			{}

			LYAH_NODISCARD LYAH_INLINE mat(T m00, T m01, T m02, T m03, T m10, T m11, T m12, T m13, T m20, T m21, T m22, T m23, T m30, T m31, T m32, T m33) :
				m{{m00, m01, m02, m03}, {m10, m11, m12, m13}, {m20, m21, m22, m23}, {m30, m31, m32, m33}}
			{}

			LYAH_NODISCARD LYAH_INLINE mat(vec<4, T> m0, vec<4, T> m1, vec<4, T> m2, vec<4, T> m3) :
				m{m0, m1, m2, m3}
			{}

			template<typename U>
			LYAH_NODISCARD LYAH_INLINE explicit mat(mat<4, 4, U> a) :
				m{vec<4, T>(a.m[0]), vec<4, T>(a.m[1]), vec<4, T>(a.m[2]), vec<4, T>(a.m[3])}
			{}

			// Returns a rotation matrix computed from a.
			// a is assumed to be normalized.
			LYAH_NODISCARD explicit mat(quat<T> a);

			LYAH_NODISCARD LYAH_CONSTEXPR LYAH_INLINE const vec<4, T>& LYAH_CALL operator[](std::size_t index) const LYAH_NOEXCEPT {
				LYAH_ASSERT(index < 4);

				return m[index];
			}

			LYAH_NODISCARD LYAH_CONSTEXPR LYAH_INLINE vec<4, T>& LYAH_CALL operator[](std::size_t index) LYAH_NOEXCEPT {
				LYAH_ASSERT(index < 4);

				return m[index];
			}

		public:
			vec<4, T> m[4];
	};

	/// See https://www.euclideanspace.com/maths/geometry/rotations/conversions/quaternionToMatrix.
	template<typename T>
	LYAH_NODISCARD LYAH_INLINE mat<4, 4, T>::mat(quat<T> a) {
		static constexpr T _0 = static_cast<T>(0);
		static constexpr T _1 = static_cast<T>(1);

		a *= static_cast<T>(1.41421356237);

		const T xx = a.x * a.x;
		//const T xy = a.x * a.y;
		//const T xz = a.x * a.z;
		const T xw = a.x * a.w;
		const T yy = a.y * a.y;
		//const T yz = a.y * a.z;
		const T yw = a.y * a.w;
		const T zz = a.z * a.z;
		const T zw = a.z * a.w;

		/*m[0] = {_1 - yy - zz, xy - zw,      xz + yw,      _0};
		m[1] = {xy + zw,      _1 - xx - zz, yz - xw,      _0};
		m[2] = {xz - yw,      yz + xw,      _1 - xx - yy, _0};
		m[3] = {_0,           _0,           _0,           _1};*/

		vec<3, T> xyz = {a.x, a.y, a.z};

		const vec<3, T> r0 = fma(xyz, vec<3, T>(a.x), { 0,  -zw,  yw});
		const vec<3, T> r1 = fma(xyz, vec<3, T>(a.y), { zw,  0,  -xw});
		const vec<3, T> r2 = fma(xyz, vec<3, T>(a.z), {-yw,  xw,  0 });

		m[0] = {1 - yy - zz, r0.y,        r0.z,        0};
		m[1] = {r1.x,        1 - xx - zz, r1.z,        0};
		m[2] = {r2.x,        r2.y,        1 - xx - yy, 0};
		m[3] = {0,           0,           0,           1};
	}

	template<typename T>
	LYAH_INLINE mat<4, 4, T>& LYAH_CALL operator*=(mat<4, 4, T>& A, mat<4, 4, T> B) {
		const vec<4, T> a0 = A[0];
		const vec<4, T> a1 = A[1];
		const vec<4, T> a2 = A[2];
		const vec<4, T> a3 = A[3];
		const vec<4, T> b0 = B[0];
		const vec<4, T> b1 = B[1];
		const vec<4, T> b2 = B[2];
		const vec<4, T> b3 = B[3];

		A[0] = fma(b3, vec<4, T>(a0.w), fma(b2, vec<4, T>(a0.z), fma(b1, vec<4, T>(a0.y), b0 * a0.x)));
		A[1] = fma(b3, vec<4, T>(a1.w), fma(b2, vec<4, T>(a1.z), fma(b1, vec<4, T>(a1.y), b0 * a1.x)));
		A[2] = fma(b3, vec<4, T>(a2.w), fma(b2, vec<4, T>(a2.z), fma(b1, vec<4, T>(a2.y), b0 * a2.x)));
		A[3] = fma(b3, vec<4, T>(a3.w), fma(b2, vec<4, T>(a3.z), fma(b1, vec<4, T>(a3.y), b0 * a3.x)));

		return A;
	}

	// https://stackoverflow.com/a/30006505/17136841
	template<typename T>
	LYAH_NODISCARD LYAH_INLINE T LYAH_CALL determinant(mat<4, 4, T> a) {
		const mat<2, 2, T> aa = {
			a[0][0], a[0][1],
			a[1][0], a[1][1],
		};
		const mat<2, 2, T> ab = {
			a[0][2], a[0][3],
			a[1][2], a[1][3],
		};
		const mat<2, 2, T> ac = {
			a[2][0], a[2][1],
			a[3][0], a[3][1],
		};
		const mat<2, 2, T> ad = {
			a[2][2], a[2][3],
			a[3][2], a[3][3],
		};

		return determinant(aa - ab * inverse(ad) * ac) * determinant(ad);
	}

	// https://en.wikipedia.org/wiki/Invertible_matrix#Inversion_of_4_%C3%97_4_matrices
	template<typename T>
	LYAH_NODISCARD LYAH_INLINE mat<4, 4, T> LYAH_CALL inverse(mat<4, 4, T> M) {
		const T d = determinant(M);

		LYAH_ASSERT(abs(d) >= epsilon<T>());

		const mat<2, 2, T> A = {
			M[0][0], M[0][1],
			M[1][0], M[1][1],
		};
		const mat<2, 2, T> B = {
			M[0][2], M[0][3],
			M[1][2], M[1][3],
		};
		const mat<2, 2, T> C = {
			M[2][0], M[2][1],
			M[3][0], M[3][1],
		};
		const mat<2, 2, T> D = {
			M[2][2], M[2][3],
			M[3][2], M[3][3],
		};

		const mat<2, 2, T> a0 = inverse(A - B * inverse(D) * C);
		const mat<2, 2, T> a1 = inverse(D - C * inverse(A) * B);
		const mat<4, 4, T> a = {
			a0[0][0], a0[0][1], 0, 0,
			a0[1][0], a0[1][1], 0, 0,
			0, 0, a1[0][0], a1[0][1],
			0, 0, a1[1][0], a1[1][1],
		};

		const mat<2, 2, T> b0 = -B * inverse(D);
		const mat<2, 2, T> b1 = -C * inverse(A);
		const mat<4, 4, T> b = {
			1, 0, b0[0][0], b0[0][1],
			0, 1, b0[1][0], b0[1][1],
			b1[0][0], b1[0][1], 1, 0,
			b1[1][0], b1[1][1], 0, 1,
		};

		return a * b;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE mat<4, 4, T> LYAH_CALL transpose(mat<4, 4, T> A) {
		std::swap(A[0][1], A[1][0]);
		std::swap(A[0][2], A[2][0]);
		std::swap(A[0][3], A[3][0]);
		std::swap(A[1][2], A[2][1]);
		std::swap(A[1][3], A[3][1]);
		std::swap(A[2][3], A[3][2]);

		return A;
	}
}