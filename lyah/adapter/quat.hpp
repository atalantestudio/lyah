// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

#include "lyah/adapter/base.hpp"

namespace lyah {
	/// A single floating point quaternion.
	template<>
	struct quat<std::float_t>;

	/// A double floating point quaternion.
	template<>
	struct quat<std::double_t>;

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR bool LYAH_CALL operator==(quat<T> a, quat<T> b);

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR bool LYAH_CALL operator!=(quat<T> a, quat<T> b);

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR quat<T> LYAH_CALL operator+(quat<T> a);

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR quat<T> LYAH_CALL operator-(quat<T> a);

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR quat<T> LYAH_CALL operator+(quat<T> a, quat<T> b);

	template<typename T>
	LYAH_INLINE quat<T>& LYAH_CALL operator+=(quat<T>& a, quat<T> b);

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR quat<T> LYAH_CALL operator-(quat<T> a, quat<T> b);

	template<typename T>
	LYAH_INLINE quat<T>& LYAH_CALL operator-=(quat<T>& a, quat<T> b);

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR quat<T> LYAH_CALL operator*(quat<T> a, T b);

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR quat<T> LYAH_CALL operator*(T a, quat<T> b);

	template<typename T>
	LYAH_INLINE quat<T>& LYAH_CALL operator*=(quat<T>& a, T b);

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR quat<T> LYAH_CALL operator*(quat<T> a, quat<T> b);

	template<typename T>
	LYAH_INLINE quat<T>& LYAH_CALL operator*=(quat<T>& a, quat<T> b);

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR quat<T> LYAH_CALL operator/(quat<T> a, T b);

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR quat<T> LYAH_CALL operator/(T a, quat<T> b);

	template<typename T>
	LYAH_INLINE quat<T>& LYAH_CALL operator/=(quat<T>& a, T b);

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR quat<T> LYAH_CALL operator/(quat<T> a, quat<T> b);

	template<typename T>
	LYAH_INLINE quat<T>& LYAH_CALL operator/=(quat<T>& a, quat<T> b);

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR quat<T> LYAH_CALL conjugate(quat<T> a);

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL dot(quat<T> a, quat<T> b);

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR quat<T> LYAH_CALL inverse(quat<T> a);

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL length(quat<T> a);

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL lengthSquared(quat<T> a);

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR quat<T> LYAH_CALL normalized(quat<T> a);
}