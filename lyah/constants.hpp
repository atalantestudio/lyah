// Copyright 2025 Mattéo Legagneux.
// Licensed under the MIT License.

#pragma once

#include "base.hpp"

namespace lyah {
	template<typename T>
	LYAH_NODISCARD LYAH_CONSTEXPR LYAH_INLINE T epsilon() {
		return std::numeric_limits<T>::epsilon();
	}

	template<typename T>
	LYAH_NODISCARD LYAH_CONSTEXPR LYAH_INLINE T infinity() {
		LYAH_ASSERT(std::numeric_limits<T>::has_infinity);

		return std::numeric_limits<T>::infinity();
	}

	template<typename T>
	LYAH_NODISCARD LYAH_CONSTEXPR LYAH_INLINE T nan() {
		LYAH_ASSERT(std::numeric_limits<T>::has_quiet_NaN);

		return std::numeric_limits<T>::quiet_NaN();
	}

	template<typename T>
	LYAH_NODISCARD LYAH_CONSTEXPR LYAH_INLINE T pi() {
		return static_cast<T>(3.141592653589793);
	}
}