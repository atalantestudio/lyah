// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

namespace lyah {
	template<typename T>
	LYAH_CONSTEXPR mat<2, 2, T> operator*(mat<2, 2, T> a, mat<2, 2, T> b) {
		return {
			a[0][0] * b[0][0] + a[0][1] * b[1][0], a[0][0] * b[0][1] + a[0][1] * b[1][1],
			a[1][0] * b[0][0] + a[1][1] * b[1][0], a[1][0] * b[0][1] + a[1][1] * b[1][1],
		};
	}

	template<typename T>
	LYAH_CONSTEXPR T determinant(mat<2, 2, T> a) {
		return a[0][0] * a[1][1] - a[0][1] * a[1][0];
	}

	template<typename T>
	LYAH_CONSTEXPR mat<2, 2, T> adjugate(mat<2, 2, T> a) {
		return {
			 a[1][1], -a[0][1],
			-a[1][0],  a[0][0],
		};
	}

	template<typename T>
	LYAH_CONSTEXPR mat<2, 2, T> transpose(mat<2, 2, T> a) {
		T t;

		t = a[0][1];
		a[0][1] = a[1][0];
		a[1][0] = t;

		return a;
	}
}