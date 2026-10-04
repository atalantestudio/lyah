// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

template<typename T, typename>
LYAH_CONSTEXPR T lyah::epsilon() {
	return std::numeric_limits<T>::epsilon();
}

template<typename T, typename>
LYAH_CONSTEXPR T lyah::pi() {
	return static_cast<T>(3.141592653589793);
}

template<typename T, typename>
LYAH_CONSTEXPR T lyah::tau() {
	return static_cast<T>(6.283185307179586);
}