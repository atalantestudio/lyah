// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#include "pch.hpp"

#include "glm_adapter/adapter.hpp"

namespace glm_adapter {
	template<typename T>
	inline T fma(T x, T y, T z) {
		return glm::fma(x, y, z);
	}

	template<typename T>
	inline T abs(T x) {
		return glm::abs(x);
	}

	template<typename T>
	inline T min(T x, T y) {
		return glm::min(x, y);
	}

	template<typename T>
	inline T max(T x, T y) {
		return glm::max(x, y);
	}

	template<typename T>
	inline T clamp(T x, T min, T max) {
		return glm::clamp(x, min, max);
	}

	template<typename T>
	inline T lerp(T a, T b, T t) {
		return glm::mix(a, b, t);
	}

	template<typename T>
	inline T epsilon() {
		return glm::epsilon<T>();
	}

	template<typename T>
	inline T pi() {
		return glm::pi<T>();
	}

	template<typename T>
	inline T tau() {
		return glm::tau<T>();
	}

	template<typename T>
	inline T log2(T x) {
		return glm::log2(x);
	}

	template<typename T>
	inline T pow(T x, T y) {
		return glm::pow(x, y);
	}

	template<typename T>
	inline T sqrt(T x) {
		return glm::sqrt(x);
	}

	template<typename T>
	inline T floor(T x) {
		return glm::floor(x);
	}

	template<typename T>
	inline T ceil(T x) {
		return glm::ceil(x);
	}

	template<typename T>
	inline T round(T x) {
		return glm::round(x);
	}

	template<typename T>
	inline T degrees(T radians) {
		return glm::degrees(radians);
	}

	template<typename T>
	inline T radians(T degrees) {
		return glm::radians(degrees);
	}

	template<typename T>
	inline T sin(T x) {
		return glm::sin(x);
	}

	template<typename T>
	inline T cos(T x) {
		return glm::cos(x);
	}

	template<typename T>
	inline T tan(T x) {
		return glm::tan(x);
	}

	template<typename T>
	inline T asin(T x) {
		return glm::asin(x);
	}

	template<typename T>
	inline T acos(T x) {
		return glm::acos(x);
	}

	template<typename T>
	inline T atan(T x) {
		return glm::atan(x);
	}
}