// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace glm_adapter {
	template<typename T>
	inline T floor(T x) {
		return glm::floor(x);
	}

	template<std::size_t C, typename T>
	inline lyah::vec<C, T> floor(lyah::vec<C, T> x) {
		return glm2lyah(glm::floor(lyah2glm(x)));
	}

	template<typename T>
	inline T ceil(T x) {
		return glm::ceil(x);
	}

	template<std::size_t C, typename T>
	inline lyah::vec<C, T> ceil(lyah::vec<C, T> x) {
		return glm2lyah(glm::ceil(lyah2glm(x)));
	}

	template<typename T, typename = std::enable_if<std::is_unsigned<T>::value>::type>
	inline T ceil(T x, T y) {
		return glm::ceilMultiple(x, y);
	}

	template<typename T>
	inline T round(T x) {
		return glm::round(x);
	}

	template<std::size_t C, typename T>
	inline lyah::vec<C, T> round(lyah::vec<C, T> x) {
		return glm2lyah(glm::round(lyah2glm(x)));
	}
}