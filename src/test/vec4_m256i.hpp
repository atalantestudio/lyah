#pragma once

#include "pch.hpp"

namespace vec4_m256i {
	void testDefaultConstructor() {
		const std::int64_t expected[4] = {0, 0, 0, 0};

		const lyah::vec<4, std::int64_t> result;

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
		test::assert(test::eq(result[2], expected[2]));
		test::assert(test::eq(result[3], expected[3]));
	}

	void testComponentConstructor() {
		const std::int64_t expected[4] = {1, 4, 6, -1};

		const lyah::vec<4, std::int64_t> result = {1, 4, 6, -1};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
		test::assert(test::eq(result[2], expected[2]));
		test::assert(test::eq(result[3], expected[3]));
	}

	void testComponentBroadcastConstructor() {
		const std::int64_t expected = 1;

		const lyah::vec<4, std::int64_t> result = lyah::vec<4, std::int64_t>(1);

		test::assert(test::eq(result[0], expected));
		test::assert(test::eq(result[1], expected));
		test::assert(test::eq(result[2], expected));
		test::assert(test::eq(result[3], expected));
	}

	void testSimdConstructor() {
		const lyah::vec<4, std::int64_t> expected = {1, 4, 6, -1};
		const __m256i m = _mm256_set_epi64x(-1, 6, 4, 1);

		const lyah::vec<4, std::int64_t> result(m);

		test::assert(test::eq(result, expected));
	}

	void testConvertingConstructor() {
		const lyah::vec<4, std::int64_t> expected = {1, 4, 6, -1};
		const lyah::vec<4, std::int32_t> a = {1, 4, 6, -1};

		const lyah::vec<4, std::int64_t> result(a);

		test::assert(test::eq(result, expected));
	}

	void testEquality() {
		const bool expected[2] = {true, false};
		const lyah::vec<4, std::int64_t> a = {1, 4, 6, -1};
		const lyah::vec<4, std::int64_t> b = {1, 0, 6, -1};

		const bool result[2] = {a == a, a == b};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
	}

	void testInequality() {
		const bool expected[2] = {false, true};
		const lyah::vec<4, std::int64_t> a = {1, 4, 6, -1};
		const lyah::vec<4, std::int64_t> b = {1, 0, 6, -1};

		const bool result[2] = {a != a, a != b};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
	}

	void testUnaryPlus() {
		const lyah::vec<4, std::int64_t> expected = {1, 4, 6, -1};
		const lyah::vec<4, std::int64_t> a = {1, 4, 6, -1};

		const lyah::vec<4, std::int64_t> result = +a;

		test::assert(test::eq(result, expected));
	}

	void testUnaryMinus() {
		const lyah::vec<4, std::int64_t> expected = {-1, -4, -6, 1};
		const lyah::vec<4, std::int64_t> a = {1, 4, 6, -1};

		const lyah::vec<4, std::int64_t> result = -a;

		test::assert(test::eq(result, expected));
	}

	void testAddition() {
		const lyah::vec<4, std::int64_t> expected = {6, 7, 8, 3};
		const lyah::vec<4, std::int64_t> a = {1, 4, 6, -1};
		const lyah::vec<4, std::int64_t> b = {5, 3, 2, 4};

		const lyah::vec<4, std::int64_t> result = a + b;

		test::assert(test::eq(result, expected));
	}

	void testAdditionAssignment() {
		const lyah::vec<4, std::int64_t> expected = {6, 7, 8, 3};
		const lyah::vec<4, std::int64_t> a = {5, 3, 2, 4};
		lyah::vec<4, std::int64_t> result = {1, 4, 6, -1};

		result += a;

		test::assert(test::eq(result, expected));
	}

	void testSubtraction() {
		const lyah::vec<4, std::int64_t> expected = {-4, 1, 4, -8};
		const lyah::vec<4, std::int64_t> a = {1, 4, 6, -1};
		const lyah::vec<4, std::int64_t> b = {5, 3, 2, 7};

		const lyah::vec<4, std::int64_t> result = a - b;

		test::assert(test::eq(result, expected));
	}

	void testSubtractionAssignment() {
		const lyah::vec<4, std::int64_t> expected = {-4, 1, 4, -8};
		const lyah::vec<4, std::int64_t> a = {5, 3, 2, 7};
		lyah::vec<4, std::int64_t> result = {1, 4, 6, -1};

		result -= a;

		test::assert(test::eq(result, expected));
	}

