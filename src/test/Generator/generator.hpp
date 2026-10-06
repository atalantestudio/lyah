// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

#include "test/Generator/Distribution.hpp"

template<typename T, bool Normalized>
struct Generator;

template<typename T, bool Normalized = false>
struct Generator : public Distribution<T> {
	using Distribution<T>::Distribution;
};

template<std::size_t C, typename T, bool Normalized>
struct Generator<lyah::vec<C, T>, Normalized> : public Distribution<T> {
	using Distribution<T>::Distribution;
};

template<std::size_t M, std::size_t N, typename T, bool Normalized>
struct Generator<lyah::mat<M, N, T>, Normalized> : public Distribution<T> {
	using Distribution<T>::Distribution;
};

template<typename T, bool Normalized>
struct Generator<lyah::quat<T>, Normalized> : public Distribution<T> {
	using Distribution<T>::Distribution;
};

template<typename T>
using NormalizedGenerator = Generator<T, true>;

template<typename T, bool Normalized>
T next(Generator<T, Normalized>& generator) {
	return generator.distribution(generator.engine);
}

template<typename T, bool Normalized>
lyah::vec<2, T> next(Generator<lyah::vec<2, T>, Normalized>& generator) {
	lyah::vec<2, T> a = {
		generator.distribution(generator.engine),
		generator.distribution(generator.engine),
	};

	if constexpr (Normalized) {
		a = lyah::normalized(a);
	}

	return a;
}

template<typename T, bool Normalized>
lyah::vec<3, T> next(Generator<lyah::vec<3, T>, Normalized>& generator) {
	lyah::vec<3, T> a = {
		generator.distribution(generator.engine),
		generator.distribution(generator.engine),
		generator.distribution(generator.engine),
	};

	if constexpr (Normalized) {
		a = lyah::normalized(a);
	}

	return a;
}

template<typename T, bool Normalized>
lyah::vec<4, T> next(Generator<lyah::vec<4, T>, Normalized>& generator) {
	lyah::vec<4, T> a = {
		generator.distribution(generator.engine),
		generator.distribution(generator.engine),
		generator.distribution(generator.engine),
		generator.distribution(generator.engine),
	};

	if constexpr (Normalized) {
		a = lyah::normalized(a);
	}

	return a;
}

template<std::size_t M, typename T>
lyah::mat<M, 2, T> next(Generator<lyah::mat<M, 2, T>, false>& generator) {
	return {
		generator.distribution(generator.engine), generator.distribution(generator.engine),
		generator.distribution(generator.engine), generator.distribution(generator.engine),
	};
}

template<std::size_t M, typename T>
lyah::mat<M, 3, T> next(Generator<lyah::mat<M, 3, T>, false>& generator) {
	return {
		generator.distribution(generator.engine), generator.distribution(generator.engine), generator.distribution(generator.engine),
		generator.distribution(generator.engine), generator.distribution(generator.engine), generator.distribution(generator.engine),
		generator.distribution(generator.engine), generator.distribution(generator.engine), generator.distribution(generator.engine),
	};
}

template<std::size_t M, typename T>
lyah::mat<M, 4, T> next(Generator<lyah::mat<M, 4, T>, false>& generator) {
	return {
		generator.distribution(generator.engine), generator.distribution(generator.engine), generator.distribution(generator.engine), generator.distribution(generator.engine),
		generator.distribution(generator.engine), generator.distribution(generator.engine), generator.distribution(generator.engine), generator.distribution(generator.engine),
		generator.distribution(generator.engine), generator.distribution(generator.engine), generator.distribution(generator.engine), generator.distribution(generator.engine),
		generator.distribution(generator.engine), generator.distribution(generator.engine), generator.distribution(generator.engine), generator.distribution(generator.engine),
	};
}

template<typename T, bool Normalized>
lyah::quat<T> next(Generator<lyah::quat<T>, Normalized>& generator) {
	lyah::quat<T> a = {
		generator.distribution(generator.engine),
		generator.distribution(generator.engine),
		generator.distribution(generator.engine),
		generator.distribution(generator.engine),
	};

	if constexpr (Normalized) {
		a = lyah::normalized(a);
	}

	return a;
}