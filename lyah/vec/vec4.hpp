// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace lyah {
	#define VEC4(T) \
		template<> \
		struct vec<4, T> { \
			LYAH_INLINE LYAH_CONSTEXPR vec(); \
			\
			LYAH_INLINE LYAH_CONSTEXPR vec(T x, T y, T z, T w); \
			\
			LYAH_INLINE LYAH_CONSTEXPR explicit vec(T a); \
			\
			template<typename U> \
			LYAH_INLINE LYAH_CONSTEXPR explicit vec(vec<4, U> a); \
			\
			LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL operator[](std::size_t index) const; \
			\
			LYAH_NODISCARD LYAH_INLINE T& LYAH_CALL operator[](std::size_t index); \
			\
			T x; \
			T y; \
			T z; \
			T w; \
		};

	VEC4(std::float_t);
	VEC4(std::double_t);
	VEC4(std::int32_t);
	VEC4(std::int64_t);

	#undef VEC4
}

#include "lyah/vec/vec4_float.ipp"
#include "lyah/vec/vec4_double.ipp"
#include "lyah/vec/vec4_int32.ipp"
#include "lyah/vec/vec4_int64.ipp"
#include "lyah/vec/vec4.ipp"