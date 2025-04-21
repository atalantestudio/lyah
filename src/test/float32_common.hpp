#pragma once

#include "pch.hpp"

namespace float32_common {
	static void testAbs() {
		const std::float_t expected = 1.0f;
		const std::float_t a = -1.0f;

		const std::float_t result = lyah::abs(a);

		test::assert(test::eq(result, expected));
	}

	static void testLerp() {
		const std::float_t expected = 3.0f;
		const std::float_t a = 0.0f;
		const std::float_t b = 6.0f;
		const std::float_t t = 0.5f;

		const std::float_t result = lyah::lerp(a, b, t);

		test::assert(test::eq(result, expected));
	}

	static void runAll() {
		test::printTestCategory("32-bit single floating-point common functions");

		test::runTest(&testAbs, "Absolute value");
		test::runTest(&testLerp, "Linear interpolation");
	}
}