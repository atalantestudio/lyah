#pragma once

#include "pch.hpp"

namespace int32_common {
	static void testAbs() {
		const std::int32_t expected = 1;
		const std::int32_t a = -1;

		const std::int32_t result = lyah::abs(a);

		test::assert(test::eq(result, expected));
	}

	static void runAll() {
		test::printTestCategory("32-bit integer common functions");

		test::runTest(&testAbs, "Absolute value");
	}
}