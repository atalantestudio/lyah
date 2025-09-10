// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

#pragma once

#include "base.hpp"

namespace lyah {
	// Returns the signed parallelogram area formed by a and b.
	template<typename T>
	LYAH_NODISCARD LYAH_INLINE T LYAH_CALL area(vec<2, T> a, vec<2, T> b) {
		return a[0] * b[1] - a[1] * b[0];
	}

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE T LYAH_CALL dot(vec<C, T> a, vec<C, T> b) {
		return sum(a * b);
	}

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE T LYAH_CALL length(vec<C, T> a) {
		return sqrt(lengthSquared(a));
	}

	// Returns the squared length of a.
	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE T LYAH_CALL lengthSquared(vec<C, T> a) {
		return dot(a, a);
	}

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE T LYAH_CALL distance(vec<C, T> a, vec<C, T> b) {
		return length(b - a);
	}

	// Returns the squared distance between a and b.
	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE T LYAH_CALL distanceSquared(vec<C, T> a, vec<C, T> b) {
		return lengthSquared(b - a);
	}

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE vec<C, T> LYAH_CALL normalized(vec<C, T> a) {
		return a / length(a);
	}
}

#include "vec/m128/geometric.ipp"
#include "vec/m256d/geometric.ipp"