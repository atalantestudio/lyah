// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

template<typename T, typename>
LYAH_CONSTEXPR T lyah::degrees(T radians) {
	return radians * static_cast<T>(57.295779513082321);
}

template<std::size_t C, typename T, typename>
LYAH_CONSTEXPR lyah::vec<C, T> lyah::degrees(vec<C, T> radians) {
	return radians * static_cast<T>(57.295779513082321);
}

template<typename T, typename>
LYAH_CONSTEXPR T lyah::radians(T degrees) {
	return degrees * static_cast<T>(0.017453292519943);
}

template<std::size_t C, typename T, typename>
LYAH_CONSTEXPR lyah::vec<C, T> lyah::radians(vec<C, T> degrees) {
	return degrees * static_cast<T>(0.017453292519943);
}

template<>
LYAH_INLINE LYAH_CONSTEXPR_CPP26 std::float_t lyah::sin(std::float_t x) {
	return std::sinf(x);
}

template<>
LYAH_INLINE LYAH_CONSTEXPR_CPP26 std::double_t lyah::sin(std::double_t x) {
	return std::sinl(x);
}

template<std::size_t C, typename T, typename>
LYAH_CONSTEXPR_CPP26 lyah::vec<C, T> lyah::sin(vec<C, T> x) {
	return apply<C, T>::modifier(x, sin);
}

template<>
LYAH_INLINE LYAH_CONSTEXPR_CPP26 std::float_t lyah::cos(std::float_t x) {
	return std::cosf(x);
}

template<>
LYAH_INLINE LYAH_CONSTEXPR_CPP26 std::double_t lyah::cos(std::double_t x) {
	return std::cosl(x);
}

template<std::size_t C, typename T, typename>
LYAH_CONSTEXPR_CPP26 lyah::vec<C, T> lyah::cos(vec<C, T> x) {
	return apply<C, T>::modifier(x, cos);
}

template<>
LYAH_INLINE LYAH_CONSTEXPR_CPP26 std::float_t lyah::tan(std::float_t x) {
	return std::tanf(x);
}

template<>
LYAH_INLINE LYAH_CONSTEXPR_CPP26 std::double_t lyah::tan(std::double_t x) {
	return std::tanl(x);
}

template<std::size_t C, typename T, typename>
LYAH_CONSTEXPR_CPP26 lyah::vec<C, T> lyah::tan(vec<C, T> x) {
	return apply<C, T>::modifier(x, tan);
}

template<>
LYAH_INLINE LYAH_CONSTEXPR_CPP26 std::float_t lyah::asin(std::float_t x) {
	return std::asinf(x);
}

template<>
LYAH_INLINE LYAH_CONSTEXPR_CPP26 std::double_t lyah::asin(std::double_t x) {
	return std::asinl(x);
}

template<std::size_t C, typename T, typename>
LYAH_CONSTEXPR_CPP26 lyah::vec<C, T> lyah::asin(vec<C, T> x) {
	return apply<C, T>::modifier(x, asin);
}

template<>
LYAH_INLINE LYAH_CONSTEXPR_CPP26 std::float_t lyah::acos(std::float_t x) {
	return std::acosf(x);
}

template<>
LYAH_INLINE LYAH_CONSTEXPR_CPP26 std::double_t lyah::acos(std::double_t x) {
	return std::acosl(x);
}

template<std::size_t C, typename T, typename>
LYAH_CONSTEXPR_CPP26 lyah::vec<C, T> lyah::acos(vec<C, T> x) {
	return apply<C, T>::modifier(x, acos);
}

template<>
LYAH_INLINE LYAH_CONSTEXPR_CPP26 std::float_t lyah::atan(std::float_t x) {
	return std::atanf(x);
}

template<>
LYAH_INLINE LYAH_CONSTEXPR_CPP26 std::double_t lyah::atan(std::double_t x) {
	return std::atanl(x);
}

template<std::size_t C, typename T, typename>
LYAH_CONSTEXPR_CPP26 lyah::vec<C, T> lyah::atan(vec<C, T> x) {
	return apply<C, T>::modifier(x, atan);
}