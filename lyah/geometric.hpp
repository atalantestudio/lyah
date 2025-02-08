// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

#pragma once

#include "base.hpp"

namespace lyah {
	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE T LYAH_CALL dot(vec<C, T> a, vec<C, T> b) {
		return sum(a * b);
	}

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE T LYAH_CALL length(vec<C, T> a) {
		return sqrt(dot(a, a));
	}

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE T LYAH_CALL distance(vec<C, T> a, vec<C, T> b) {
		return length(b - a);
	}

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE vec<C, T> LYAH_CALL normalized(vec<C, T> a) {
		return a / length(a);
	}
}