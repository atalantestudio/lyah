// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#include "pch.hpp"

#include "glm_adapter/adapter.hpp"

namespace glm_adapter {
	template<std::size_t C, typename T>
	inline bool operator==(lyah::vec<C, T> a, lyah::vec<C, T> b) {
		return lyah2glm(a) == lyah2glm(b);
	}

	template<std::size_t C, typename T>
	inline bool operator!=(lyah::vec<C, T> a, lyah::vec<C, T> b) {
		return lyah2glm(a) != lyah2glm(b);
	}

	template<std::size_t C, typename T>
	inline lyah::vec<C, T> operator+(lyah::vec<C, T> a) {
		return glm2lyah(+lyah2glm(a));
	}

	template<std::size_t C, typename T>
	inline lyah::vec<C, T> operator-(lyah::vec<C, T> a) {
		return glm2lyah(-lyah2glm(a));
	}

	template<std::size_t C, typename T>
	inline lyah::vec<C, T> operator+(lyah::vec<C, T> a, lyah::vec<C, T> b) {
		return glm2lyah(lyah2glm(a) + lyah2glm(b));
	}

	template<std::size_t C, typename T>
	inline lyah::vec<C, T> operator-(lyah::vec<C, T> a, lyah::vec<C, T> b) {
		return glm2lyah(lyah2glm(a) - lyah2glm(b));
	}

	template<std::size_t C, typename T>
	inline lyah::vec<C, T> operator*(lyah::vec<C, T> a, T b) {
		return glm2lyah(lyah2glm(a) * b);
	}

	template<std::size_t C, typename T>
	inline lyah::vec<C, T> operator*(T a, lyah::vec<C, T> b) {
		return glm2lyah(a * lyah2glm(b));
	}

	template<std::size_t C, typename T>
	inline lyah::vec<C, T> operator*(lyah::vec<C, T> a, lyah::vec<C, T> b) {
		return glm2lyah(lyah2glm(a) * lyah2glm(b));
	}

	template<std::size_t C, typename T>
	inline lyah::vec<C, T> operator*(lyah::vec<C, T> a, lyah::mat<C, C, T> b) {
		return glm2lyah(lyah2glm(b) * lyah2glm(a));
	}

	template<std::size_t C, typename T>
	inline lyah::vec<C, T> operator*(lyah::vec<C, T> a, lyah::quat<T> b) {
		return glm2lyah(lyah2glm(b) * lyah2glm(a));
	}

	template<std::size_t C, typename T>
	inline lyah::vec<C, T> operator/(lyah::vec<C, T> a, T b) {
		return glm2lyah(lyah2glm(a) / b);
	}

	template<std::size_t C, typename T>
	inline lyah::vec<C, T> operator/(T a, lyah::vec<C, T> b) {
		return glm2lyah(a / lyah2glm(b));
	}

	template<std::size_t C, typename T>
	inline lyah::vec<C, T> operator/(lyah::vec<C, T> a, lyah::vec<C, T> b) {
		return glm2lyah(lyah2glm(a) / lyah2glm(b));
	}

	template<std::size_t C, typename T>
	inline lyah::vec<C, T> degrees(lyah::vec<C, T> a) {
		return glm2lyah(glm::degrees(lyah2glm(a)));
	}

	template<std::size_t C, typename T>
	inline lyah::vec<C, T> radians(lyah::vec<C, T> a) {
		return glm2lyah(glm::radians(lyah2glm(a)));
	}

	template<std::size_t C, typename T>
	inline lyah::vec<C, T> sin(lyah::vec<C, T> a) {
		return glm2lyah(glm::sin(lyah2glm(a)));
	}

	template<std::size_t C, typename T>
	inline lyah::vec<C, T> cos(lyah::vec<C, T> a) {
		return glm2lyah(glm::cos(lyah2glm(a)));
	}

	template<std::size_t C, typename T>
	inline lyah::vec<C, T> tan(lyah::vec<C, T> a) {
		return glm2lyah(glm::tan(lyah2glm(a)));
	}

	template<std::size_t C, typename T>
	inline lyah::vec<C, T> asin(lyah::vec<C, T> a) {
		return glm2lyah(glm::asin(lyah2glm(a)));
	}

	template<std::size_t C, typename T>
	inline lyah::vec<C, T> acos(lyah::vec<C, T> a) {
		return glm2lyah(glm::acos(lyah2glm(a)));
	}

	template<std::size_t C, typename T>
	inline lyah::vec<C, T> atan(lyah::vec<C, T> a) {
		return glm2lyah(glm::atan(lyah2glm(a)));
	}
}