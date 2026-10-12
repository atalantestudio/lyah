// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

namespace lyah {
	template<std::size_t M, typename T>
	LYAH_CONSTEXPR bool operator==(mat<M, 2, T> a, mat<M, 2, T> b) {
		return a[0] == b[0] && a[1] == b[1];
	}

	template<std::size_t M, typename T>
	LYAH_CONSTEXPR bool operator!=(mat<M, 2, T> a, mat<M, 2, T> b) {
		return a[0] != b[0] || a[1] != b[1];
	}

	template<std::size_t M, typename T>
	LYAH_CONSTEXPR mat<M, 2, T> operator-(mat<M, 2, T> a) {
		a[0] = -a[0];
		a[1] = -a[1];

		return a;
	}

	template<std::size_t M, typename T>
	LYAH_CONSTEXPR mat<M, 2, T> operator+(mat<M, 2, T> a, mat<M, 2, T> b) {
		a[0] += b[0];
		a[1] += b[1];

		return a;
	}

	template<std::size_t M, typename T>
	LYAH_CONSTEXPR mat<M, 2, T> operator*(mat<M, 2, T> a, T b) {
		a[0] *= b;
		a[1] *= b;

		return a;
	}
}