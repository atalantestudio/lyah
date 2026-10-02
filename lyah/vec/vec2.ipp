// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

namespace lyah {
	template<typename T>
	LYAH_CONSTEXPR bool operator==(vec<2, T> a, vec<2, T> b) {
		return a.x == b.x && a.y == b.y;
	}

	template<typename T>
	LYAH_CONSTEXPR bool operator!=(vec<2, T> a, vec<2, T> b) {
		return a.x != b.x || a.y != b.y;
	}

	template<typename T>
	LYAH_CONSTEXPR vec<2, T> operator-(vec<2, T> a) {
		a.x = -a.x;
		a.y = -a.y;

		return a;
	}

	template<typename T>
	LYAH_CONSTEXPR vec<2, T> operator+(vec<2, T> a, vec<2, T> b) {
		a.x += b.x;
		a.y += b.y;

		return a;
	}

	template<typename T>
	LYAH_CONSTEXPR vec<2, T> operator*(vec<2, T> a, T b) {
		a.x *= b;
		a.y *= b;

		return a;
	}

	template<typename T>
	LYAH_CONSTEXPR vec<2, T> operator*(vec<2, T> a, vec<2, T> b) {
		a.x *= b.x;
		a.y *= b.y;

		return a;
	}

	template<typename T>
	LYAH_CONSTEXPR vec<2, T> operator*(vec<2, T> a, mat<2, 2, T> b) {
		return {
			dot({b[0][0], b[1][0]}, a),
			dot({b[0][1], b[1][1]}, a),
		};
	}

	template<typename T>
	LYAH_CONSTEXPR vec<2, T> operator/(T a, vec<2, T> b) {
		b.x = a / b.x;
		b.y = a / b.y;

		return b;
	}

	template<typename T>
	T sum(vec<2, T> a) {
		return a.x + a.y;
	}

	template<typename T>
	vec<2, T> pow(vec<2, T> a, vec<2, T> b) {
		a.x = pow(a.x, b.x);
		a.y = pow(a.y, b.y);

		return a;
	}

	template<typename T>
	vec<2, T> sqrt(vec<2, T> a) {
		a.x = sqrt(a.x);
		a.y = sqrt(a.y);

		return a;
	}
}