// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace lyah {
	/// Returns `x` * `y` + `z`.
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 std::float_t LYAH_CALL fma(std::float_t x, std::float_t y, std::float_t z);
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 std::double_t LYAH_CALL fma(std::double_t x, std::double_t y, std::double_t z);

	/// Returns `x` * `y` + `z` component-wise.
	template<typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 vec<2, T> LYAH_CALL fma(vec<2, T> x, vec<2, T> y, vec<2, T> z);

	/// Returns `x` * `y` + `z` component-wise.
	template<typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 vec<3, T> LYAH_CALL fma(vec<3, T> x, vec<3, T> y, vec<3, T> z);

	/// Returns `x` * `y` + `z` component-wise.
	template<typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 vec<4, T> LYAH_CALL fma(vec<4, T> x, vec<4, T> y, vec<4, T> z);

	/// Returns the component-wise sum of `x`.
	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL sum(vec<2, T> x);

	/// Returns the component-wise sum of `x`.
	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL sum(vec<3, T> x);

	/// Returns the component-wise sum of `x`.
	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL sum(vec<4, T> x);

	/// Returns the absolute value of `x`.
	template<typename T, typename = std::enable_if<std::is_floating_point<T>::value || std::is_signed<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL abs(T x);

	/// Returns the component-wise absolute value of `x`.
	template<std::size_t C, typename T, typename = std::enable_if<std::is_floating_point<T>::value || std::is_signed<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<C, T> LYAH_CALL abs(vec<C, T> x);

	/// Returns the minimum value between `x` and `y`.
	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL min(T x, T y);

	/// Returns the component-wise minimum value between `x` and `y`.
	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<C, T> LYAH_CALL min(vec<C, T> x, vec<C, T> y);

	/// Returns the maximum value between `x` and `y`.
	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL max(T x, T y);

	/// Returns the component-wise maximum value between `x` and `y`.
	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<C, T> LYAH_CALL max(vec<C, T> x, vec<C, T> y);

	/// Returns `x` clamped between `min` and `max`.
	/// `max` must be >= `min`.
	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL clamp(T x, T min, T max);

	/// Returns the linear interpolation of `t` between `a` and `b`.
	template<typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL lerp(T a, T b, T t);

	/// Returns the linear interpolation of `t` between `a` and `b`.
	template<std::size_t C, typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<C, T> LYAH_CALL lerp(vec<C, T> a, vec<C, T> b, T t);

	/// Returns the linear interpolation of `t` between `a` and `b`.
	/// `t` is applied component-wise.
	template<std::size_t C, typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<C, T> LYAH_CALL lerp(vec<C, T> a, vec<C, T> b, vec<C, T> t);
}