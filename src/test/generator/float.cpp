// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

//#include "pch.hpp"

//#include "test/generator/generator.hpp"

template<>
struct Generator<std::float_t> : public BaseGenerator {
	using BaseGenerator::BaseGenerator;

	std::uniform_real_distribution<std::float_t> distribution;
};

template<>
inline std::float_t next(Generator<std::float_t>& generator) {
	return generator.distribution(generator.engine);
}

template<>
struct Generator<lyah::vec<2, std::float_t>> : public BaseGenerator {
	using BaseGenerator::BaseGenerator;

	std::uniform_real_distribution<std::float_t> distribution;
};

template<>
inline lyah::vec<2, std::float_t> next(Generator<lyah::vec<2, std::float_t>>& generator) {
	return {
		generator.distribution(generator.engine),
		generator.distribution(generator.engine),
	};
}