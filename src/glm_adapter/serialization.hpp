// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

template<typename T>
std::ostream& operator<<(std::ostream& stream, lyah::vec<2, T> a);

template std::ostream& operator<<(std::ostream& stream, lyah::vec<2, std::float_t> a);
template std::ostream& operator<<(std::ostream& stream, lyah::vec<2, std::double_t> a);
template std::ostream& operator<<(std::ostream& stream, lyah::vec<2, std::int32_t> a);
template std::ostream& operator<<(std::ostream& stream, lyah::vec<2, std::int64_t> a);

template<typename T>
std::ostream& operator<<(std::ostream& stream, lyah::vec<3, T> a);

template std::ostream& operator<<(std::ostream& stream, lyah::vec<3, std::float_t> a);
template std::ostream& operator<<(std::ostream& stream, lyah::vec<3, std::double_t> a);
template std::ostream& operator<<(std::ostream& stream, lyah::vec<3, std::int32_t> a);
template std::ostream& operator<<(std::ostream& stream, lyah::vec<3, std::int64_t> a);

template<typename T>
std::ostream& operator<<(std::ostream& stream, lyah::vec<4, T> a);

template std::ostream& operator<<(std::ostream& stream, lyah::vec<4, std::float_t> a);
template std::ostream& operator<<(std::ostream& stream, lyah::vec<4, std::double_t> a);
template std::ostream& operator<<(std::ostream& stream, lyah::vec<4, std::int32_t> a);
template std::ostream& operator<<(std::ostream& stream, lyah::vec<4, std::int64_t> a);

template<typename T>
std::ostream& operator<<(std::ostream& stream, lyah::quat<T> a);

template std::ostream& operator<<(std::ostream& stream, lyah::quat<std::float_t> a);
template std::ostream& operator<<(std::ostream& stream, lyah::quat<std::double_t> a);

template<typename T>
std::ostream& operator<<(std::ostream& stream, lyah::mat<2, 2, T> a);

template std::ostream& operator<<(std::ostream& stream, lyah::mat<2, 2, std::float_t> a);
template std::ostream& operator<<(std::ostream& stream, lyah::mat<2, 2, std::double_t> a);

template<typename T>
std::ostream& operator<<(std::ostream& stream, const lyah::mat<3, 3, T>& a);

template std::ostream& operator<<(std::ostream& stream, const lyah::mat<3, 3, std::float_t>& a);
template std::ostream& operator<<(std::ostream& stream, const lyah::mat<3, 3, std::double_t>& a);

template<typename T>
std::ostream& operator<<(std::ostream& stream, const lyah::mat<4, 4, T>& a);

template std::ostream& operator<<(std::ostream& stream, const lyah::mat<4, 4, std::float_t>& a);
template std::ostream& operator<<(std::ostream& stream, const lyah::mat<4, 4, std::double_t>& a);

namespace glm_adapter {
	using namespace lyah;

	inline glm::vec2 lyah2glm(vec2<std::float_t> a) {
		return *static_cast<const glm::vec2*>(static_cast<const void*>(&a));
	}

	inline glm::vec3 lyah2glm(vec3<std::float_t> a) {
		return *static_cast<const glm::vec3*>(static_cast<const void*>(&a));
	}

	inline glm::vec4 lyah2glm(vec4<std::float_t> a) {
		return *static_cast<const glm::vec4*>(static_cast<const void*>(&a));
	}

	inline glm::quat lyah2glm(quat<std::float_t> a) {
		return {a.w, a.x, a.y, a.z};
	}

	inline vec2<std::float_t> glm2lyah(glm::vec2 a) {
		return *static_cast<const vec2<std::float_t>*>(static_cast<const void*>(&a));
	}

	inline vec3<std::float_t> glm2lyah(glm::vec3 a) {
		return *static_cast<const vec3<std::float_t>*>(static_cast<const void*>(&a));
	}

	inline vec4<std::float_t> glm2lyah(glm::vec4 a) {
		return *static_cast<const vec4<std::float_t>*>(static_cast<const void*>(&a));
	}

	inline quat<std::float_t> glm2lyah(glm::quat a) {
		return {a.w, a.x, a.y, a.z};
	}
}