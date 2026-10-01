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
	LYAH_CONSTEXPR vec<2, T> operator*(vec<2, T> a, mat<2, 2, T> B) {
		a = {
			dot({B[0][0], B[1][0]}, a),
			dot({B[0][1], B[1][1]}, a),
		};

		return a;
	}

	template<typename T>
	LYAH_CONSTEXPR vec<2, T> operator/(T a, vec<2, T> b) {
		b.x = a / b.x;
		b.y = a / b.y;

		return b;
	}

	template<typename T>
	LYAH_CONSTEXPR_CPP23 vec<2, T> fma(vec<2, T> a, vec<2, T> b, vec<2, T> c) {
		a.x = fma(a.x, b.x, c.x);
		a.y = fma(a.y, b.y, c.y);

		return a;
	}

	template<typename T>
	vec<2, T> max(vec<2, T> a, vec<2, T> b) {
		a.x = max(a.x, b.x);
		a.y = max(a.y, b.y);

		return a;
	}

	template<typename T>
	vec<2, T> min(vec<2, T> a, vec<2, T> b) {
		a.x = min(a.x, b.x);
		a.y = min(a.y, b.y);

		return a;
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

	template<typename T>
	vec<2, T> cos(vec<2, T> a) {
		a.x = cos(a.x);
		a.y = cos(a.y);

		return a;
	}

	template<typename T>
	vec<2, T> sin(vec<2, T> a) {
		a.x = sin(a.x);
		a.y = sin(a.y);

		return a;
	}

	template<typename T>
	vec<2, T> tan(vec<2, T> a) {
		a.x = tan(a.x);
		a.y = tan(a.y);

		return a;
	}
}