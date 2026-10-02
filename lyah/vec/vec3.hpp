// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace lyah {
	#define VEC3(T) \
		template<> \
		struct vec<3, T> { \
			LYAH_INLINE LYAH_CONSTEXPR vec(); \
			\
			LYAH_INLINE LYAH_CONSTEXPR vec(T x, T y, T z); \
			\
			LYAH_INLINE LYAH_CONSTEXPR explicit vec(T a); \
			\
			template<typename U> \
			LYAH_INLINE LYAH_CONSTEXPR explicit vec(vec<3, U> a); \
			\
			LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL operator[](std::size_t index) const; \
			\
			LYAH_NODISCARD LYAH_INLINE T& LYAH_CALL operator[](std::size_t index); \
			\
			T x; \
			T y; \
			T z; \
		};

	VEC3(std::float_t);
	VEC3(std::double_t);
	VEC3(std::int32_t);
	VEC3(std::int64_t);

	#undef VEC3
}

#include "lyah/vec/vec3_float.ipp"
#include "lyah/vec/vec3_double.ipp"
#include "lyah/vec/vec3_int32.ipp"
#include "lyah/vec/vec3_int64.ipp"
#include "lyah/vec/vec3.ipp"