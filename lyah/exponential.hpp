// Copyright 2025 Atalante Studio.
// Distributed under the MIT License.

#pragma once

#include "base.hpp"

namespace lyah {
	LYAH_NODISCARD LYAH_CONSTEXPR_CPP26 LYAH_INLINE std::float_t LYAH_CALL log2(std::float_t a) {
		return std::log2f(a);
	}

	LYAH_NODISCARD LYAH_CONSTEXPR_CPP26 LYAH_INLINE std::double_t LYAH_CALL log2(std::double_t a) {
		return std::log2l(a);
	}

	LYAH_NODISCARD LYAH_CONSTEXPR_CPP26 LYAH_INLINE std::float_t LYAH_CALL pow(std::float_t a, std::float_t e) {
		return std::powf(a, e);
	}

	LYAH_NODISCARD LYAH_CONSTEXPR_CPP26 LYAH_INLINE std::double_t LYAH_CALL pow(std::double_t a, std::double_t e) {
		return std::powl(a, e);
	}

	LYAH_NODISCARD LYAH_CONSTEXPR_CPP26 LYAH_INLINE std::float_t LYAH_CALL sqrt(std::float_t a) {
		return std::sqrtf(a);
	}

	LYAH_NODISCARD LYAH_CONSTEXPR_CPP26 LYAH_INLINE std::double_t LYAH_CALL sqrt(std::double_t a) {
		return std::sqrtl(a);
	}
}