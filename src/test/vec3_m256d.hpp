#pragma once

#include "pch.hpp"

namespace vec3_m256d {
	void testDefaultConstructor() {
		const std::double_t expected[3] = {0.0, 0.0, 0.0};

		const lyah::vec<3, std::double_t> result;

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
		test::assert(test::eq(result[2], expected[2]));
	}

	void testComponentConstructor() {
		const std::double_t expected[3] = {1.0, 4.0, 6.0};

		const lyah::vec<3, std::double_t> result = {1.0, 4.0, 6.0};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
		test::assert(test::eq(result[2], expected[2]));
	}

	void testSimdConstructor() {
		const lyah::vec<3, std::double_t> expected = {1.0, 4.0, 6.0};
		const __m256d m = _mm256_set_pd(0.0, 6.0, 4.0, 1.0);

		const lyah::vec<3, std::double_t> result(m);

		test::assert(test::eq(result, expected));
	}

	void testConvertingConstructor() {
		const lyah::vec<3, std::double_t> expected = {1.0, 4.0, 6.0};
		const lyah::vec<3, std::float_t> a = {1.0f, 4.0f, 6.0f};

		const lyah::vec<3, std::double_t> result(a);

		test::assert(test::eq(result, expected));
	}

	void testEquality() {
		const bool expected[2] = {true, false};
		const lyah::vec<3, std::double_t> a = {1.0, 4.0, 6.0};
		const lyah::vec<3, std::double_t> b = {1.0, 0.0, 6.0};

		const bool result[2] = {a == a, a == b};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
	}

	void testInequality() {
		const bool expected[2] = {false, true};
		const lyah::vec<3, std::double_t> a = {1.0, 4.0, 6.0};
		const lyah::vec<3, std::double_t> b = {1.0, 0.0, 6.0};

		const bool result[2] = {a != a, a != b};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
	}

	void testUnaryPlus() {
		const lyah::vec<3, std::double_t> expected = {1.0, 4.0, 6.0};
		const lyah::vec<3, std::double_t> a = {1.0, 4.0, 6.0};

		const lyah::vec<3, std::double_t> result = +a;

		test::assert(test::eq(result, expected));
	}

	void testUnaryMinus() {
		const lyah::vec<3, std::double_t> expected = {-1.0, -4.0, -6.0};
		const lyah::vec<3, std::double_t> a = {1.0, 4.0, 6.0};

		const lyah::vec<3, std::double_t> result = -a;

		test::assert(test::eq(result, expected));
	}

	void testAddition() {
		const lyah::vec<3, std::double_t> expected = {6.0, 7.0, 8.0};
		const lyah::vec<3, std::double_t> a = {1.0, 4.0, 6.0};
		const lyah::vec<3, std::double_t> b = {5.0, 3.0, 2.0};

		const lyah::vec<3, std::double_t> result = a + b;

		test::assert(test::eq(result, expected));
	}

	void testAdditionAssignment() {
		const lyah::vec<3, std::double_t> expected = {6.0, 7.0, 8.0};
		const lyah::vec<3, std::double_t> a = {5.0, 3.0, 2.0};
		lyah::vec<3, std::double_t> result = {1.0, 4.0, 6.0};

		result += a;

		test::assert(test::eq(result, expected));
	}

	void testSubtraction() {
		const lyah::vec<3, std::double_t> expected = {-4.0, 1.0, 4.0};
		const lyah::vec<3, std::double_t> a = {1.0, 4.0, 6.0};
		const lyah::vec<3, std::double_t> b = {5.0, 3.0, 2.0};

		const lyah::vec<3, std::double_t> result = a - b;

		test::assert(test::eq(result, expected));
	}

	void testSubtractionAssignment() {
		const lyah::vec<3, std::double_t> expected = {-4.0, 1.0, 4.0};
		const lyah::vec<3, std::double_t> a = {5.0, 3.0, 2.0};
		lyah::vec<3, std::double_t> result = {1.0, 4.0, 6.0};

		result -= a;

		test::assert(test::eq(result, expected));
	}

