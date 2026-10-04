// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

template<typename T>
LYAH_CONSTEXPR T lyah::epsilon() {
	return std::numeric_limits<T>::epsilon();
}

template<typename T>
LYAH_CONSTEXPR T lyah::infinity() {
	LYAH_STATIC_ASSERT(std::numeric_limits<T>::has_infinity);

	return std::numeric_limits<T>::infinity();
}

template<typename T>
LYAH_CONSTEXPR T lyah::nan() {
	LYAH_STATIC_ASSERT(std::numeric_limits<T>::has_quiet_NaN);

	return std::numeric_limits<T>::quiet_NaN();
}

template<typename T, typename>
LYAH_CONSTEXPR T lyah::pi() {
	return static_cast<T>(3.141592653589793);
}

template<typename T, typename>
LYAH_CONSTEXPR T lyah::tau() {
	return static_cast<T>(6.283185307179586);
}