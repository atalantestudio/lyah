// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace glm_adapter {
	template<typename T>
	T identity();

	lyah::quat<std::float_t> axisAngle(lyah::vec<3, std::float_t> axis, std::float_t angle);
	bool operator==(lyah::quat<std::float_t> a, lyah::quat<std::float_t> b);
	bool operator!=(lyah::quat<std::float_t> a, lyah::quat<std::float_t> b);
	lyah::quat<std::float_t> operator+(lyah::quat<std::float_t> a);
	lyah::quat<std::float_t> operator-(lyah::quat<std::float_t> a);
	lyah::quat<std::float_t> operator+(lyah::quat<std::float_t> a, lyah::quat<std::float_t> b);
	lyah::quat<std::float_t> operator-(lyah::quat<std::float_t> a, lyah::quat<std::float_t> b);
	lyah::quat<std::float_t> operator*(lyah::quat<std::float_t> a, std::float_t b);
	lyah::quat<std::float_t> operator*(std::float_t a, lyah::quat<std::float_t> b);
	lyah::quat<std::float_t> operator*(lyah::quat<std::float_t> a, lyah::quat<std::float_t> b);
	lyah::quat<std::float_t> operator/(lyah::quat<std::float_t> a, std::float_t b);
	lyah::quat<std::float_t> conjugate(lyah::quat<std::float_t> a);
	std::float_t dot(lyah::quat<std::float_t> a, lyah::quat<std::float_t> b);
	lyah::quat<std::float_t> inverse(lyah::quat<std::float_t> a);
	std::float_t length(lyah::quat<std::float_t> a);
	std::float_t lengthSquared(lyah::quat<std::float_t> a);
	std::float_t distance(lyah::quat<std::float_t> a, lyah::quat<std::float_t> b);
	std::float_t distanceSquared(lyah::quat<std::float_t> a, lyah::quat<std::float_t> b);
	lyah::quat<std::float_t> normalized(lyah::quat<std::float_t> a);
}