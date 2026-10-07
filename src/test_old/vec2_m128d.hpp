#pragma once

#include "pch.hpp"

namespace vec2_m128d {
	void testDefaultConstructor() {
		const std::double_t expected[2] = {0.0, 0.0};

		const lyah::vec<2, std::double_t> result;

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
	}

	void testComponentConstructor() {
		const std::double_t expected[2] = {1.0, 4.0};

		const lyah::vec<2, std::double_t> result = {1.0, 4.0};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
	}

	void testComponentBroadcastConstructor() {
		const std::double_t expected = 1.0;

		const lyah::vec<2, std::double_t> result = lyah::vec<2, std::double_t>(1.0);

		test::assert(test::eq(result[0], expected));
		test::assert(test::eq(result[1], expected));
	}

	void testConvertingConstructor() {
		const lyah::vec<2, std::double_t> expected = {1.0, 4.0};
		const lyah::vec<2, std::float_t> a = {1.0f, 4.0f};

		const lyah::vec<2, std::double_t> result(a);

		test::assert(test::eq(result, expected));
	}

	void testAdditionAssignment() {
		const lyah::vec<2, std::double_t> expected = {6.0, 7.0};
		const lyah::vec<2, std::double_t> a = {5.0, 3.0};
		lyah::vec<2, std::double_t> result = {1.0, 4.0};

		result += a;

		test::assert(test::eq(result, expected));
	}

	void testSubtractionAssignment() {
		const lyah::vec<2, std::double_t> expected = {-4.0, 1.0};
		const lyah::vec<2, std::double_t> a = {5.0, 3.0};
		lyah::vec<2, std::double_t> result = {1.0, 4.0};

		result -= a;

		test::assert(test::eq(result, expected));
	}

	void testVectorScalarMultiplicationAssignment() {
		const lyah::vec<2, std::double_t> expected = {3.0, 12.0};
		const std::double_t a = 3.0;
		lyah::vec<2, std::double_t> result = {1.0, 4.0};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testVectorVectorMultiplicationAssignment() {
		const lyah::vec<2, std::double_t> expected = {5.0, 12.0};
		const lyah::vec<2, std::double_t> a = {5.0, 3.0};
		lyah::vec<2, std::double_t> result = {1.0, 4.0};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testVectorMatrixMultiplicationAssignment() {
		const lyah::vec<2, std::double_t> expected = {21.0, 16.0};
		const lyah::mat<2, 2, std::double_t> A = {
			1.0, 4.0,
			5.0, 3.0,
		};
		lyah::vec<2, std::double_t> result = {1.0, 4.0};

		result *= A;

		test::assert(test::eq(result, expected));
	}

	void testVectorScalarDivisionAssignment() {
		const lyah::vec<2, std::double_t> expected = {0.333, 1.333};
		const std::double_t a = 3.0;
		lyah::vec<2, std::double_t> result = {1.0, 4.0};

		result /= a;

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testVectorVectorDivisionAssignment() {
		const lyah::vec<2, std::double_t> expected = {lyah::infinity<std::double_t>(), 1.333};
		const lyah::vec<2, std::double_t> a = {0.0, 3.0};
		lyah::vec<2, std::double_t> result = {1.0, 4.0};

		result /= a;

		test::assert(test::eq(result, expected, 0.001f));
	}

	/* void testHorizontalMin() {
		const std::double_t expected = 1.0;
		const lyah::vec<2, std::double_t> a = {1.0, 4.0};

		const std::double_t result = lyah::min(a);

		test::assert(test::eq(result, expected));
	} */

	/* void testHorizontalMax() {
		const std::double_t expected = 4.0f;
		const lyah::vec<2, std::double_t> a = {1.0, 4.0};

		const std::double_t result = lyah::max(a);

		test::assert(test::eq(result, expected));
	} */

	void testCrossProduct() {
		const lyah::vec<2, std::double_t> expected = {4.0, 1.0};
		const lyah::vec<2, std::double_t> a = {1.0, -4.0};
		const std::double_t b = -1.0;

		const lyah::vec<2, std::double_t> result = lyah::cross(a, b);

		test::assert(test::eq(result, expected));
	}

	void runAll() {
		test::printTestCategory("lyah::vec<2, std::double_t> - 2-component double floating-point vector");

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

		/*test::runTest(&testHorizontalMin, "Horizontal min");
		test::runTest(&testHorizontalMax, "Horizontal max");*/

		test::runTest(&testCrossProduct, "Cross product");
	}
}