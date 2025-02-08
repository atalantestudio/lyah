// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

#pragma once

#include "base.hpp"

namespace lyah {
	using std::abs;

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE vec<C, T> LYAH_CALL lerp(vec<C, T> a, vec<C, T> b, T t) {
		return a * (static_cast<T>(1) - t) + b * t;
	}
}

#include "vec/m128/common.inl"
#include "vec/m128d/common.inl"
#include "vec/m256d/common.inl"