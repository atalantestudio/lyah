#pragma once

#include "pch.hpp"

namespace float64_common {
	static void testAbs() {
		const std::double_t expected = 1.0;
		const std::double_t a = -1.0;

		const std::double_t result = lyah::abs(a);

		test::assert(test::eq(result, expected));
	}

	static void runAll() {
		test::printTestCategory("64-bit float common functions");

		test::runTest(&testAbs, "Absolute value");
	}
}