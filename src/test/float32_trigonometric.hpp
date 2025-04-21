#pragma once

#include "pch.hpp"

namespace float32_trigonometric {
	void testDegrees() {
		const std::float_t expected = 360.0f;
		const std::float_t a = 2.0f * lyah::pi<std::float_t>();

		const std::float_t result = lyah::degrees(a);

		test::assert(test::eq(result, expected));
	}

	void testRadians() {
		const std::float_t expected = 2.0f * lyah::pi<std::float_t>();
		const std::float_t a = 360.0f;

		const std::float_t result = lyah::radians(a);

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testSin() {
		const std::float_t expected = 0.841f;
		const std::float_t a = 1.0f;

		const std::float_t result = lyah::sin(a);

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testCos() {
		const std::float_t expected = 0.540f;
		const std::float_t a = 1.0f;

		const std::float_t result = lyah::cos(a);

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testTan() {
		const std::float_t expected = 1.557f;
		const std::float_t a = 1.0f;

		const std::float_t result = lyah::tan(a);

		test::assert(test::eq(result, expected, 0.001f));
	}

	void runAll() {
		test::printTestCategory("32-bit single floating-point trigonometric functions");

		test::runTest(&testDegrees, "Degrees");
		test::runTest(&testRadians, "Radians");
		test::runTest(&testSin, "Sin");
		test::runTest(&testCos, "Cos");
		test::runTest(&testTan, "Tan");
	}
}