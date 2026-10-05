// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

template<typename T, typename>
LYAH_CONSTEXPR lyah::quat<T> lyah::identity() {
	return {1, 0, 0, 0};
}

template<typename T, typename>
LYAH_CONSTEXPR_CPP26 lyah::quat<T> lyah::axisAngle(vec<3, T> axis, T angle) {
	angle *= static_cast<T>(0.5);
	axis *= sin<T>(angle);

	return {cos(angle), axis.x, axis.y, axis.z};
}

template<typename T>
LYAH_CONSTEXPR lyah::quat<T>::quat() :
	w(0),
	x(0),
	y(0),
	z(0)
{}

template<typename T>
LYAH_CONSTEXPR lyah::quat<T>::quat(T w, T x, T y, T z) :
	w(w),
	x(x),
	y(y),
	z(z)
{}

template<typename T>
template<typename U>
LYAH_CONSTEXPR lyah::quat<T>::quat(quat<U> a) :
	w(static_cast<T>(a.w)),
	x(static_cast<T>(a.x)),
	y(static_cast<T>(a.y)),
	z(static_cast<T>(a.z))
{}

template<typename T>
LYAH_CONSTEXPR T lyah::quat<T>::operator[](std::size_t index) const {
	LYAH_ASSERT(index < 4);

	return static_cast<const T*>(static_cast<const void*>(this))[index];
}

template<typename T>
T& lyah::quat<T>::operator[](std::size_t index) {
	LYAH_ASSERT(index < 4);

	return static_cast<T*>(static_cast<void*>(this))[index];
}

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

template<typename T, typename>
LYAH_CONSTEXPR lyah::quat<T> lyah::operator/(quat<T> a, T b) {
	return a * (static_cast<T>(1) / b);
}

template<typename T, typename>
LYAH_CONSTEXPR lyah::quat<T> lyah::operator/(T a, quat<T> b) {
	return a * inverse(b);
}

template<typename T, typename>
lyah::quat<T>& lyah::operator/=(quat<T>& a, T b) {
	return a = a / b;
}

template<typename T, typename>
LYAH_CONSTEXPR lyah::quat<T> lyah::operator/(quat<T> a, quat<T> b) {
	return a * inverse(b);
}

template<typename T, typename>
lyah::quat<T>& lyah::operator/=(quat<T>& a, quat<T> b) {
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