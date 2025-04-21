// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

#pragma once

#include "base.hpp"

namespace lyah {
	using std::pow;

	template<typename T>
	LYAH_NODISCARD LYAH_CONSTEXPR LYAH_INLINE T LYAH_CALL rcp(T a) {
		return static_cast<T>(1) / a;
	}

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE vec<C, T> LYAH_CALL rcp(vec<C, T> a) {
		return static_cast<T>(1) / a;
	}

	using std::sqrt;

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