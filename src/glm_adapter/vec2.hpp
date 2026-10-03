// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#include "pch.hpp"

#include "glm_adapter/adapter.hpp"

namespace glm_adapter {
	template<typename T>
	inline bool operator==(lyah::vec<2, T> a, lyah::vec<2, T> b) {
		return lyah2glm(a) == lyah2glm(b);
	}

	template<typename T>
	inline bool operator!=(lyah::vec<2, T> a, lyah::vec<2, T> b) {
		return lyah2glm(a) != lyah2glm(b);
	}

	template<typename T>
	inline lyah::vec<2, T> operator+(lyah::vec<2, T> a) {
		return glm2lyah(+lyah2glm(a));
	}

	template<typename T>
	inline lyah::vec<2, T> operator-(lyah::vec<2, T> a) {
		return glm2lyah(-lyah2glm(a));
	}

	template<typename T>
	inline lyah::vec<2, T> operator+(lyah::vec<2, T> a, lyah::vec<2, T> b) {
		return glm2lyah(lyah2glm(a) + lyah2glm(b));
	}

	template<typename T>
	inline lyah::vec<2, T> operator-(lyah::vec<2, T> a, lyah::vec<2, T> b) {
		return glm2lyah(lyah2glm(a) - lyah2glm(b));
	}

	template<typename T>
	inline lyah::vec<2, T> operator*(lyah::vec<2, T> a, T b) {
		return glm2lyah(lyah2glm(a) * b);
	}

	template<typename T>
	inline lyah::vec<2, T> operator*(T a, lyah::vec<2, T> b) {
		return glm2lyah(a * lyah2glm(b));
	}

	template<typename T>
	inline lyah::vec<2, T> operator*(lyah::vec<2, T> a, lyah::vec<2, T> b) {
		return glm2lyah(lyah2glm(a) * lyah2glm(b));
	}

	template<typename T>
	inline lyah::vec<2, T> operator/(lyah::vec<2, T> a, T b) {
		return glm2lyah(lyah2glm(a) / b);
	}

	template<typename T>
	inline lyah::vec<2, T> operator/(T a, lyah::vec<2, T> b) {
		return glm2lyah(a / lyah2glm(b));
	}

	template<typename T>
	inline lyah::vec<2, T> operator/(lyah::vec<2, T> a, lyah::vec<2, T> b) {
		return glm2lyah(lyah2glm(a) / lyah2glm(b));
	}

	template<typename T>
	inline lyah::vec<2, T> fma(lyah::vec<2, T> x, lyah::vec<2, T> y, lyah::vec<2, T> z) {
		return glm2lyah(glm::fma(lyah2glm(x), lyah2glm(y), lyah2glm(z)));
	}

	template<typename T>
	inline T dot(lyah::vec<2, T> a, lyah::vec<2, T> b) {
		return glm::dot(lyah2glm(a), lyah2glm(b));
	}

	template<typename T>
	inline T length(lyah::vec<2, T> a) {
		return glm::length(lyah2glm(a));
	}

	template<typename T>
	inline T lengthSquared(lyah::vec<2, T> a) {
		return glm::length2(lyah2glm(a));
	}

	template<typename T>
	inline T distance(lyah::vec<2, T> a, lyah::vec<2, T> b) {
		return glm::distance(lyah2glm(a), lyah2glm(b));
	}

	template<typename T>
	inline T distanceSquared(lyah::vec<2, T> a, lyah::vec<2, T> b) {
		return glm::distance2(lyah2glm(a), lyah2glm(b));
	}

	template<typename T>
	inline lyah::vec<2, T> normalized(lyah::vec<2, T> a) {
		return glm2lyah(glm::normalize(lyah2glm(a)));
	}
}