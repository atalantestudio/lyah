// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

template<typename T, typename>
LYAH_CONSTEXPR bool lyah::operator==(quat<T> a, quat<T> b) {
	return a.w == b.w && a.x == b.x && a.y == b.y && a.z == b.z;
}

template<typename T, typename>
LYAH_CONSTEXPR bool lyah::operator!=(quat<T> a, quat<T> b) {
	return a.w != b.w || a.x != b.x || a.y != b.y || a.z != b.z;
}

template<typename T, typename>
LYAH_CONSTEXPR lyah::quat<T> lyah::operator+(quat<T> a) {
	return a;
}

template<typename T, typename>
LYAH_CONSTEXPR lyah::quat<T> lyah::operator-(quat<T> a) {
	a.w = -a.w;
	a.x = -a.x;
	a.y = -a.y;
	a.z = -a.z;

	return a;
}

template<typename T, typename>
LYAH_CONSTEXPR lyah::quat<T> lyah::operator+(quat<T> a, quat<T> b) {
	a.w += b.w;
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;

	return a;
}

template<typename T, typename>
lyah::quat<T>& lyah::operator+=(quat<T>& a, quat<T> b) {
	return a = a + b;
}

template<typename T, typename>
LYAH_CONSTEXPR lyah::quat<T> lyah::operator-(quat<T> a, quat<T> b) {
	a.w -= b.w;
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;

	return a;
}

template<typename T, typename>
lyah::quat<T>& lyah::operator-=(quat<T>& a, quat<T> b) {
	return a = a - b;
}

template<typename T, typename>
LYAH_CONSTEXPR lyah::quat<T> lyah::operator*(quat<T> a, T b) {
	a.w *= b;
	a.x *= b;
	a.y *= b;
	a.z *= b;

	return a;
}

template<typename T, typename>
LYAH_CONSTEXPR lyah::quat<T> lyah::operator*(T a, quat<T> b) {
	b.w *= a;
	b.x *= a;
	b.y *= a;
	b.z *= a;

	return b;
}

template<typename T, typename>
lyah::quat<T>& lyah::operator*=(quat<T>& a, T b) {
	return a = a * b;
}

template<typename T, typename>
LYAH_CONSTEXPR lyah::quat<T> lyah::operator*(quat<T> a, quat<T> b) {
	return {
		a.w * b.w - (a.x * b.x + a.y * b.y) - a.z * b.z,
		a.w * b.x +  a.x * b.w + a.y * b.z  - a.z * b.y,
		a.w * b.y +  a.y * b.w + a.z * b.x  - a.x * b.z,
		a.w * b.z +  a.z * b.w + a.x * b.y  - a.y * b.x,
	};
}

template<typename T, typename>
lyah::quat<T>& lyah::operator*=(quat<T>& a, quat<T> b) {
	return a = a * b;
}

// See https://blog.molecular-matters.com/2013/05/24/a-faster-quaternion-vector-multiplication.
template<typename T, typename>
LYAH_CONSTEXPR lyah::vec<3, T> lyah::operator*(vec<3, T> a, quat<T> b) {
	const vec<3, T> c = {b.x, b.y, b.z};

	return static_cast<T>(2) * (dot(c, a) * c + b.w * (cross(c, a) + b.w * a)) - a;
}

template<typename T, typename>
lyah::vec<3, T>& lyah::operator*=(vec<3, T>& a, quat<T> b) {
	return a = a * b;
}

template<typename T, typename>
LYAH_CONSTEXPR lyah::quat<T> lyah::operator/(quat<T> a, T b) {
	return a * (static_cast<T>(1) / b);
}

template<typename T, typename>
lyah::quat<T>& lyah::operator/=(quat<T>& a, T b) {
	return a = a / b;
}

template<typename T, typename>
LYAH_CONSTEXPR lyah::quat<T> lyah::conjugate(quat<T> a) {
	a.x = -a.x;
	a.y = -a.y;
	a.z = -a.z;

	return a;
}

template<typename T, typename>
LYAH_CONSTEXPR lyah::quat<T> lyah::inverse(quat<T> a) {
	return conjugate(a) / dot(a, a);
}

template<typename T>
LYAH_CONSTEXPR T lyah::dot(quat<T> a, quat<T> b) {
	return a.w * b.w + a.x * b.x + a.y * b.y + a.z * b.z;
}

template<typename T>
LYAH_CONSTEXPR_CPP26 T lyah::length(quat<T> a) {
	return sqrt(lengthSquared(a));
}

template<typename T>
LYAH_CONSTEXPR T lyah::lengthSquared(quat<T> a) {
	return dot(a, a);
}

template<typename T>
LYAH_CONSTEXPR_CPP26 T lyah::distance(quat<T> a, quat<T> b) {
	return length(b - a);
}

template<typename T>
LYAH_CONSTEXPR T lyah::distanceSquared(quat<T> a, quat<T> b) {
	return lengthSquared(b - a);
}

template<typename T>
LYAH_CONSTEXPR_CPP26 lyah::quat<T> lyah::normalized(quat<T> a) {
	return a / length(a);
}