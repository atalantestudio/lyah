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

	template<std::size_t C, typename T>
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
	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<C, T> LYAH_CALL operator*(vec<C, T> a, mat<C, C, T> B);

	/// Post-multiplies `a` by `b`, then returns `a`.
	template<std::size_t C, typename T>
	LYAH_INLINE vec<C, T>& LYAH_CALL operator*=(vec<C, T>& a, mat<C, C, T> B);

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<C, T> LYAH_CALL operator*(vec<C, T> a, quat<T> b);

	template<std::size_t C, typename T>
	LYAH_INLINE vec<C, T>& LYAH_CALL operator*=(vec<C, T>& a, quat<T> b);

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