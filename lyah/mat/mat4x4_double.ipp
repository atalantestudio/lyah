// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

namespace lyah {
	LYAH_CONSTEXPR mat<4, 4, std::double_t> mat<4, 4, std::double_t>::identity() {
		return {
			1.0, 0.0, 0.0, 0.0,
			0.0, 1.0, 0.0, 0.0,
			0.0, 0.0, 1.0, 0.0,
			0.0, 0.0, 0.0, 1.0,
		};
	}

	LYAH_CONSTEXPR mat<4, 4, std::double_t> mat<4, 4, std::double_t>::translation(vec<3, std::double_t> a) {
		return {
			1.0, 0.0, 0.0, 0.0,
			0.0, 1.0, 0.0, 0.0,
			0.0, 0.0, 1.0, 0.0,
			a.x, a.y, a.z, 1.0,
		};
	}

	/// `axis` is assumed to be normalized.
	/// `angle` is in radians.
	LYAH_CONSTEXPR_CPP26 mat<4, 4, std::double_t> mat<4, 4, std::double_t>::rotation(vec<3, std::double_t> axis, std::double_t angle) {
		const std::double_t cosAngle = cos(angle);
		const std::double_t sinAngle = sin(angle);
		const std::double_t one_cosAngle = 1.0 - cosAngle;

		return {
			axis.x * axis.x * one_cosAngle + cosAngle,          axis.x * axis.y * one_cosAngle + axis.z * sinAngle, axis.x * axis.z * one_cosAngle - axis.y * sinAngle, 0.0,
			axis.x * axis.y * one_cosAngle - axis.z * sinAngle, axis.y * axis.y * one_cosAngle + cosAngle,          axis.y * axis.z * one_cosAngle + axis.x * sinAngle, 0.0,
			axis.x * axis.z * one_cosAngle + axis.y * sinAngle, axis.y * axis.z * one_cosAngle - axis.x * sinAngle, axis.z * axis.z * one_cosAngle + cosAngle,          0.0,
			0.0,                                                0.0,                                                0.0,                                                1.0,
		};
	}

	LYAH_CONSTEXPR mat<4, 4, std::double_t> mat<4, 4, std::double_t>::scaling(vec<3, std::double_t> a) {
		return {
			a.x, 0.0, 0.0, 0.0,
			0.0, a.y, 0.0, 0.0,
			0.0, 0.0, a.z, 0.0,
			0.0, 0.0, 0.0, 1.0,
		};
	}

	/// Returns a left-handed matrix.
	LYAH_CONSTEXPR mat<4, 4, std::double_t> mat<4, 4, std::double_t>::orthographic(std::double_t left, std::double_t right, std::double_t bottom, std::double_t top, std::double_t near, std::double_t far) {
		return {
			 2.0 / (right - left),  0.0,                   0.0,                -(right + left) / (right - left),
			 0.0,                   2.0 / (top - bottom),  0.0,                -(top + bottom) / (top - bottom),
			 0.0,                   0.0,                   2.0 / (far - near), -(far + near) / (far - near),
			 0.0,                   0.0,                   0.0,                 1.0,
		};
	}

	/// Returns a left-handed matrix.
	LYAH_CONSTEXPR mat<4, 4, std::double_t> mat<4, 4, std::double_t>::lookAt(vec<3, std::double_t> eye, vec<3, std::double_t> target, vec<3, std::double_t> up) {
		const vec<3, std::double_t> f = normalized(target - eye);
		const vec<3, std::double_t> r = normalized(cross(up, f));
		const vec<3, std::double_t> u = cross(f, r);

		return {
			 r.x,          u.x,          f.x,          0.0,
			 r.y,          u.y,          f.y,          0.0,
			 r.z,          u.z,          f.z,          0.0,
			-dot(r, eye), -dot(u, eye), -dot(f, eye),  1.0,
		};
	}

	LYAH_CONSTEXPR mat<4, 4, std::double_t>::mat() :
		m{}
	{}

	LYAH_CONSTEXPR mat<4, 4, std::double_t>::mat(std::double_t m00, std::double_t m01, std::double_t m02, std::double_t m03, std::double_t m10, std::double_t m11, std::double_t m12, std::double_t m13, std::double_t m20, std::double_t m21, std::double_t m22, std::double_t m23, std::double_t m30, std::double_t m31, std::double_t m32, std::double_t m33) :
		m{
			{m00, m01, m02, m03},
			{m10, m11, m12, m13},
			{m20, m21, m22, m23},
			{m30, m31, m32, m33},
		}
	{}

	LYAH_CONSTEXPR mat<4, 4, std::double_t>::mat(vec<4, std::double_t> m0, vec<4, std::double_t> m1, vec<4, std::double_t> m2, vec<4, std::double_t> m3) :
		m{
			m0,
			m1,
			m2,
			m3,
		}
	{}

	template<typename U>
	LYAH_CONSTEXPR mat<4, 4, std::double_t>::mat(mat<4, 4, U> a) :
		m{
			vec<4, std::double_t>(a[0]),
			vec<4, std::double_t>(a[1]),
			vec<4, std::double_t>(a[2]),
			vec<4, std::double_t>(a[3]),
		}
	{}

	/// `a` is assumed to be normalized.
	/// See https://www.euclideanspace.com/maths/geometry/rotations/conversions/quaternionToMatrix.
	LYAH_CONSTEXPR mat<4, 4, std::double_t>::mat(quat<std::double_t> a) {
		a = a * 1.41421356237;

		const std::double_t xx = a.x * a.x;
		//const std::double_t xy = a.x * a.y;
		//const std::double_t xz = a.x * a.z;
		const std::double_t xw = a.x * a.w;
		const std::double_t yy = a.y * a.y;
		//const std::double_t yz = a.y * a.z;
		const std::double_t yw = a.y * a.w;
		const std::double_t zz = a.z * a.z;
		const std::double_t zw = a.z * a.w;

		/*m[0] = {_1 - yy - zz, xy - zw,      xz + yw,      0.0};
		m[1] = {xy + zw,      _1 - xx - zz, yz - xw,      0.0};
		m[2] = {xz - yw,      yz + xw,      _1 - xx - yy, 0.0};
		m[3] = {0.0,           0.0,           0.0,           1.0};*/

		const vec<3, std::double_t> xyz = {a.x, a.y, a.z};

		const vec<3, std::double_t> r0 = fma(xyz, vec<3, std::double_t>(a.x), { 0.0,  -zw,    yw });
		const vec<3, std::double_t> r1 = fma(xyz, vec<3, std::double_t>(a.y), { zw,    0.0,  -xw });
		const vec<3, std::double_t> r2 = fma(xyz, vec<3, std::double_t>(a.z), {-yw,    xw,    0.0});

		m[0] = {1.0 - yy - zz, r0.y,          r0.z,          0.0};
		m[1] = {r1.x,          1.0 - xx - zz, r1.z,          0.0};
		m[2] = {r2.x,          r2.y,          1.0 - xx - yy, 0.0};
		m[3] = {0.0,           0.0,           0.0,           1.0};
	}

	LYAH_CONSTEXPR const vec<4, std::double_t>& mat<4, 4, std::double_t>::operator[](std::size_t index) const {
		LYAH_ASSERT(index < 4);

		return m[index];
	}

	vec<4, std::double_t>& mat<4, 4, std::double_t>::operator[](std::size_t index) {
		LYAH_ASSERT(index < 4);

		return m[index];
	}
}