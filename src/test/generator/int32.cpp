// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#include "pch.hpp"

#include "test/generator/generator.hpp"

/*template<>
struct IntervalGenerator<std::int32_t> : public BaseGenerator {
	explicit IntervalGenerator(std::mt19937& engine, std::int32_t min, std::int32_t max) :
		BaseGenerator(engine),
		distribution(min, max)
	{}

	std::uniform_int_distribution<std::mt19937::result_type> distribution;
};

template<>
std::int32_t next(IntervalGenerator<std::int32_t>& generator) {
	return generator.distribution(generator.engine);
}*/