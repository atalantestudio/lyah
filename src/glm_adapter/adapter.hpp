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

#include "glm_adapter/serialization.hpp"

#include "glm_adapter/types/vec.hpp"
#include "glm_adapter/types/quat.hpp"

#include "glm_adapter/common.hpp"
#include "glm_adapter/constants.hpp"
#include "glm_adapter/exponential.hpp"
#include "glm_adapter/geometric.hpp"
#include "glm_adapter/rounding.hpp"
#include "glm_adapter/trigonometric.hpp"