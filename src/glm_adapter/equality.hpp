// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

template<typename T>
inline bool compare(T a, T b) {
	return a == b;
}

template<>
inline bool compare(std::float_t a, std::float_t b) {
	return abs(a - b) <= 1e-4f;
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