// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace lyah {
	/// Returns the base 2 logarithm of `x`.
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 std::float_t LYAH_CALL log2(std::float_t x);
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 std::double_t LYAH_CALL log2(std::double_t x);

	/// Returns `x` raised to the power `exponent`.
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 std::float_t LYAH_CALL pow(std::float_t x, std::float_t exponent);
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 std::double_t LYAH_CALL pow(std::double_t x, std::double_t exponent);

	/// Returns `x` raised to the power `exponent`.
	template<typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 vec<2, T> LYAH_CALL pow(vec<2, T> x, T exponent);

	/// Returns `x` raised to the power `exponent`.
	template<typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 vec<3, T> LYAH_CALL pow(vec<3, T> x, T exponent);

	/// Returns `x` raised to the power `exponent`.
	template<typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 vec<4, T> LYAH_CALL pow(vec<4, T> x, T exponent);

	/// Returns `x` raised to the power `exponent`.
	/// `exponent` is applied component-wise.
	template<typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 vec<2, T> LYAH_CALL pow(vec<2, T> x, vec<2, T> exponent);

	/// Returns `x` raised to the power `exponent`.
	/// `exponent` is applied component-wise.
	template<typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 vec<3, T> LYAH_CALL pow(vec<3, T> x, vec<3, T> exponent);

	/// Returns `x` raised to the power `exponent`.
	/// `exponent` is applied component-wise.
	template<typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 vec<4, T> LYAH_CALL pow(vec<4, T> x, vec<4, T> exponent);

	/// Returns the square root of `x`.
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 std::float_t LYAH_CALL sqrt(std::float_t x);
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 std::double_t LYAH_CALL sqrt(std::double_t x);

	/// Returns the component-wise square root of `x`.
	template<typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 vec<2, T> LYAH_CALL sqrt(vec<2, T> x);

	/// Returns the component-wise square root of `x`.
	template<typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 vec<3, T> LYAH_CALL sqrt(vec<3, T> x);

	/// Returns the component-wise square root of `x`.
	template<typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 vec<4, T> LYAH_CALL sqrt(vec<4, T> x);
}