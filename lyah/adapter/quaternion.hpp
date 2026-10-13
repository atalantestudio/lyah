// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace lyah {
	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR bool LYAH_CALL operator==(quat<T> a, quat<T> b);

	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR bool LYAH_CALL operator!=(quat<T> a, quat<T> b);

	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR quat<T> LYAH_CALL operator+(quat<T> a);

	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR quat<T> LYAH_CALL operator-(quat<T> a);

	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR quat<T> LYAH_CALL operator+(quat<T> a, quat<T> b);

	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_INLINE quat<T>& LYAH_CALL operator+=(quat<T>& a, quat<T> b);

	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR quat<T> LYAH_CALL operator-(quat<T> a, quat<T> b);

	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_INLINE quat<T>& LYAH_CALL operator-=(quat<T>& a, quat<T> b);

	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR quat<T> LYAH_CALL operator*(quat<T> a, T b);

	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR quat<T> LYAH_CALL operator*(T a, quat<T> b);

	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_INLINE quat<T>& LYAH_CALL operator*=(quat<T>& a, T b);

	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR quat<T> LYAH_CALL operator*(quat<T> a, quat<T> b);

	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_INLINE quat<T>& LYAH_CALL operator*=(quat<T>& a, quat<T> b);

	/// Returns the product of `a` and `b`.
	/// `b` is assumed to be normalized.
	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<3, T> LYAH_CALL operator*(vec<3, T> a, quat<T> b);

	/// Sets `a` to the product of `a` and `b`, then returns `a`.
	/// `b` is assumed to be normalized.
	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_INLINE vec<3, T>& LYAH_CALL operator*=(vec<3, T>& a, quat<T> b);

	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR quat<T> LYAH_CALL operator/(quat<T> a, T b);

	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_INLINE quat<T>& LYAH_CALL operator/=(quat<T>& a, T b);

	/// Returns the conjugate of `a`.
	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR quat<T> LYAH_CALL conjugate(quat<T> a);

	/// Returns the inverse of `a`.
	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR quat<T> LYAH_CALL inverse(quat<T> a);

	/// Returns the dot product of `a` and `b`.
	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL dot(quat<T> a, quat<T> b);

	/// Returns the length of `a`.
	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 T LYAH_CALL length(quat<T> a);

	/// Returns the squared length of `a`.
	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL lengthSquared(quat<T> a);

	/// Returns the distance between `a` and `b`.
	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 T LYAH_CALL distance(quat<T> a, quat<T> b);

	/// Returns the squared distance between `a` and `b`.
	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL distanceSquared(quat<T> a, quat<T> b);

	/// Returns the normalization of `a`.
	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 quat<T> LYAH_CALL normalized(quat<T> a);
}