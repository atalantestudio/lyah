// Copyright 2025 Atalante Studio.
// Distributed under the MIT License.

namespace lyah {
	template<std::size_t M, std::size_t N, typename T>
	LYAH_NODISCARD LYAH_CONSTEXPR LYAH_INLINE mat<M, N, T> LYAH_CALL operator+(mat<M, N, T> a) {
		return a;
	}

	template<std::size_t M, std::size_t N, typename T>
	LYAH_NODISCARD LYAH_INLINE mat<M, N, T> LYAH_CALL operator+(mat<M, N, T> a, mat<M, N, T> b) {
		return a += b;
	}

	template<std::size_t M, std::size_t N, typename T>
	LYAH_NODISCARD LYAH_INLINE mat<M, N, T> LYAH_CALL operator-(mat<M, N, T> a, mat<M, N, T> b) {
		return a -= b;
	}

	template<std::size_t M, std::size_t N, typename T>
	LYAH_NODISCARD LYAH_INLINE mat<M, N, T> LYAH_CALL operator*(mat<M, N, T> a, T b) {
		return a *= b;
	}

	template<std::size_t M, std::size_t N, typename T>
	LYAH_NODISCARD LYAH_INLINE mat<M, N, T> LYAH_CALL operator*(T a, mat<M, N, T> b) {
		return b *= a;
	}

	template<std::size_t M, std::size_t N, typename T>
	LYAH_NODISCARD LYAH_INLINE mat<M, N, T> LYAH_CALL operator*(mat<M, N, T> a, mat<M, N, T> b) {
		return a *= b;
	}

	template<std::size_t M, std::size_t N, typename T>
	LYAH_INLINE mat<M, N, T>& LYAH_CALL operator/=(mat<M, N, T>& A, T b) {
		return A *= static_cast<T>(1) / b;
	}

	template<std::size_t M, std::size_t N, typename T>
	LYAH_NODISCARD LYAH_INLINE mat<M, N, T> LYAH_CALL operator/(mat<M, N, T> A, T b) {
		return A /= b;
	}
}