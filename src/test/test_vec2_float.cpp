// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#include "pch.hpp"

#include "test/ClassTest.hpp"

template<>
const char* ClassTest<lyah::vec<2, std::float_t>>::getClassName() {
	return "vec<2, float_t>";
}

template<>
void ClassTest<lyah::vec<2, std::float_t>>::runTests(std::mt19937& engine) {
	typedef std::float_t S;
	typedef lyah::vec<2, S> V;

	Generator<S> scalar(engine, -1.0f, 1.0f);
	Generator<V> vector(engine, -1.0f, 1.0f);

	runTest<bool, V, V>("Equality", lyah::operator==, glm_adapter::operator==, vector, vector);
	runTest<bool, V, V>("Inequality", lyah::operator!=, glm_adapter::operator!=, vector, vector);

	runTest<V>("Unary plus", lyah::operator+, glm_adapter::operator+, vector);
	runTest<V>("Unary minus", lyah::operator-, glm_adapter::operator-, vector);

	runTest<V, V, V>("Addition", lyah::operator+, glm_adapter::operator+, vector, vector);
	runTest<V, V, V>("Subtraction", lyah::operator-, glm_adapter::operator-, vector, vector);
	runTest<V, V, S>("Multiplication (vector-scalar)", lyah::operator*, glm_adapter::operator*, vector, scalar);
	runTest<V, S, V>("Multiplication (scalar-vector)", lyah::operator*, glm_adapter::operator*, scalar, vector);
	runTest<V, V, V>("Multiplication (vector-vector)", lyah::operator*, glm_adapter::operator*, vector, vector);
	runTest<V, V, S>("Division (vector-scalar)", lyah::operator/, glm_adapter::operator/, vector, scalar);
	runTest<V>("Division (scalar-vector)", lyah::operator/, glm_adapter::operator/, scalar, vector);
	runTest<V>("Division (vector-vector)", lyah::operator/, glm_adapter::operator/, vector, vector);
	runTest<V>("Fused multiply-add", lyah::fma, glm_adapter::fma, vector, vector, vector);

	runTest<S>("Parallelogram area", lyah::parallelogramArea, glm_adapter::parallelogramArea, vector, vector);
	runTest<V>("Perpendicular left", lyah::perpendicularLeft, glm_adapter::perpendicularLeft, vector);
	runTest<V>("Perpendicular right", lyah::perpendicularRight, glm_adapter::perpendicularRight, vector);
	runTest<S, V>("Dot product", lyah::dot, glm_adapter::dot, vector, vector);
	runTest<S, V>("Length", lyah::length, glm_adapter::length, vector);
	runTest<S, V>("Squared length", lyah::lengthSquared, glm_adapter::lengthSquared, vector);
	runTest<S, V>("Distance", lyah::distance, glm_adapter::distance, vector, vector);
	runTest<S, V>("Squared distance", lyah::distanceSquared, glm_adapter::distanceSquared, vector, vector);
	runTest<V>("Normalization", lyah::normalized, glm_adapter::normalized, vector);

	runTest<V>("Radians to degrees", lyah::degrees, glm_adapter::degrees, vector);
	runTest<V>("Degrees to radians", lyah::radians, glm_adapter::radians, vector);
	runTest<V>("Sine", lyah::sin, glm_adapter::sin, vector);
	runTest<V>("Cosine", lyah::cos, glm_adapter::cos, vector);
	runTest<V>("Tangent", lyah::tan, glm_adapter::tan, vector);
	runTest<V>("Arcsine", lyah::asin, glm_adapter::asin, vector);
	runTest<V>("Arccosine", lyah::acos, glm_adapter::acos, vector);
	runTest<V>("Arctangent", lyah::atan, glm_adapter::atan, vector);
}