	void testVectorScalarMultiplication() {
		const lyah::vec<4, std::int64_t> expected = {3, 12, 18, -3};
		const lyah::vec<4, std::int64_t> a = {1, 4, 6, -1};
		const std::int64_t b = 3;

		const lyah::vec<4, std::int64_t> result = a * b;

		test::assert(test::eq(result, expected));
	}

	void testScalarVectorMultiplication() {
		const lyah::vec<4, std::int64_t> expected = {3, 12, 18, -3};
		const lyah::vec<4, std::int64_t> a = {1, 4, 6, -1};
		const std::int64_t b = 3;

		const lyah::vec<4, std::int64_t> result = b * a;

		test::assert(test::eq(result, expected));
	}

	void testVectorScalarMultiplicationAssignment() {
		const lyah::vec<4, std::int64_t> expected = {3, 12, 18, -3};
		const std::int64_t a = 3;
		lyah::vec<4, std::int64_t> result = {1, 4, 6, -1};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testVectorVectorMultiplication() {
		const lyah::vec<4, std::int64_t> expected = {5, 12, 12, -7};
		const lyah::vec<4, std::int64_t> a = {1, 4, 6, -1};
		const lyah::vec<4, std::int64_t> b = {5, 3, 2, 7};

		const lyah::vec<4, std::int64_t> result = a * b;

		test::assert(test::eq(result, expected));
	}

	void testVectorVectorMultiplicationAssignment() {
		const lyah::vec<4, std::int64_t> expected = {5, 12, 12, -7};
		const lyah::vec<4, std::int64_t> a = {5, 3, 2, 7};
		lyah::vec<4, std::int64_t> result = {1, 4, 6, -1};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	/*void testVectorScalarDivision() {
		const lyah::vec<4, std::int64_t> expected = {0.333, 1.333, 2, -0.333};
		const lyah::vec<4, std::int64_t> a = {1, 4, 6, -1};
		const std::int64_t b = 3;

		const lyah::vec<4, std::int64_t> result = a / b;

		test::assert(test::eq(result, expected, 001));
	}

	void testScalarVectorDivision() {
		const lyah::vec<4, std::int64_t> expected = {lyah::infinity<std::int64_t>(), 0.75, 0.5, -3};
		const lyah::vec<4, std::int64_t> a = {0, 4, 6, -1};
		const std::int64_t b = 3;

		const lyah::vec<4, std::int64_t> result = b / a;

		test::assert(test::eq(result, expected, 001));
	}

	void testVectorScalarDivisionAssignment() {
		const lyah::vec<4, std::int64_t> expected = {0.333, 1.333, 2, -0.333};
		const std::int64_t a = 3;
		lyah::vec<4, std::int64_t> result = {1, 4, 6, -1};

		result /= a;

		test::assert(test::eq(result, expected, 001));
	}

	void testVectorVectorDivision() {
		const lyah::vec<4, std::int64_t> expected = {lyah::infinity<std::int64_t>(), 1.333, 3, -0.143};
		const lyah::vec<4, std::int64_t> a = {1, 4, 6, -1};
		const lyah::vec<4, std::int64_t> b = {0, 3, 2, 7};

		const lyah::vec<4, std::int64_t> result = a / b;

		test::assert(test::eq(result, expected, 001));
	}

	void testVectorVectorDivisionAssignment() {
		const lyah::vec<4, std::int64_t> expected = {lyah::infinity<std::int64_t>(), 1.333, 3, -0.143};
		const lyah::vec<4, std::int64_t> a = {0, 3, 2, 7};
		lyah::vec<4, std::int64_t> result = {1, 4, 6, -1};

		result /= a;

		test::assert(test::eq(result, expected, 001));
	}

	void testFloor() {
		const lyah::vec<4, std::int64_t> expected = {1, 4, 6, -1};
		const lyah::vec<4, std::int64_t> a = {1.999, 4, 6.111, -0.5};

		const lyah::vec<4, std::int64_t> result = lyah::floor(a);

		test::assert(test::eq(result, expected));
	}

	void testCeil() {
		const lyah::vec<4, std::int64_t> expected = {1, 4, 6, -1};
		const lyah::vec<4, std::int64_t> a = {0.999, 4, 5.111, -1.5};

		const lyah::vec<4, std::int64_t> result = lyah::ceil(a);

		test::assert(test::eq(result, expected));
	}

	void testRound() {
		const lyah::vec<4, std::int64_t> expected = {1, 4, 7, 0};
		const lyah::vec<4, std::int64_t> a = {1.3279, 407, 6.897, -0.5};

		const lyah::vec<4, std::int64_t> result = lyah::round(a);

		test::assert(test::eq(result, expected));
	}

	void testVerticalMax() {
		const lyah::vec<4, std::int64_t> expected = {5, 4, 6, 7};
		const lyah::vec<4, std::int64_t> a = {5, 3, 2, 7};
		const lyah::vec<4, std::int64_t> b = {1, 4, 6, 2};

		const lyah::vec<4, std::int64_t> result = lyah::max(a, b);

		test::assert(test::eq(result, expected));
	}

	void testVerticalMin() {
		const lyah::vec<4, std::int64_t> expected = {1, 3, 2, 2};
		const lyah::vec<4, std::int64_t> a = {5, 3, 2, 7};
		const lyah::vec<4, std::int64_t> b = {1, 4, 6, 2};

		const lyah::vec<4, std::int64_t> result = lyah::min(a, b);

		test::assert(test::eq(result, expected));
	}

	void testLerp() {
		const lyah::vec<4, std::int64_t> expected = {2.2, 3.7, 4.8, 1.4};
		const lyah::vec<4, std::int64_t> a = {1, 4, 6, -1};
		const lyah::vec<4, std::int64_t> b = {5, 3, 2, 7};
		const std::int64_t t = 0.3;

		const lyah::vec<4, std::int64_t> result = lyah::lerp(a, b, t);

		test::assert(test::eq(result, expected, 001));
	}

	void testSum() {
		const std::int64_t expected = 13;
		const lyah::vec<4, std::int64_t> a = {1, 4, 6, 2};

		const std::int64_t result = lyah::sum(a);

		test::assert(test::eq(result, expected));
	}

	void testPow() {
		const lyah::vec<4, std::int64_t> expected = {1, 64, 36, -1};
		const lyah::vec<4, std::int64_t> a = {1, 4, 6, -1};
		const lyah::vec<4, std::int64_t> b = {5, 3, 2, 7};

		const lyah::vec<4, std::int64_t> result = lyah::pow(a, b);

		test::assert(test::eq(result, expected));
	}

	void testRcp() {
		const lyah::vec<4, std::int64_t> expected = {lyah::infinity<std::int64_t>(), 0.25, 0.167, -1};
		const lyah::vec<4, std::int64_t> a = {0, 4, 6, -1};

		const lyah::vec<4, std::int64_t> result = lyah::rcp(a);

		test::assert(test::eq(result, expected, 001));
	}

	void testSqrt() {
		const lyah::vec<4, std::int64_t> expected = {1, 2, 2.449, 0.707};
		const lyah::vec<4, std::int64_t> a = {1, 4, 6, 0.5};

		const lyah::vec<4, std::int64_t> result = lyah::sqrt(a);

		test::assert(test::eq(result, expected, 001));
	}

	void testRsqrt() {
		const lyah::vec<4, std::int64_t> expected = {1, 0.5, 0.408, 1.414};
		const lyah::vec<4, std::int64_t> a = {1, 4, 6, 0.5};

		const lyah::vec<4, std::int64_t> result = lyah::rsqrt(a);

		test::assert(test::eq(result, expected, 001));
	}

	void testDotProduct() {
		const std::int64_t expected = 22;
		const lyah::vec<4, std::int64_t> a = {1, 4, 6, -1};
		const lyah::vec<4, std::int64_t> b = {5, 3, 2, 7};

		const std::int64_t result = lyah::dot(a, b);

		test::assert(test::eq(result, expected));
	}

	void testLength() {
		const std::int64_t expected = 7.348;
		const lyah::vec<4, std::int64_t> a = {1, 4, 6, -1};

		const std::int64_t result = lyah::length(a);

		test::assert(test::eq(result, expected, 001));
	}

	void testDistance() {
		const std::int64_t expected = 9.849;
		const lyah::vec<4, std::int64_t> a = {1, 4, 6, -1};
		const lyah::vec<4, std::int64_t> b = {5, 3, 2, 7};

		const std::int64_t result = lyah::distance(a, b);

		test::assert(test::eq(result, expected, 001));
	}

	void testNormalization() {
		const lyah::vec<4, std::int64_t> expected = {0.136, 0.544, 0.816, -0.136};
		const lyah::vec<4, std::int64_t> a = {1, 4, 6, -1};

		const lyah::vec<4, std::int64_t> result = lyah::normalized(a);

		test::assert(test::eq(result, expected, 001));
	}

	void testDegrees() {
		const lyah::vec<4, std::int64_t> expected = {180, -45, 0, 360};
		const lyah::vec<4, std::int64_t> a = {lyah::pi<std::int64_t>(), -lyah::pi<std::int64_t>() * 0.25, 0, 2 * lyah::pi<std::int64_t>()};

		const lyah::vec<4, std::int64_t> result = lyah::degrees(a);

		test::assert(test::eq(result, expected, 001));
	}

	void testRadians() {
		const lyah::vec<4, std::int64_t> expected = {lyah::pi<std::int64_t>(), -lyah::pi<std::int64_t>() * 0.25, 0, 2 * lyah::pi<std::int64_t>()};
		const lyah::vec<4, std::int64_t> a = {180, -45, 0, 360};

		const lyah::vec<4, std::int64_t> result = lyah::radians(a);

		test::assert(test::eq(result, expected, 001));
	}

	void testSin() {
		const lyah::vec<4, std::int64_t> expected = {0.841, 0.479, 0.894, 0};
		const lyah::vec<4, std::int64_t> a = {1, 0.5, 90, 0};

		const lyah::vec<4, std::int64_t> result = lyah::sin(a);

		test::assert(test::eq(result, expected, 001));
	}

	void testCos() {
		const lyah::vec<4, std::int64_t> expected = {0.540, 0.878, -0.448, 1};
		const lyah::vec<4, std::int64_t> a = {1, 0.5, 90, 0};

		const lyah::vec<4, std::int64_t> result = lyah::cos(a);

		test::assert(test::eq(result, expected, 001));
	}

	void testTan() {
		const lyah::vec<4, std::int64_t> expected = {1.557, 0.546, -1.995, 0};
		const lyah::vec<4, std::int64_t> a = {1, 0.5, 90, 0};

		const lyah::vec<4, std::int64_t> result = lyah::tan(a);

		test::assert(test::eq(result, expected, 001));
	}*/

	void runAll() {
		test::printTestCategory("lyah::vec<4, std::int64_t> - 4-component 64-bit integer vector");

		test::runTest(&testDefaultConstructor, "Default constructor");
		test::runTest(&testComponentConstructor, "Component constructor");
		test::runTest(&testComponentBroadcastConstructor, "Component broadcast constructor");
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

		test::runTest(&testVectorScalarMultiplication, "Vector-scalar multiplication (*)");
		test::runTest(&testScalarVectorMultiplication, "Scalar-vector multiplication (*)");
		test::runTest(&testVectorScalarMultiplicationAssignment, "Vector-scalar multiplication assignment (*=)");
		test::runTest(&testVectorVectorMultiplication, "Vector-vector multiplication (*)");
		test::runTest(&testVectorVectorMultiplicationAssignment, "Vector-vector multiplication assignment (*=)");

		/*test::runTest(&testVectorScalarDivision, "Vector-scalar division (/)");
		test::runTest(&testScalarVectorDivision, "Scalar-vector division (/)");
		test::runTest(&testVectorScalarDivisionAssignment, "Vector-scalar division assignment (/=)");
		test::runTest(&testVectorVectorDivision, "Vector-vector division (/)");
		test::runTest(&testVectorVectorDivisionAssignment, "Vector-vector division assignment (/=)");

		test::runTest(&testVerticalMax, "Vertical max");
		test::runTest(&testVerticalMin, "Vertical min");
		test::runTest(&testLerp, "Linear interpolation");
		test::runTest(&testSum, "Sum");

		test::runTest(&testPow, "Power");
		test::runTest(&testRcp, "Reciprocal");
		test::runTest(&testSqrt, "Square root");
		test::runTest(&testRsqrt, "Inverse square root");

		test::runTest(&testDotProduct, "Dot product");
		test::runTest(&testLength, "Length");
		test::runTest(&testDistance, "Distance");
		test::runTest(&testNormalization, "Normalization");

		test::runTest(&testDegrees, "Degrees");
		test::runTest(&testRadians, "Radians");
		test::runTest(&testSin, "Sin");
		test::runTest(&testCos, "Cos");
		test::runTest(&testTan, "Tan");*/
	}
}