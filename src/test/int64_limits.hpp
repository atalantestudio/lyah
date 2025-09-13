#pragma once

#include "pch.hpp"

namespace int64_limits {
	static void testMin() {
		const std::int64_t expected = 1;
		const std::int64_t a = 1;
		const std::int64_t b = 4;

		const std::int64_t result = lyah::min(a, b);

		test::assert(test::eq(result, expected));
	}

	static void testMax() {
		const std::int64_t expected = 4;
		const std::int64_t a = 1;
		const std::int64_t b = 4;

		const std::int64_t result = lyah::max(a, b);

		test::assert(test::eq(result, expected));
	}

	static void testClamp() {
		const std::int64_t expected = 4;
		const std::int64_t a = 1;
		const std::int64_t min = 4;
		const std::int64_t max = 6;

		const std::int64_t result = lyah::clamp(a, min, max);

		test::assert(test::eq(result, expected));
	}

	static void runAll() {
		test::printTestCategory("64-bit integer limit-related functions");

		test::runTest(&testMin, "Min");
		test::runTest(&testMax, "Max");
		test::runTest(&testClamp, "Clamp");
	}
}