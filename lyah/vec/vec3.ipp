// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

template<typename T>
LYAH_CONSTEXPR lyah::vec<3, T>::vec() :
	x(0),
	y(0),
	z(0)
{}

template<typename T>
LYAH_CONSTEXPR lyah::vec<3, T>::vec(T x, T y, T z) :
	x(x),
	y(y),
	z(z)
{}

template<typename T>
LYAH_CONSTEXPR lyah::vec<3, T>::vec(T a) :
	x(a),
	y(a),
	z(a)
{}

template<typename T>
template<typename U>
LYAH_CONSTEXPR lyah::vec<3, T>::vec(vec<3, U> a) :
	x(static_cast<T>(a.x)),
	y(static_cast<T>(a.y)),
	z(static_cast<T>(a.z))
{}

template<typename T>
LYAH_CONSTEXPR T lyah::vec<3, T>::operator[](std::size_t index) const {
	LYAH_ASSERT(index < 3);

	return static_cast<const T*>(static_cast<const void*>(this))[index];
}

template<typename T>
T& lyah::vec<3, T>::operator[](std::size_t index) {
	LYAH_ASSERT(index < 3);

	return static_cast<T*>(static_cast<void*>(this))[index];
}

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
}

// See https://blog.molecular-matters.com/2013/05/24/a-faster-quaternion-vector-multiplication.
template<typename T>
LYAH_CONSTEXPR lyah::vec<3, T> lyah::operator*(vec<3, T> a, quat<T> b) {
	const vec<3, T> c = {b.x, b.y, b.z};

	return 2 * (dot(c, a) * c + b.w * (cross(c, a) + b.w * a)) - a;
}

template<typename T>
lyah::vec<3, T>& lyah::operator*=(vec<3, T>& a, quat<T> b) {
	return a = a * b;
}