// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#include "pch.hpp"

#include "TestGroup.hpp"

template<>
const char* TestGroup<lyah::mat<4, 4, std::double_t>>::getGroupName() {
	return "mat4x4<double_t>";
}

template<>
void TestGroup<lyah::mat<4, 4, std::double_t>>::runTestsInternal(std::mt19937& engine) {
	typedef std::double_t S;
	typedef lyah::mat<4, 4, S> M;
	typedef lyah::vec<3, S> V3;

	Generator<S> scalar(engine, -2.0, 2.0);
	Generator<S> normalizedScalar(engine, 0.0, 1.0);
	Generator<S> positiveScalar(engine, 0.0, 8.0);
	Generator<M> matrix(engine, -2.0, 2.0);
	Generator<V3> vector3(engine, -2.0, 2.0);
	NormalizedGenerator<V3> normalizedVector3(engine, -2.0, 2.0);

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
	runTest<M>("Orthographic", lyah::orthographic, glm_adapter::orthographic, scalar, scalar, scalar, scalar, scalar, scalar);
	runTest<M>("Perspective", lyah::perspective, glm_adapter::perspective, positiveScalar, normalizedScalar, positiveScalar, positiveScalar);
	runTest<M>("Perspective (Reversed-Z)", lyah::perspectiveReversedZ, glm_adapter::perspectiveReversedZ, positiveScalar, normalizedScalar, positiveScalar);

	// Transformation
	runTest<M>("Translation", lyah::translation, glm_adapter::translation, vector3);
	runTest<M>("Axis/angle rotation", lyah::rotationAxisAngle, glm_adapter::rotationAxisAngle, normalizedVector3, scalar);
	runTest<M>("Scaling", lyah::scaling, glm_adapter::scaling, vector3);
	runTest<M>("Uniform scaling", lyah::uniformScaling, glm_adapter::uniformScaling, scalar);

	// TODO: Fix look-at test.
	runTest<M>("Look-at", lyah::lookAt, glm_adapter::lookAt, normalizedVector3, normalizedVector3, normalizedVector3);
}