// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

LYAH_CONSTEXPR_CPP23 std::float_t lyah::fma(std::float_t a, std::float_t b, std::float_t c) {
	return std::fmaf(a, b, c);
}

LYAH_CONSTEXPR_CPP23 std::double_t lyah::fma(std::double_t a, std::double_t b, std::double_t c) {
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
	return x > static_cast<T>(0) ? x : -x;
}

template<typename T, typename>
LYAH_CONSTEXPR lyah::vec<2, T> lyah::abs(vec<2, T> x) {
	x.x = abs(x.x);
	x.y = abs(x.y);

	return x;
}

template<typename T, typename>
LYAH_CONSTEXPR lyah::vec<3, T> lyah::abs(vec<3, T> x) {
	x.x = abs(x.x);
	x.y = abs(x.y);
	x.z = abs(x.z);

	return x;
}

template<typename T, typename>
LYAH_CONSTEXPR lyah::vec<4, T> lyah::abs(vec<4, T> x) {
	x.x = abs(x.x);
	x.y = abs(x.y);
	x.z = abs(x.z);
	x.w = abs(x.w);

	return x;
}

template<typename T>
LYAH_CONSTEXPR T lyah::min(T x, T y) {
	return x >= y ? y : x;
}

template<typename T>
LYAH_CONSTEXPR lyah::vec<2, T> lyah::min(vec<2, T> x, vec<2, T> y) {
	x.x = min(x.x, y.x);
	x.y = min(x.y, y.y);

	return x;
}

template<typename T>
LYAH_CONSTEXPR lyah::vec<3, T> lyah::min(vec<3, T> x, vec<3, T> y) {
	x.x = min(x.x, y.x);
	x.y = min(x.y, y.y);
	x.z = min(x.z, y.z);

	return x;
}

template<typename T>
LYAH_CONSTEXPR lyah::vec<4, T> lyah::min(vec<4, T> x, vec<4, T> y) {
	x.x = min(x.x, y.x);
	x.y = min(x.y, y.y);
	x.z = min(x.z, y.z);
	x.w = min(x.w, y.w);

	return x;
}

template<typename T>
LYAH_CONSTEXPR T lyah::max(T x, T y) {
	return x <= y ? y : x;
}

template<typename T>
LYAH_CONSTEXPR lyah::vec<2, T> lyah::max(vec<2, T> x, vec<2, T> y) {
	x.x = max(x.x, y.x);
	x.y = max(x.y, y.y);

	return x;
}

template<typename T>
LYAH_CONSTEXPR lyah::vec<3, T> lyah::max(vec<3, T> x, vec<3, T> y) {
	x.x = max(x.x, y.x);
	x.y = max(x.y, y.y);
	x.z = max(x.z, y.z);

	return x;
}

template<typename T>
LYAH_CONSTEXPR lyah::vec<4, T> lyah::max(vec<4, T> x, vec<4, T> y) {
	x.x = max(x.x, y.x);
	x.y = max(x.y, y.y);
	x.z = max(x.z, y.z);
	x.w = max(x.w, y.w);

	return x;
}

template<typename T>
LYAH_CONSTEXPR T lyah::clamp(T x, T _min, T _max) {
	return min(max(x, _min), _max);
}

template<typename T, typename>
LYAH_CONSTEXPR T lyah::lerp(T a, T b, T t) {
	return a * (static_cast<T>(1) - t) + b * t;
}

template<std::size_t C, typename T, typename>
LYAH_CONSTEXPR lyah::vec<C, T> lyah::lerp(vec<C, T> a, vec<C, T> b, T t) {
	return a * (static_cast<T>(1) - t) + b * t;
}

template<std::size_t C, typename T, typename>
LYAH_CONSTEXPR lyah::vec<C, T> lyah::lerp(vec<C, T> a, vec<C, T> b, vec<C, T> t) {
	return a * (vec<C, T>(static_cast<T>(1)) - t) + b * t;
}