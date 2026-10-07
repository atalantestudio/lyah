// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace glm_adapter {
	template<typename T>
	inline lyah::quat<T> identity() {
		return glm2lyah(glm::identity<glm::qua<T>>());
	}

	template<typename T>
	inline lyah::quat<T> axisAngle(lyah::vec<3, T> axis, T angle) {
		return glm2lyah(glm::angleAxis(angle, lyah2glm(axis)));
	}

	template<typename T>
	inline bool operator==(lyah::quat<T> a, lyah::quat<T> b) {
		return lyah2glm(a) == lyah2glm(b);
	}

	template<typename T>
	inline bool operator!=(lyah::quat<T> a, lyah::quat<T> b) {
		return lyah2glm(a) != lyah2glm(b);
	}

	template<typename T>
	inline lyah::quat<T> operator+(lyah::quat<T> a) {
		return glm2lyah(+lyah2glm(a));
	}

	template<typename T>
	inline lyah::quat<T> operator-(lyah::quat<T> a) {
		return glm2lyah(-lyah2glm(a));
	}

	template<typename T>
	inline lyah::quat<T> operator+(lyah::quat<T> a, lyah::quat<T> b) {
		return glm2lyah(lyah2glm(a) + lyah2glm(b));
	}

	template<typename T>
	inline lyah::quat<T> operator-(lyah::quat<T> a, lyah::quat<T> b) {
		return glm2lyah(lyah2glm(a) - lyah2glm(b));
	}

	template<typename T>
	inline lyah::quat<T> operator*(lyah::quat<T> a, T b) {
		return glm2lyah(lyah2glm(a) * b);
	}

	template<typename T>
	inline lyah::quat<T> operator*(T a, lyah::quat<T> b) {
		return glm2lyah(a * lyah2glm(b));
	}

	template<typename T>
	inline lyah::quat<T> operator*(lyah::quat<T> a, lyah::quat<T> b) {
		return glm2lyah(lyah2glm(a) * lyah2glm(b));
	}

	template<typename T>
	inline lyah::quat<T> operator/(lyah::quat<T> a, T b) {
		return glm2lyah(lyah2glm(a) / b);
	}

	template<typename T>
	inline lyah::quat<T> conjugate(lyah::quat<T> a) {
		return glm2lyah(glm::conjugate(lyah2glm(a)));
	}

	template<typename T>
	inline lyah::quat<T> inverse(lyah::quat<T> a) {
		return glm2lyah(glm::inverse(lyah2glm(a)));
	}
}