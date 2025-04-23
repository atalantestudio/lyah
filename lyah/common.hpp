// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

#pragma once

#include "base.hpp"

namespace lyah {
	LYAH_NODISCARD LYAH_CONSTEXPR_CPP23 LYAH_INLINE std::float_t abs(std::float_t a) {
		return std::fabsf(a);
	}

	LYAH_NODISCARD LYAH_CONSTEXPR_CPP23 LYAH_INLINE std::double_t abs(std::double_t a) {
		return std::fabsl(a);
	}

	LYAH_NODISCARD LYAH_CONSTEXPR_CPP23 LYAH_INLINE std::int32_t abs(std::int32_t a) {
		return static_cast<std::int32_t>(std::fabs(a));
	}

	LYAH_NODISCARD LYAH_CONSTEXPR_CPP23 LYAH_INLINE std::int64_t abs(std::int64_t a) {
		return static_cast<std::int64_t>(std::fabs(a));
	}

	LYAH_NODISCARD LYAH_CONSTEXPR LYAH_INLINE std::float_t LYAH_CALL lerp(std::float_t a, std::float_t b, std::float_t t) {
		return a * (1.0f - t) + b * t;
	}

	LYAH_NODISCARD LYAH_CONSTEXPR LYAH_INLINE std::double_t LYAH_CALL lerp(std::double_t a, std::double_t b, std::double_t t) {
		return a * (1.0 - t) + b * t;
	}

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE vec<C, T> LYAH_CALL lerp(vec<C, T> a, vec<C, T> b, T t) {
		return a * (static_cast<T>(1) - t) + b * t;
	}

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE vec<C, T> LYAH_CALL lerp(vec<C, T> a, vec<C, T> b, vec<C, T> t) {
		return a * (vec<C, T>(static_cast<T>(1)) - t) + b * t;
	}
}

#include "vec/m128/common.ipp"
#include "vec/m128d/common.ipp"
#include "vec/m256d/common.ipp"