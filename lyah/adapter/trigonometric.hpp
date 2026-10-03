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
	LYAH_NODISCARD LYAH_CONSTEXPR_CPP26 LYAH_INLINE std::float_t LYAH_CALL sin(std::float_t x);
	LYAH_NODISCARD LYAH_CONSTEXPR_CPP26 LYAH_INLINE std::double_t LYAH_CALL sin(std::double_t x);

	/// Returns the cosine of `x`.
	LYAH_NODISCARD LYAH_CONSTEXPR_CPP26 LYAH_INLINE std::float_t LYAH_CALL cos(std::float_t x);
	LYAH_NODISCARD LYAH_CONSTEXPR_CPP26 LYAH_INLINE std::double_t LYAH_CALL cos(std::double_t x);

	/// Returns the tangent of `x`.
	LYAH_NODISCARD LYAH_CONSTEXPR_CPP26 LYAH_INLINE std::float_t LYAH_CALL tan(std::float_t x);
	LYAH_NODISCARD LYAH_CONSTEXPR_CPP26 LYAH_INLINE std::double_t LYAH_CALL tan(std::double_t x);

	// TODO: Add asin/acos/atan.
}