// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

namespace lyah {
	template<std::size_t M, typename T>
	LYAH_NODISCARD LYAH_INLINE bool LYAH_CALL operator==(mat<M, 3, T> a, mat<M, 3, T> b) {
		return a[0] == b[0] && a[1] == b[1] && a[2] == b[2];
	}

	template<std::size_t M, typename T>
	LYAH_NODISCARD LYAH_INLINE bool LYAH_CALL operator!=(mat<M, 3, T> a, mat<M, 3, T> b) {
		return a[0] != b[0] || a[1] != b[1] || a[2] != b[2];
	}

	template<std::size_t M, typename T>
	LYAH_NODISCARD LYAH_INLINE mat<M, 3, T> LYAH_CALL operator-(mat<M, 3, T> a) {
		a[0] = -a[0];
		a[1] = -a[1];
		a[2] = -a[2];

		return a;
	}

	template<std::size_t M, typename T>
	LYAH_INLINE mat<M, 3, T>& LYAH_CALL operator+=(mat<M, 3, T>& a, mat<M, 3, T> b) {
		a[0] += b[0];
		a[1] += b[1];
		a[2] += b[2];

		return a;
	}

	template<std::size_t M, typename T>
	LYAH_INLINE mat<M, 3, T>& LYAH_CALL operator-=(mat<M, 3, T>& a, mat<M, 3, T> b) {
		a[0] -= b[0];
		a[1] -= b[1];
		a[2] -= b[2];

		return a;
	}

	template<std::size_t M, typename T>
	LYAH_INLINE mat<M, 3, T>& LYAH_CALL operator*=(mat<M, 3, T>& a, T b) {
		a[0] *= b;
		a[1] *= b;
		a[2] *= b;

		return a;
	}
}