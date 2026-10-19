// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace glm_adapter {
	template<typename T>
	inline lyah::mat<3, 3, T> orthographic(lyah::vec<2, T> o, lyah::vec<2, T> v) {
		return glm2lyah(glm::mat<3, 3, T>{
			 2 / v.x,  0,       0,
			 0,        2 / v.y, 0,
			 o.x,      o.y,     1,
		});
	}

	template<typename T>
	inline lyah::mat<3, 3, T> orthographicScreen(lyah::vec<2, T> v) {
		return glm2lyah(glm::mat<3, 3, T>{
			 2 / v.x,  0,       0,
			 0,       -2 / v.y, 0,
			-1,        1,       1,
		});
	}

	template<typename T>
	inline lyah::mat<4, 4, T> orthographic(T l, T r, T b, T t, T n, T f) {
		return glm2lyah(glm::orthoLH_ZO(l, r, b, t, n, f));
	}

	template<typename T>
	inline lyah::mat<4, 4, T> perspective(T fieldOfView, T aspectRatio, T nearPlane, T farPlane) {
		return glm2lyah(glm::perspectiveLH_ZO(fieldOfView, aspectRatio, nearPlane, farPlane));
	}

	template<typename T>
	inline lyah::mat<4, 4, T> perspectiveReversedZ(T fieldOfView, T aspectRatio, T nearPlane) {
		return glm2lyah(glm::infinitePerspectiveLH_ZO(fieldOfView, aspectRatio, nearPlane));
	}
}