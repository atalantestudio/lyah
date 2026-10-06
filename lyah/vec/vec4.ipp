// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

template<typename T>
LYAH_CONSTEXPR lyah::vec<4, T>::vec() :
	x(0),
	y(0),
	z(0),
	w(0)
{}

template<typename T>
LYAH_CONSTEXPR lyah::vec<4, T>::vec(T x, T y, T z, T w) :
	x(x),
	y(y),
	z(z),
	w(w)
{}

template<typename T>
LYAH_CONSTEXPR lyah::vec<4, T>::vec(T a) :
	x(a),
	y(a),
	z(a),
	w(a)
{}

template<typename T>
template<typename U>
LYAH_CONSTEXPR lyah::vec<4, T>::vec(vec<4, U> a) :
	x(static_cast<T>(a.x)),
	y(static_cast<T>(a.y)),
	z(static_cast<T>(a.z)),
	w(static_cast<T>(a.w))
{}

template<typename T>
LYAH_CONSTEXPR T lyah::vec<4, T>::operator[](std::size_t index) const {
	LYAH_ASSERT(index < 4);

	return static_cast<const T*>(static_cast<const void*>(this))[index];
}

template<typename T>
T& lyah::vec<4, T>::operator[](std::size_t index) {
	LYAH_ASSERT(index < 4);

	return static_cast<T*>(static_cast<void*>(this))[index];
}

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
	LYAH_CONSTEXPR vec<4, T> operator-(vec<4, T> a, vec<4, T> b) {
		a.x -= b.x;
		a.y -= b.y;
		a.z -= b.z;
		a.w -= b.w;

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
	LYAH_CONSTEXPR vec<4, T> operator*(vec<4, T> a, mat<4, 4, T> b) {
		return {
			dot({b[0][0], b[1][0], b[2][0], b[3][0]}, a),
			dot({b[0][1], b[1][1], b[2][1], b[3][1]}, a),
			dot({b[0][2], b[1][2], b[2][2], b[3][2]}, a),
			dot({b[0][3], b[1][3], b[2][3], b[3][3]}, a),
		};
	}

	template<typename T>
	LYAH_CONSTEXPR vec<4, T> operator/(vec<4, T> a, T b) {
		a.x /= b;
		a.y /= b;
		a.z /= b;
		a.w /= b;

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
	LYAH_CONSTEXPR vec<4, T> operator/(vec<4, T> a, vec<4, T> b) {
		a.x /= b.x;
		a.y /= b.y;
		a.z /= b.z;
		a.w /= b.w;

		return a;
	}
}