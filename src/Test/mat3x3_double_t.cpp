// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#include "pch.hpp"

#include "TestGroup.hpp"

template<>
const char* TestGroup<lyah::mat<3, 3, std::double_t>>::getGroupName() {
	return "mat3x3<double_t>";
}

template<>
void TestGroup<lyah::mat<3, 3, std::double_t>>::runTestsInternal(std::mt19937& engine) {
	typedef std::double_t S;
	typedef lyah::mat<3, 3, S> M;
	typedef lyah::vec<2, S> V2;
	typedef lyah::quat<S> Q;

	Generator<S> scalar(engine, -4.0, 4.0);
	Generator<M> matrix(engine, -4.0, 4.0);
	Generator<V2> vector2(engine, -4.0, 4.0);
	Generator<V2> positiveVector2(engine, 0.0, 8.0);

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

	// TODO: Test quaternion to matrix.

	// Common
	runTest<M>("Identity", lyah::identity, glm_adapter::identity);

	// Projection
	runTest<M>("Orthographic", lyah::orthographic, glm_adapter::orthographic, vector2, positiveVector2);
	runTest<M>("Orthographic (screen)", lyah::orthographicScreen, glm_adapter::orthographicScreen, positiveVector2);

	// Transformation
	runTest<M>("Translation", lyah::translation, glm_adapter::translation, vector2);
	runTest<M>("Angle rotation", lyah::rotationAngle, glm_adapter::rotationAngle, scalar);
	runTest<M>("Scaling", lyah::scaling, glm_adapter::scaling, vector2);
	runTest<M>("Uniform scaling", lyah::uniformScaling, glm_adapter::uniformScaling, scalar);
}