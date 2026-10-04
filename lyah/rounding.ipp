// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

template<>
LYAH_INLINE LYAH_CONSTEXPR std::float_t lyah::floor(std::float_t x) {
	#if LYAH_STANDARD >= LYAH_STANDARD_CPP23
		return std::floorf(x);
	#else
		const std::float_t nearestInteger = static_cast<std::float_t>(static_cast<std::int32_t>(x));

		return nearestInteger;
	#endif
}

template<>
LYAH_INLINE LYAH_CONSTEXPR std::double_t lyah::floor(std::double_t x) {
	#if LYAH_STANDARD >= LYAH_STANDARD_CPP23
		return std::floorl(x);
	#else
		const std::double_t nearestInteger = static_cast<std::double_t>(static_cast<std::int64_t>(x));

		return nearestInteger;
	#endif
}

template<std::size_t C, typename T, typename>
LYAH_CONSTEXPR lyah::vec<C, T> lyah::floor(vec<C, T> x) {
	return apply<C, T>::modifier(x, floor);
}

template<>
LYAH_INLINE LYAH_CONSTEXPR std::float_t lyah::ceil(std::float_t x) {
	#if LYAH_STANDARD >= LYAH_STANDARD_CPP23
		return std::ceilf(x);
	#else
		const std::float_t nearestInteger = static_cast<std::float_t>(static_cast<std::int32_t>(x));

		return nearestInteger == x ? x : nearestInteger + 1.0f;
	#endif
}

template<>
LYAH_INLINE LYAH_CONSTEXPR std::double_t lyah::ceil(std::double_t x) {
	#if LYAH_STANDARD >= LYAH_STANDARD_CPP23
		return std::ceill(x);
	#else
		const std::double_t nearestInteger = static_cast<std::double_t>(static_cast<std::int64_t>(x));

		return nearestInteger == x ? x : nearestInteger + 1.0;
	#endif
}

template<std::size_t C, typename T, typename>
LYAH_CONSTEXPR lyah::vec<C, T> lyah::ceil(vec<C, T> x) {
	return apply<C, T>::modifier(x, ceil);
}

template<>
LYAH_INLINE LYAH_CONSTEXPR std::float_t lyah::round(std::float_t x) {
	#if LYAH_STANDARD >= LYAH_STANDARD_CPP23
		return std::roundf(x);
	#else
		constexpr std::float_t epsilon = 1e-6f;

		const std::float_t nearestInteger = static_cast<std::float_t>(static_cast<std::int32_t>(x));

		return nearestInteger + abs(nearestInteger - x - 0.5f) <= epsilon ? x > 0.0f : 0.0f;
	#endif
}

template<>
LYAH_INLINE LYAH_CONSTEXPR std::double_t lyah::round(std::double_t x) {
	#if LYAH_STANDARD >= LYAH_STANDARD_CPP23
		return std::roundl(x);
	#else
		constexpr std::double_t epsilon = 1e-6;

		const std::double_t nearestInteger = static_cast<std::double_t>(static_cast<std::int64_t>(x));

		return nearestInteger + abs(nearestInteger - x - 0.5) <= epsilon ? x > 0.0 : 0.0;
	#endif
}

template<std::size_t C, typename T, typename>
LYAH_CONSTEXPR lyah::vec<C, T> lyah::round(vec<C, T> x) {
	return apply<C, T>::modifier(x, round);
}