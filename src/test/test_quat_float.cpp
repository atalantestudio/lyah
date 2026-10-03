// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#include "pch.hpp"

#include "test/ClassTest.hpp"

const char* SingleFloatingPointQuaternion::getClassName() const {
	return "quat<float_t>";
}

void SingleFloatingPointQuaternion::runTests() const {
	std::random_device device;
	std::mt19937 engine(device());

	Generator<std::float_t> scalar(engine, -1.0f, 1.0f);
	//Generator<lyah::vec<2, std::float_t>> vec2Gen(engine, -1.0f, 1.0f);
	Generator<lyah::vec<3, std::float_t>> vec3(engine, -1.0f, 1.0f);
	Generator<lyah::quat<std::float_t>> quat(engine);

	//runTest("Linear interpolation", lyah::lerp<std::float_t>, glm_adapter::floatlerp, floatGen, floatGen, floatGen);
	//runTest("Linear interpolation", lyah::lerp, glm_adapter::lerp, vec2Gen, vec2Gen, vec2Gen);

	runTest("Identity", lyah::quat<std::float_t>::identity, glm_adapter::identity);
	runTest("Axis-angle", lyah::quat<std::float_t>::axisAngle, glm_adapter::axisAngle, vec3, scalar);

	runTest("Equality", lyah::operator==, glm_adapter::operator==, quat, quat);
	runTest("Inequality", lyah::operator!=, glm_adapter::operator!=, quat, quat);

	runTest<lyah::quat<std::float_t>>("Unary plus", lyah::operator+, glm_adapter::operator+, quat);
	runTest<lyah::quat<std::float_t>>("Unary minus", lyah::operator-, glm_adapter::operator-, quat);

	runTest<lyah::quat<std::float_t>, lyah::quat<std::float_t>, lyah::quat<std::float_t>>("Addition", lyah::operator+, glm_adapter::operator+, quat, quat);
	runTest<lyah::quat<std::float_t>, lyah::quat<std::float_t>, lyah::quat<std::float_t>>("Subtraction", lyah::operator-, glm_adapter::operator-, quat, quat);
	runTest<lyah::quat<std::float_t>, lyah::quat<std::float_t>, std::float_t>("Multiplication (quaternion-scalar)", lyah::operator*, glm_adapter::operator*, quat, scalar);
	runTest<lyah::quat<std::float_t>, std::float_t, lyah::quat<std::float_t>>("Multiplication (scalar-quaternion)", lyah::operator*, glm_adapter::operator*, scalar, quat);
	runTest<lyah::quat<std::float_t>, lyah::quat<std::float_t>, lyah::quat<std::float_t>>("Multiplication (quaternion-quaternion)", lyah::operator*, glm_adapter::operator*, quat, quat);
	runTest("Division (quaternion-scalar)", lyah::operator/, glm_adapter::operator/, quat, scalar);

	runTest("Conjugate", lyah::conjugate, glm_adapter::conjugate, quat);
	runTest("Dot product", lyah::dot, glm_adapter::dot, quat, quat);
	runTest("Inverse", lyah::inverse, glm_adapter::inverse, quat);
	runTest("Length", lyah::length, glm_adapter::length, quat);
	runTest("Squared length", lyah::lengthSquared, glm_adapter::lengthSquared, quat);
	runTest("Distance", lyah::distance, glm_adapter::distance, quat, quat);
	runTest("Squared distance", lyah::distanceSquared, glm_adapter::distanceSquared, quat, quat);
	runTest("Normalization", lyah::normalized, glm_adapter::normalized, quat);
}