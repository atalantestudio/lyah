// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace lyah {
	/// Returns the signed area of the parallelogram formed by `b` and `b`.
	template<typename T, typename = std::enable_if<std::is_floating_point<T>::value>>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL parallelogramArea(vec<2, T> a, vec<2, T> b);

	/// Returns the perpendicular vector to the left of `a`.
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<2, std::float_t> LYAH_CALL perpendicularLeft(vec<2, std::float_t> a);
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<2, std::double_t> LYAH_CALL perpendicularLeft(vec<2, std::double_t> a);

	/// Returns the perpendicular vector to the right of `a`.
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<2, std::float_t> LYAH_CALL perpendicularRight(vec<2, std::float_t> a);
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<2, std::double_t> LYAH_CALL perpendicularRight(vec<2, std::double_t> a);

	/// Returns the cross product of `a` and `b`.
	template<typename T, typename = std::enable_if<std::is_floating_point<T>::value>>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 vec<3, T> LYAH_CALL cross(vec<3, T> a, vec<3, T> b);

	/// Returns the dot product of `a` and `b`.
	template<std::size_t C, typename T, typename = std::enable_if<std::is_floating_point<T>::value>>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL dot(vec<C, T> a, vec<C, T> b);

	/// Returns the dot product of `a` and `b`.
	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL dot(quat<T> a, quat<T> b);

	template<std::size_t C, typename T, typename = std::enable_if<std::is_floating_point<T>::value>>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 T LYAH_CALL length(vec<C, T> a);

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 T LYAH_CALL length(quat<T> a);

	template<std::size_t C, typename T, typename = std::enable_if<std::is_floating_point<T>::value>>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL lengthSquared(vec<C, T> a);

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL lengthSquared(quat<T> a);

	template<std::size_t C, typename T, typename = std::enable_if<std::is_floating_point<T>::value>>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 T LYAH_CALL distance(vec<C, T> a, vec<C, T> b);

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 T LYAH_CALL distance(quat<T> a, quat<T> b);

	template<std::size_t C, typename T, typename = std::enable_if<std::is_floating_point<T>::value>>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL distanceSquared(vec<C, T> a, vec<C, T> b);

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL distanceSquared(quat<T> a, quat<T> b);

	template<std::size_t C, typename T, typename = std::enable_if<std::is_floating_point<T>::value>>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 vec<C, T> LYAH_CALL normalized(vec<C, T> a);

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 quat<T> LYAH_CALL normalized(quat<T> a);
}