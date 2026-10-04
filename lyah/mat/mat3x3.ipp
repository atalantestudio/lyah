// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

template<typename T>
LYAH_CONSTEXPR lyah::mat<3, 3, T> lyah::mat<3, 3, T>::identity() {
	return {
		1, 0, 0,
		0, 1, 0,
		0, 0, 1,
	};
}

template<typename T>
LYAH_CONSTEXPR lyah::mat<3, 3, T> lyah::mat<3, 3, T>::translation(vec<2, T> a) {
	return {
		1,   0,   0,
		0,   1,   0,
		a.x, a.y, 1,
	};
}

template<typename T>
LYAH_CONSTEXPR_CPP26 lyah::mat<3, 3, T> lyah::mat<3, 3, T>::rotation(T a) {
	const T c = cos(a);
	const T s = sin(a);

	return {
		 c, -s,  0,
		 s,  c,  0,
		 0,  0,  1,
	};
}

template<typename T>
LYAH_CONSTEXPR lyah::mat<3, 3, T> lyah::mat<3, 3, T>::scaling(vec<2, T> a) {
	return {
		a.x, 0,   0,
		0,   a.y, 0,
		0,   0,   1,
	};
}

template<typename T>
LYAH_CONSTEXPR lyah::mat<3, 3, T>::mat() :
	m{}
{}

template<typename T>
LYAH_CONSTEXPR lyah::mat<3, 3, T>::mat(T m00, T m01, T m02, T m10, T m11, T m12, T m20, T m21, T m22) :
	m{
		{m00, m01, m02},
		{m10, m11, m12},
		{m20, m21, m22},
	}
{}

template<typename T>
LYAH_CONSTEXPR lyah::mat<3, 3, T>::mat(vec<3, T> m0, vec<3, T> m1, vec<3, T> m2) :
	m{
		m0,
		m1,
		m2,
	}
{}

/// `a` is assumed to be normalized.
/// See https://www.euclideanspace.com/maths/geometry/rotations/conversions/quaternionToMatrix.
template<typename T>
LYAH_CONSTEXPR lyah::mat<3, 3, T>::mat(quat<T> a) {
	a = a * static_cast<T>(1.41421356237);

	const T xx = a.x * a.x;
	const T xy = a.x * a.y;
	const T xz = a.x * a.z;
	const T xw = a.x * a.w;
	const T yy = a.y * a.y;
	const T yz = a.y * a.z;
	const T yw = a.y * a.w;
	const T zz = a.z * a.z;
	const T zw = a.z * a.w;

	m[0] = {1 - yy - zz, xy - zw,     xz + yw    };
	m[1] = {xy + zw,     1 - xx - zz, yz - xw    };
	m[2] = {xz - yw,     yz + xw,     1 - xx - yy};
}

template<typename T>
template<typename U>
LYAH_CONSTEXPR lyah::mat<3, 3, T>::mat(mat<3, 3, U> a) :
	m{
		vec<3, T>(a[0]),
		vec<3, T>(a[1]),
		vec<3, T>(a[2]),
	}
{}

template<typename T>
LYAH_CONSTEXPR const lyah::vec<3, T>& lyah::mat<3, 3, T>::operator[](std::size_t index) const {
	LYAH_ASSERT(index < 3);

	return m[index];
}

template<typename T>
lyah::vec<3, T>& lyah::mat<3, 3, T>::operator[](std::size_t index) {
	LYAH_ASSERT(index < 3);

	return m[index];
}

namespace lyah {
	template<typename T>
	LYAH_CONSTEXPR mat<3, 3, T> operator*(mat<3, 3, T> a, mat<3, 3, T> b) {
		// TODO: Benchmark.
		/*const vec<3, T> a0 = a[0];
		const vec<3, T> a1 = a[1];
		const vec<3, T> a2 = a[2];
		const vec<3, T> b0 = b[0];
		const vec<3, T> b1 = b[1];
		const vec<3, T> b2 = b[2];

		a[0] = fma(b2, vec<3, T>(a0.z), fma(b1, vec<3, T>(a0.y), b0 * a0.x));
		a[1] = fma(b2, vec<3, T>(a1.z), fma(b1, vec<3, T>(a1.y), b0 * a1.x));
		a[2] = fma(b2, vec<3, T>(a2.z), fma(b1, vec<3, T>(a2.y), b0 * a2.x));*/

		const T a00 = a[0][0];
		const T a01 = a[0][1];
		const T a02 = a[0][2];
		const T a10 = a[1][0];
		const T a11 = a[1][1];
		const T a12 = a[1][2];
		const T a20 = a[2][0];
		const T a21 = a[2][1];
		const T a22 = a[2][2];

		const T b00 = b[0][0];
		const T b01 = b[0][1];
		const T b02 = b[0][2];
		const T b10 = b[1][0];
		const T b11 = b[1][1];
		const T b12 = b[1][2];
		const T b20 = b[2][0];
		const T b21 = b[2][1];
		const T b22 = b[2][2];

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

		a[0] = fma(a[0], {b00_b01_b02 - a01 - a02, b11_b10_b12 - a00 - a02, b22_b20_b21 - a00 - a01}, {p1 + p2 - p19 - p20, p1 + p3 - p19 - p21, p2 + p3 - p20 - p21});
		a[1] = fma(a[1], {b00_b01_b02 - a11 - a12, b11_b10_b12 - a10 - a12, b22_b20_b21 - a10 - a11}, {p7 + p8 - p19 - p20, p7 + p9 - p19 - p21, p8 + p9 - p20 - p21});
		a[2] = fma(a[2], {b00_b01_b02 - a21 - a22, b11_b10_b12 - a20 - a22, b22_b20_b21 - a20 - a21}, {p13 + p14 - p19 - p20, p13 + p15 - p19 - p21, p14 + p15 - p20 - p21});

		return a;
	}

	template<typename T>
	LYAH_CONSTEXPR T determinant(mat<3, 3, T> a) {
		return dot(a[0], cross(a[1], a[2]));
	}

	template<typename T>
	LYAH_CONSTEXPR mat<3, 3, T> adjugate(mat<3, 3, T> a) {
		return {
			  a[1][1] * a[2][2] - a[2][1] * a[1][2],  -(a[0][1] * a[2][2] - a[2][1] * a[0][2]),   a[0][1] * a[1][2] - a[1][1] * a[0][2],
			-(a[1][0] * a[2][2] - a[2][0] * a[1][2]),   a[0][0] * a[2][2] - a[2][0] * a[0][2],  -(a[0][0] * a[1][2] - a[1][0] * a[0][2]),
			  a[1][0] * a[2][1] - a[2][0] * a[1][1],  -(a[0][0] * a[2][1] - a[2][0] * a[0][1]),   a[0][0] * a[1][1] - a[1][0] * a[0][1],
		};
	}

	template<typename T>
	LYAH_CONSTEXPR mat<3, 3, T> transpose(mat<3, 3, T> a) {
		T t;

		t = a[0][1];
		a[0][1] = a[1][0];
		a[1][0] = t;

		t = a[0][2];
		a[0][2] = a[2][0];
		a[2][0] = t;

		t = a[1][2];
		a[1][2] = a[2][1];
		a[2][1] = t;

		return a;
	}
}