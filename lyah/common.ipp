// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

namespace lyah {
	LYAH_CONSTEXPR std::float_t abs(std::float_t x) {
		return x > 0.0f ? x : -x;
	}

	LYAH_CONSTEXPR std::double_t abs(std::double_t x) {
		return x > 0.0 ? x : -x;
	}

	LYAH_CONSTEXPR std::int32_t abs(std::int32_t x) {
		return x > 0 ? x : -x;
	}

	LYAH_CONSTEXPR std::int64_t abs(std::int64_t x) {
		return x > 0 ? x : -x;
	}

	template<typename T, typename>
	LYAH_CONSTEXPR vec<2, T> abs(vec<2, T> x) {
		x.x = abs(x.x);
		x.y = abs(x.y);

		return x;
	}

	template<typename T, typename>
	LYAH_CONSTEXPR vec<3, T> abs(vec<3, T> x) {
		x.x = abs(x.x);
		x.y = abs(x.y);
		x.z = abs(x.z);

		return x;
	}

	template<typename T, typename>
	LYAH_CONSTEXPR vec<4, T> abs(vec<4, T> x) {
		x.x = abs(x.x);
		x.y = abs(x.y);
		x.z = abs(x.z);
		x.w = abs(x.w);

		return x;
	}

	LYAH_CONSTEXPR_CPP23 std::float_t fma(std::float_t a, std::float_t b, std::float_t c) {
		return std::fmaf(a, b, c);
	}

	LYAH_CONSTEXPR_CPP23 std::double_t fma(std::double_t a, std::double_t b, std::double_t c) {
		return std::fmal(a, b, c);
	}

	LYAH_CONSTEXPR_CPP23 vec<2, std::float_t> fma(vec<2, std::float_t> a, vec<2, std::float_t> b, vec<2, std::float_t> c) {
		a.x = fma(a.x, b.x, c.x);
		a.y = fma(a.y, b.y, c.y);

		return a;
	}

	LYAH_CONSTEXPR_CPP23 vec<2, std::double_t> fma(vec<2, std::double_t> a, vec<2, std::double_t> b, vec<2, std::double_t> c) {
		a.x = fma(a.x, b.x, c.x);
		a.y = fma(a.y, b.y, c.y);

		return a;
	}

	LYAH_CONSTEXPR_CPP23 vec<3, std::float_t> fma(vec<3, std::float_t> a, vec<3, std::float_t> b, vec<3, std::float_t> c) {
		a.x = fma(a.x, b.x, c.x);
		a.y = fma(a.y, b.y, c.y);
		a.z = fma(a.z, b.z, c.z);

		return a;
	}

	LYAH_CONSTEXPR_CPP23 vec<3, std::double_t> fma(vec<3, std::double_t> a, vec<3, std::double_t> b, vec<3, std::double_t> c) {
		a.x = fma(a.x, b.x, c.x);
		a.y = fma(a.y, b.y, c.y);
		a.z = fma(a.z, b.z, c.z);

		return a;
	}

	LYAH_CONSTEXPR_CPP23 vec<4, std::float_t> fma(vec<4, std::float_t> a, vec<4, std::float_t> b, vec<4, std::float_t> c) {
		a.x = fma(a.x, b.x, c.x);
		a.y = fma(a.y, b.y, c.y);
		a.z = fma(a.z, b.z, c.z);
		a.w = fma(a.w, b.w, c.w);

		return a;
	}

	LYAH_CONSTEXPR_CPP23 vec<4, std::double_t> fma(vec<4, std::double_t> a, vec<4, std::double_t> b, vec<4, std::double_t> c) {
		a.x = fma(a.x, b.x, c.x);
		a.y = fma(a.y, b.y, c.y);
		a.z = fma(a.z, b.z, c.z);
		a.w = fma(a.w, b.w, c.w);

		return a;
	}

	template<typename T>
	LYAH_CONSTEXPR T min(T x, T y) {
		return x >= y ? y : x;
	}

	template<typename T>
	LYAH_CONSTEXPR vec<2, T> min(vec<2, T> x, vec<2, T> y) {
		x.x = min(x.x, y.x);
		x.y = min(x.y, y.y);

		return x;
	}

	template<typename T>
	LYAH_CONSTEXPR vec<3, T> min(vec<3, T> x, vec<3, T> y) {
		x.x = min(x.x, y.x);
		x.y = min(x.y, y.y);
		x.z = min(x.z, y.z);

		return x;
	}

	template<typename T>
	LYAH_CONSTEXPR vec<4, T> min(vec<4, T> x, vec<4, T> y) {
		x.x = min(x.x, y.x);
		x.y = min(x.y, y.y);
		x.z = min(x.z, y.z);
		x.w = min(x.w, y.w);

		return x;
	}

	template<typename T>
	LYAH_CONSTEXPR T max(T x, T y) {
		return x <= y ? y : x;
	}

	template<typename T>
	LYAH_CONSTEXPR vec<2, T> max(vec<2, T> x, vec<2, T> y) {
		x.x = max(x.x, y.x);
		x.y = max(x.y, y.y);

		return x;
	}

	template<typename T>
	LYAH_CONSTEXPR vec<3, T> max(vec<3, T> x, vec<3, T> y) {
		x.x = max(x.x, y.x);
		x.y = max(x.y, y.y);
		x.z = max(x.z, y.z);

		return x;
	}

	template<typename T>
	LYAH_CONSTEXPR vec<4, T> max(vec<4, T> x, vec<4, T> y) {
		x.x = max(x.x, y.x);
		x.y = max(x.y, y.y);
		x.z = max(x.z, y.z);
		x.w = max(x.w, y.w);

		return x;
	}

	template<typename T>
	LYAH_CONSTEXPR T clamp(T x, T _min, T _max) {
		return min(max(x, _min), _max);
	}

	template<typename T, typename>
	LYAH_CONSTEXPR T lerp(T a, T b, T t) {
		return a * (static_cast<T>(1) - t) + b * t;
	}

	template<std::size_t C, typename T, typename>
	LYAH_CONSTEXPR vec<C, T> lerp(vec<C, T> a, vec<C, T> b, T t) {
		return a * (static_cast<T>(1) - t) + b * t;
	}

	template<std::size_t C, typename T, typename>
	LYAH_CONSTEXPR vec<C, T> lerp(vec<C, T> a, vec<C, T> b, vec<C, T> t) {
		return a * (vec<C, T>(static_cast<T>(1)) - t) + b * t;
	}
}