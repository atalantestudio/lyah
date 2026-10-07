// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace lyah {
	/// Returns the nearest integer below `x`.
	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 T LYAH_CALL floor(T x);

	/// Returns the nearest integer below `x` component-wise.
	template<std::size_t C, typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 vec<C, T> LYAH_CALL floor(vec<C, T> x);

	/// Returns the nearest integer above `x`.
	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 T LYAH_CALL ceil(T x);

	/// Returns the nearest integer above `x` component-wise.
	template<std::size_t C, typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 vec<C, T> LYAH_CALL ceil(vec<C, T> x);

	/// Returns the largest `y` multiple above `x`.
	/// `y` is assumed to be a power of 2.
	template<typename T, typename = typename std::enable_if<std::is_unsigned<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL ceilPowerOf2(T x, T y);

	/// Returns the nearest integer to `x`, rounded away from 0 in halfway cases.
	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 T LYAH_CALL round(T x);

	/// Returns the nearest integer to `x` component-wise, rounded away from 0 in halfway cases.
	template<std::size_t C, typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 vec<C, T> LYAH_CALL round(vec<C, T> x);
}