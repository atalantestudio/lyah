// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#include "pch.hpp"

#include "test/TestGroup.hpp"

template<>
const char* TestGroup<std::int64_t>::getGroupName() {
	return "int64_t";
}

template<>
void TestGroup<std::int64_t>::runTestsInternal(std::mt19937& engine) {
	typedef std::int64_t S;

	Generator<S> scalar(engine, -64, 64);
	Generator<S> positiveScalar(engine, 0, 128);

	// Common
	runTest<S>("Absolute value", lyah::abs, glm_adapter::abs, scalar);
	runTest<S>("Minimum", lyah::min, glm_adapter::min, scalar, scalar);
	runTest<S>("Maximum", lyah::max, glm_adapter::max, scalar, scalar);
	runTest<S>("Clamp", lyah::clamp, glm_adapter::clamp, scalar, scalar, scalar);
}