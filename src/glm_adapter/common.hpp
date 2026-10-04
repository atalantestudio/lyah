// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#include "pch.hpp"

#include "glm_adapter/adapter.hpp"

namespace glm_adapter {
	template<std::size_t C, typename T>
	inline T sum(lyah::vec<C, T> x) {
		return glm::dot(lyah2glm(x), glm::vec<C, T>(1));
	}

	template<typename T>
	inline T abs(T x) {
		return glm::abs(x);
	}

	template<std::size_t C, typename T>
	inline lyah::vec<C, T> abs(lyah::vec<C, T> x) {
		return glm2lyah(glm::abs(lyah2glm(x)));
	}

	template<typename T>
	inline T min(T x, T y) {
		return glm::min(x, y);
	}

	template<std::size_t C, typename T>
	inline lyah::vec<C, T> min(lyah::vec<C, T> x, lyah::vec<C, T> y) {
		return glm2lyah(glm::min(lyah2glm(x), lyah2glm(y)));
	}

	template<typename T>
	inline T max(T x, T y) {
		return glm::max(x, y);
	}

	template<std::size_t C, typename T>
	inline lyah::vec<C, T> max(lyah::vec<C, T> x, lyah::vec<C, T> y) {
		return glm2lyah(glm::max(lyah2glm(x), lyah2glm(y)));
	}

	template<typename T>
	inline T clamp(T x, T min, T max) {
		return glm::clamp(x, min, max);
	}

	template<std::size_t C, typename T>
	inline lyah::vec<C, T> clamp(lyah::vec<C, T> x, lyah::vec<C, T> min, lyah::vec<C, T> max) {
		return glm2lyah(glm::clamp(lyah2glm(x), lyah2glm(min), lyah2glm(max)));
	}

	template<typename T>
	inline T lerp(T a, T b, T t) {
		return glm::mix(a, b, t);
	}

	template<std::size_t C, typename T>
	inline lyah::vec<C, T> lerp(lyah::vec<C, T> a, lyah::vec<C, T> b, T t) {
		return glm2lyah(glm::lerp(lyah2glm(a), lyah2glm(b), t));
	}

	template<std::size_t C, typename T>
	inline lyah::vec<C, T> lerp(lyah::vec<C, T> a, lyah::vec<C, T> b, lyah::vec<C, T> t) {
		return glm2lyah(glm::lerp(lyah2glm(a), lyah2glm(b), lyah2glm(t)));
	}

	template<typename T>
	inline T fma(T x, T y, T z) {
		return glm::fma(x, y, z);
	}

	template<std::size_t C, typename T>
	inline lyah::vec<C, T> fma(lyah::vec<C, T> x, lyah::vec<C, T> y, lyah::vec<C, T> z) {
		return glm2lyah(glm::fma(lyah2glm(x), lyah2glm(y), lyah2glm(z)));
	}
}