#pragma once

#include "pch.hpp"

namespace int32_limits {
	static void testMin() {
		const std::int32_t expected = 1;
		const std::int32_t a = 1;
		const std::int32_t b = 4;

		const std::int32_t result = lyah::min(a, b);

		test::assert(test::eq(result, expected));
	}

	static void testMax() {
		const std::int32_t expected = 4;
		const std::int32_t a = 1;
		const std::int32_t b = 4;

		const std::int32_t result = lyah::max(a, b);

		test::assert(test::eq(result, expected));
	}

	static void testClamp() {
		const std::int32_t expected = 4;
		const std::int32_t a = 1;
		const std::int32_t min = 4;
		const std::int32_t max = 6;

		const std::int32_t result = lyah::clamp(a, min, max);

		test::assert(test::eq(result, expected));
	}

	static void runAll() {
		test::printTestCategory("32-bit integer limit-related functions");

		test::runTest(&testMin, "Min");
		test::runTest(&testMax, "Max");
		test::runTest(&testClamp, "Clamp");
	}
}