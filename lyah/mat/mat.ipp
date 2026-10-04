// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

template<std::size_t M, std::size_t N, typename T>
LYAH_CONSTEXPR lyah::mat<M, N, T> lyah::operator+(mat<M, N, T> a) {
	return a;
}

template<std::size_t M, std::size_t N, typename T>
lyah::mat<M, N, T>& lyah::operator+=(mat<M, N, T>& a, mat<M, N, T> b) {
	return a = a + b;
}

template<std::size_t M, std::size_t N, typename T>
LYAH_CONSTEXPR lyah::mat<M, N, T> lyah::operator-(mat<M, N, T> a, mat<M, N, T> b) {
	return a + -b;
}

template<std::size_t M, std::size_t N, typename T>
lyah::mat<M, N, T>& lyah::operator-=(mat<M, N, T>& a, mat<M, N, T> b) {
	return a = a - b;
}

template<std::size_t M, std::size_t N, typename T>
LYAH_CONSTEXPR lyah::mat<M, N, T> lyah::operator*(T a, mat<M, N, T> b) {
	return b * a;
}

template<std::size_t M, std::size_t N, typename T>
lyah::mat<M, N, T>& lyah::operator*=(mat<M, N, T>& a, T b) {
	return a = a * b;
}

template<std::size_t M, std::size_t N, typename T>
lyah::mat<M, N, T>& lyah::operator*=(mat<M, N, T>& a, mat<M, N, T> b) {
	return a = a * b;
}

template<std::size_t M, std::size_t N, typename T>
LYAH_CONSTEXPR lyah::mat<M, N, T> lyah::operator/(mat<M, N, T> a, T b) {
	return a * (1 / b);
}

template<std::size_t M, std::size_t N, typename T>
lyah::mat<M, N, T>& lyah::operator/=(mat<M, N, T>& a, T b) {
	return a = a / b;
}

/// See https://www.dr-lex.be/random/matrix-inv.html.
template<std::size_t M, typename T>
LYAH_CONSTEXPR lyah::mat<M, M, T> lyah::inverse(mat<M, M, T> a) {
	const T d = determinant(a);

	if (abs(d) <= 1e-6) {
		return {};
	}

	return adjugate(a) / d;
}