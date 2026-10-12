// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace lyah {
	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR bool LYAH_CALL operator==(vec<C, T> a, vec<C, T> b);

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR bool LYAH_CALL operator!=(vec<C, T> a, vec<C, T> b);

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<C, T> LYAH_CALL operator+(vec<C, T> a);

	template<std::size_t C, typename T, typename = typename std::enable_if<!std::is_unsigned<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<C, T> LYAH_CALL operator-(vec<C, T> a);

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<C, T> LYAH_CALL operator+(vec<C, T> a, vec<C, T> b);

	template<std::size_t C, typename T>
	LYAH_INLINE vec<C, T>& LYAH_CALL operator+=(vec<C, T>& a, vec<C, T> b);

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<C, T> LYAH_CALL operator-(vec<C, T> a, vec<C, T> b);

	template<std::size_t C, typename T>
	LYAH_INLINE vec<C, T>& LYAH_CALL operator-=(vec<C, T>& a, vec<C, T> b);

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<C, T> LYAH_CALL operator*(vec<C, T> a, T b);

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<C, T> LYAH_CALL operator*(T a, vec<C, T> b);

	template<std::size_t C, typename T>
	LYAH_INLINE vec<C, T>& LYAH_CALL operator*=(vec<C, T>& a, T b);

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<C, T> LYAH_CALL operator*(vec<C, T> a, vec<C, T> b);

	template<std::size_t C, typename T>
	LYAH_INLINE vec<C, T>& LYAH_CALL operator*=(vec<C, T>& a, vec<C, T> b);

	/// Returns the post-multiplication of `a` and `b`.
	template<std::size_t C, typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<C, T> LYAH_CALL operator*(vec<C, T> a, mat<C, C, T> b);

	/// Sets `a` to the post-multiplication of `a` and `b`, then returns `a`.
	template<std::size_t C, typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_INLINE vec<C, T>& LYAH_CALL operator*=(vec<C, T>& a, mat<C, C, T> b);

	/// Returns the product of `a` and `b`.
	/// `b` is assumed to be normalized.
	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<3, T> LYAH_CALL operator*(vec<3, T> a, quat<T> b);

	/// Sets `a` to the product of `a` and `b`, then returns `a`.
	/// `b` is assumed to be normalized.
	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_INLINE vec<3, T>& LYAH_CALL operator*=(vec<3, T>& a, quat<T> b);

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<C, T> LYAH_CALL operator/(vec<C, T> a, T b);

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<C, T> LYAH_CALL operator/(T a, vec<C, T> b);

	template<std::size_t C, typename T>
	LYAH_INLINE vec<C, T>& LYAH_CALL operator/=(vec<C, T>& a, T b);

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<C, T> LYAH_CALL operator/(vec<C, T> a, vec<C, T> b);

	template<std::size_t C, typename T>
	LYAH_INLINE vec<C, T>& LYAH_CALL operator/=(vec<C, T>& a, vec<C, T> b);
}