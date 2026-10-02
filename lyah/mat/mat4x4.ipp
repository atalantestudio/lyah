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

		return determinant(aa - ab * inverse(ad) * ac) * determinant(ad);
	}

	template<typename T>
	LYAH_CONSTEXPR mat<4, 4, T> adjugate(mat<4, 4, T> a) {
		const T a2323 = a[2][2] * a[3][3] - a[2][3] * a[3][2];
		const T a1323 = a[2][1] * a[3][3] - a[2][3] * a[3][1];
		const T a1223 = a[2][1] * a[3][2] - a[2][2] * a[3][1];
		const T a0323 = a[2][0] * a[3][3] - a[2][3] * a[3][0];
		const T a0223 = a[2][0] * a[3][2] - a[2][2] * a[3][0];
		const T a0123 = a[2][0] * a[3][1] - a[2][1] * a[3][0];
		const T a2313 = a[1][2] * a[3][3] - a[1][3] * a[3][2];
		const T a1313 = a[1][1] * a[3][3] - a[1][3] * a[3][1];
		const T a1213 = a[1][1] * a[3][2] - a[1][2] * a[3][1];
		const T a2312 = a[1][2] * a[2][3] - a[1][3] * a[2][2];
		const T a1312 = a[1][1] * a[2][3] - a[1][3] * a[2][1];
		const T a1212 = a[1][1] * a[2][2] - a[1][2] * a[2][1];
		const T a0313 = a[1][0] * a[3][3] - a[1][3] * a[3][0];
		const T a0213 = a[1][0] * a[3][2] - a[1][2] * a[3][0];
		const T a0312 = a[1][0] * a[2][3] - a[1][3] * a[2][0];
		const T a0212 = a[1][0] * a[2][2] - a[1][2] * a[2][0];
		const T a0113 = a[1][0] * a[3][1] - a[1][1] * a[3][0];
		const T a0112 = a[1][0] * a[2][1] - a[1][1] * a[2][0];

		return {
			  a[1][1] * a2323 - a[1][2] * a1323 + a[1][3] * a1223,
			-(a[0][1] * a2323 - a[0][2] * a1323 + a[0][3] * a1223),
			  a[0][1] * a2313 - a[0][2] * a1313 + a[0][3] * a1213,
			-(a[0][1] * a2312 - a[0][2] * a1312 + a[0][3] * a1212),
			-(a[1][0] * a2323 - a[1][2] * a0323 + a[1][3] * a0223),
			  a[0][0] * a2323 - a[0][2] * a0323 + a[0][3] * a0223,
			-(a[0][0] * a2313 - a[0][2] * a0313 + a[0][3] * a0213),
			  a[0][0] * a2312 - a[0][2] * a0312 + a[0][3] * a0212,
			  a[1][0] * a1323 - a[1][1] * a0323 + a[1][3] * a0123,
			-(a[0][0] * a1323 - a[0][1] * a0323 + a[0][3] * a0123),
			  a[0][0] * a1313 - a[0][1] * a0313 + a[0][3] * a0113,
			-(a[0][0] * a1312 - a[0][1] * a0312 + a[0][3] * a0112),
			-(a[1][0] * a1223 - a[1][1] * a0223 + a[1][2] * a0123),
			  a[0][0] * a1223 - a[0][1] * a0223 + a[0][2] * a0123,
			-(a[0][0] * a1213 - a[0][1] * a0213 + a[0][2] * a0113),
			  a[0][0] * a1212 - a[0][1] * a0212 + a[0][2] * a0112,
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