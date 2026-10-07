// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace lyah {
	/// Returns the base 2 logarithm of `x`.
	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 T LYAH_CALL log2(T x);

	/// Returns `x` raised to the power `y`.
	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 T LYAH_CALL pow(T x, T y);

	/// Returns `x` raised to the power `y`.
	template<std::size_t C, typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 vec<C, T> LYAH_CALL pow(vec<C, T> x, T y);

	/// Returns `x` raised to the power `y`.
	/// `y` is applied component-wise.
	template<std::size_t C, typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 vec<C, T> LYAH_CALL pow(vec<C, T> x, vec<C, T> y);

	/// Returns the square root of `x`.
	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 T LYAH_CALL sqrt(T x);

	/// Returns the component-wise square root of `x`.
	template<std::size_t C, typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 vec<C, T> LYAH_CALL sqrt(vec<C, T> x);
}