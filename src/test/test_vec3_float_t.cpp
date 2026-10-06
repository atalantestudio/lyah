// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#include "pch.hpp"

#include "test/TestGroup.hpp"

template<>
const char* TestGroup<lyah::vec<3, std::float_t>>::getGroupName() {
	return "vec<3, float_t>";
}

template<>
void TestGroup<lyah::vec<3, std::float_t>>::runTestsInternal(std::mt19937& engine) {
	typedef std::float_t S;
	typedef lyah::vec<3, S> V;
	typedef lyah::mat<3, 3, S> M;
	typedef lyah::quat<S> Q;

	Generator<S> scalar(engine, -64.0f, 64.0f);
	Generator<V> vector(engine, -64.0f, 64.0f);
	Generator<V> positiveVector(engine, 0.0f, 128.0f);
	Generator<M> matrix(engine, -64.0f, 64.0f);
	NormalizedGenerator<Q> normalizedQuaternion(engine, -64.0f, 64.0f);

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
	runTest<V>("Multiplication (vector-matrix)", lyah::operator*, glm_adapter::operator*, vector, matrix);
	runTest<V>("Multiplication (vector-quaternion)", lyah::operator*, glm_adapter::operator*, vector, normalizedQuaternion);
	runTest<V>("Division (vector-scalar)", lyah::operator/, glm_adapter::operator/, vector, scalar);
	runTest<V>("Division (scalar-vector)", lyah::operator/, glm_adapter::operator/, scalar, vector);
	runTest<V>("Division (vector-vector)", lyah::operator/, glm_adapter::operator/, vector, vector);

	// Common
	runTest<S>("Sum", lyah::sum, glm_adapter::sum, vector);
	runTest<V>("Absolute value", lyah::abs, glm_adapter::abs, vector);
	runTest<V>("Minimum", lyah::min, glm_adapter::min, vector, vector);
	runTest<V>("Maximum", lyah::max, glm_adapter::max, vector, vector);
	runTest<V>("Clamp", lyah::clamp, glm_adapter::clamp, vector, vector, vector);
	runTest<V>("Linear interpolation (scalar interpolant)", lyah::lerp, glm_adapter::lerp, vector, vector, scalar);
	runTest<V>("Linear interpolation (vector interpolant)", lyah::lerp, glm_adapter::lerp, vector, vector, vector);
	runTest<V>("Fused multiply-add", lyah::fma, glm_adapter::fma, vector, vector, vector);

	// Exponential
	runTest<V>("Power (scalar exponent)", lyah::pow, glm_adapter::pow, positiveVector, scalar);
	runTest<V>("Power (vector exponent)", lyah::pow, glm_adapter::pow, positiveVector, vector);
	runTest<V>("Square root", lyah::pow, glm_adapter::pow, positiveVector, vector);

	// Geometric
	runTest<V>("Cross product", lyah::cross, glm_adapter::cross, vector, vector);
	runTest<S>("Dot product", lyah::dot, glm_adapter::dot, vector, vector);
	runTest<S>("Length", lyah::length, glm_adapter::length, vector);
	runTest<S>("Squared length", lyah::lengthSquared, glm_adapter::lengthSquared, vector);
	runTest<S>("Distance", lyah::distance, glm_adapter::distance, vector, vector);
	runTest<S>("Squared distance", lyah::distanceSquared, glm_adapter::distanceSquared, vector, vector);
	runTest<V>("Normalization", lyah::normalized, glm_adapter::normalized, vector);

	// Rounding
	runTest<V>("Floor", lyah::floor, glm_adapter::floor, vector);
	runTest<V>("Ceil", lyah::ceil, glm_adapter::ceil, vector);
	runTest<V>("Round", lyah::round, glm_adapter::round, vector);

	// Trigonometric
	runTest<V>("Radians to degrees", lyah::degrees, glm_adapter::degrees, vector);
	runTest<V>("Degrees to radians", lyah::radians, glm_adapter::radians, vector);
	runTest<V>("Sine", lyah::sin, glm_adapter::sin, vector);
	runTest<V>("Cosine", lyah::cos, glm_adapter::cos, vector);
	runTest<V>("Tangent", lyah::tan, glm_adapter::tan, vector);
	runTest<V>("Arcsine", lyah::asin, glm_adapter::asin, vector);
	runTest<V>("Arccosine", lyah::acos, glm_adapter::acos, vector);
	runTest<V>("Arctangent", lyah::atan, glm_adapter::atan, vector);
}