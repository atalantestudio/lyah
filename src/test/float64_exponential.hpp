#pragma once

#include "pch.hpp"

namespace float64_exponential {
	void testLog2() {
		const std::double_t expected = 1.585;
		const std::double_t a = 3.0;

		const std::double_t result = lyah::log2(a);

		test::assert(test::eq(result, expected, 0.001));
	}

	void testPow() {
		const std::double_t expected = 128.0;
		const std::double_t a = 2.0;
		const std::double_t b = 7.0;

		const std::double_t result = lyah::pow(a, b);

		test::assert(test::eq(result, expected));
	}

	void testRcp() {
		const std::double_t expected = 0.2;
		const std::double_t a = 5.0;

		const std::double_t result = lyah::rcp(a);

		test::assert(test::eq(result, expected, 0.001));
	}

	void testSqrt() {
		const std::double_t expected = 5.0;
		const std::double_t a = 25.0;

		const std::double_t result = lyah::sqrt(a);

		test::assert(test::eq(result, expected, 0.001));
	}

	void testRsqrt() {
		const std::double_t expected = 0.2;
		const std::double_t a = 25.0;

		const std::double_t result = lyah::rsqrt(a);

		test::assert(test::eq(result, expected, 0.001));
	}

	void runAll() {
		test::printTestCategory("64-bit double floating-point exponential functions");

		test::runTest(&testLog2, "Base 2 logarithm");
		test::runTest(&testPow, "Power");
		test::runTest(&testRcp, "Reciprocal");
		test::runTest(&testSqrt, "Square root");
		test::runTest(&testRsqrt, "Inverse square root");
	}
}