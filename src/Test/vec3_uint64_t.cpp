// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#include "pch.hpp"

#include "TestGroup.hpp"

template<>
const char* TestGroup<lyah::vec<3, std::uint64_t>>::getGroupName() {
	return "vec<3, uint64_t>";
}

template<>
void TestGroup<lyah::vec<3, std::uint64_t>>::runTestsInternal(std::mt19937& engine) {
	typedef std::uint64_t S;
	typedef lyah::vec<3, S> V;

	Generator<S> scalar(engine, 0, 128);
	Generator<S> nonZeroScalar(engine, 1, 128);
	Generator<V> vector(engine, 0, 128);
	Generator<V> nonZeroVector(engine, 1, 128);

	// Comparison
	runTest<bool>("Equality", lyah::operator==, glm_adapter::operator==, vector, vector);
	runTest<bool>("Inequality", lyah::operator!=, glm_adapter::operator!=, vector, vector);

	// Arithmetic
	runTest<V>("Unary plus", lyah::operator+, glm_adapter::operator+, vector);
	runTest<V>("Addition", lyah::operator+, glm_adapter::operator+, vector, vector);
	runTest<V>("Subtraction", lyah::operator-, glm_adapter::operator-, vector, vector);
	runTest<V>("Multiplication (vector-scalar)", lyah::operator*, glm_adapter::operator*, vector, scalar);
	runTest<V>("Multiplication (scalar-vector)", lyah::operator*, glm_adapter::operator*, scalar, vector);
	runTest<V>("Multiplication (vector-vector)", lyah::operator*, glm_adapter::operator*, vector, vector);
	runTest<V>("Division (vector-scalar)", lyah::operator/, glm_adapter::operator/, vector, nonZeroScalar);
	runTest<V>("Division (scalar-vector)", lyah::operator/, glm_adapter::operator/, scalar, nonZeroVector);
	runTest<V>("Division (vector-vector)", lyah::operator/, glm_adapter::operator/, vector, nonZeroVector);

	// Common
	runTest<S>("Sum", lyah::sum, glm_adapter::sum, vector);
	runTest<V>("Minimum", lyah::min, glm_adapter::min, vector, vector);
	runTest<V>("Maximum", lyah::max, glm_adapter::max, vector, vector);
	runTest<V>("Clamp", lyah::clamp, glm_adapter::clamp, vector, vector, vector);
}