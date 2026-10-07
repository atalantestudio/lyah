// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

#include "Generator/Distribution.hpp"
#include "Generator/GeneratorFlags.hpp"

template<typename T, GeneratorFlags Flags>
struct Generator;

template<typename T, GeneratorFlags Flags = GeneratorFlags::NONE>
struct Generator : public Distribution<T> {
	using Distribution<T>::Distribution;
};

template<std::size_t C, typename T, GeneratorFlags Flags>
struct Generator<lyah::vec<C, T>, Flags> : public Distribution<T> {
	using Distribution<T>::Distribution;
};

template<std::size_t M, std::size_t N, typename T, GeneratorFlags Flags>
struct Generator<lyah::mat<M, N, T>, Flags> : public Distribution<T> {
	using Distribution<T>::Distribution;
};

template<typename T, GeneratorFlags Flags>
struct Generator<lyah::quat<T>, Flags> : public Distribution<T> {
	using Distribution<T>::Distribution;
};

template<typename T>
using NormalizedGenerator = Generator<T, GeneratorFlags::NORMALIZED>;

template<typename T>
using PowerOf2Generator = Generator<T, GeneratorFlags::POWER_OF_2>;

template<typename T, GeneratorFlags Flags>
T next(Generator<T, Flags>& generator) {
	T a = generator.distribution(generator.engine);

	if constexpr (Flags & GeneratorFlags::POWER_OF_2) {
		a = std::exp2(a);
	}

	return a;
}

template<typename T, GeneratorFlags Flags>
lyah::vec<2, T> next(Generator<lyah::vec<2, T>, Flags>& generator) {
	lyah::vec<2, T> a = {
		generator.distribution(generator.engine),
		generator.distribution(generator.engine),
	};

	if constexpr (Flags & GeneratorFlags::NORMALIZED) {
		a = lyah::normalized(a);
	}

	return a;
}

template<typename T, GeneratorFlags Flags>
lyah::vec<3, T> next(Generator<lyah::vec<3, T>, Flags>& generator) {
	lyah::vec<3, T> a = {
		generator.distribution(generator.engine),
		generator.distribution(generator.engine),
		generator.distribution(generator.engine),
	};

	if constexpr (Flags & GeneratorFlags::NORMALIZED) {
		a = lyah::normalized(a);
	}

	return a;
}

template<typename T, GeneratorFlags Flags>
lyah::vec<4, T> next(Generator<lyah::vec<4, T>, Flags>& generator) {
	lyah::vec<4, T> a = {
		generator.distribution(generator.engine),
		generator.distribution(generator.engine),
		generator.distribution(generator.engine),
		generator.distribution(generator.engine),
	};

	if constexpr (Flags & GeneratorFlags::NORMALIZED) {
		a = lyah::normalized(a);
	}

	return a;
}

template<std::size_t M, typename T>
lyah::mat<M, 2, T> next(Generator<lyah::mat<M, 2, T>, GeneratorFlags::NONE>& generator) {
	return {
		generator.distribution(generator.engine), generator.distribution(generator.engine),
		generator.distribution(generator.engine), generator.distribution(generator.engine),
	};
}

template<std::size_t M, typename T>
lyah::mat<M, 3, T> next(Generator<lyah::mat<M, 3, T>, GeneratorFlags::NONE>& generator) {
	return {
		generator.distribution(generator.engine), generator.distribution(generator.engine), generator.distribution(generator.engine),
		generator.distribution(generator.engine), generator.distribution(generator.engine), generator.distribution(generator.engine),
		generator.distribution(generator.engine), generator.distribution(generator.engine), generator.distribution(generator.engine),
	};
}

template<std::size_t M, typename T>
lyah::mat<M, 4, T> next(Generator<lyah::mat<M, 4, T>, GeneratorFlags::NONE>& generator) {
	return {
		generator.distribution(generator.engine), generator.distribution(generator.engine), generator.distribution(generator.engine), generator.distribution(generator.engine),
		generator.distribution(generator.engine), generator.distribution(generator.engine), generator.distribution(generator.engine), generator.distribution(generator.engine),
		generator.distribution(generator.engine), generator.distribution(generator.engine), generator.distribution(generator.engine), generator.distribution(generator.engine),
		generator.distribution(generator.engine), generator.distribution(generator.engine), generator.distribution(generator.engine), generator.distribution(generator.engine),
	};
}

template<typename T, GeneratorFlags Flags>
lyah::quat<T> next(Generator<lyah::quat<T>, Flags>& generator) {
	lyah::quat<T> a = {
		generator.distribution(generator.engine),
		generator.distribution(generator.engine),
		generator.distribution(generator.engine),
		generator.distribution(generator.engine),
	};

	if constexpr (Flags & GeneratorFlags::NORMALIZED) {
		a = lyah::normalized(a);
	}

	return a;
}