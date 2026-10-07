// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace glm_adapter {
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
}