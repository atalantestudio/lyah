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
	inline T parallelogramArea(lyah::vec<2, T> a, lyah::vec<2, T> b) {
		return glm::determinant(glm::mat<2, 2, T>(lyah2glm(a), lyah2glm(b)));
	}

	template<typename T>
	inline lyah::vec<2, T> perpendicularLeft(lyah::vec<2, T> a) {
		return {-a.y, a.x};
	}

	template<typename T>
	inline lyah::vec<2, T> perpendicularRight(lyah::vec<2, T> a) {
		return {a.y, -a.x};
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

	template<typename T>
	inline lyah::vec<2, T> degrees(lyah::vec<2, T> a) {
		return glm2lyah(glm::degrees(lyah2glm(a)));
	}

	template<typename T>
	inline lyah::vec<2, T> radians(lyah::vec<2, T> a) {
		return glm2lyah(glm::radians(lyah2glm(a)));
	}

	template<typename T>
	inline lyah::vec<2, T> sin(lyah::vec<2, T> a) {
		return glm2lyah(glm::sin(lyah2glm(a)));
	}

	template<typename T>
	inline lyah::vec<2, T> cos(lyah::vec<2, T> a) {
		return glm2lyah(glm::cos(lyah2glm(a)));
	}

	template<typename T>
	inline lyah::vec<2, T> tan(lyah::vec<2, T> a) {
		return glm2lyah(glm::tan(lyah2glm(a)));
	}

	template<typename T>
	inline lyah::vec<2, T> asin(lyah::vec<2, T> a) {
		return glm2lyah(glm::asin(lyah2glm(a)));
	}

	template<typename T>
	inline lyah::vec<2, T> acos(lyah::vec<2, T> a) {
		return glm2lyah(glm::acos(lyah2glm(a)));
	}

	template<typename T>
	inline lyah::vec<2, T> atan(lyah::vec<2, T> a) {
		return glm2lyah(glm::atan(lyah2glm(a)));
	}
}