// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#include "pch.hpp"

namespace glm_adapter {
	template<>
	lyah::quat<std::float_t> identity() {
		return glm2lyah(glm::quat());
	}

	lyah::quat<std::float_t> axisAngle(lyah::vec<3, std::float_t> axis, std::float_t angle) {
		return glm2lyah(glm::angleAxis(angle, lyah2glm(axis)));
	}

	bool operator==(lyah::quat<std::float_t> a, lyah::quat<std::float_t> b) {
		return lyah2glm(a) == lyah2glm(b);
	}

	bool operator!=(lyah::quat<std::float_t> a, lyah::quat<std::float_t> b) {
		return lyah2glm(a) != lyah2glm(b);
	}

	lyah::quat<std::float_t> operator+(lyah::quat<std::float_t> a) {
		return glm2lyah(+lyah2glm(a));
	}

	lyah::quat<std::float_t> operator-(lyah::quat<std::float_t> a) {
		return glm2lyah(-lyah2glm(a));
	}

	lyah::quat<std::float_t> operator+(lyah::quat<std::float_t> a, lyah::quat<std::float_t> b) {
		return glm2lyah(lyah2glm(a) + lyah2glm(b));
	}

	lyah::quat<std::float_t> operator-(lyah::quat<std::float_t> a, lyah::quat<std::float_t> b) {
		return glm2lyah(lyah2glm(a) - lyah2glm(b));
	}

	lyah::quat<std::float_t> operator*(lyah::quat<std::float_t> a, std::float_t b) {
		return glm2lyah(lyah2glm(a) * b);
	}

	lyah::quat<std::float_t> operator*(std::float_t a, lyah::quat<std::float_t> b) {
		return glm2lyah(a * lyah2glm(b));
	}

	lyah::quat<std::float_t> operator*(lyah::quat<std::float_t> a, lyah::quat<std::float_t> b) {
		return glm2lyah(lyah2glm(a) * lyah2glm(b));
	}

	lyah::quat<std::float_t> operator/(lyah::quat<std::float_t> a, std::float_t b) {
		return glm2lyah(lyah2glm(a) / b);
	}

	lyah::quat<std::float_t> conjugate(lyah::quat<std::float_t> a) {
		return glm2lyah(glm::conjugate(lyah2glm(a)));
	}

	std::float_t dot(lyah::quat<std::float_t> a, lyah::quat<std::float_t> b) {
		return glm::dot(lyah2glm(a), lyah2glm(b));
	}

	lyah::quat<std::float_t> inverse(lyah::quat<std::float_t> a) {
		return glm2lyah(glm::inverse(lyah2glm(a)));
	}

	std::float_t length(lyah::quat<std::float_t> a) {
		return glm::length(lyah2glm(a));
	}

	std::float_t lengthSquared(lyah::quat<std::float_t> a) {
		glm::quat a2 = lyah2glm(a);

		return glm::dot(a2, a2);
	}

	std::float_t distance(lyah::quat<std::float_t> a, lyah::quat<std::float_t> b) {
		return glm::length(lyah2glm(b) - lyah2glm(a));
	}

	std::float_t distanceSquared(lyah::quat<std::float_t> a, lyah::quat<std::float_t> b) {
		glm::quat ab = lyah2glm(b) - lyah2glm(a);

		return glm::dot(ab, ab);
	}

	lyah::quat<std::float_t> normalized(lyah::quat<std::float_t> a) {
		return glm2lyah(glm::normalize(lyah2glm(a)));
	}
}