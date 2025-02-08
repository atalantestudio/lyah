// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

#pragma once

#include <cassert>
#include <cmath>
#include <immintrin.h>
#include <limits>

#define LYAH_ASSERT assert

#define LYAH_CALL __vectorcall

#define LYAH_COMPILER_CLANG	1
#define LYAH_COMPILER_GCC	2
#define LYAH_COMPILER_MSVC	3

#define LYAH_LANGUAGE_CPP11 201103L
#define LYAH_LANGUAGE_CPP14 201403L
#define LYAH_LANGUAGE_CPP17 201703L
#define LYAH_LANGUAGE_CPP20 202003L
#define LYAH_LANGUAGE_CPP23 202303L

#ifdef __clang__
	#define LYAH_COMPILER LYAH_COMPILER_CLANG
	#define LYAH_LANGUAGE _cplusplus
#elif __GNUC__
	#define LYAH_COMPILER LYAH_COMPILER_GCC
	#define LYAH_LANGUAGE _cplusplus
#elif _MSC_VER
	#define LYAH_COMPILER LYAH_COMPILER_MSVC
	#define LYAH_LANGUAGE _MSVC_LANG
#else
	#define LYAH_COMPILER
	#define LYAH_LANGUAGE _cplusplus
#endif

#if LYAH_COMPILER == LYAH_COMPILER_CLANG
	#define LYAH_INLINE __attribute__((always_inline))
#elif LYAH_COMPILER == LYAH_COMPILER_GCC
	#define LYAH_INLINE __attribute__((always_inline))
#elif LYAH_COMPILER == LYAH_COMPILER_MSVC
	#define LYAH_INLINE __forceinline
#else
	#define LYAH_INLINE inline
#endif

#if LYAH_LANGUAGE >= LYAH_LANGUAGE_CPP11
	#define LYAH_CONSTEXPR constexpr
#else
	#define LYAH_CONSTEXPR
#endif

#if LYAH_LANGUAGE >= LYAH_LANGUAGE_CPP11
	#define LYAH_NOEXCEPT noexcept
#else
	#define LYAH_NOEXCEPT
#endif

#if LYAH_LANGUAGE >= LYAH_LANGUAGE_CPP17
	#define LYAH_NODISCARD [[nodiscard]]
#else
	#define LYAH_NODISCARD
#endif