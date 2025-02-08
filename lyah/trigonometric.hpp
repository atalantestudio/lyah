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

	using std::sin;

	using std::cos;

	using std::tan;
}

#include "vec/m128/trigonometric.inl"
#include "vec/m128d/trigonometric.inl"
#include "vec/m256d/trigonometric.inl"