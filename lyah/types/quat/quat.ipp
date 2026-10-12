// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

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
LYAH_CONSTEXPR lyah::quat<T>::quat(quat<U> q) :
	w(static_cast<T>(q.w)),
	x(static_cast<T>(q.x)),
	y(static_cast<T>(q.y)),
	z(static_cast<T>(q.z))
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