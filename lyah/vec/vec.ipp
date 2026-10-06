// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

template<std::size_t C, typename T>
LYAH_CONSTEXPR lyah::vec<C, T> lyah::operator+(vec<C, T> a) {
	return a;
}

template<std::size_t C, typename T>
lyah::vec<C, T>& lyah::operator+=(vec<C, T>& a, vec<C, T> b) {
	return a = a + b;
}

template<std::size_t C, typename T>
LYAH_CONSTEXPR lyah::vec<C, T> lyah::operator-(vec<C, T> a, vec<C, T> b) {
	return a + -b;
}

template<std::size_t C, typename T>
lyah::vec<C, T>& lyah::operator-=(vec<C, T>& a, vec<C, T> b) {
	return a = a - b;
}

template<std::size_t C, typename T>
LYAH_CONSTEXPR lyah::vec<C, T> lyah::operator*(T a, vec<C, T> b) {
	return b * a;
}

template<std::size_t C, typename T>
lyah::vec<C, T>& lyah::operator*=(vec<C, T>& a, T b) {
	return a = a * b;
}

template<std::size_t C, typename T>
lyah::vec<C, T>& lyah::operator*=(vec<C, T>& a, vec<C, T> b) {
	return a = a * b;
}

template<std::size_t C, typename T, typename>
lyah::vec<C, T>& lyah::operator*=(vec<C, T>& a, mat<C, C, T> b) {
	return a = a * b;
}

template<std::size_t C, typename T>
lyah::vec<C, T>& lyah::operator/=(vec<C, T>& a, T b) {
	return a = a / b;
}

template<std::size_t C, typename T>
lyah::vec<C, T>& lyah::operator/=(vec<C, T>& a, vec<C, T> b) {
	return a = a / b;
}