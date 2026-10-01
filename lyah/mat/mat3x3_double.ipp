// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

namespace lyah {
	LYAH_CONSTEXPR mat<3, 3, std::double_t> mat<3, 3, std::double_t>::identity() {
		return {
			1.0, 0.0, 0.0,
			0.0, 1.0, 0.0,
			0.0, 0.0, 1.0,
		};
	}

	LYAH_CONSTEXPR mat<3, 3, std::double_t> mat<3, 3, std::double_t>::translation(vec<2, std::double_t> a) {
		return {
			1.0, 0.0, 0.0,
			0.0, 1.0, 0.0,
			a.x, a.y, 1.0,
		};
	}

	LYAH_CONSTEXPR_CPP26 mat<3, 3, std::double_t> mat<3, 3, std::double_t>::rotation(std::double_t a) {
		const std::double_t c = cos(a);
		const std::double_t s = sin(a);

		return {
			 c,   -s,    0.0,
			 s,    c,    0.0,
			 0.0,  0.0,  1.0,
		};
	}

	LYAH_CONSTEXPR mat<3, 3, std::double_t> mat<3, 3, std::double_t>::scaling(vec<2, std::double_t> a) {
		return {
			a.x, 0.0, 0.0,
			0.0, a.y, 0.0,
			0.0, 0.0, 1.0,
		};
	}

	LYAH_CONSTEXPR mat<3, 3, std::double_t>::mat() :
		m{}
	{}

	LYAH_CONSTEXPR mat<3, 3, std::double_t>::mat(std::double_t m00, std::double_t m01, std::double_t m02, std::double_t m10, std::double_t m11, std::double_t m12, std::double_t m20, std::double_t m21, std::double_t m22) :
		m{
			{m00, m01, m02},
			{m10, m11, m12},
			{m20, m21, m22},
		}
	{}

	LYAH_CONSTEXPR mat<3, 3, std::double_t>::mat(vec<3, std::double_t> m0, vec<3, std::double_t> m1, vec<3, std::double_t> m2) :
		m{
			m0,
			m1,
			m2,
		}
	{}

	/// `a` is assumed to be normalized.
	/// See https://www.euclideanspace.com/maths/geometry/rotations/conversions/quaternionToMatrix.
	LYAH_CONSTEXPR mat<3, 3, std::double_t>::mat(quat<std::double_t> a) {
		a = a * 1.41421356237;

		const std::double_t xx = a.x * a.x;
		const std::double_t xy = a.x * a.y;
		const std::double_t xz = a.x * a.z;
		const std::double_t xw = a.x * a.w;
		const std::double_t yy = a.y * a.y;
		const std::double_t yz = a.y * a.z;
		const std::double_t yw = a.y * a.w;
		const std::double_t zz = a.z * a.z;
		const std::double_t zw = a.z * a.w;

		m[0] = {1.0 - yy - zz, xy - zw,       xz + yw      };
		m[1] = {xy + zw,       1.0 - xx - zz, yz - xw      };
		m[2] = {xz - yw,       yz + xw,       1.0 - xx - yy};
	}

	template<typename U>
	LYAH_CONSTEXPR mat<3, 3, std::double_t>::mat(mat<3, 3, U> a) :
		m{
			vec<3, std::double_t>(a[0]),
			vec<3, std::double_t>(a[1]),
			vec<3, std::double_t>(a[2]),
		}
	{}

	LYAH_CONSTEXPR const vec<3, std::double_t>& mat<3, 3, std::double_t>::operator[](std::size_t index) const {
		LYAH_ASSERT(index < 3);

		return m[index];
	}

	vec<3, std::double_t>& mat<3, 3, std::double_t>::operator[](std::size_t index) {
		LYAH_ASSERT(index < 3);

		return m[index];
	}
}