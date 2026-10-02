// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

namespace lyah {
	template<std::size_t C, typename T>
	LYAH_CONSTEXPR vec<C, T> operator+(vec<C, T> a) {
		return a;
	}

	template<std::size_t C, typename T>
	vec<C, T>& operator+=(vec<C, T>& a, vec<C, T> b) {
		return a = a + b;
	}

	template<std::size_t C, typename T>
	LYAH_CONSTEXPR vec<C, T> operator-(vec<C, T> a, vec<C, T> b) {
		return a + -b;
	}

	template<std::size_t C, typename T>
	vec<C, T>& operator-=(vec<C, T>& a, vec<C, T> b) {
		return a = a - b;
	}

	template<std::size_t C, typename T>
	LYAH_CONSTEXPR vec<C, T> operator*(T a, vec<C, T> b) {
		return b * a;
	}

	template<std::size_t C, typename T>
	vec<C, T>& operator*=(vec<C, T>& a, T b) {
		return a = a * b;
	}

	template<std::size_t C, typename T>
	vec<C, T>& operator*=(vec<C, T>& a, vec<C, T> b) {
		return a = a * b;
	}

	template<std::size_t C, typename T>
	vec<C, T>& operator*=(vec<C, T>& a, mat<C, C, T> b) {
		return a = a * b;
	}

	template<std::size_t C, typename T>
	LYAH_CONSTEXPR vec<C, T> operator/(vec<C, T> a, T b) {
		return a * (static_cast<T>(1) / b);
	}

	template<std::size_t C, typename T>
	vec<C, T>& operator/=(vec<C, T>& a, T b) {
		return a = a * (static_cast<T>(1) / b);
	}

	template<std::size_t C, typename T>
	LYAH_CONSTEXPR vec<C, T> operator/(vec<C, T> a, vec<C, T> b) {
		return a = a * (static_cast<T>(1) / b);
	}

	template<std::size_t C, typename T>
	vec<C, T>& operator/=(vec<C, T>& a, vec<C, T> b) {
		return a = a / b;
	}
}