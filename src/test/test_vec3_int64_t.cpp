// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#include "pch.hpp"

#include "test/TestGroup.hpp"

template<>
const char* TestGroup<lyah::vec<3, std::int64_t>>::getGroupName() {
	return "vec<3, int64_t>";
}

template<>
void TestGroup<lyah::vec<3, std::int64_t>>::runTestsInternal(std::mt19937& engine) {
	typedef std::int64_t S;
	typedef lyah::vec<3, S> V;

	Generator<S> scalar(engine, -64, 64);
	Generator<S> positiveNonZeroScalar(engine, 1, 128);
	Generator<V> vector(engine, -64, 64);
	Generator<V> positiveNonZeroVector(engine, 1, 128);

	// Comparison
	runTest<bool>("Equality", lyah::operator==, glm_adapter::operator==, vector, vector);
	runTest<bool>("Inequality", lyah::operator!=, glm_adapter::operator!=, vector, vector);

	// Arithmetic
	runTest<V>("Unary plus", lyah::operator+, glm_adapter::operator+, vector);
	runTest<V>("Unary minus", lyah::operator-, glm_adapter::operator-, vector);
	runTest<V>("Addition", lyah::operator+, glm_adapter::operator+, vector, vector);
	runTest<V>("Subtraction", lyah::operator-, glm_adapter::operator-, vector, vector);
	runTest<V>("Multiplication (vector-scalar)", lyah::operator*, glm_adapter::operator*, vector, scalar);
	runTest<V>("Multiplication (scalar-vector)", lyah::operator*, glm_adapter::operator*, scalar, vector);
	runTest<V>("Multiplication (vector-vector)", lyah::operator*, glm_adapter::operator*, vector, vector);
	runTest<V>("Division (vector-scalar)", lyah::operator/, glm_adapter::operator/, vector, positiveNonZeroScalar);
	runTest<V>("Division (scalar-vector)", lyah::operator/, glm_adapter::operator/, scalar, positiveNonZeroVector);
	runTest<V>("Division (vector-vector)", lyah::operator/, glm_adapter::operator/, vector, positiveNonZeroVector);

	// Common
	runTest<S>("Sum", lyah::sum, glm_adapter::sum, vector);
	runTest<V>("Absolute value", lyah::abs, glm_adapter::abs, vector);
	runTest<V>("Minimum", lyah::min, glm_adapter::min, vector, vector);
	runTest<V>("Maximum", lyah::max, glm_adapter::max, vector, vector);
	runTest<V>("Clamp", lyah::clamp, glm_adapter::clamp, vector, vector, vector);
}