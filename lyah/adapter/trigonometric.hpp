// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace lyah {
	template<typename T, typename = std::enable_if<std::is_floating_point<T>::value>>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL degrees(T radians);

	template<std::size_t C, typename T, typename = std::enable_if<std::is_floating_point<T>::value>>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<C, T> LYAH_CALL degrees(vec<C, T> radians);

	template<typename T, typename = std::enable_if<std::is_floating_point<T>::value>>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL radians(T degrees);

	template<std::size_t C, typename T, typename = std::enable_if<std::is_floating_point<T>::value>>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<C, T> LYAH_CALL radians(vec<C, T> degrees);

	LYAH_NODISCARD LYAH_CONSTEXPR_CPP26 LYAH_INLINE std::float_t LYAH_CALL sin(std::float_t a);
	LYAH_NODISCARD LYAH_CONSTEXPR_CPP26 LYAH_INLINE std::double_t LYAH_CALL sin(std::double_t a);

	LYAH_NODISCARD LYAH_CONSTEXPR_CPP26 LYAH_INLINE std::float_t LYAH_CALL cos(std::float_t a);
	LYAH_NODISCARD LYAH_CONSTEXPR_CPP26 LYAH_INLINE std::double_t LYAH_CALL cos(std::double_t a);

	LYAH_NODISCARD LYAH_CONSTEXPR_CPP26 LYAH_INLINE std::float_t LYAH_CALL tan(std::float_t a);
	LYAH_NODISCARD LYAH_CONSTEXPR_CPP26 LYAH_INLINE std::double_t LYAH_CALL tan(std::double_t a);
}