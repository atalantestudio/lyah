// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace glm_adapter {
	template<std::size_t M, std::size_t N, typename T>
	inline lyah::mat<M, N, T> identity() {
		return glm2lyah(glm::identity<glm::mat<M, N, T>>());
	}

	template<std::size_t M, std::size_t N, typename T>
	inline bool operator==(lyah::mat<M, N, T> a, lyah::mat<M, N, T> b) {
		return lyah2glm(a) == lyah2glm(b);
	}

	template<std::size_t M, std::size_t N, typename T>
	inline bool operator!=(lyah::mat<M, N, T> a, lyah::mat<M, N, T> b) {
		return lyah2glm(a) != lyah2glm(b);
	}

	template<std::size_t M, std::size_t N, typename T>
	inline lyah::mat<M, N, T> operator+(lyah::mat<M, N, T> a) {
		return glm2lyah(+lyah2glm(a));
	}

	template<std::size_t M, std::size_t N, typename T>
	inline lyah::mat<M, N, T> operator-(lyah::mat<M, N, T> a) {
		return glm2lyah(-lyah2glm(a));
	}

	template<std::size_t M, std::size_t N, typename T>
	inline lyah::mat<M, N, T> operator+(lyah::mat<M, N, T> a, lyah::mat<M, N, T> b) {
		return glm2lyah(lyah2glm(a) + lyah2glm(b));
	}

	template<std::size_t M, std::size_t N, typename T>
	inline lyah::mat<M, N, T> operator-(lyah::mat<M, N, T> a, lyah::mat<M, N, T> b) {
		return glm2lyah(lyah2glm(a) - lyah2glm(b));
	}

	template<std::size_t M, std::size_t N, typename T>
	inline lyah::mat<M, N, T> operator*(lyah::mat<M, N, T> a, T b) {
		return glm2lyah(lyah2glm(a) * b);
	}

	template<std::size_t M, std::size_t N, typename T>
	inline lyah::mat<M, N, T> operator*(T a, lyah::mat<M, N, T> b) {
		return glm2lyah(a * lyah2glm(b));
	}

	template<std::size_t M, std::size_t N, typename T>
	inline lyah::mat<M, N, T> operator*(lyah::mat<M, N, T> a, lyah::mat<M, N, T> b) {
		return glm2lyah(lyah2glm(b) * lyah2glm(a));
	}

	template<std::size_t M, std::size_t N, typename T>
	inline lyah::mat<M, N, T> operator/(lyah::mat<M, N, T> a, T b) {
		return glm2lyah(lyah2glm(a) / b);
	}

	template<std::size_t M, typename T>
	inline T determinant(lyah::mat<M, M, T> a) {
		return glm::determinant(lyah2glm(a));
	}

	template<std::size_t M, typename T>
	inline lyah::mat<M, M, T> adjugate(lyah::mat<M, M, T> a) {
		return glm2lyah(glm::adjugate(lyah2glm(a)));
	}

	template<std::size_t M, typename T>
	inline lyah::mat<M, M, T> inverse(lyah::mat<M, M, T> a) {
		return glm2lyah(glm::inverse(lyah2glm(a)));
	}

	template<std::size_t M, std::size_t N, typename T>
	inline lyah::mat<M, N, T> transpose(lyah::mat<M, N, T> a) {
		return glm2lyah(glm::transpose(lyah2glm(a)));
	}
}