#pragma once

#include "pch.hpp"

namespace float64_common {
	static void testAbs() {
		const std::double_t expected = 1.0;
		const std::double_t a = -1.0;

		const std::double_t result = lyah::abs(a);

		test::assert(test::eq(result, expected));
	}

	static void testLerp() {
		const std::double_t expected = 3.0;
		const std::double_t a = 0.0;
		const std::double_t b = 6.0;
		const std::double_t t = 0.5;

		const std::double_t result = lyah::lerp(a, b, t);

		test::assert(test::eq(result, expected));
	}

	static void runAll() {
		test::printTestCategory("64-bit double floating-point common functions");

		test::runTest(&testAbs, "Absolute value");
		test::runTest(&testLerp, "Linear interpolation");
	}
}