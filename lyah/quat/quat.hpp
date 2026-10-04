// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

#include "lyah/base.hpp"

template<typename T>
struct lyah::quat {
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR static quat<T> LYAH_CALL identity();

	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 static quat<T> LYAH_CALL axisAngle(vec<3, T> axis, T angle);

	LYAH_INLINE LYAH_CONSTEXPR quat();

	LYAH_INLINE LYAH_CONSTEXPR quat(T w, T x, T y, T z);

	template<typename U>
	LYAH_INLINE LYAH_CONSTEXPR explicit quat(quat<U> a);

	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL operator[](std::size_t index) const;

	LYAH_NODISCARD LYAH_INLINE T& LYAH_CALL operator[](std::size_t index);

	T w;
	T x;
	T y;
	T z;
};

template struct lyah::quat<std::float_t>;
template struct lyah::quat<std::double_t>;

#include "lyah/quat/quat.ipp"