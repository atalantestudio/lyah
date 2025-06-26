// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

#pragma once

#include "base.hpp"

namespace lyah {
	LYAH_NODISCARD LYAH_CONSTEXPR_CPP26 LYAH_INLINE std::double_t LYAH_CALL pow(std::double_t a, std::double_t e) {
		return std::powl(a, e);
	}

	LYAH_NODISCARD LYAH_CONSTEXPR_CPP26 LYAH_INLINE std::float_t LYAH_CALL pow(std::float_t a, std::float_t e) {
		return std::powf(a, e);
	}

	template<typename T>
	LYAH_NODISCARD LYAH_CONSTEXPR LYAH_INLINE T LYAH_CALL rcp(T a) {
		return static_cast<T>(1) / a;
	}

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE vec<C, T> LYAH_CALL rcp(vec<C, T> a) {
		return static_cast<T>(1) / a;
	}

	LYAH_NODISCARD LYAH_CONSTEXPR_CPP26 LYAH_INLINE std::float_t LYAH_CALL sqrt(std::float_t a) {
		return std::sqrtf(a);
	}

	LYAH_NODISCARD LYAH_CONSTEXPR_CPP26 LYAH_INLINE std::double_t LYAH_CALL sqrt(std::double_t a) {
		return std::sqrtl(a);
	}

	template<typename T>
	LYAH_NODISCARD LYAH_CONSTEXPR LYAH_INLINE T LYAH_CALL rsqrt(T a) {
		return rcp(sqrt(a));
	}

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE vec<C, T> LYAH_CALL rsqrt(vec<C, T> a) {
		return rcp(sqrt(a));
	}
}

#include "vec/m128/exponential.ipp"
#include "vec/m128d/exponential.ipp"
#include "vec/m256d/exponential.ipp"