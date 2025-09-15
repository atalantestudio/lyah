#pragma once

#include "pch.hpp"

namespace float64_common {
	void testAbs() {
		const std::double_t expected = 1.0;
		const std::double_t a = -1.0;

		const std::double_t result = lyah::abs(a);

		test::assert(test::eq(result, expected));
	}

	void testCeil() {
		const std::double_t expected = 2.0;
		const std::double_t a = 1.5;

		const std::double_t result = lyah::ceil(a);

		test::assert(test::eq(result, expected));
	}

	void testFloor() {
		const std::double_t expected = 1.0;
		const std::double_t a = 1.5;

		const std::double_t result = lyah::floor(a);

		test::assert(test::eq(result, expected));
	}

	void testLerp() {
		const std::double_t expected = 3.0;
		const std::double_t a = 0.0;
		const std::double_t b = 6.0;
		const std::double_t t = 0.5;

		const std::double_t result = lyah::lerp(a, b, t);

		test::assert(test::eq(result, expected));
	}

	void runAll() {
		test::printTestCategory("64-bit double floating-point common functions");

		test::runTest(&testAbs, "Absolute value");
		test::runTest(&testCeil, "Ceil");
		test::runTest(&testFloor, "Floor");
		test::runTest(&testLerp, "Linear interpolation");
	}
}