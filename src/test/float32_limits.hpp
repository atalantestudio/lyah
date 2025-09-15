#pragma once

#include "pch.hpp"

namespace float32_limits {
	void testMin() {
		const std::float_t expected = 1.0f;
		const std::float_t a = 1.0f;
		const std::float_t b = 4.0f;

		const std::float_t result = lyah::min(a, b);

		test::assert(test::eq(result, expected));
	}

	void testMax() {
		const std::float_t expected = 4.0f;
		const std::float_t a = 1.0f;
		const std::float_t b = 4.0f;

		const std::float_t result = lyah::max(a, b);

		test::assert(test::eq(result, expected));
	}

	void testClamp() {
		const std::float_t expected = 4.0f;
		const std::float_t a = 1.0f;
		const std::float_t min = 4.0f;
		const std::float_t max = 6.0f;

		const std::float_t result = lyah::clamp(a, min, max);

		test::assert(test::eq(result, expected));
	}

	void runAll() {
		test::printTestCategory("32-bit single floating-point limit-related functions");

		test::runTest(&testMin, "Min");
		test::runTest(&testMax, "Max");
		test::runTest(&testClamp, "Clamp");
	}
}