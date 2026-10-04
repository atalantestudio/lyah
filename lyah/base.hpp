// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <limits>

#define LYAH_ASSERT assert
#define LYAH_STATIC_ASSERT static_assert

#define LYAH_COMPILER_CLANG 1
#define LYAH_COMPILER_GCC 2
#define LYAH_COMPILER_MSVC 3

#define LYAH_STANDARD_CPP11 201103l
#define LYAH_STANDARD_CPP14 201402l
#define LYAH_STANDARD_CPP17 201703l
#define LYAH_STANDARD_CPP20 202002l
#define LYAH_STANDARD_CPP23 202302l
#define LYAH_STANDARD_CPP26 202603l

#if defined(__clang__)
	#define LYAH_COMPILER LYAH_COMPILER_CLANG
	#define LYAH_STANDARD __cplusplus
#elif defined(__GNUC__)
	#define LYAH_COMPILER LYAH_COMPILER_GCC
	#define LYAH_STANDARD __cplusplus
#elif defined(_MSC_VER)
	#define LYAH_COMPILER LYAH_COMPILER_MSVC
	#define LYAH_STANDARD _MSVC_LANG
#else
	#define LYAH_COMPILER
	#define LYAH_STANDARD __cplusplus
#endif

#if LYAH_STANDARD < LYAH_STANDARD_CPP11
	#error Language standards below C++11 are not supported.
#endif

#if LYAH_COMPILER == LYAH_COMPILER_CLANG
	#define LYAH_INLINE inline
#elif LYAH_COMPILER == LYAH_COMPILER_GCC
	#define LYAH_INLINE __attribute__((always_inline)) inline
#elif LYAH_COMPILER == LYAH_COMPILER_MSVC
	#define LYAH_INLINE __forceinline
#else
	#define LYAH_INLINE inline
#endif

#define LYAH_CONSTEXPR constexpr

#if LYAH_STANDARD >= LYAH_STANDARD_CPP17
	#define LYAH_NODISCARD [[nodiscard]]
#else
	#define LYAH_NODISCARD
#endif

#if LYAH_STANDARD >= LYAH_STANDARD_CPP14
	#define LYAH_CONSTEXPR_CPP14 constexpr
#else
	#define LYAH_CONSTEXPR_CPP14
#endif

#if LYAH_STANDARD >= LYAH_STANDARD_CPP23
	#define LYAH_CONSTEXPR_CPP23 constexpr
#else
	#define LYAH_CONSTEXPR_CPP23
#endif

#if LYAH_STANDARD >= LYAH_STANDARD_CPP26
	#define LYAH_CONSTEXPR_CPP26 constexpr
#else
	#define LYAH_CONSTEXPR_CPP26
#endif

#define LYAH_CALL