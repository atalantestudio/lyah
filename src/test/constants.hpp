#pragma once

#include "pch.hpp"

namespace constants {
	static void testEpsilon() {
		const std::float_t expected = std::numeric_limits<std::float_t>::epsilon();

		const std::float_t result = lyah::epsilon<std::float_t>();

		test::assert(test::eq(result, expected));
	}

	static void testInfinity() {
		const std::float_t result = lyah::infinity<std::float_t>();

		test::assert(std::isinf(result));
	}

	static void testNaN() {
		const std::float_t result = lyah::nan<std::float_t>();

		test::assert(std::isnan(result));
	}

	static void testPi() {
		const std::float_t expected = 3.141592653589793f;

		const std::float_t result = lyah::pi<std::float_t>();

		test::assert(test::eq(result, expected));
	}

	static void runAll() {
		test::printTestCategory("Constants");

		test::runTest(&testEpsilon, "Epsilon");
		test::runTest(&testInfinity, "Infinity");
		test::runTest(&testNaN, "NaN");
		test::runTest(&testPi, "Pi");
	}
}