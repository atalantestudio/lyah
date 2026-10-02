// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

namespace lyah {
	template<typename T>
	LYAH_CONSTEXPR bool operator==(vec<3, T> a, vec<3, T> b) {
		return a.x == b.x && a.y == b.y && a.z == b.z;
	}

	template<typename T>
	LYAH_CONSTEXPR bool operator!=(vec<3, T> a, vec<3, T> b) {
		return a.x != b.x || a.y != b.y || a.z != b.z;
	}

	template<typename T>
	LYAH_CONSTEXPR vec<3, T> operator-(vec<3, T> a) {
		a.x = -a.x;
		a.y = -a.y;
		a.z = -a.z;

		return a;
	}

	template<typename T>
	LYAH_CONSTEXPR vec<3, T> operator+(vec<3, T> a, vec<3, T> b) {
		a.x += b.x;
		a.y += b.y;
		a.z += b.z;

		return a;
	}

	template<typename T>
	LYAH_CONSTEXPR vec<3, T> operator*(vec<3, T> a, T b) {
		a.x *= b;
		a.y *= b;
		a.z *= b;

		return a;
	}

	template<typename T>
	LYAH_CONSTEXPR vec<3, T> operator*(vec<3, T> a, vec<3, T> b) {
		a.x *= b.x;
		a.y *= b.y;
		a.z *= b.z;

		return a;
	}

	template<typename T>
	LYAH_CONSTEXPR vec<3, T> operator*(vec<3, T> a, mat<3, 3, T> b) {
		return {
			dot({b[0][0], b[1][0], b[2][0]}, a),
			dot({b[0][1], b[1][1], b[2][1]}, a),
			dot({b[0][2], b[1][2], b[2][2]}, a),
		};
	}

	template<typename T>
	LYAH_CONSTEXPR vec<3, T> operator/(T a, vec<3, T> b) {
		b.x = a / b.x;
		b.y = a / b.y;
		b.z = a / b.z;

		return b;
	}

	/// `b` is assumed to be normalized.
	/// See https://blog.molecular-matters.com/2013/05/24/a-faster-quaternion-vector-multiplication.
	template<typename T>
	vec<3, T>& operator*=(vec<3, T>& a, quat<T> b) {
		const vec<3, T> xyz = {b.x, b.y, b.z};

		a = static_cast<T>(2) * (dot(xyz, a) * xyz + b.w * (cross(xyz, a) + b.w * a)) - a;

		return a;
	}

	template<typename T>
	vec<3, T> operator*(vec<3, T> a, quat<T> b) {
		return a *= b;
	}

	template<typename T>
	T sum(vec<3, T> a) {
		return a.x + a.y + a.z;
	}

	template<typename T>
	vec<3, T> pow(vec<3, T> a, vec<3, T> b) {
		a.x = pow(a.x, b.x);
		a.y = pow(a.y, b.y);
		a.z = pow(a.z, b.z);

		return a;
	}

	template<typename T>
	vec<3, T> sqrt(vec<3, T> a) {
		a.x = sqrt(a.x);
		a.y = sqrt(a.y);
		a.z = sqrt(a.z);

		return a;
	}
}