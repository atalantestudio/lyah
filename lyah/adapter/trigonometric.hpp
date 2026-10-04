// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace lyah {
	/// Returns the conversion of `radians` to degrees.
	template<typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL degrees(T radians);

	/// Returns the conversion of `radians` to degrees.
	template<std::size_t C, typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<C, T> LYAH_CALL degrees(vec<C, T> radians);

	/// Returns the conversion of `degrees` to radians.
	template<typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL radians(T degrees);

	/// Returns the conversion of `degrees` to radians.
	template<std::size_t C, typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<C, T> LYAH_CALL radians(vec<C, T> degrees);

	/// Returns the sine of `x`.
	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 T LYAH_CALL sin(T x);

	/// Returns the component-wise sine of `x`.
	template<std::size_t C, typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 vec<C, T> LYAH_CALL sin(vec<C, T> x);

	/// Returns the cosine of `x`.
	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 T LYAH_CALL cos(T x);

	/// Returns the component-wise cosine of `x`.
	template<std::size_t C, typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 vec<C, T> LYAH_CALL cos(vec<C, T> x);

	/// Returns the tangent of `x`.
	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 T LYAH_CALL tan(T x);

	/// Returns the component-wise tangent of `x`.
	template<std::size_t C, typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 vec<C, T> LYAH_CALL tan(vec<C, T> x);

	/// Returns the arcsine of `x`.
	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 T LYAH_CALL asin(T x);

	/// Returns the component-wise arcsine of `x`.
	template<std::size_t C, typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 vec<C, T> LYAH_CALL asin(vec<C, T> x);

	/// Returns the arccosine of `x`.
	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 T LYAH_CALL acos(T x);

	/// Returns the component-wise arccosine of `x`.
	template<std::size_t C, typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 vec<C, T> LYAH_CALL acos(vec<C, T> x);

	/// Returns the arctangent of `x`.
	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 T LYAH_CALL atan(T x);

	/// Returns the component-wise arctangent of `x`.
	template<std::size_t C, typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 vec<C, T> LYAH_CALL atan(vec<C, T> x);
}