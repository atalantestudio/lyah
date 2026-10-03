// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#include "pch.hpp"

namespace glm_adapter {
	template<>
	lyah::quat<std::double_t> identity() {
		return glm2lyah(glm::dquat());
	}

	lyah::quat<std::double_t> axisAngle(lyah::vec<3, std::double_t> axis, std::double_t angle) {
		return glm2lyah(glm::angleAxis(angle, lyah2glm(axis)));
	}

	bool operator==(lyah::quat<std::double_t> a, lyah::quat<std::double_t> b) {
		return lyah2glm(a) == lyah2glm(b);
	}

	bool operator!=(lyah::quat<std::double_t> a, lyah::quat<std::double_t> b) {
		return lyah2glm(a) != lyah2glm(b);
	}

	lyah::quat<std::double_t> operator+(lyah::quat<std::double_t> a) {
		return glm2lyah(+lyah2glm(a));
	}

	lyah::quat<std::double_t> operator-(lyah::quat<std::double_t> a) {
		return glm2lyah(-lyah2glm(a));
	}

	lyah::quat<std::double_t> operator+(lyah::quat<std::double_t> a, lyah::quat<std::double_t> b) {
		return glm2lyah(lyah2glm(a) + lyah2glm(b));
	}

	lyah::quat<std::double_t> operator-(lyah::quat<std::double_t> a, lyah::quat<std::double_t> b) {
		return glm2lyah(lyah2glm(a) - lyah2glm(b));
	}

	lyah::quat<std::double_t> operator*(lyah::quat<std::double_t> a, std::double_t b) {
		return glm2lyah(lyah2glm(a) * b);
	}

	lyah::quat<std::double_t> operator*(std::double_t a, lyah::quat<std::double_t> b) {
		return glm2lyah(a * lyah2glm(b));
	}

	lyah::quat<std::double_t> operator*(lyah::quat<std::double_t> a, lyah::quat<std::double_t> b) {
		return glm2lyah(lyah2glm(a) * lyah2glm(b));
	}

	lyah::quat<std::double_t> operator/(lyah::quat<std::double_t> a, std::double_t b) {
		return glm2lyah(lyah2glm(a) / b);
	}

	lyah::quat<std::double_t> conjugate(lyah::quat<std::double_t> a) {
		return glm2lyah(glm::conjugate(lyah2glm(a)));
	}

	std::double_t dot(lyah::quat<std::double_t> a, lyah::quat<std::double_t> b) {
		return glm::dot(lyah2glm(a), lyah2glm(b));
	}

	lyah::quat<std::double_t> inverse(lyah::quat<std::double_t> a) {
		return glm2lyah(glm::inverse(lyah2glm(a)));
	}

	std::double_t length(lyah::quat<std::double_t> a) {
		return glm::length(lyah2glm(a));
	}

	std::double_t lengthSquared(lyah::quat<std::double_t> a) {
		glm::dquat a2 = lyah2glm(a);

		return glm::dot(a2, a2);
	}

	std::double_t distance(lyah::quat<std::double_t> a, lyah::quat<std::double_t> b) {
		return glm::length(lyah2glm(b) - lyah2glm(a));
	}

	std::double_t distanceSquared(lyah::quat<std::double_t> a, lyah::quat<std::double_t> b) {
		glm::dquat ab = lyah2glm(b) - lyah2glm(a);

		return glm::dot(ab, ab);
	}

	lyah::quat<std::double_t> normalized(lyah::quat<std::double_t> a) {
		return glm2lyah(glm::normalize(lyah2glm(a)));
	}
}