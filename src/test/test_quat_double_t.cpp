// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#include "pch.hpp"

#include "test/TestGroup.hpp"

template<>
const char* TestGroup<lyah::quat<std::double_t>>::getGroupName() {
	return "quat<double_t>";
}

template<>
void TestGroup<lyah::quat<std::double_t>>::runTestsInternal(std::mt19937& engine) {
	typedef std::double_t S;
	typedef lyah::vec<3, S> V;
	typedef lyah::quat<S> Q;

	Generator<S> scalar(engine, -1.0, 1.0);
	Generator<V> vector(engine, -1.0, 1.0);
	Generator<Q> quaternion(engine, -1.0, 1.0);

	runTest<Q>("Identity", lyah::identity, glm_adapter::identity);

	// TODO: Add normalized vec3 generator.
	runTest<Q>("Axis-angle", lyah::axisAngle, glm_adapter::axisAngle, vector, scalar);

	// Comparison
	runTest<bool, Q, Q>("Equality", lyah::operator==, glm_adapter::operator==, quaternion, quaternion);
	runTest<bool, Q, Q>("Inequality", lyah::operator!=, glm_adapter::operator!=, quaternion, quaternion);

	// Arithmetic
	runTest<Q>("Unary plus", lyah::operator+, glm_adapter::operator+, quaternion);
	runTest<Q>("Unary minus", lyah::operator-, glm_adapter::operator-, quaternion);
	runTest<Q, Q, Q>("Addition", lyah::operator+, glm_adapter::operator+, quaternion, quaternion);
	runTest<Q, Q, Q>("Subtraction", lyah::operator-, glm_adapter::operator-, quaternion, quaternion);
	runTest<Q, Q, S>("Multiplication (quaternion-scalar)", lyah::operator*, glm_adapter::operator*, quaternion, scalar);
	runTest<Q, S, Q>("Multiplication (scalar-quaternion)", lyah::operator*, glm_adapter::operator*, scalar, quaternion);
	runTest<Q, Q, Q>("Multiplication (quaternion-quaternion)", lyah::operator*, glm_adapter::operator*, quaternion, quaternion);
	runTest<Q>("Division (quaternion-scalar)", lyah::operator/, glm_adapter::operator/, quaternion, scalar);

	// Quaternion
	runTest<Q>("Conjugate", lyah::conjugate, glm_adapter::conjugate, quaternion);
	runTest<Q>("Inverse", lyah::inverse, glm_adapter::inverse, quaternion);

	// Geometric
	runTest<S>("Dot product", lyah::dot, glm_adapter::dot, quaternion, quaternion);
	runTest<S>("Length", lyah::length, glm_adapter::length, quaternion);
	runTest<S>("Squared length", lyah::lengthSquared, glm_adapter::lengthSquared, quaternion);
	runTest<S>("Distance", lyah::distance, glm_adapter::distance, quaternion, quaternion);
	runTest<S>("Squared distance", lyah::distanceSquared, glm_adapter::distanceSquared, quaternion, quaternion);
	runTest<Q>("Normalization", lyah::normalized, glm_adapter::normalized, quaternion);
}