// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

template<typename T>
inline bool compare(T a, T b) {
	return a == b;
}

template<>
inline bool compare(std::float_t a, std::float_t b) {
	constexpr std::float_t epsilon = 1e-4f;

	return abs(a - b) <= epsilon;
}

template<>
inline bool compare(std::double_t a, std::double_t b) {
	constexpr std::double_t epsilon = 1e-4;

	return abs(a - b) <= epsilon;
}

template<typename T>
inline bool compare(lyah::vec<2, T> a, lyah::vec<2, T> b) {
	constexpr T epsilon = static_cast<T>(1e-4);

	return (
		abs(a.x - b.x) <= epsilon &&
		abs(a.y - b.y) <= epsilon
	);
}

template<typename T>
inline bool compare(lyah::vec<3, T> a, lyah::vec<3, T> b) {
	constexpr T epsilon = static_cast<T>(1e-4);

	return (
		abs(a.x - b.x) <= epsilon &&
		abs(a.y - b.y) <= epsilon &&
		abs(a.z - b.z) <= epsilon
	);
}

template<typename T>
inline bool compare(lyah::vec<4, T> a, lyah::vec<4, T> b) {
	constexpr T epsilon = static_cast<T>(1e-4);

	return (
		abs(a.x - b.x) <= epsilon &&
		abs(a.y - b.y) <= epsilon &&
		abs(a.z - b.z) <= epsilon &&
		abs(a.w - b.w) <= epsilon
	);
}

template<typename T>
inline bool compare(lyah::quat<T> a, lyah::quat<T> b) {
	constexpr T epsilon = static_cast<T>(1e-4);

	return (
		abs(a.w - b.w) <= epsilon &&
		abs(a.x - b.x) <= epsilon &&
		abs(a.y - b.y) <= epsilon &&
		abs(a.z - b.z) <= epsilon
	);
}