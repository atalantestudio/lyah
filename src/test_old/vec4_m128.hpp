#pragma once

#include "pch.hpp"

namespace vec4_m128 {
	void testDefaultConstructor() {
		const std::float_t expected[4] = {0.0f, 0.0f, 0.0f, 0.0f};

		const lyah::vec<4, std::float_t> result;

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
		test::assert(test::eq(result[2], expected[2]));
		test::assert(test::eq(result[3], expected[3]));
	}

	void testComponentConstructor() {
		const std::float_t expected[4] = {1.0f, 4.0f, 6.0f, -1.0f};

		const lyah::vec<4, std::float_t> result = {1.0f, 4.0f, 6.0f, -1.0f};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
		test::assert(test::eq(result[2], expected[2]));
		test::assert(test::eq(result[3], expected[3]));
	}

	void testComponentBroadcastConstructor() {
		const std::float_t expected = 1.0f;

		const lyah::vec<4, std::float_t> result = lyah::vec<4, std::float_t>(1.0f);

		test::assert(test::eq(result[0], expected));
		test::assert(test::eq(result[1], expected));
		test::assert(test::eq(result[2], expected));
		test::assert(test::eq(result[3], expected));
	}

	void testConvertingConstructor() {
		const lyah::vec<4, std::float_t> expected = {1.0f, 4.0f, 6.0f, -1.0f};
		const lyah::vec<4, std::double_t> a = {1.0, 4.0, 6.0, -1.0};

		const lyah::vec<4, std::float_t> result(a);

		test::assert(test::eq(result, expected));
	}

	void testAdditionAssignment() {
		const lyah::vec<4, std::float_t> expected = {6.0f, 7.0f, 8.0f, 3.0f};
		const lyah::vec<4, std::float_t> a = {5.0f, 3.0f, 2.0f, 4.0f};
		lyah::vec<4, std::float_t> result = {1.0f, 4.0f, 6.0f, -1.0f};

		result += a;

		test::assert(test::eq(result, expected));
	}

	void testSubtractionAssignment() {
		const lyah::vec<4, std::float_t> expected = {-4.0f, 1.0f, 4.0f, -8.0f};
		const lyah::vec<4, std::float_t> a = {5.0f, 3.0f, 2.0f, 7.0f};
		lyah::vec<4, std::float_t> result = {1.0f, 4.0f, 6.0f, -1.0f};

		result -= a;

		test::assert(test::eq(result, expected));
	}

	void testVectorScalarMultiplicationAssignment() {
		const lyah::vec<4, std::float_t> expected = {3.0f, 12.0f, 18.0f, -3.0f};
		const std::float_t a = 3.0f;
		lyah::vec<4, std::float_t> result = {1.0f, 4.0f, 6.0f, -1.0f};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testVectorVectorMultiplicationAssignment() {
		const lyah::vec<4, std::float_t> expected = {5.0f, 12.0f, 12.0f, -7.0f};
		const lyah::vec<4, std::float_t> a = {5.0f, 3.0f, 2.0f, 7.0f};
		lyah::vec<4, std::float_t> result = {1.0f, 4.0f, 6.0f, -1.0f};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testVectorMatrixMultiplicationAssignment() {
		const lyah::vec<4, std::float_t> expected = {19.0f, -36.0f, 19.0f, 44.0f};
		const lyah::mat<4, 4, std::float_t> a = {
			1.0f,  4.0f,  6.0f, -1.0f,
			5.0f,  3.0f,  2.0f,  7.0f,
			0.0f, -8.0f,  0.5f,  3.0f,
			2.0f,  4.0f, -2.0f,  1.0f,
		};
		lyah::vec<4, std::float_t> result = {1.0f, 4.0f, 6.0f, -1.0f};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testVectorScalarDivisionAssignment() {
		const lyah::vec<4, std::float_t> expected = {0.333f, 1.333f, 2.0f, -0.333f};
		const std::float_t a = 3.0f;
		lyah::vec<4, std::float_t> result = {1.0f, 4.0f, 6.0f, -1.0f};

		result /= a;

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testVectorVectorDivisionAssignment() {
		const lyah::vec<4, std::float_t> expected = {lyah::infinity<std::float_t>(), 1.333f, 3.0f, -0.143f};
		const lyah::vec<4, std::float_t> a = {0.0f, 3.0f, 2.0f, 7.0f};
		lyah::vec<4, std::float_t> result = {1.0f, 4.0f, 6.0f, -1.0f};

		result /= a;

		test::assert(test::eq(result, expected, 0.001f));
	}

	/* void testSign() {
		const lyah::vec<4, std::float_t> expected = {1.0f, -1.0f, 1.0f, -0.0f};
		const lyah::vec<4, std::float_t> a = {1.0f, -4.0f, 6.0f, -0.0f};

		const lyah::vec<4, std::float_t> result = lyah::sign(a);

		test::assert(test::eq(result, expected));
	} */

	void runAll() {
		test::printTestCategory("lyah::vec<4, std::float_t> - 4-component single floating-point vector");

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

		//test::runTest(&testSign, "Sign");
	}
}