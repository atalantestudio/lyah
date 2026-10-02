// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

namespace lyah {
	template<typename T>
	LYAH_CONSTEXPR bool operator==(vec<4, T> a, vec<4, T> b) {
		return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w;
	}

	template<typename T>
	LYAH_CONSTEXPR bool operator!=(vec<4, T> a, vec<4, T> b) {
		return a.x != b.x || a.y != b.y || a.z != b.z || a.w != b.w;
	}

	template<typename T>
	LYAH_CONSTEXPR vec<4, T> operator-(vec<4, T> a) {
		a.x = -a.x;
		a.y = -a.y;
		a.z = -a.z;
		a.w = -a.w;

		return a;
	}

	template<typename T>
	LYAH_CONSTEXPR vec<4, T> operator+(vec<4, T> a, vec<4, T> b) {
		a.x += b.x;
		a.y += b.y;
		a.z += b.z;
		a.w += b.w;

		return a;
	}

	template<typename T>
	LYAH_CONSTEXPR vec<4, T> operator*(vec<4, T> a, T b) {
		a.x *= b;
		a.y *= b;
		a.z *= b;
		a.w *= b;

		return a;
	}

	template<typename T>
	LYAH_CONSTEXPR vec<4, T> operator*(vec<4, T> a, vec<4, T> b) {
		a.x *= b.x;
		a.y *= b.y;
		a.z *= b.z;
		a.w *= b.w;

		return a;
	}

	template<typename T>
	LYAH_CONSTEXPR vec<4, T> operator*(vec<4, T> a, mat<4, 4, T> A) {
		a = {
			dot({A[0][0], A[1][0], A[2][0], A[3][0]}, a),
			dot({A[0][1], A[1][1], A[2][1], A[3][1]}, a),
			dot({A[0][2], A[1][2], A[2][2], A[3][2]}, a),
			dot({A[0][3], A[1][3], A[2][3], A[3][3]}, a),
		};

		return a;
	}

	template<typename T>
	LYAH_CONSTEXPR vec<4, T> operator/(T a, vec<4, T> b) {
		b.x = a / b.x;
		b.y = a / b.y;
		b.z = a / b.z;
		b.w = a / b.w;

		return b;
	}

	template<typename T>
	T sum(vec<4, T> a) {
		return a.x + a.y + a.z + a.w;
	}

	template<typename T>
	vec<4, T> pow(vec<4, T> a, vec<4, T> b) {
		a.x = pow(a.x, b.x);
		a.y = pow(a.y, b.y);
		a.z = pow(a.z, b.z);
		a.w = pow(a.w, b.w);

		return a;
	}

	template<typename T>
	vec<4, T> sqrt(vec<4, T> a) {
		a.x = sqrt(a.x);
		a.y = sqrt(a.y);
		a.z = sqrt(a.z);
		a.w = sqrt(a.w);

		return a;
	}
}