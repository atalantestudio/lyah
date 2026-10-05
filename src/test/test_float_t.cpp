// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#include "pch.hpp"

#include "test/TestGroup.hpp"

template<>
const char* TestGroup<std::float_t>::getGroupName() {
	return "float_t";
}

template<>
void TestGroup<std::float_t>::runTestsInternal(std::mt19937& engine) {
	typedef std::float_t S;

	Generator<S> scalar(engine, -1.0f, 1.0f);
	Generator<S> positiveScalar(engine, 0.0f, 2.0f);

	// Common
	runTest<S>("Absolute value", lyah::abs, glm_adapter::abs, scalar);
	runTest<S>("Minimum", lyah::min, glm_adapter::min, scalar, scalar);
	runTest<S>("Maximum", lyah::max, glm_adapter::max, scalar, scalar);
	runTest<S>("Clamp", lyah::clamp, glm_adapter::clamp, scalar, scalar, scalar);
	runTest<S>("Linear interpolation", lyah::lerp, glm_adapter::lerp, scalar, scalar, scalar);
	runTest<S>("Fused multiply-add", lyah::fma, glm_adapter::fma, scalar, scalar, scalar);

	// Constants
	runTest<S>("Machine epsilon", lyah::epsilon, glm_adapter::epsilon);
	runTest<S>("Pi", lyah::pi, glm_adapter::pi);
	runTest<S>("Tau", lyah::tau, glm_adapter::tau);

	// Exponential
	runTest<S>("Base 2 logarithm", lyah::log2, glm_adapter::log2, positiveScalar);
	runTest<S>("Power", lyah::pow, glm_adapter::pow, positiveScalar, scalar);
	runTest<S>("Square root", lyah::sqrt, glm_adapter::sqrt, positiveScalar);

	// Rounding
	runTest<S>("Floor", lyah::floor, glm_adapter::floor, scalar);
	runTest<S>("Ceil", lyah::ceil, glm_adapter::ceil, scalar);
	runTest<S>("Round", lyah::round, glm_adapter::round, scalar);

	// Trigonometric
	runTest<S>("Radians to degrees", lyah::degrees, glm_adapter::degrees, scalar);
	runTest<S>("Degrees to radians", lyah::radians, glm_adapter::radians, scalar);
	runTest<S>("Sine", lyah::sin, glm_adapter::sin, scalar);
	runTest<S>("Cosine", lyah::cos, glm_adapter::cos, scalar);
	runTest<S>("Tangent", lyah::tan, glm_adapter::tan, scalar);
	runTest<S>("Arcsine", lyah::asin, glm_adapter::asin, scalar);
	runTest<S>("Arccosine", lyah::acos, glm_adapter::acos, scalar);
	runTest<S>("Arctangent", lyah::atan, glm_adapter::atan, scalar);
}