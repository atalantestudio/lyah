// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

template<>
LYAH_INLINE LYAH_CONSTEXPR_CPP26 std::float_t lyah::log2(std::float_t x) {
	return std::log2f(x);
}

template<>
LYAH_INLINE LYAH_CONSTEXPR_CPP26 std::double_t lyah::log2(std::double_t x) {
	return std::log2l(x);
}

template<>
LYAH_INLINE LYAH_CONSTEXPR_CPP26 std::float_t lyah::pow(std::float_t x, std::float_t y) {
	return std::powf(x, y);
}

template<>
LYAH_INLINE LYAH_CONSTEXPR_CPP26 std::double_t lyah::pow(std::double_t x, std::double_t y) {
	return std::powl(x, y);
}

template<std::size_t C, typename T, typename>
LYAH_CONSTEXPR_CPP26 lyah::vec<C, T> lyah::pow(vec<C, T> x, T y) {
	return apply<C, T>::modifier(x, y, pow);
}

template<std::size_t C, typename T, typename>
LYAH_CONSTEXPR_CPP26 lyah::vec<C, T> lyah::pow(vec<C, T> x, lyah::vec<C, T> y) {
	return apply<C, T>::modifier(x, y, pow);
}

template<>
LYAH_INLINE LYAH_CONSTEXPR_CPP26 std::float_t lyah::sqrt(std::float_t x) {
	return std::sqrtf(x);
}

template<>
LYAH_INLINE LYAH_CONSTEXPR_CPP26 std::double_t lyah::sqrt(std::double_t x) {
	return std::sqrtl(x);
}

template<std::size_t C, typename T, typename>
LYAH_CONSTEXPR_CPP26 lyah::vec<C, T> lyah::sqrt(vec<C, T> x) {
	return apply<C, T>::modifier(x, sqrt);
}