// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

namespace lyah {
	LYAH_CONSTEXPR mat<4, 4, std::float_t> mat<4, 4, std::float_t>::identity() {
		return {
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f,
		};
	}

	LYAH_CONSTEXPR mat<4, 4, std::float_t> mat<4, 4, std::float_t>::translation(vec<3, std::float_t> a) {
		return {
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			a.x,  a.y,  a.z,  1.0f,
		};
	}

	/// `axis` is assumed to be normalized.
	/// `angle` is in radians.
	LYAH_CONSTEXPR_CPP26 mat<4, 4, std::float_t> mat<4, 4, std::float_t>::rotation(vec<3, std::float_t> axis, std::float_t angle) {
		const std::float_t cosAngle = cos(angle);
		const std::float_t sinAngle = sin(angle);
		const std::float_t one_cosAngle = 1.0f - cosAngle;

		return {
			axis.x * axis.x * one_cosAngle + cosAngle,          axis.x * axis.y * one_cosAngle + axis.z * sinAngle, axis.x * axis.z * one_cosAngle - axis.y * sinAngle, 0.0f,
			axis.x * axis.y * one_cosAngle - axis.z * sinAngle, axis.y * axis.y * one_cosAngle + cosAngle,          axis.y * axis.z * one_cosAngle + axis.x * sinAngle, 0.0f,
			axis.x * axis.z * one_cosAngle + axis.y * sinAngle, axis.y * axis.z * one_cosAngle - axis.x * sinAngle, axis.z * axis.z * one_cosAngle + cosAngle,          0.0f,
			0.0f,                                               0.0f,                                               0.0f,                                               1.0f,
		};
	}

	LYAH_CONSTEXPR mat<4, 4, std::float_t> mat<4, 4, std::float_t>::scaling(vec<3, std::float_t> a) {
		return {
			a.x,  0.0f, 0.0f, 0.0f,
			0.0f, a.y,  0.0f, 0.0f,
			0.0f, 0.0f, a.z,  0.0f,
			0.0f, 0.0f, 0.0f, 1.0f,
		};
	}

	/// Returns a left-handed matrix.
	LYAH_CONSTEXPR mat<4, 4, std::float_t> mat<4, 4, std::float_t>::orthographic(std::float_t left, std::float_t right, std::float_t bottom, std::float_t top, std::float_t near, std::float_t far) {
		return {
			 2.0f / (right - left),  0.0f,                   0.0f,                -(right + left) / (right - left),
			 0.0f,                   2.0f / (top - bottom),  0.0f,                -(top + bottom) / (top - bottom),
			 0.0f,                   0.0f,                   2.0f / (far - near), -(far + near) / (far - near),
			 0.0f,                   0.0f,                   0.0f,                 1.0f,
		};
	}

	/// Returns a left-handed matrix.
	LYAH_CONSTEXPR_CPP26 mat<4, 4, std::float_t> mat<4, 4, std::float_t>::lookAt(vec<3, std::float_t> eye, vec<3, std::float_t> target, vec<3, std::float_t> up) {
		const vec<3, std::float_t> f = normalized(target - eye);
		const vec<3, std::float_t> r = normalized(cross(up, f));
		const vec<3, std::float_t> u = cross(f, r);

		return {
			 r.x,          u.x,          f.x,          0.0f,
			 r.y,          u.y,          f.y,          0.0f,
			 r.z,          u.z,          f.z,          0.0f,
			-dot(r, eye), -dot(u, eye), -dot(f, eye),  1.0f,
		};
	}

	LYAH_CONSTEXPR mat<4, 4, std::float_t>::mat() :
		m{}
	{}

	LYAH_CONSTEXPR mat<4, 4, std::float_t>::mat(std::float_t m00, std::float_t m01, std::float_t m02, std::float_t m03, std::float_t m10, std::float_t m11, std::float_t m12, std::float_t m13, std::float_t m20, std::float_t m21, std::float_t m22, std::float_t m23, std::float_t m30, std::float_t m31, std::float_t m32, std::float_t m33) :
		m{
			{m00, m01, m02, m03},
			{m10, m11, m12, m13},
			{m20, m21, m22, m23},
			{m30, m31, m32, m33},
		}
	{}

	LYAH_CONSTEXPR mat<4, 4, std::float_t>::mat(vec<4, std::float_t> m0, vec<4, std::float_t> m1, vec<4, std::float_t> m2, vec<4, std::float_t> m3) :
		m{
			m0,
			m1,
			m2,
			m3,
		}
	{}

	template<typename U>
	LYAH_CONSTEXPR mat<4, 4, std::float_t>::mat(mat<4, 4, U> a) :
		m{
			vec<4, std::float_t>(a[0]),
			vec<4, std::float_t>(a[1]),
			vec<4, std::float_t>(a[2]),
			vec<4, std::float_t>(a[3]),
		}
	{}

	/// `a` is assumed to be normalized.
	/// See https://www.euclideanspace.com/maths/geometry/rotations/conversions/quaternionToMatrix.
	LYAH_CONSTEXPR_CPP23 mat<4, 4, std::float_t>::mat(quat<std::float_t> a) {
		a = a * 1.41421356237f;

		const std::float_t xx = a.x * a.x;
		//const std::float_t xy = a.x * a.y;
		//const std::float_t xz = a.x * a.z;
		const std::float_t xw = a.x * a.w;
		const std::float_t yy = a.y * a.y;
		//const std::float_t yz = a.y * a.z;
		const std::float_t yw = a.y * a.w;
		const std::float_t zz = a.z * a.z;
		const std::float_t zw = a.z * a.w;

		/*m[0] = {_1 - yy - zz, xy - zw,      xz + yw,      0.0};
		m[1] = {xy + zw,      _1 - xx - zz, yz - xw,      0.0};
		m[2] = {xz - yw,      yz + xw,      _1 - xx - yy, 0.0};
		m[3] = {0.0,           0.0,           0.0,           1.0};*/

		const vec<3, std::float_t> xyz = {a.x, a.y, a.z};

		const vec<3, std::float_t> r0 = fma(xyz, vec<3, std::float_t>(a.x), { 0.0f,  -zw,     yw  });
		const vec<3, std::float_t> r1 = fma(xyz, vec<3, std::float_t>(a.y), { zw,     0.0f,  -xw  });
		const vec<3, std::float_t> r2 = fma(xyz, vec<3, std::float_t>(a.z), {-yw,     xw,     0.0f});

		m[0] = {1.0f - yy - zz, r0.y,           r0.z,           0.0f};
		m[1] = {r1.x,           1.0f - xx - zz, r1.z,           0.0f};
		m[2] = {r2.x,           r2.y,           1.0f - xx - yy, 0.0f};
		m[3] = {0.0f,           0.0f,           0.0f,           1.0f};
	}

	LYAH_CONSTEXPR const vec<4, std::float_t>& mat<4, 4, std::float_t>::operator[](std::size_t index) const {
		LYAH_ASSERT(index < 4);

		return m[index];
	}

	vec<4, std::float_t>& mat<4, 4, std::float_t>::operator[](std::size_t index) {
		LYAH_ASSERT(index < 4);

		return m[index];
	}
}