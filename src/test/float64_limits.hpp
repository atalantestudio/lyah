#pragma once

#include "pch.hpp"

namespace float64_limits {
	static void testMin() {
		const std::double_t expected = 1.0;
		const std::double_t a = 1.0;
		const std::double_t b = 4.0;

		const std::double_t result = lyah::min(a, b);

		test::assert(test::eq(result, expected));
	}

	static void testMax() {
		const std::double_t expected = 4.0;
		const std::double_t a = 1.0;
		const std::double_t b = 4.0;

		const std::double_t result = lyah::max(a, b);

		test::assert(test::eq(result, expected));
	}

	static void testClamp() {
		const std::double_t expected = 4.0;
		const std::double_t a = 1.0;
		const std::double_t min = 4.0;
		const std::double_t max = 6.0;

		const std::double_t result = lyah::clamp(a, min, max);

		test::assert(test::eq(result, expected));
	}

	static void runAll() {
		test::printTestCategory("64-bit double floating-point limit-related functions");

		test::runTest(&testMin, "Min");
		test::runTest(&testMax, "Max");
		test::runTest(&testClamp, "Clamp");
	}
}