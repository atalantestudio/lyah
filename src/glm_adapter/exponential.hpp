// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#include "pch.hpp"

#include "glm_adapter/adapter.hpp"

namespace glm_adapter {
	template<typename T>
	inline T log2(T x) {
		return glm::log2(x);
	}

	template<typename T>
	inline T pow(T x, T y) {
		return glm::pow(x, y);
	}

	template<std::size_t C, typename T>
	inline lyah::vec<C, T> pow(lyah::vec<C, T> x, T y) {
		return glm2lyah(glm::pow(lyah2glm(x), glm::vec<C, T>(y)));
	}

	template<std::size_t C, typename T>
	inline lyah::vec<C, T> pow(lyah::vec<C, T> x, lyah::vec<C, T> y) {
		return glm2lyah(glm::pow(lyah2glm(x), lyah2glm(y)));
	}

	template<typename T>
	inline T sqrt(T x) {
		return glm::sqrt(x);
	}

	template<std::size_t C, typename T>
	inline lyah::vec<C, T> sqrt(lyah::vec<C, T> x) {
		return glm2lyah(glm::sqrt(lyah2glm(x)));
	}
}