// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

#include "lyah/common.hpp"
#include "lyah/exponential.hpp"
#include "lyah/geometric.hpp"
#include "lyah/limits.hpp"
#include "lyah/trigonometric.hpp"

namespace lyah {
	#define VEC2(T) \
		template<> \
		struct vec<2, T> { \
			LYAH_INLINE LYAH_CONSTEXPR vec(); \
			\
			LYAH_INLINE LYAH_CONSTEXPR vec(T x, T y); \
			\
			LYAH_INLINE LYAH_CONSTEXPR explicit vec(T a); \
			\
			template<typename U> \
			LYAH_INLINE LYAH_CONSTEXPR explicit vec(vec<2, U> a); \
			\
			LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL operator[](std::size_t index) const; \
			\
			LYAH_NODISCARD LYAH_INLINE T& LYAH_CALL operator[](std::size_t index); \
			\
			T x; \
			T y; \
		};

	VEC2(std::float_t);
	VEC2(std::double_t);
	VEC2(std::int32_t);
	VEC2(std::int64_t);

	#undef VEC2
}

#include "lyah/vec/vec2_float.ipp"
#include "lyah/vec/vec2_double.ipp"
#include "lyah/vec/vec2_int32.ipp"
#include "lyah/vec/vec2_int64.ipp"
#include "lyah/vec/vec2.ipp"