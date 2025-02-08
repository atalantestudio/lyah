#pragma once

#include "pch.hpp"

namespace scalar_exponential {
	void testPow() {
		const std::float_t expected = 128.0f;
		const std::float_t a = 2.0f;
		const std::float_t b = 7.0f;

		const std::float_t result = lyah::pow(a, b);

		test::assert(test::eq(result, expected));
	}

	void testRcp() {
		const std::float_t expected = 0.2f;
		const std::float_t a = 5.0f;

		const std::float_t result = lyah::rcp(a);

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testSqrt() {
		const std::float_t expected = 5.0f;
		const std::float_t a = 25.0f;

		const std::float_t result = lyah::sqrt(a);

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testRsqrt() {
		const std::float_t expected = 0.2f;
		const std::float_t a = 25.0f;

		const std::float_t result = lyah::rsqrt(a);

		test::assert(test::eq(result, expected, 0.001f));
	}

	void runAll() {
		test::printTestCategory("Exponential scalar functions");

		test::runTest(&testPow, "Power");
		test::runTest(&testRcp, "Reciprocal");
		test::runTest(&testSqrt, "Square root");
		test::runTest(&testRsqrt, "Inverse square root");
	}
}