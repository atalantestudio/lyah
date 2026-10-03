// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace lyah {
	/// Returns the nearest integer below `x`.
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR std::float_t LYAH_CALL floor(std::float_t x);
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR std::double_t LYAH_CALL floor(std::double_t x);

	/// Returns the nearest integer below `x` component-wise.
	template<typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<2, T> LYAH_CALL floor(vec<2, T> x);

	/// Returns the nearest integer below `x` component-wise.
	template<typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<3, T> LYAH_CALL floor(vec<3, T> x);

	/// Returns the nearest integer below `x` component-wise.
	template<typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<4, T> LYAH_CALL floor(vec<4, T> x);

	/// Returns the nearest integer above `x`.
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR std::float_t LYAH_CALL ceil(std::float_t x);
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR std::double_t LYAH_CALL ceil(std::double_t x);

	/// Returns the nearest integer above `x` component-wise.
	template<typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<2, T> LYAH_CALL ceil(vec<2, T> x);

	/// Returns the nearest integer above `x` component-wise.
	template<typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<3, T> LYAH_CALL ceil(vec<3, T> x);

	/// Returns the nearest integer above `x` component-wise.
	template<typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<4, T> LYAH_CALL ceil(vec<4, T> x);

	/// Returns the nearest integer to `x`, rounded away from 0 in halfway cases.
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR std::float_t LYAH_CALL round(std::float_t x);
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR std::double_t LYAH_CALL round(std::double_t x);

	/// Returns the nearest integer to `x` component-wise, rounded away from 0 in halfway cases.
	template<typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<2, T> LYAH_CALL round(vec<2, T> x);

	/// Returns the nearest integer to `x` component-wise, rounded away from 0 in halfway cases.
	template<typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<3, T> LYAH_CALL round(vec<3, T> x);

	/// Returns the nearest integer to `x` component-wise, rounded away from 0 in halfway cases.
	template<typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<4, T> LYAH_CALL round(vec<4, T> x);
}