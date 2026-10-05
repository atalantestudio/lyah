// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

template<typename T>
LYAH_CONSTEXPR T lyah::sum(vec<2, T> x) {
	return x.x + x.y;
}

template<typename T>
LYAH_CONSTEXPR T lyah::sum(vec<3, T> x) {
	return x.x + x.y + x.z;
}

template<typename T>
LYAH_CONSTEXPR T lyah::sum(vec<4, T> x) {
	return x.x + x.y + x.z + x.w;
}

template<typename T, typename>
LYAH_CONSTEXPR T lyah::abs(T x) {
	return x > 0 ? x : -x;
}

template<std::size_t C, typename T, typename>
LYAH_CONSTEXPR lyah::vec<C, T> lyah::abs(vec<C, T> x) {
	return apply<vec<C, T>>::modifier(x, abs);
}

template<typename T>
LYAH_CONSTEXPR T lyah::min(T x, T y) {
	return x >= y ? y : x;
}

template<std::size_t C, typename T>
LYAH_CONSTEXPR lyah::vec<C, T> lyah::min(vec<C, T> x, vec<C, T> y) {
	return apply<vec<C, T>>::modifier(x, y, min);
}

template<typename T>
LYAH_CONSTEXPR T lyah::max(T x, T y) {
	return x <= y ? y : x;
}

template<std::size_t C, typename T>
LYAH_CONSTEXPR lyah::vec<C, T> lyah::max(vec<C, T> x, vec<C, T> y) {
	return apply<vec<C, T>>::modifier(x, y, max);
}

template<typename T>
LYAH_CONSTEXPR T lyah::clamp(T x, T _min, T _max) {
	return min(max(x, _min), _max);
}

template<typename T, typename>
LYAH_CONSTEXPR T lyah::lerp(T a, T b, T t) {
	return a * (1 - t) + b * t;
}

template<std::size_t C, typename T, typename>
LYAH_CONSTEXPR lyah::vec<C, T> lyah::lerp(vec<C, T> a, vec<C, T> b, T t) {
	return a * (1 - t) + b * t;
}

template<std::size_t C, typename T, typename>
LYAH_CONSTEXPR lyah::vec<C, T> lyah::lerp(vec<C, T> a, vec<C, T> b, vec<C, T> t) {
	return a * (vec<C, T>(1) - t) + b * t;
}

template<>
LYAH_INLINE LYAH_CONSTEXPR_CPP23 std::float_t lyah::fma(std::float_t a, std::float_t b, std::float_t c) {
	return std::fmaf(a, b, c);
}

template<>
LYAH_INLINE LYAH_CONSTEXPR_CPP23 std::double_t lyah::fma(std::double_t a, std::double_t b, std::double_t c) {
	return std::fmal(a, b, c);
}

template<typename T, typename>
LYAH_CONSTEXPR_CPP23 lyah::vec<2, T> lyah::fma(vec<2, T> x, vec<2, T> y, vec<2, T> z) {
	x.x = fma(x.x, y.x, z.x);
	x.y = fma(x.y, y.y, z.y);

	return x;
}

template<typename T, typename>
LYAH_CONSTEXPR_CPP23 lyah::vec<3, T> lyah::fma(vec<3, T> x, vec<3, T> y, vec<3, T> z) {
	x.x = fma(x.x, y.x, z.x);
	x.y = fma(x.y, y.y, z.y);
	x.z = fma(x.z, y.z, z.z);

	return x;
}

template<typename T, typename>
LYAH_CONSTEXPR_CPP23 lyah::vec<4, T> lyah::fma(vec<4, T> x, vec<4, T> y, vec<4, T> z) {
	x.x = fma(x.x, y.x, z.x);
	x.y = fma(x.y, y.y, z.y);
	x.z = fma(x.z, y.z, z.z);
	x.w = fma(x.w, y.w, z.w);

	return x;
}