// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#include "pch.hpp"

#include "test/Generator/Generator.hpp"

template<>
std::double_t next(Generator<std::double_t>& generator) {
	return generator.distribution(generator.engine);
}