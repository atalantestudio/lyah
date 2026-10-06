// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#include "pch.hpp"

#include "test/TestGroup.hpp"

template<>
const char* TestGroup<lyah::mat<4, 4, std::double_t>>::getGroupName() {
	return "mat4x4<double_t>";
}

template<>
void TestGroup<lyah::mat<4, 4, std::double_t>>::runTestsInternal(std::mt19937& engine) {
	typedef std::double_t S;
	typedef lyah::mat<4, 4, S> M;

	Generator<S> scalar(engine, -64.0, 64.0);
	Generator<M> matrix(engine, -64.0, 64.0);

	runTest<M>("Identity", lyah::identity, glm_adapter::identity);

	// Comparison
	runTest<bool>("Equality", lyah::operator==, glm_adapter::operator==, matrix, matrix);
	runTest<bool>("Inequality", lyah::operator!=, glm_adapter::operator!=, matrix, matrix);

	// Arithmetic
	runTest<M>("Unary plus", lyah::operator+, glm_adapter::operator+, matrix);
	runTest<M>("Unary minus", lyah::operator-, glm_adapter::operator-, matrix);
	runTest<M>("Addition", lyah::operator+, glm_adapter::operator+, matrix, matrix);
	runTest<M>("Subtraction", lyah::operator-, glm_adapter::operator-, matrix, matrix);
	runTest<M>("Multiplication (matrix-scalar)", lyah::operator*, glm_adapter::operator*, matrix, scalar);
	runTest<M>("Multiplication (scalar-matrix)", lyah::operator*, glm_adapter::operator*, scalar, matrix);
	runTest<M>("Multiplication (matrix-matrix)", lyah::operator*, glm_adapter::operator*, matrix, matrix);
	runTest<M>("Division (matrix-scalar)", lyah::operator/, glm_adapter::operator/, matrix, scalar);

	// Matrix
	runTest<S>("Determinant", lyah::determinant, glm_adapter::determinant, matrix);
	runTest<M>("Adjugate", lyah::adjugate, glm_adapter::adjugate, matrix);
	runTest<M>("Inverse", lyah::inverse, glm_adapter::inverse, matrix);
	runTest<M>("Transpose", lyah::transpose, glm_adapter::transpose, matrix);

	// TODO: Projection tests.
	// TODO: Transformation tests.
}