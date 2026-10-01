// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

#include "lyah/base.hpp"

namespace lyah {
	#define QUAT(T) \
		template<> \
		struct quat<T> { \
			LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR static quat<T> LYAH_CALL identity(); \
			\
			/* TODO: Make constexpr. */ \
			LYAH_NODISCARD LYAH_INLINE /*LYAH_CONSTEXPR*/ static quat<T> LYAH_CALL axisAngle(vec<3, T> axis, T angle); \
			\
			LYAH_INLINE LYAH_CONSTEXPR quat(); \
			\
			LYAH_INLINE LYAH_CONSTEXPR quat(T w, T x, T y, T z); \
			\
			template<typename U> \
			LYAH_INLINE LYAH_CONSTEXPR explicit quat(quat<U> a); \
			\
			LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL operator[](std::size_t index) const LYAH_NOEXCEPT; \
			\
			LYAH_NODISCARD LYAH_INLINE T& LYAH_CALL operator[](std::size_t index) LYAH_NOEXCEPT; \
			\
			T w; \
			T x; \
			T y; \
			T z; \
		};

	QUAT(std::float_t);
	QUAT(std::double_t);

	#undef QUAT
}

#include "lyah/quat/quat_float.ipp"
#include "lyah/quat/quat_double.ipp"
#include "lyah/quat/quat.ipp"