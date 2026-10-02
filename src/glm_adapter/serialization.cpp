// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#include "pch.hpp"

#include "glm_adapter/serialization.hpp"

template<typename T>
std::ostream& operator<<(std::ostream& stream, lyah::vec<2, T> a) {
	return stream << a.x << ' ' << a.y;
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, lyah::vec<3, T> a) {
	return stream << a.x << ' ' << a.y << ' ' << a.z;
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, lyah::vec<4, T> a) {
	return stream << a.x << ' ' << a.y << ' ' << a.z << ' ' << a.w;
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, lyah::quat<T> a) {
	return stream << a.w << ' ' << a.x << ' ' << a.y << ' ' << a.z;
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, lyah::mat<2, 2, T> a) {
	stream << a[0].x << ' ' << a[0].y << '\n';
	stream << a[1].x << ' ' << a[1].y << '\n';

	return stream;
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, lyah::mat<3, 3, T> a) {
	stream << a[0].x << ' ' << a[0].y << ' ' << a[0].z << '\n';
	stream << a[1].x << ' ' << a[1].y << ' ' << a[1].z << '\n';
	stream << a[2].x << ' ' << a[2].y << ' ' << a[2].z << '\n';

	return stream;
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, lyah::mat<4, 4, T> a) {
	stream << a[0].x << ' ' << a[0].y << ' ' << a[0].z << ' ' << a[0].w << '\n';
	stream << a[1].x << ' ' << a[1].y << ' ' << a[1].z << ' ' << a[1].w << '\n';
	stream << a[2].x << ' ' << a[2].y << ' ' << a[2].z << ' ' << a[2].w << '\n';
	stream << a[3].x << ' ' << a[3].y << ' ' << a[3].z << ' ' << a[3].w << '\n';

	return stream;
}