#pragma once

#include "pch.hpp"

namespace float32_common {
	void testAbs() {
		const std::float_t expected = 1.0f;
		const std::float_t a = -1.0f;

		const std::float_t result = lyah::abs(a);

		test::assert(test::eq(result, expected));
	}

	void testCeil() {
		const std::float_t expected = 2.0f;
		const std::float_t a = 1.5f;

		const std::float_t result = lyah::ceil(a);

		test::assert(test::eq(result, expected));
	}

	void testFloor() {
		const std::float_t expected = 1.0f;
		const std::float_t a = 1.5f;

		const std::float_t result = lyah::floor(a);

		test::assert(test::eq(result, expected));
	}

	void testLerp() {
		const std::float_t expected = 3.0f;
		const std::float_t a = 0.0f;
		const std::float_t b = 6.0f;
		const std::float_t t = 0.5f;

		const std::float_t result = lyah::lerp(a, b, t);

		test::assert(test::eq(result, expected));
	}

	void runAll() {
		test::printTestCategory("32-bit single floating-point common functions");

		test::runTest(&testAbs, "Absolute value");
		test::runTest(&testCeil, "Ceil");
		test::runTest(&testFloor, "Floor");
		test::runTest(&testLerp, "Linear interpolation");
	}
}