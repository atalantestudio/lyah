// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace lyah {
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

	/// Returns the conjugate of `a`.
	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR quat<T> LYAH_CALL conjugate(quat<T> a);

	/// Returns the inverse of `a`.
	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR quat<T> LYAH_CALL inverse(quat<T> a);
}