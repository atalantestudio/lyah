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
	LYAH_CONSTEXPR vec<3, T> operator*(vec<3, T> a, mat<3, 3, T> A) {
		a = {
			dot({A[0][0], A[1][0], A[2][0]}, a),
			dot({A[0][1], A[1][1], A[2][1]}, a),
			dot({A[0][2], A[1][2], A[2][2]}, a),
		};

		return a;
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
	LYAH_CONSTEXPR_CPP23 vec<3, T> fma(vec<3, T> a, vec<3, T> b, vec<3, T> c) {
		a.x = fma(a.x, b.x, c.x);
		a.y = fma(a.y, b.y, c.y);
		a.z = fma(a.z, b.z, c.z);

		return a;
	}

	template<typename T>
	vec<3, T> max(vec<3, T> a, vec<3, T> b) {
		a.x = max(a.x, b.x);
		a.y = max(a.y, b.y);
		a.z = max(a.z, b.z);

		return a;
	}

	template<typename T>
	vec<3, T> min(vec<3, T> a, vec<3, T> b) {
		a.x = min(a.x, b.x);
		a.y = min(a.y, b.y);
		a.z = min(a.z, b.z);

		return a;
	}

	template<typename T>
	T sum(vec<3, T> a) {
		return a.x + a.y + a.z;
	}

	template<typename T>
	vec<3, T> cross(vec<3, T> a, vec<3, T> b) {
		return {
			fma(a.y, b.z, -a.z * b.y),
			fma(a.z, b.x, -a.x * b.z),
			fma(a.x, b.y, -a.y * b.x),
		};
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

	template<typename T>
	vec<3, T> cos(vec<3, T> a) {
		a.x = cos(a.x);
		a.y = cos(a.y);
		a.z = cos(a.z);

		return a;
	}

	template<typename T>
	vec<3, T> sin(vec<3, T> a) {
		a.x = sin(a.x);
		a.y = sin(a.y);
		a.z = sin(a.z);

		return a;
	}

	template<typename T>
	vec<3, T> tan(vec<3, T> a) {
		a.x = tan(a.x);
		a.y = tan(a.y);
		a.z = tan(a.z);

		return a;
	}
}