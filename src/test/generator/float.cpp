// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#include "pch.hpp"

#include "test/generator/generator.hpp"

template<>
std::float_t next(Generator<std::float_t>& generator) {
	return generator.distribution(generator.engine);
}

template<>
std::double_t next(Generator<std::double_t>& generator) {
	return generator.distribution(generator.engine);
}

template<>
lyah::vec<2, std::float_t> next(Generator<lyah::vec<2, std::float_t>>& generator) {
	return {
		generator.distribution(generator.engine),
		generator.distribution(generator.engine),
	};
}

template<>
lyah::vec<3, std::float_t> next(Generator<lyah::vec<3, std::float_t>>& generator) {
	return {
		generator.distribution(generator.engine),
		generator.distribution(generator.engine),
		generator.distribution(generator.engine),
	};
}

template<>
lyah::vec<4, std::float_t> next(Generator<lyah::vec<4, std::float_t>>& generator) {
	return {
		generator.distribution(generator.engine),
		generator.distribution(generator.engine),
		generator.distribution(generator.engine),
		generator.distribution(generator.engine),
	};
}

template<>
lyah::quat<std::float_t> next(Generator<lyah::quat<std::float_t>>& generator) {
	return {
		generator.distribution(generator.engine),
		generator.distribution(generator.engine),
		generator.distribution(generator.engine),
		generator.distribution(generator.engine),
	};
}