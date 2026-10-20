// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace glm_adapter {
	template<std::size_t M, std::size_t N, typename T>
	inline lyah::mat<M, N, T> identity() {
		return glm2lyah(glm::identity<glm::mat<M, N, T>>());
	}

	template<std::size_t M, typename T>
	inline lyah::mat<M, M, T> translation(lyah::vec<M - 1, T> translation) {
		const glm::mat<M, M, T> a = glm::translate(glm::identity<glm::mat<M, M, T>>(), lyah2glm(translation));

		return glm2lyah(a);
	}

	template<std::size_t M, typename T>
	inline lyah::mat<M, M, T> rotationAngle(T angle) {
		const glm::mat<3, 3, T> a = glm::rotate(glm::identity<glm::mat<3, 3, T>>(), angle);

		return glm2lyah(glm::mat<M, M, T>(glm::transpose(a)));
	}

	template<typename T>
	inline lyah::mat<4, 4, T> rotationAxisAngle(lyah::vec<3, T> axis, T angle) {
		const glm::mat<4, 4, T> a = glm::rotate(glm::identity<glm::mat<4, 4, T>>(), angle, lyah2glm(axis));

		return glm2lyah(a);
	}

	template<std::size_t M, typename T>
	inline lyah::mat<M, M, T> scaling(lyah::vec<M - 1, T> scale) {
		const glm::mat<M, M, T> a = glm::scale(glm::identity<glm::mat<M, M, T>>(), lyah2glm(scale));

		return glm2lyah(a);
	}

	template<std::size_t M, typename T>
	inline lyah::mat<M, M, T> uniformScaling(T scale) {
		const glm::mat<M, M, T> a = glm::scale(glm::identity<glm::mat<M, M, T>>(), glm::vec<M - 1, T>(scale));

		return glm2lyah(a);
	}

	template<typename T>
	inline lyah::mat<4, 4, T> lookAt(lyah::vec<3, T> eye, lyah::vec<3, T> target, lyah::vec<3, T> up) {
		return glm2lyah(glm::lookAt(lyah2glm(eye), lyah2glm(target), lyah2glm(up)));
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
		return glm::determinant(glm::transpose(lyah2glm(a)));
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