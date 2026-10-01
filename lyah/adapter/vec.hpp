// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace lyah {
	/// A C-component vector of type T.
	template<std::size_t C, typename T>
	struct vec;

	/// A 2-component single floating point vector.
	template<>
	struct vec<2, std::float_t>;

	/// A 3-component single floating point vector.
	template<>
	struct vec<3, std::float_t>;

	/// A 4-component single floating point vector.
	template<>
	struct vec<4, std::float_t>;

	/// A 2-component double floating point vector.
	template<>
	struct vec<2, std::double_t>;

	/// A 3-component double floating point vector.
	template<>
	struct vec<3, std::double_t>;

	/// A 4-component double floating point vector.
	template<>
	struct vec<4, std::double_t>;

	/// A 2-component 32-bit integer point vector.
	template<>
	struct vec<2, std::int32_t>;

	/// A 3-component 32-bit integer point vector.
	template<>
	struct vec<3, std::int32_t>;

	/// A 4-component 32-bit integer point vector.
	template<>
	struct vec<4, std::int32_t>;

	/// A 2-component 64-bit integer point vector.
	template<>
	struct vec<2, std::int64_t>;

	/// A 3-component 64-bit integer point vector.
	template<>
	struct vec<3, std::int64_t>;

	/// A 4-component 64-bit integer point vector.
	template<>
	struct vec<4, std::int64_t>;

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

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<C, T> LYAH_CALL fma(vec<C, T> a, vec<C, T> b, vec<C, T> c);
}