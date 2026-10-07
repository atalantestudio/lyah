#pragma once

#include "pch.hpp"

namespace vec4_m256d {
	void testDefaultConstructor() {
		const std::double_t expected[4] = {0.0, 0.0, 0.0, 0.0};

		const lyah::vec<4, std::double_t> result;

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
		test::assert(test::eq(result[2], expected[2]));
		test::assert(test::eq(result[3], expected[3]));
	}

	void testComponentConstructor() {
		const std::double_t expected[4] = {1.0, 4.0, 6.0, -1.0};

		const lyah::vec<4, std::double_t> result = {1.0, 4.0, 6.0, -1.0};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
		test::assert(test::eq(result[2], expected[2]));
		test::assert(test::eq(result[3], expected[3]));
	}

	void testComponentBroadcastConstructor() {
		const std::double_t expected = 1.0;

		const lyah::vec<4, std::double_t> result = lyah::vec<4, std::double_t>(1.0);

		test::assert(test::eq(result[0], expected));
		test::assert(test::eq(result[1], expected));
		test::assert(test::eq(result[2], expected));
		test::assert(test::eq(result[3], expected));
	}

	void testConvertingConstructor() {
		const lyah::vec<4, std::double_t> expected = {1.0, 4.0, 6.0, -1.0};
		const lyah::vec<4, std::float_t> a = {1.0f, 4.0f, 6.0f, -1.0f};

		const lyah::vec<4, std::double_t> result(a);

		test::assert(test::eq(result, expected));
	}

	void testAdditionAssignment() {
		const lyah::vec<4, std::double_t> expected = {6.0, 7.0, 8.0, 3.0};
		const lyah::vec<4, std::double_t> a = {5.0, 3.0, 2.0, 4.0};
		lyah::vec<4, std::double_t> result = {1.0, 4.0, 6.0, -1.0};

		result += a;

		test::assert(test::eq(result, expected));
	}

	void testSubtractionAssignment() {
		const lyah::vec<4, std::double_t> expected = {-4.0, 1.0, 4.0, -8.0};
		const lyah::vec<4, std::double_t> a = {5.0, 3.0, 2.0, 7.0};
		lyah::vec<4, std::double_t> result = {1.0, 4.0, 6.0, -1.0};

		result -= a;

		test::assert(test::eq(result, expected));
	}

	void testVectorScalarMultiplicationAssignment() {
		const lyah::vec<4, std::double_t> expected = {3.0, 12.0, 18.0, -3.0};
		const std::double_t a = 3.0;
		lyah::vec<4, std::double_t> result = {1.0, 4.0, 6.0, -1.0};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testVectorVectorMultiplicationAssignment() {
		const lyah::vec<4, std::double_t> expected = {5.0, 12.0, 12.0, -7.0};
		const lyah::vec<4, std::double_t> a = {5.0, 3.0, 2.0, 7.0};
		lyah::vec<4, std::double_t> result = {1.0, 4.0, 6.0, -1.0};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testVectorMatrixMultiplicationAssignment() {
		const lyah::vec<4, std::double_t> expected = {19.0, -36.0, 19.0, 44.0};
		const lyah::mat<4, 4, std::double_t> a = {
			1.0,  4.0,  6.0, -1.0,
			5.0,  3.0,  2.0,  7.0,
			0.0, -8.0,  0.5,  3.0,
			2.0,  4.0, -2.0,  1.0,
		};
		lyah::vec<4, std::double_t> result = {1.0, 4.0, 6.0, -1.0};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testVectorScalarDivisionAssignment() {
		const lyah::vec<4, std::double_t> expected = {0.333, 1.333, 2.0, -0.333};
		const std::double_t a = 3.0;
		lyah::vec<4, std::double_t> result = {1.0, 4.0, 6.0, -1.0};

		result /= a;

		test::assert(test::eq(result, expected, 0.001));
	}

	void testVectorVectorDivisionAssignment() {
		const lyah::vec<4, std::double_t> expected = {lyah::infinity<std::double_t>(), 1.333, 3.0, -0.143};
		const lyah::vec<4, std::double_t> a = {0.0, 3.0, 2.0, 7.0};
		lyah::vec<4, std::double_t> result = {1.0, 4.0, 6.0, -1.0};

		result /= a;

		test::assert(test::eq(result, expected, 0.001));
	}

	void runAll() {
		test::printTestCategory("lyah::vec<4, std::double_t> - 4-component double floating-point vector");

		test::runTest(&testDefaultConstructor, "Default constructor");
		test::runTest(&testComponentConstructor, "Component constructor");
		test::runTest(&testComponentBroadcastConstructor, "Component broadcast constructor");
		test::runTest(&testConvertingConstructor, "Converting constructor");

		test::runTest(&testAdditionAssignment, "Addition assignment (+=)");
		test::runTest(&testSubtractionAssignment, "Subtraction assignment (-=)");
		test::runTest(&testVectorScalarMultiplicationAssignment, "Vector-scalar multiplication assignment (*=)");
		test::runTest(&testVectorVectorMultiplicationAssignment, "Vector-vector multiplication assignment (*=)");
		test::runTest(&testVectorMatrixMultiplicationAssignment, "Vector-matrix multiplication assignment (*=)");
		test::runTest(&testVectorScalarDivisionAssignment, "Vector-scalar division assignment (/=)");
		test::runTest(&testVectorVectorDivisionAssignment, "Vector-vector division assignment (/=)");
	}
}