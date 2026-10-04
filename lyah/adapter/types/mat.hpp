// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace lyah {
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

	/// Returns the determinant of `a`.
	template<std::size_t M, typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL determinant(mat<M, M, T> a);

	/// Returns the adjugate of `a`.
	template<std::size_t M, typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR mat<M, M, T> LYAH_CALL adjugate(mat<M, M, T> a);

	/// Returns the inverse of `a`.
	/// If `a` is not invertible, returns a zero MxM matrix.
	template<std::size_t M, typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR mat<M, M, T> LYAH_CALL inverse(mat<M, M, T> a);

	/// Returns the transpose of `a`.
	template<std::size_t M, std::size_t N, typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR mat<M, N, T> LYAH_CALL transpose(mat<M, N, T> a);
}