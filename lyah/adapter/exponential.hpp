// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace lyah {
	/// Returns the base 2 logarithm of `a`.
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 std::float_t LYAH_CALL log2(std::float_t a);
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 std::double_t LYAH_CALL log2(std::double_t a);

	/// Returns `a` raised to the power `exponent`.
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 std::float_t LYAH_CALL pow(std::float_t a, std::float_t exponent);
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 std::double_t LYAH_CALL pow(std::double_t a, std::double_t exponent);

	/// Returns the square root of `a`.
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 std::float_t LYAH_CALL sqrt(std::float_t a);
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 std::double_t LYAH_CALL sqrt(std::double_t a);
}