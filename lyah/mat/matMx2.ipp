// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

namespace lyah {
	template<std::size_t M, typename T>
	LYAH_NODISCARD LYAH_INLINE bool LYAH_CALL operator==(mat<M, 2, T> a, mat<M, 2, T> b) {
		return a[0] == b[0] && a[1] == b[1];
	}

	template<std::size_t M, typename T>
	LYAH_NODISCARD LYAH_INLINE bool LYAH_CALL operator!=(mat<M, 2, T> a, mat<M, 2, T> b) {
		return a[0] != b[0] || a[1] != b[1];
	}

	template<std::size_t M, typename T>
	LYAH_NODISCARD LYAH_INLINE mat<M, 2, T> LYAH_CALL operator-(mat<M, 2, T> A) {
		A[0] = -A[0];
		A[1] = -A[1];

		return A;
	}

	template<std::size_t M, typename T>
	LYAH_INLINE mat<M, 2, T>& LYAH_CALL operator+=(mat<M, 2, T>& A, mat<M, 2, T> B) {
		A[0] += B[0];
		A[1] += B[1];

		return A;
	}

	template<std::size_t M, typename T>
	LYAH_INLINE mat<M, 2, T>& LYAH_CALL operator-=(mat<M, 2, T>& A, mat<M, 2, T> B) {
		A[0] -= B[0];
		A[1] -= B[1];

		return A;
	}

	template<std::size_t M, typename T>
	LYAH_INLINE mat<M, 2, T>& LYAH_CALL operator*=(mat<M, 2, T>& A, T b) {
		A[0] *= b;
		A[1] *= b;

		return A;
	}
}