// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

#pragma once

#include "base.hpp"

namespace lyah {
	template<typename T>
	LYAH_NODISCARD LYAH_CONSTEXPR LYAH_INLINE T LYAH_CALL degrees(T a) {
		return a * static_cast<T>(57.295779513082321);
	}

	template<std::size_t C, typename T>
	LYAH_INLINE vec<C, T> LYAH_CALL degrees(vec<C, T> a) {
		return a * static_cast<T>(57.295779513082321);
	}

	template<typename T>
	LYAH_NODISCARD LYAH_CONSTEXPR LYAH_INLINE T LYAH_CALL radians(T a) {
		return a * static_cast<T>(0.017453292519943);
	}

	template<std::size_t C, typename T>
	LYAH_INLINE vec<C, T> LYAH_CALL radians(vec<C, T> a) {
		return a * static_cast<T>(0.017453292519943);
	}

	LYAH_NODISCARD LYAH_INLINE std::float_t LYAH_CALL sin(std::float_t a) {
		return std::sinf(a);
	}

	LYAH_NODISCARD LYAH_INLINE std::double_t LYAH_CALL sin(std::double_t a) {
		return std::sinl(a);
	}

	LYAH_NODISCARD LYAH_INLINE std::float_t LYAH_CALL cos(std::float_t a) {
		return std::cosf(a);
	}

	LYAH_NODISCARD LYAH_INLINE std::double_t LYAH_CALL cos(std::double_t a) {
		return std::cosl(a);
	}

	LYAH_NODISCARD LYAH_INLINE std::float_t LYAH_CALL tan(std::float_t a) {
		return std::tanf(a);
	}

	LYAH_NODISCARD LYAH_INLINE std::double_t LYAH_CALL tan(std::double_t a) {
		return std::tanl(a);
	}
}

#include "vec/m128/trigonometric.ipp"
#include "vec/m128d/trigonometric.ipp"
#include "vec/m256d/trigonometric.ipp"