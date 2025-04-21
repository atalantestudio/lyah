#pragma once

#include "pch.hpp"

namespace int64_common {
	static void testAbs() {
		const std::int64_t expected = 1;
		const std::int64_t a = -1;

		const std::int64_t result = lyah::abs(a);

		test::assert(test::eq(result, expected));
	}

	static void runAll() {
		test::printTestCategory("64-bit integer common functions");

		test::runTest(&testAbs, "Absolute value");
	}
}