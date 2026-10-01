// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

namespace lyah {
	template<std::size_t M, typename T>
	LYAH_CONSTEXPR bool operator==(mat<M, 4, T> a, mat<M, 4, T> b) {
		return a[0] == b[0] && a[1] == b[1] && a[2] == b[2] && a[3] == b[3];
	}

	template<std::size_t M, typename T>
	LYAH_CONSTEXPR bool operator!=(mat<M, 4, T> a, mat<M, 4, T> b) {
		return a[0] != b[0] || a[1] != b[1] || a[2] != b[2] || a[3] != b[3];
	}

	template<std::size_t M, typename T>
	LYAH_CONSTEXPR mat<M, 4, T> operator-(mat<M, 4, T> a) {
		a[0] = -a[0];
		a[1] = -a[1];
		a[2] = -a[2];
		a[3] = -a[3];

		return a;
	}

	template<std::size_t M, typename T>
	LYAH_CONSTEXPR mat<M, 4, T> operator+(mat<M, 4, T> a, mat<M, 4, T> b) {
		a[0] += b[0];
		a[1] += b[1];
		a[2] += b[2];
		a[3] += b[3];

		return a;
	}

	template<std::size_t M, typename T>
	LYAH_CONSTEXPR mat<M, 4, T> operator*(mat<M, 4, T> a, T b) {
		a[0] *= b;
		a[1] *= b;
		a[2] *= b;
		a[3] *= b;

		return a;
	}
}