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
		// glm::infinitePerspectiveLH_ZO does not reverse depth.
		const T f = 1 / glm::tan(fieldOfView / 2);
		const T r = aspectRatio;
		const T n = nearPlane;

		glm::mat<4, 4, T> a = glm::zero<glm::mat<4, 4, T>>();
		a[0][0] = f / r;
		a[1][1] = f;
		a[2][2] = 0;
		a[2][3] = 1;
		a[3][2] = n;

		return glm2lyah(a);
	}
}