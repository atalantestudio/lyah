#pragma once

#include "pch.hpp"

namespace float32_common {
	static void testAbs() {
		const std::float_t expected = 1.0f;
		const std::float_t a = -1.0f;

		const std::float_t result = lyah::abs(a);

		test::assert(test::eq(result, expected));
	}

	static void runAll() {
		test::printTestCategory("32-bit float common functions");

		test::runTest(&testAbs, "Absolute value");
	}
}