// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#include "pch.hpp"

#include "glm_adapter/adapter.hpp"

namespace glm_adapter {
	template<typename T>
	inline T parallelogramArea(lyah::vec<2, T> a, lyah::vec<2, T> b) {
		return glm::determinant(glm::mat<2, 2, T>(lyah2glm(a), lyah2glm(b)));
	}

	template<typename T>
	inline lyah::vec<2, T> perpendicularLeft(lyah::vec<2, T> a) {
		return {-a.y, a.x};
	}

	template<typename T>
	inline lyah::vec<2, T> perpendicularRight(lyah::vec<2, T> a) {
		return {a.y, -a.x};
	}

	template<typename T>
	inline lyah::vec<3, T> cross(lyah::vec<3, T> a, lyah::vec<3, T> b) {
		return glm2lyah(glm::cross(lyah2glm(a), lyah2glm(b)));
	}

	template<std::size_t C, typename T>
	inline T dot(lyah::vec<C, T> a, lyah::vec<C, T> b) {
		return glm::dot(lyah2glm(a), lyah2glm(b));
	}

	template<typename T>
	inline T dot(lyah::quat<T> a, lyah::quat<T> b) {
		return glm::dot(lyah2glm(a), lyah2glm(b));
	}

	template<std::size_t C, typename T>
	inline T length(lyah::vec<C, T> a) {
		return glm::length(lyah2glm(a));
	}

	template<typename T>
	inline T length(lyah::quat<T> a) {
		return glm::length(lyah2glm(a));
	}

	template<std::size_t C, typename T>
	inline T lengthSquared(lyah::vec<C, T> a) {
		return glm::length2(lyah2glm(a));
	}

	template<typename T>
	inline T lengthSquared(lyah::quat<T> a) {
		const glm::qua<T> a2 = lyah2glm(a);

		return glm::dot(a2, a2);
	}

	template<std::size_t C, typename T>
	inline T distance(lyah::vec<C, T> a, lyah::vec<C, T> b) {
		return glm::distance(lyah2glm(a), lyah2glm(b));
	}

	template<typename T>
	inline T distance(lyah::quat<T> a, lyah::quat<T> b) {
		return glm::length(lyah2glm(b) - lyah2glm(a));
	}

	template<std::size_t C, typename T>
	inline T distanceSquared(lyah::vec<C, T> a, lyah::vec<C, T> b) {
		return glm::distance2(lyah2glm(a), lyah2glm(b));
	}

	template<typename T>
	inline T distanceSquared(lyah::quat<T> a, lyah::quat<T> b) {
		const glm::qua<T> ab = lyah2glm(b) - lyah2glm(a);

		return glm::dot(ab, ab);
	}

	template<std::size_t C, typename T>
	inline lyah::vec<C, T> normalized(lyah::vec<C, T> a) {
		return glm2lyah(glm::normalize(lyah2glm(a)));
	}

	template<typename T>
	inline lyah::quat<T> normalized(lyah::quat<T> a) {
		return glm2lyah(glm::normalize(lyah2glm(a)));
	}
}