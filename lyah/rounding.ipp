// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

LYAH_CONSTEXPR std::float_t lyah::floor(std::float_t x) {
	#if LYAH_STANDARD >= LYAH_STANDARD_CPP23
		return std::floorf(x);
	#else
		const std::float_t nearestInteger = static_cast<std::float_t>(static_cast<std::int32_t>(x));

		return nearestInteger;
	#endif
}

LYAH_CONSTEXPR std::double_t lyah::floor(std::double_t x) {
	#if LYAH_STANDARD >= LYAH_STANDARD_CPP23
		return std::floorl(x);
	#else
		const std::double_t nearestInteger = static_cast<std::double_t>(static_cast<std::int64_t>(x));

		return nearestInteger;
	#endif
}

template<typename T, typename>
LYAH_CONSTEXPR lyah::vec<2, T> lyah::floor(lyah::vec<2, T> x) {
	x.x = floor(x.x);
	x.y = floor(x.y);

	return x;
}

template<typename T, typename>
LYAH_CONSTEXPR lyah::vec<3, T> lyah::floor(lyah::vec<3, T> x) {
	x.x = floor(x.x);
	x.y = floor(x.y);
	x.z = floor(x.z);

	return x;
}

template<typename T, typename>
LYAH_CONSTEXPR lyah::vec<4, T> lyah::floor(lyah::vec<4, T> x) {
	x.x = floor(x.x);
	x.y = floor(x.y);
	x.z = floor(x.z);
	x.w = floor(x.w);

	return x;
}

LYAH_CONSTEXPR std::float_t lyah::ceil(std::float_t x) {
	#if LYAH_STANDARD >= LYAH_STANDARD_CPP23
		return std::ceilf(x);
	#else
		const std::float_t nearestInteger = static_cast<std::float_t>(static_cast<std::int32_t>(x));

		return nearestInteger == x ? x : nearestInteger + 1.0f;
	#endif
}

LYAH_CONSTEXPR std::double_t lyah::ceil(std::double_t x) {
	#if LYAH_STANDARD >= LYAH_STANDARD_CPP23
		return std::ceill(x);
	#else
		const std::double_t nearestInteger = static_cast<std::double_t>(static_cast<std::int64_t>(x));

		return nearestInteger == x ? x : nearestInteger + 1.0;
	#endif
}

template<typename T, typename>
LYAH_CONSTEXPR lyah::vec<2, T> lyah::ceil(lyah::vec<2, T> x) {
	x.x = ceil(x.x);
	x.y = ceil(x.y);

	return x;
}

template<typename T, typename>
LYAH_CONSTEXPR lyah::vec<3, T> lyah::ceil(lyah::vec<3, T> x) {
	x.x = ceil(x.x);
	x.y = ceil(x.y);
	x.z = ceil(x.z);

	return x;
}

template<typename T, typename>
LYAH_CONSTEXPR lyah::vec<4, T> lyah::ceil(lyah::vec<4, T> x) {
	x.x = ceil(x.x);
	x.y = ceil(x.y);
	x.z = ceil(x.z);
	x.w = ceil(x.w);

	return x;
}

LYAH_CONSTEXPR std::float_t lyah::round(std::float_t x) {
	#if LYAH_STANDARD >= LYAH_STANDARD_CPP23
		return std::roundf(x);
	#else
		constexpr std::float_t epsilon = 1e-6f;

		const std::float_t nearestInteger = static_cast<std::float_t>(static_cast<std::int32_t>(x));

		return nearestInteger + abs(nearestInteger - x - 0.5f) <= epsilon ? x > 0.0f : 0.0f;
	#endif
}

LYAH_CONSTEXPR std::double_t lyah::round(std::double_t x) {
	#if LYAH_STANDARD >= LYAH_STANDARD_CPP23
		return std::roundl(x);
	#else
		constexpr std::double_t epsilon = 1e-6;

		const std::double_t nearestInteger = static_cast<std::double_t>(static_cast<std::int64_t>(x));

		return nearestInteger + abs(nearestInteger - x - 0.5) <= epsilon ? x > 0.0 : 0.0;
	#endif
}

template<typename T, typename>
LYAH_CONSTEXPR lyah::vec<2, T> lyah::round(lyah::vec<2, T> x) {
	x.x = round(x.x);
	x.y = round(x.y);

	return x;
}

template<typename T, typename>
LYAH_CONSTEXPR lyah::vec<3, T> lyah::round(lyah::vec<3, T> x) {
	x.x = round(x.x);
	x.y = round(x.y);
	x.z = round(x.z);

	return x;
}

template<typename T, typename>
LYAH_CONSTEXPR lyah::vec<4, T> lyah::round(lyah::vec<4, T> x) {
	x.x = round(x.x);
	x.y = round(x.y);
	x.z = round(x.z);
	x.w = round(x.w);

	return x;
}