// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

template<typename T>
struct Comparator {
	static bool compare(bool x, bool y) {
		return x == y;
	}

	static bool compare(std::float_t x, std::float_t y) {
		constexpr std::float_t epsilon = 0.01f;

		return std::abs(y - x) <= epsilon;
	}

	static bool compare(std::double_t x, std::double_t y) {
		constexpr std::double_t epsilon = 0.01;

		return std::abs(y - x) <= epsilon;
	}

	static bool compare(std::int32_t x, std::int32_t y) {
		return x == y;
	}

	static bool compare(std::int64_t x, std::int64_t y) {
		return x == y;
	}

	static bool compare(std::uint32_t x, std::uint32_t y) {
		return x == y;
	}

	static bool compare(std::uint64_t x, std::uint64_t y) {
		return x == y;
	}
};

template<typename T>
struct Comparator<lyah::vec<2, T>> {
	static bool compare(lyah::vec<2, T> x, lyah::vec<2, T> y) {
		return (
			Comparator<T>::compare(x.x, y.x) &&
			Comparator<T>::compare(x.y, y.y)
		);
	}
};

template<typename T>
struct Comparator<lyah::vec<3, T>> {
	static bool compare(lyah::vec<3, T> x, lyah::vec<3, T> y) {
		return (
			Comparator<T>::compare(x.x, y.x) &&
			Comparator<T>::compare(x.y, y.y) &&
			Comparator<T>::compare(x.z, y.z)
		);
	}
};

template<typename T>
struct Comparator<lyah::vec<4, T>> {
	static bool compare(lyah::vec<4, T> x, lyah::vec<4, T> y) {
		return (
			Comparator<T>::compare(x.x, y.x) &&
			Comparator<T>::compare(x.y, y.y) &&
			Comparator<T>::compare(x.z, y.z) &&
			Comparator<T>::compare(x.w, y.w)
		);
	}
};

template<typename T>
struct Comparator<lyah::mat<2, 2, T>> {
	static bool compare(lyah::mat<2, 2, T> x, lyah::mat<2, 2, T> y) {
		return (
			Comparator<lyah::vec<2, T>>::compare(x[0], y[0]) &&
			Comparator<lyah::vec<2, T>>::compare(x[1], y[1])
		);
	}
};

template<typename T>
struct Comparator<lyah::mat<3, 3, T>> {
	static bool compare(lyah::mat<3, 3, T> x, lyah::mat<3, 3, T> y) {
		return (
			Comparator<lyah::vec<3, T>>::compare(x[0], y[0]) &&
			Comparator<lyah::vec<3, T>>::compare(x[1], y[1]) &&
			Comparator<lyah::vec<3, T>>::compare(x[2], y[2])
		);
	}
};

template<typename T>
struct Comparator<lyah::mat<4, 4, T>> {
	static bool compare(lyah::mat<4, 4, T> x, lyah::mat<4, 4, T> y) {
		return (
			Comparator<lyah::vec<4, T>>::compare(x[0], y[0]) &&
			Comparator<lyah::vec<4, T>>::compare(x[1], y[1]) &&
			Comparator<lyah::vec<4, T>>::compare(x[2], y[2]) &&
			Comparator<lyah::vec<4, T>>::compare(x[3], y[3])
		);
	}
};

template<typename T>
struct Comparator<lyah::quat<T>> {
	static bool compare(lyah::quat<T> x, lyah::quat<T> y) {
		return (
			Comparator<T>::compare(x.w, y.w) &&
			Comparator<T>::compare(x.x, y.x) &&
			Comparator<T>::compare(x.y, y.y) &&
			Comparator<T>::compare(x.z, y.z)
		);
	}
};