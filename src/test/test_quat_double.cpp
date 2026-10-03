// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#include "pch.hpp"

#include "test/ClassTest.hpp"

template<>
const char* ClassTest<lyah::quat<std::double_t>>::getClassName() {
	return "quat<double_t>";
}

template<>
void ClassTest<lyah::quat<std::double_t>>::runTests() {
	typedef lyah::quat<std::double_t> T;

	std::random_device device;
	std::mt19937 engine(device());

	Generator<std::double_t> scalar(engine, -1.0f, 1.0f);
	Generator<lyah::vec<3, std::double_t>> vector(engine, -1.0f, 1.0f);
	Generator<T> quaternion(engine);

	runTest("Identity", T::identity, glm_adapter::identity);
	runTest("Axis-angle", T::axisAngle, glm_adapter::axisAngle, vector, scalar);

	runTest<bool, T, T>("Equality", lyah::operator==, glm_adapter::operator==, quaternion, quaternion);
	runTest<bool, T, T>("Inequality", lyah::operator!=, glm_adapter::operator!=, quaternion, quaternion);

	runTest<T>("Unary plus", lyah::operator+, glm_adapter::operator+, quaternion);
	runTest<T>("Unary minus", lyah::operator-, glm_adapter::operator-, quaternion);

	runTest<T, T, T>("Addition", lyah::operator+, glm_adapter::operator+, quaternion, quaternion);
	runTest<T, T, T>("Subtraction", lyah::operator-, glm_adapter::operator-, quaternion, quaternion);
	runTest<T, T, std::double_t>("Multiplication (quaternion-scalar)", lyah::operator*, glm_adapter::operator*, quaternion, scalar);
	runTest<T, std::double_t, T>("Multiplication (scalar-quaternion)", lyah::operator*, glm_adapter::operator*, scalar, quaternion);
	runTest<T, T, T>("Multiplication (quaternion-quaternion)", lyah::operator*, glm_adapter::operator*, quaternion, quaternion);
	runTest<T>("Division (quaternion-scalar)", lyah::operator/, glm_adapter::operator/, quaternion, scalar);

	runTest<T>("Conjugate", lyah::conjugate, glm_adapter::conjugate, quaternion);
	runTest<std::double_t>("Dot product", lyah::dot, glm_adapter::dot, quaternion, quaternion);
	runTest<T>("Inverse", lyah::inverse, glm_adapter::inverse, quaternion);
	runTest<std::double_t>("Length", lyah::length, glm_adapter::length, quaternion);
	runTest<std::double_t>("Squared length", lyah::lengthSquared, glm_adapter::lengthSquared, quaternion);
	runTest<std::double_t>("Distance", lyah::distance, glm_adapter::distance, quaternion, quaternion);
	runTest<std::double_t>("Squared distance", lyah::distanceSquared, glm_adapter::distanceSquared, quaternion, quaternion);
	runTest<T>("Normalization", lyah::normalized, glm_adapter::normalized, quaternion);
}