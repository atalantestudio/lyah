// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

namespace lyah {
	template<std::size_t M, std::size_t N, typename T>
	LYAH_CONSTEXPR mat<M, N, T> operator+(mat<M, N, T> a) {
		return a;
	}

	template<std::size_t M, std::size_t N, typename T>
	mat<M, N, T>& operator+=(mat<M, N, T>& a, mat<M, N, T> b) {
		return a = a + b;
	}

	template<std::size_t M, std::size_t N, typename T>
	LYAH_CONSTEXPR mat<M, N, T> operator-(mat<M, N, T> a, mat<M, N, T> b) {
		return a + -b;
	}

	template<std::size_t M, std::size_t N, typename T>
	mat<M, N, T>& operator-=(mat<M, N, T>& a, mat<M, N, T> b) {
		return a = a - b;
	}

	template<std::size_t M, std::size_t N, typename T>
	LYAH_CONSTEXPR mat<M, N, T> operator*(T a, mat<M, N, T> b) {
		return b * a;
	}

	template<std::size_t M, std::size_t N, typename T>
	mat<M, N, T>& operator*=(mat<M, N, T>& a, T b) {
		return a = a * b;
	}

	template<std::size_t M, std::size_t N, typename T>
	mat<M, N, T>& operator*=(mat<M, N, T>& a, mat<M, N, T> b) {
		return a = a * b;
	}

	template<std::size_t M, std::size_t N, typename T>
	LYAH_CONSTEXPR mat<M, N, T> operator/(mat<M, N, T> a, T b) {
		return a * (static_cast<T>(1) / b);
	}

	template<std::size_t M, std::size_t N, typename T>
	mat<M, N, T>& operator/=(mat<M, N, T>& a, T b) {
		return a = a / b;
	}

	/// See https://www.dr-lex.be/random/matrix-inv.html.
	template<std::size_t M, typename T>
	LYAH_CONSTEXPR mat<M, M, T> inverse(mat<M, M, T> a) {
		const T d = determinant(a);

		if (abs(d) <= static_cast<T>(1e-6)) {
			return {};
		}

		return adjugate(a) / d;
	}
}