#pragma once

#include "pch.hpp"

namespace float64_constants {
	void testEpsilon() {
		const std::double_t expected = std::numeric_limits<std::double_t>::epsilon();

		const std::double_t result = lyah::epsilon<std::double_t>();

		test::assert(test::eq(result, expected));
	}

	void testInfinity() {
		const std::double_t result = lyah::infinity<std::double_t>();

		test::assert(std::isinf(result));
	}

	void testNaN() {
		const std::double_t result = lyah::nan<std::double_t>();

		test::assert(std::isnan(result));
	}

	void testPi() {
		const std::double_t expected = 3.141592653589793;

		const std::double_t result = lyah::pi<std::double_t>();

		test::assert(test::eq(result, expected));
	}

	void testTau() {
		const std::double_t expected = 6.283185307179586;

		const std::double_t result = lyah::tau<std::double_t>();

		test::assert(test::eq(result, expected));
	}

	void runAll() {
		test::printTestCategory("64-bit double floating-point constants");

		test::runTest(&testEpsilon, "Epsilon");
		test::runTest(&testInfinity, "Infinity");
		test::runTest(&testNaN, "NaN");
		test::runTest(&testPi, "Pi");
		test::runTest(&testTau, "Tau");
	}
}