	void testScalarMultiplicationAB() {
		const lyah::vec<3, std::double_t> expected = {3.0, 12.0, 18.0};
		const lyah::vec<3, std::double_t> a = {1.0, 4.0, 6.0};
		const std::double_t b = 3.0;

		const lyah::vec<3, std::double_t> result = a * b;

		test::assert(test::eq(result, expected));
	}

	void testScalarMultiplicationBA() {
		const lyah::vec<3, std::double_t> expected = {3.0, 12.0, 18.0};
		const lyah::vec<3, std::double_t> a = {1.0, 4.0, 6.0};
		const std::double_t b = 3.0;

		const lyah::vec<3, std::double_t> result = b * a;

		test::assert(test::eq(result, expected));
	}

	void testScalarMultiplicationAssignment() {
		const lyah::vec<3, std::double_t> expected = {3.0, 12.0, 18.0};
		const std::double_t a = 3.0;
		lyah::vec<3, std::double_t> result = {1.0, 4.0, 6.0};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testMultiplication() {
		const lyah::vec<3, std::double_t> expected = {5.0, 12.0, 12.0};
		const lyah::vec<3, std::double_t> a = {1.0, 4.0, 6.0};
		const lyah::vec<3, std::double_t> b = {5.0, 3.0, 2.0};

		const lyah::vec<3, std::double_t> result = a * b;

		test::assert(test::eq(result, expected));
	}

	void testMultiplicationAssignment() {
		const lyah::vec<3, std::double_t> expected = {5.0, 12.0, 12.0};
		const lyah::vec<3, std::double_t> a = {5.0, 3.0, 2.0};
		lyah::vec<3, std::double_t> result = {1.0, 4.0, 6.0};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testScalarDivisionAB() {
		const lyah::vec<3, std::double_t> expected = {0.333, 1.333, 2.0};
		const lyah::vec<3, std::double_t> a = {1.0, 4.0, 6.0};
		const std::double_t b = 3.0;

		const lyah::vec<3, std::double_t> result = a / b;

		test::assert(test::eq(result, expected, 0.001));
	}

	void testScalarDivisionBA() {
		const lyah::vec<3, std::double_t> expected = {lyah::infinity<std::double_t>(), 0.75, 0.5};
		const lyah::vec<3, std::double_t> a = {0.0, 4.0, 6.0};
		const std::double_t b = 3.0;

		const lyah::vec<3, std::double_t> result = b / a;

		test::assert(test::eq(result, expected, 0.001));
	}

	void testScalarDivisionAssignment() {
		const lyah::vec<3, std::double_t> expected = {0.333, 1.333, 2.0};
		const std::double_t a = 3.0;
		lyah::vec<3, std::double_t> result = {1.0, 4.0, 6.0};

		result /= a;

		test::assert(test::eq(result, expected, 0.001));
	}

	void testDivision() {
		const lyah::vec<3, std::double_t> expected = {lyah::infinity<std::double_t>(), 1.333, 3.0};
		const lyah::vec<3, std::double_t> a = {1.0, 4.0, 6.0};
		const lyah::vec<3, std::double_t> b = {0.0, 3.0, 2.0};

		const lyah::vec<3, std::double_t> result = a / b;

		test::assert(test::eq(result, expected, 0.001));
	}

	void testDivisionAssignment() {
		const lyah::vec<3, std::double_t> expected = {lyah::infinity<std::double_t>(), 1.333, 3.0};
		const lyah::vec<3, std::double_t> a = {0.0, 3.0, 2.0};
		lyah::vec<3, std::double_t> result = {1.0, 4.0, 6.0};

		result /= a;

		test::assert(test::eq(result, expected, 0.001));
	}

	/* void testFloor() {
		const lyah::vec<3, std::double_t> expected = {1.0, 4.0, 6.0};
		const lyah::vec<3, std::double_t> a = {1.999, 4.0, 6.111};

		const lyah::vec<3, std::double_t> result = lyah::floor(a);

		test::assert(test::eq(result, expected));
	} */

	/* void testCeil() {
		const lyah::vec<3, std::double_t> expected = {1.0, 4.0, 6.0};
		const lyah::vec<3, std::double_t> a = {0.999, 4.0, 5.111};

		const lyah::vec<3, std::double_t> result = lyah::ceil(a);

		test::assert(test::eq(result, expected));
	} */

	/* void testRound() {
		const lyah::vec<3, std::double_t> expected = {1.0, 4.0, 7.0};
		const lyah::vec<3, std::double_t> a = {1.3279, 4.007, 6.897};

		const lyah::vec<3, std::double_t> result = lyah::round(a);

		test::assert(test::eq(result, expected));
	} */

	void testVerticalMax() {
		const lyah::vec<3, std::double_t> expected = {5.0, 4.0, 6.0};
		const lyah::vec<3, std::double_t> a = {5.0, 3.0, 2.0};
		const lyah::vec<3, std::double_t> b = {1.0, 4.0, 6.0};

		const lyah::vec<3, std::double_t> result = lyah::max(a, b);

		test::assert(test::eq(result, expected));
	}

	void testVerticalMin() {
		const lyah::vec<4, std::double_t> expected = {1.0, 3.0, 2.0, 2.0};
		const lyah::vec<4, std::double_t> a = {5.0, 3.0, 2.0, 7.0};
		const lyah::vec<4, std::double_t> b = {1.0, 4.0, 6.0, 2.0};

		const lyah::vec<4, std::double_t> result = lyah::min(a, b);

		test::assert(test::eq(result, expected));
	}

	void testLerp() {
		const lyah::vec<3, std::double_t> expected = {2.2, 3.7, 4.8};
		const lyah::vec<3, std::double_t> a = {1.0, 4.0, 6.0};
		const lyah::vec<3, std::double_t> b = {5.0, 3.0, 2.0};
		const std::double_t t = 0.3;

		const lyah::vec<3, std::double_t> result = lyah::lerp(a, b, t);

		test::assert(test::eq(result, expected, 0.001));
	}

	void testSum() {
		const std::double_t expected = 11.0;
		const lyah::vec<3, std::double_t> a = {1.0, 4.0, 6.0};

		const std::double_t result = lyah::sum(a);

		test::assert(test::eq(result, expected));
	}

	void testPow() {
		const lyah::vec<3, std::double_t> expected = {1.0, 64.0, 36.0};
		const lyah::vec<3, std::double_t> a = {1.0, 4.0, 6.0};
		const lyah::vec<3, std::double_t> b = {5.0, 3.0, 2.0};

		const lyah::vec<3, std::double_t> result = lyah::pow(a, b);

		test::assert(test::eq(result, expected, 0.001));
	}

	void testRcp() {
		const lyah::vec<3, std::double_t> expected = {lyah::infinity<std::double_t>(), 0.25, 0.167};
		const lyah::vec<3, std::double_t> a = {0.0, 4.0, 6.0};

		const lyah::vec<3, std::double_t> result = lyah::rcp(a);

		test::assert(test::eq(result, expected, 0.001));
	}

	void testSqrt() {
		const lyah::vec<3, std::double_t> expected = {1.0, 2.0, 2.449};
		const lyah::vec<3, std::double_t> a = {1.0, 4.0, 6.0};

		const lyah::vec<3, std::double_t> result = lyah::sqrt(a);

		test::assert(test::eq(result, expected, 0.001));
	}

	void testRsqrt() {
		const lyah::vec<3, std::double_t> expected = {1.0, 0.5, 0.408};
		const lyah::vec<3, std::double_t> a = {1.0, 4.0, 6.0};

		const lyah::vec<3, std::double_t> result = lyah::rsqrt(a);

		test::assert(test::eq(result, expected, 0.001));
	}

	void testCrossProduct() {
		const lyah::vec<3, std::double_t> expected = {-10.0, 28.0, -17.0};
		const lyah::vec<3, std::double_t> a = {1.0, 4.0, 6.0};
		const lyah::vec<3, std::double_t> b = {5.0, 3.0, 2.0};

		const lyah::vec<3, std::double_t> result = lyah::cross(a, b);

		test::assert(test::eq(result, expected));
	}

	void testDotProduct() {
		const std::double_t expected = 29.0;
		const lyah::vec<3, std::double_t> a = {1.0, 4.0, 6.0};
		const lyah::vec<3, std::double_t> b = {5.0, 3.0, 2.0};

		const std::double_t result = lyah::dot(a, b);

		test::assert(test::eq(result, expected));
	}

	void testLength() {
		const std::double_t expected = 7.280;
		const lyah::vec<3, std::double_t> a = {1.0, 4.0, 6.0};

		const std::double_t result = lyah::length(a);

		test::assert(test::eq(result, expected, 0.001));
	}

	void testDistance() {
		const std::double_t expected = 5.745;
		const lyah::vec<3, std::double_t> a = {1.0, 4.0, 6.0};
		const lyah::vec<3, std::double_t> b = {5.0, 3.0, 2.0};

		const std::double_t result = lyah::distance(a, b);

		test::assert(test::eq(result, expected, 0.001));
	}

	void testNormalization() {
		const lyah::vec<3, std::double_t> expected = {0.137, 0.550, 0.824};
		const lyah::vec<3, std::double_t> a = {1.0, 4.0, 6.0};

		const lyah::vec<3, std::double_t> result = lyah::normalized(a);

		test::assert(test::eq(result, expected, 0.001));
	}

	void runAll() {
		test::printTestCategory("lyah::vec<3, std::double_t> - 3-component double floating-point vector");

		test::runTest(&testDefaultConstructor, "Default constructor");
		test::runTest(&testComponentConstructor, "Component constructor");
		test::runTest(&testSimdConstructor, "SIMD constructor");
		test::runTest(&testConvertingConstructor, "Converting constructor");

		test::runTest(&testEquality, "Equality (==)");
		test::runTest(&testInequality, "Inequality (!=)");

		test::runTest(&testUnaryPlus, "Unary plus (+)");
		test::runTest(&testUnaryMinus, "Unary minus (-)");

		test::runTest(&testAddition, "Addition (+)");
		test::runTest(&testAdditionAssignment, "Addition assignment (+=)");

		test::runTest(&testSubtraction, "Subtraction (-)");
		test::runTest(&testSubtractionAssignment, "Subtraction assignment (-=)");

		test::runTest(&testScalarMultiplicationAB, "Scalar multiplication (*) - AB");
		test::runTest(&testScalarMultiplicationBA, "Scalar multiplication (*) - BA");
		test::runTest(&testScalarMultiplicationAssignment, "Scalar multiplication assignment (*=)");
		test::runTest(&testMultiplication, "Multiplication (*)");
		test::runTest(&testMultiplicationAssignment, "Multiplication assignment (*=)");

		test::runTest(&testScalarDivisionAB, "Scalar division (/) - AB");
		test::runTest(&testScalarDivisionBA, "Scalar division (/) - BA");
		test::runTest(&testScalarDivisionAssignment, "Scalar division assignment (/=)");
		test::runTest(&testDivision, "Division (/)");
		test::runTest(&testDivisionAssignment, "Division assignment (/=)");

		// test::runTest(&testFloor, "Floor");
		// test::runTest(&testCeil, "Ceil");
		// test::runTest(&testRound, "Round");
		test::runTest(&testVerticalMax, "Vertical max");
		test::runTest(&testVerticalMin, "Vertical min");
		test::runTest(&testLerp, "Linear interpolation");
		test::runTest(&testSum, "Sum");

		test::runTest(&testPow, "Power");
		test::runTest(&testRcp, "Reciprocal");
		test::runTest(&testSqrt, "Square root");
		test::runTest(&testRsqrt, "Inverse square root");

		test::runTest(&testCrossProduct, "Cross product");
		test::runTest(&testDotProduct, "Dot product");
		test::runTest(&testLength, "Length");
		test::runTest(&testDistance, "Distance");
		test::runTest(&testNormalization, "Normalization");
	}
}