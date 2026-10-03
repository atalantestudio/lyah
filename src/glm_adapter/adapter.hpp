// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace glm_adapter {
	template<typename T>
	inline glm::vec<2, T> lyah2glm(lyah::vec<2, T> a) {
		return {a.x, a.y};
	}

	template<typename T>
	inline glm::vec<3, T> lyah2glm(lyah::vec<3, T> a) {
		return {a.x, a.y, a.z};
	}

	template<typename T>
	inline glm::vec<4, T> lyah2glm(lyah::vec<4, T> a) {
		return {a.x, a.y, a.z, a.w};
	}

	template<typename T>
	inline glm::qua<T> lyah2glm(lyah::quat<T> a) {
		return {a.w, a.x, a.y, a.z};
	}
}

namespace glm_adapter {
	template<typename T>
	inline lyah::vec<2, T> glm2lyah(glm::vec<2, T> a) {
		return {a.x, a.y};
	}

	template<typename T>
	inline lyah::vec<3, T> glm2lyah(glm::vec<3, T> a) {
		return {a.x, a.y, a.z};
	}

	template<typename T>
	inline lyah::vec<4, T> glm2lyah(glm::vec<4, T> a) {
		return {a.x, a.y, a.z, a.w};
	}

	template<typename T>
	inline lyah::quat<T> glm2lyah(glm::qua<T> a) {
		return {a.w, a.x, a.y, a.z};
	}
}

namespace glm_adapter {
	template<typename T>
	T identity();

	// quat<float_t>
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

	// quat<double_t>
	lyah::quat<std::double_t> axisAngle(lyah::vec<3, std::double_t> axis, std::double_t angle);
	bool operator==(lyah::quat<std::double_t> a, lyah::quat<std::double_t> b);
	bool operator!=(lyah::quat<std::double_t> a, lyah::quat<std::double_t> b);
	lyah::quat<std::double_t> operator+(lyah::quat<std::double_t> a);
	lyah::quat<std::double_t> operator-(lyah::quat<std::double_t> a);
	lyah::quat<std::double_t> operator+(lyah::quat<std::double_t> a, lyah::quat<std::double_t> b);
	lyah::quat<std::double_t> operator-(lyah::quat<std::double_t> a, lyah::quat<std::double_t> b);
	lyah::quat<std::double_t> operator*(lyah::quat<std::double_t> a, std::double_t b);
	lyah::quat<std::double_t> operator*(std::double_t a, lyah::quat<std::double_t> b);
	lyah::quat<std::double_t> operator*(lyah::quat<std::double_t> a, lyah::quat<std::double_t> b);
	lyah::quat<std::double_t> operator/(lyah::quat<std::double_t> a, std::double_t b);
	lyah::quat<std::double_t> conjugate(lyah::quat<std::double_t> a);
	std::double_t dot(lyah::quat<std::double_t> a, lyah::quat<std::double_t> b);
	lyah::quat<std::double_t> inverse(lyah::quat<std::double_t> a);
	std::double_t length(lyah::quat<std::double_t> a);
	std::double_t lengthSquared(lyah::quat<std::double_t> a);
	std::double_t distance(lyah::quat<std::double_t> a, lyah::quat<std::double_t> b);
	std::double_t distanceSquared(lyah::quat<std::double_t> a, lyah::quat<std::double_t> b);
	lyah::quat<std::double_t> normalized(lyah::quat<std::double_t> a);
}