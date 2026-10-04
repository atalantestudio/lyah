// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#include "pch.hpp"

#include "glm_adapter/adapter.hpp"

namespace glm_adapter {
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