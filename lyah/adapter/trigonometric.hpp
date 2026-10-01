// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace lyah {
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR std::float_t LYAH_CALL degrees(std::float_t radians);
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR std::double_t LYAH_CALL degrees(std::double_t radians);

	template<std::size_t C>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<C, std::float_t> LYAH_CALL degrees(vec<C, std::float_t> radians);

	template<std::size_t C>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<C, std::double_t> LYAH_CALL degrees(vec<C, std::double_t> radians);

	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR std::float_t LYAH_CALL radians(std::float_t degrees);
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR std::double_t LYAH_CALL radians(std::double_t degrees);

	template<std::size_t C>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<C, std::float_t> LYAH_CALL radians(vec<C, std::float_t> degrees);

	template<std::size_t C>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<C, std::double_t> LYAH_CALL radians(vec<C, std::double_t> degrees);

	LYAH_NODISCARD LYAH_CONSTEXPR_CPP26 LYAH_INLINE std::float_t LYAH_CALL sin(std::float_t a);
	LYAH_NODISCARD LYAH_CONSTEXPR_CPP26 LYAH_INLINE std::double_t LYAH_CALL sin(std::double_t a);

	LYAH_NODISCARD LYAH_CONSTEXPR_CPP26 LYAH_INLINE std::float_t LYAH_CALL cos(std::float_t a);
	LYAH_NODISCARD LYAH_CONSTEXPR_CPP26 LYAH_INLINE std::double_t LYAH_CALL cos(std::double_t a);

	LYAH_NODISCARD LYAH_CONSTEXPR_CPP26 LYAH_INLINE std::float_t LYAH_CALL tan(std::float_t a);
	LYAH_NODISCARD LYAH_CONSTEXPR_CPP26 LYAH_INLINE std::double_t LYAH_CALL tan(std::double_t a);
}