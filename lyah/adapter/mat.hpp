// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace lyah {
	/// A 2x2 single floating point matrix.
	template<>
	struct mat<2, 2, std::float_t>;

	/// A 3x3 single floating point matrix.
	template<>
	struct mat<3, 3, std::float_t>;

	/// A 4x4 single floating point matrix.
	template<>
	struct mat<4, 4, std::float_t>;

	/// A 2x2 double floating point matrix.
	template<>
	struct mat<2, 2, std::double_t>;

	/// A 3x3 double floating point matrix.
	template<>
	struct mat<3, 3, std::double_t>;

	/// A 4x4 double floating point matrix.
	template<>
	struct mat<4, 4, std::double_t>;

	template<std::size_t M, std::size_t N, typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR bool LYAH_CALL operator==(mat<M, N, T> a, mat<M, N, T> b);

	template<std::size_t M, std::size_t N, typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR bool LYAH_CALL operator!=(mat<M, N, T> a, mat<M, N, T> b);

	template<std::size_t M, std::size_t N, typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR mat<M, N, T> LYAH_CALL operator+(mat<M, N, T> a);

	template<std::size_t M, std::size_t N, typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR mat<M, N, T> LYAH_CALL operator-(mat<M, N, T> a);

	template<std::size_t M, std::size_t N, typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR mat<M, N, T> LYAH_CALL operator+(mat<M, N, T> a, mat<M, N, T> b);

	template<std::size_t M, std::size_t N, typename T>
	LYAH_INLINE mat<M, N, T>& LYAH_CALL operator+=(mat<M, N, T>& a, mat<M, N, T> b);

	template<std::size_t M, std::size_t N, typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR mat<M, N, T> LYAH_CALL operator-(mat<M, N, T> a, mat<M, N, T> b);

	template<std::size_t M, std::size_t N, typename T>
	LYAH_INLINE mat<M, N, T>& LYAH_CALL operator-=(mat<M, N, T>& a, mat<M, N, T> b);

	template<std::size_t M, std::size_t N, typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR mat<M, N, T> LYAH_CALL operator*(mat<M, N, T> a, T b);

	template<std::size_t M, std::size_t N, typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR mat<M, N, T> LYAH_CALL operator*(T a, mat<M, N, T> b);

	template<std::size_t M, std::size_t N, typename T>
	LYAH_INLINE mat<M, N, T>& LYAH_CALL operator*=(mat<M, N, T>& a, T b);

	template<std::size_t M, std::size_t N, typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR mat<M, N, T> LYAH_CALL operator*(mat<M, N, T> a, mat<M, N, T> b);

	template<std::size_t M, std::size_t N, typename T>
	LYAH_INLINE mat<M, N, T>& LYAH_CALL operator*=(mat<M, N, T>& a, mat<M, N, T> b);

	template<std::size_t M, std::size_t N, typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR mat<M, N, T> LYAH_CALL operator/(mat<M, N, T> a, T b);

	template<std::size_t M, std::size_t N, typename T>
	LYAH_INLINE mat<M, N, T>& LYAH_CALL operator/=(mat<M, N, T>& a, T b);

	template<std::size_t M, typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL determinant(mat<M, M, T> a);

	template<std::size_t M, typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR mat<M, M, T> LYAH_CALL adjugate(mat<M, M, T> a);

	template<std::size_t M, typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR mat<M, M, T> LYAH_CALL inverse(mat<M, M, T> a);

	template<std::size_t M, std::size_t N, typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR mat<M, N, T> LYAH_CALL transpose(mat<M, N, T> a);
}