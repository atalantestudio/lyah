// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace glm_adapter {
	template<typename T>
	T floatlerp(T a, T b, T c) {
		return glm::lerp(a, b, c);
	}

	inline lyah::vec<2, std::float_t> lerp(lyah::vec<2, std::float_t> a, lyah::vec<2, std::float_t> b, lyah::vec<2, std::float_t> c) {
		return glm2lyah(glm::lerp(lyah2glm(a), lyah2glm(b), lyah2glm(c)));
	}
}