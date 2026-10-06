// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

template<>
LYAH_INLINE LYAH_CONSTEXPR_CPP23 std::float_t lyah::floor(std::float_t x) {
	return std::floorf(x);
}

template<>
LYAH_INLINE LYAH_CONSTEXPR_CPP23 std::double_t lyah::floor(std::double_t x) {
	return std::floorl(x);
}

template<std::size_t C, typename T, typename>
LYAH_CONSTEXPR_CPP23 lyah::vec<C, T> lyah::floor(vec<C, T> x) {
	return apply<vec<C, T>>::modifier(x, floor);
}

template<>
LYAH_INLINE LYAH_CONSTEXPR_CPP23 std::float_t lyah::ceil(std::float_t x) {
	return std::ceilf(x);
}

template<>
LYAH_INLINE LYAH_CONSTEXPR_CPP23 std::double_t lyah::ceil(std::double_t x) {
	return std::ceill(x);
}

template<std::size_t C, typename T, typename>
LYAH_CONSTEXPR_CPP23 lyah::vec<C, T> lyah::ceil(vec<C, T> x) {
	return apply<vec<C, T>>::modifier(x, ceil);
}

template<typename T, typename>
LYAH_CONSTEXPR T lyah::ceil(T x, T y) {
	return (x + y - 1) & ~(y - 1);
}

template<>
LYAH_INLINE LYAH_CONSTEXPR_CPP23 std::float_t lyah::round(std::float_t x) {
	return std::roundf(x);
}

template<>
LYAH_INLINE LYAH_CONSTEXPR_CPP23 std::double_t lyah::round(std::double_t x) {
	return std::roundl(x);
}

template<std::size_t C, typename T, typename>
LYAH_CONSTEXPR_CPP23 lyah::vec<C, T> lyah::round(vec<C, T> x) {
	return apply<vec<C, T>>::modifier(x, round);
}