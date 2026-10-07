// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#include "pch.hpp"

#include "TestGroup.hpp"

template<>
const char* TestGroup<std::uint32_t>::getGroupName() {
	return "uint32_t";
}

template<>
void TestGroup<std::uint32_t>::runTestsInternal(std::mt19937& engine) {
	typedef std::uint32_t S;

	Generator<S> scalar(engine, 0, 128);
	Generator<S> positiveNonZeroScalar(engine, 1, 128);

	// Common
	runTest<S>("Minimum", lyah::min, glm_adapter::min, scalar, scalar);
	runTest<S>("Maximum", lyah::max, glm_adapter::max, scalar, scalar);
	runTest<S>("Clamp", lyah::clamp, glm_adapter::clamp, scalar, scalar, scalar);

	// Rounding
	runTest<S>("Ceil", lyah::ceil, glm_adapter::ceil, scalar, positiveNonZeroScalar);
}