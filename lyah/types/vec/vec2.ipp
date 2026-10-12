// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

template<typename T>
LYAH_CONSTEXPR lyah::vec<2, T>::vec() :
	x(0),
	y(0)
{}

template<typename T>
LYAH_CONSTEXPR lyah::vec<2, T>::vec(T x, T y) :
	x(x),
	y(y)
{}

template<typename T>
LYAH_CONSTEXPR lyah::vec<2, T>::vec(T a) :
	x(a),
	y(a)
{}

template<typename T>
template<typename U>
LYAH_CONSTEXPR lyah::vec<2, T>::vec(vec<2, U> a) :
	x(static_cast<T>(a.x)),
	y(static_cast<T>(a.y))
{}

template<typename T>
LYAH_CONSTEXPR T lyah::vec<2, T>::operator[](std::size_t index) const {
	LYAH_ASSERT(index < 2);

	return static_cast<const T*>(static_cast<const void*>(this))[index];
}

template<typename T>
T& lyah::vec<2, T>::operator[](std::size_t index) {
	LYAH_ASSERT(index < 2);

	return static_cast<T*>(static_cast<void*>(this))[index];
}

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
	LYAH_CONSTEXPR vec<2, T> operator-(vec<2, T> a, vec<2, T> b) {
		a.x -= b.x;
		a.y -= b.y;

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
	LYAH_CONSTEXPR vec<2, T> operator/(vec<2, T> a, T b) {
		a.x /= b;
		a.y /= b;

		return a;
	}

	template<typename T>
	LYAH_CONSTEXPR vec<2, T> operator/(T a, vec<2, T> b) {
		b.x = a / b.x;
		b.y = a / b.y;

		return b;
	}

	template<typename T>
	LYAH_CONSTEXPR vec<2, T> operator/(vec<2, T> a, vec<2, T> b) {
		a.x /= b.x;
		a.y /= b.y;

		return a;
	}
}