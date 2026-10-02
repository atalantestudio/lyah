// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

namespace lyah {
	template<typename T>
	LYAH_CONSTEXPR mat<4, 4, T> operator*(mat<4, 4, T> a, mat<4, 4, T> b) {
		const vec<4, T> a0 = a[0];
		const vec<4, T> a1 = a[1];
		const vec<4, T> a2 = a[2];
		const vec<4, T> a3 = a[3];
		const vec<4, T> b0 = b[0];
		const vec<4, T> b1 = b[1];
		const vec<4, T> b2 = b[2];
		const vec<4, T> b3 = b[3];

		a[0] = fma(b3, vec<4, T>(a0.w), fma(b2, vec<4, T>(a0.z), fma(b1, vec<4, T>(a0.y), b0 * a0.x)));
		a[1] = fma(b3, vec<4, T>(a1.w), fma(b2, vec<4, T>(a1.z), fma(b1, vec<4, T>(a1.y), b0 * a1.x)));
		a[2] = fma(b3, vec<4, T>(a2.w), fma(b2, vec<4, T>(a2.z), fma(b1, vec<4, T>(a2.y), b0 * a2.x)));
		a[3] = fma(b3, vec<4, T>(a3.w), fma(b2, vec<4, T>(a3.z), fma(b1, vec<4, T>(a3.y), b0 * a3.x)));

		return a;
	}

	/// See https://stackoverflow.com/a/30006505/17136841.
	template<typename T>
	LYAH_CONSTEXPR T determinant(mat<4, 4, T> a) {
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

		const T det = determinant(ad);
		const T invDet = static_cast<T>(1) / det;

		return determinant(aa - ab * (adjugate(ad) * invDet) * ac) * det;
	}

	template<typename T>
	LYAH_CONSTEXPR mat<4, 4, T> adjugate(mat<4, 4, T> a) {
		const T a00 = a[0][0];
		const T a01 = a[0][1];
		const T a02 = a[0][2];
		const T a03 = a[0][3];
		const T a10 = a[1][0];
		const T a11 = a[1][1];
		const T a12 = a[1][2];
		const T a13 = a[1][3];
		const T a20 = a[2][0];
		const T a21 = a[2][1];
		const T a22 = a[2][2];
		const T a23 = a[2][3];
		const T a30 = a[3][0];
		const T a31 = a[3][1];
		const T a32 = a[3][2];
		const T a33 = a[3][3];

		const T a2323 = a22 * a33 - a23 * a32;
		const T a1323 = a21 * a33 - a23 * a31;
		const T a1223 = a21 * a32 - a22 * a31;
		const T a0323 = a20 * a33 - a23 * a30;
		const T a0223 = a20 * a32 - a22 * a30;
		const T a0123 = a20 * a31 - a21 * a30;
		const T a2313 = a12 * a33 - a13 * a32;
		const T a1313 = a11 * a33 - a13 * a31;
		const T a1213 = a11 * a32 - a12 * a31;
		const T a2312 = a12 * a23 - a13 * a22;
		const T a1312 = a11 * a23 - a13 * a21;
		const T a1212 = a11 * a22 - a12 * a21;
		const T a0313 = a10 * a33 - a13 * a30;
		const T a0213 = a10 * a32 - a12 * a30;
		const T a0312 = a10 * a23 - a13 * a20;
		const T a0212 = a10 * a22 - a12 * a20;
		const T a0113 = a10 * a31 - a11 * a30;
		const T a0112 = a10 * a21 - a11 * a20;

		return {
			  a11 * a2323 - a12 * a1323 + a13 * a1223,  -(a01 * a2323 - a02 * a1323 + a03 * a1223),   a01 * a2313 - a02 * a1313 + a03 * a1213,  -(a01 * a2312 - a02 * a1312 + a03 * a1212),
			-(a10 * a2323 - a12 * a0323 + a13 * a0223),   a00 * a2323 - a02 * a0323 + a03 * a0223,  -(a00 * a2313 - a02 * a0313 + a03 * a0213),   a00 * a2312 - a02 * a0312 + a03 * a0212,
			  a10 * a1323 - a11 * a0323 + a13 * a0123,  -(a00 * a1323 - a01 * a0323 + a03 * a0123),   a00 * a1313 - a01 * a0313 + a03 * a0113,  -(a00 * a1312 - a01 * a0312 + a03 * a0112),
			-(a10 * a1223 - a11 * a0223 + a12 * a0123),   a00 * a1223 - a01 * a0223 + a02 * a0123,  -(a00 * a1213 - a01 * a0213 + a02 * a0113),   a00 * a1212 - a01 * a0212 + a02 * a0112,
		};
	}

	template<typename T>
	LYAH_CONSTEXPR mat<4, 4, T> transpose(mat<4, 4, T> a) {
		T t;

		t = a[0][1];
		a[0][1] = a[1][0];
		a[1][0] = t;

		t = a[0][2];
		a[0][2] = a[2][0];
		a[2][0] = t;

		t = a[0][3];
		a[0][3] = a[3][0];
		a[3][0] = t;

		t = a[1][2];
		a[1][2] = a[2][1];
		a[2][1] = t;

		t = a[1][3];
		a[1][3] = a[3][1];
		a[3][1] = t;

		t = a[2][3];
		a[2][3] = a[3][2];
		a[3][2] = t;

		return a;
	}
}