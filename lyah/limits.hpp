// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

#pragma once

#include "base.hpp"

namespace lyah {
	template<typename T>
	LYAH_NODISCARD LYAH_CONSTEXPR_CPP14 LYAH_INLINE T LYAH_CALL max(T a, T b) {
		return std::max(a, b);
	}

	template<typename T>
	LYAH_NODISCARD LYAH_CONSTEXPR_CPP14 LYAH_INLINE T LYAH_CALL min(T a, T b) {
		return std::min(a, b);
	}

	template<typename T>
	LYAH_NODISCARD LYAH_CONSTEXPR_CPP14 LYAH_INLINE T LYAH_CALL clamp(T a, T min, T max) {
		return lyah::min(lyah::max(a, min), max);
	}
}