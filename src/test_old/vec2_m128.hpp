#pragma once

#include "pch.hpp"

namespace vec2_m128 {
	void testDefaultConstructor() {
		const std::float_t expected[2] = {0.0f, 0.0f};

		const lyah::vec<2, std::float_t> result;

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
	}

	void testComponentConstructor() {
		const std::float_t expected[2] = {1.0f, 4.0f};

		const lyah::vec<2, std::float_t> result = {1.0f, 4.0f};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
	}

	void testComponentBroadcastConstructor() {
		const std::float_t expected = 1.0f;

		const lyah::vec<2, std::float_t> result = lyah::vec<2, std::float_t>(1.0f);

		test::assert(test::eq(result[0], expected));
		test::assert(test::eq(result[1], expected));
	}

	void testConvertingConstructor() {
		const lyah::vec<2, std::float_t> expected = {1.0f, 4.0f};
		const lyah::vec<2, std::double_t> a = {1.0, 4.0};

		const lyah::vec<2, std::float_t> result(a);

		test::assert(test::eq(result, expected));
	}

	void testAdditionAssignment() {
		const lyah::vec<2, std::float_t> expected = {6.0f, 7.0f};
		const lyah::vec<2, std::float_t> a = {5.0f, 3.0f};
		lyah::vec<2, std::float_t> result = {1.0f, 4.0f};

		result += a;

		test::assert(test::eq(result, expected));
	}

	void testSubtractionAssignment() {
		const lyah::vec<2, std::float_t> expected = {-4.0f, 1.0f};
		const lyah::vec<2, std::float_t> a = {5.0f, 3.0f};
		lyah::vec<2, std::float_t> result = {1.0f, 4.0f};

		result -= a;

		test::assert(test::eq(result, expected));
	}

	void testVectorScalarMultiplicationAssignment() {
		const lyah::vec<2, std::float_t> expected = {3.0f, 12.0f};
		const std::float_t a = 3.0f;
		lyah::vec<2, std::float_t> result = {1.0f, 4.0f};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testVectorVectorMultiplicationAssignment() {
		const lyah::vec<2, std::float_t> expected = {5.0f, 12.0f};
		const lyah::vec<2, std::float_t> a = {5.0f, 3.0f};
		lyah::vec<2, std::float_t> result = {1.0f, 4.0f};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testVectorMatrixMultiplicationAssignment() {
		const lyah::vec<2, std::float_t> expected = {21.0f, 16.0f};
		const lyah::mat<2, 2, std::float_t> A = {
			1.0f, 4.0f,
			5.0f, 3.0f,
		};
		lyah::vec<2, std::float_t> result = {1.0f, 4.0f};

		result *= A;

		test::assert(test::eq(result, expected));
	}

	void testVectorScalarDivisionAssignment() {
		const lyah::vec<2, std::float_t> expected = {0.333f, 1.333f};
		const std::float_t a = 3.0f;
		lyah::vec<2, std::float_t> result = {1.0f, 4.0f};

		result /= a;

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testVectorVectorDivisionAssignment() {
		const lyah::vec<2, std::float_t> expected = {lyah::infinity<std::float_t>(), 1.333f};
		const lyah::vec<2, std::float_t> a = {0.0f, 3.0f};
		lyah::vec<2, std::float_t> result = {1.0f, 4.0f};

		result /= a;

		test::assert(test::eq(result, expected, 0.001f));
	}

	/*void testVectorScalarRemainder() {
		const lyah::vec<2, std::float_t> expected = {1.0f, 1.0f};
		const lyah::vec<2, std::float_t> a = {1.0f, 4.0f};
		const std::float_t b = 3.0f;

		const lyah::vec<2, std::float_t> result = a % b;

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testScalarVectorRemainder() {
		const lyah::vec<2, std::float_t> expected = {lyah::nan<std::float_t>(), 3.0f};
		const lyah::vec<2, std::float_t> a = {0.0f, 4.0f};
		const std::float_t b = 3.0f;

		const lyah::vec<2, std::float_t> result = b % a;

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testVectorScalarRemainderAssignment() {
		const lyah::vec<2, std::float_t> expected = {1.0f, 1.0f};
		const std::float_t a = 3.0f;
		lyah::vec<2, std::float_t> result = {1.0f, 4.0f};

		result %= a;

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testVectorVectorRemainder() {
		const lyah::vec<2, std::float_t> expected = {lyah::nan<std::float_t>(), 1.0f};
		const lyah::vec<2, std::float_t> a = {1.0f, 4.0f};
		const lyah::vec<2, std::float_t> b = {0.0f, 3.0f};

		const lyah::vec<2, std::float_t> result = a % b;

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testVectorVectorRemainderAssignment() {
		const lyah::vec<2, std::float_t> expected = {lyah::nan<std::float_t>(), 1.0f};
		const lyah::vec<2, std::float_t> a = {0.0f, 3.0f};
		lyah::vec<2, std::float_t> result = {1.0f, 4.0f};

		result %= a;

		test::assert(test::eq(result, expected, 0.001f));
	}*/

	/* void testSign() {
		const lyah::vec<2, std::float_t> expected = {1.0f, -1.0f};
		const lyah::vec<2, std::float_t> a = {1.0f, -4.0f};

		const lyah::vec<2, std::float_t> result = lyah::sign(a);

		test::assert(test::eq(result, expected));
	} */

	/* void testHorizontalMin() {
		const std::float_t expected = 1.0f;
		const lyah::vec<2, std::float_t> a = {1.0f, 4.0f};

		const std::float_t result = lyah::min(a);

		test::assert(test::eq(result, expected));
	} */

	/* void testHorizontalMax() {
		const std::float_t expected = 4.0f;
		const lyah::vec<2, std::float_t> a = {1.0f, 4.0f};

		const std::float_t result = lyah::max(a);

		test::assert(test::eq(result, expected));
	} */

	void testCrossProduct() {
		const lyah::vec<2, std::float_t> expected = {4.0f, 1.0f};
		const lyah::vec<2, std::float_t> a = {1.0f, -4.0f};
		const std::float_t b = -1.0f;

		const lyah::vec<2, std::float_t> result = lyah::cross(a, b);

		test::assert(test::eq(result, expected));
	}

	void runAll() {
		test::printTestCategory("lyah::vec<2, std::float_t> - 2-component single floating-point vector");

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
		/*test::runTest(&testVectorScalarRemainder, "Vector-scalar remainder (%)");
		test::runTest(&testScalarVectorRemainder, "Scalar-vector remainder (%)");
		test::runTest(&testVectorScalarRemainderAssignment, "Vector-scalar remainder assignment (%=)");
		test::runTest(&testVectorVectorRemainder, "Vector-vector remainder (%)");
		test::runTest(&testVectorVectorRemainderAssignment, "Vector-vector remainder assignment (%=)");*/

		/*test::runTest(&testHorizontalMin, "Horizontal min");
		test::runTest(&testHorizontalMax, "Horizontal max");*/

		test::runTest(&testCrossProduct, "Cross product");
	}
}