#pragma once

#include "pch.hpp"

namespace float64_trigonometric {
	void testDegrees() {
		const std::double_t expected = 360.0;
		const std::double_t a = 2.0 * lyah::pi<std::double_t>();

		const std::double_t result = lyah::degrees(a);

		test::assert(test::eq(result, expected));
	}

	void testRadians() {
		const std::double_t expected = 2.0 * lyah::pi<std::double_t>();
		const std::double_t a = 360.0;

		const std::double_t result = lyah::radians(a);

		test::assert(test::eq(result, expected, 0.001));
	}

	void testSin() {
		const std::double_t expected = 0.841;
		const std::double_t a = 1.0;

		const std::double_t result = lyah::sin(a);

		test::assert(test::eq(result, expected, 0.001));
	}

	void testCos() {
		const std::double_t expected = 0.540;
		const std::double_t a = 1.0;

		const std::double_t result = lyah::cos(a);

		test::assert(test::eq(result, expected, 0.001));
	}

	void testTan() {
		const std::double_t expected = 1.557;
		const std::double_t a = 1.0;

		const std::double_t result = lyah::tan(a);

		test::assert(test::eq(result, expected, 0.001));
	}

	void runAll() {
		test::printTestCategory("64-bit double floating-point trigonometric functions");

		test::runTest(&testDegrees, "Degrees");
		test::runTest(&testRadians, "Radians");
		test::runTest(&testSin, "Sin");
		test::runTest(&testCos, "Cos");
		test::runTest(&testTan, "Tan");
	}
}