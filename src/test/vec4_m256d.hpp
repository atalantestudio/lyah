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

	void testSimdConstructor() {
		const lyah::vec<4, std::double_t> expected = {1.0, 4.0, 6.0, -1.0};
		const __m256d m = _mm256_set_pd(-1.0, 6.0, 4.0, 1.0);

		const lyah::vec<4, std::double_t> result(m);

		test::assert(test::eq(result, expected));
	}

	void testConvertingConstructor() {
		const lyah::vec<4, std::double_t> expected = {1.0, 4.0, 6.0, -1.0};
		const lyah::vec<4, std::float_t> a = {1.0f, 4.0f, 6.0f, -1.0f};

		const lyah::vec<4, std::double_t> result(a);

		test::assert(test::eq(result, expected));
	}

	void testEquality() {
		const bool expected[2] = {true, false};
		const lyah::vec<4, std::double_t> a = {1.0, 4.0, 6.0, -1.0};
		const lyah::vec<4, std::double_t> b = {1.0, 0.0, 6.0, -1.0};

		const bool result[2] = {a == a, a == b};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
	}

	void testInequality() {
		const bool expected[2] = {false, true};
		const lyah::vec<4, std::double_t> a = {1.0, 4.0, 6.0, -1.0};
		const lyah::vec<4, std::double_t> b = {1.0, 0.0, 6.0, -1.0};

		const bool result[2] = {a != a, a != b};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
	}

	void testUnaryPlus() {
		const lyah::vec<4, std::double_t> expected = {1.0, 4.0, 6.0, -1.0};
		const lyah::vec<4, std::double_t> a = {1.0, 4.0, 6.0, -1.0};

		const lyah::vec<4, std::double_t> result = +a;

		test::assert(test::eq(result, expected));
	}

	void testUnaryMinus() {
		const lyah::vec<4, std::double_t> expected = {-1.0, -4.0, -6.0, 1.0};
		const lyah::vec<4, std::double_t> a = {1.0, 4.0, 6.0, -1.0};

		const lyah::vec<4, std::double_t> result = -a;

		test::assert(test::eq(result, expected));
	}

	void testAddition() {
		const lyah::vec<4, std::double_t> expected = {6.0, 7.0, 8.0, 3.0};
		const lyah::vec<4, std::double_t> a = {1.0, 4.0, 6.0, -1.0};
		const lyah::vec<4, std::double_t> b = {5.0, 3.0, 2.0, 4.0};

		const lyah::vec<4, std::double_t> result = a + b;

		test::assert(test::eq(result, expected));
	}

	void testAdditionAssignment() {
		const lyah::vec<4, std::double_t> expected = {6.0, 7.0, 8.0, 3.0};
		const lyah::vec<4, std::double_t> a = {5.0, 3.0, 2.0, 4.0};
		lyah::vec<4, std::double_t> result = {1.0, 4.0, 6.0, -1.0};

		result += a;

		test::assert(test::eq(result, expected));
	}

	void testSubtraction() {
		const lyah::vec<4, std::double_t> expected = {-4.0, 1.0, 4.0, -8.0};
		const lyah::vec<4, std::double_t> a = {1.0, 4.0, 6.0, -1.0};
		const lyah::vec<4, std::double_t> b = {5.0, 3.0, 2.0, 7.0};

		const lyah::vec<4, std::double_t> result = a - b;

		test::assert(test::eq(result, expected));
	}

	void testSubtractionAssignment() {
		const lyah::vec<4, std::double_t> expected = {-4.0, 1.0, 4.0, -8.0};
		const lyah::vec<4, std::double_t> a = {5.0, 3.0, 2.0, 7.0};
		lyah::vec<4, std::double_t> result = {1.0, 4.0, 6.0, -1.0};

		result -= a;

		test::assert(test::eq(result, expected));
	}

	void testVectorScalarMultiplication() {
		const lyah::vec<4, std::double_t> expected = {3.0, 12.0, 18.0, -3.0};
		const lyah::vec<4, std::double_t> a = {1.0, 4.0, 6.0, -1.0};
		const std::double_t b = 3.0;

		const lyah::vec<4, std::double_t> result = a * b;

		test::assert(test::eq(result, expected));
	}

	void testScalarVectorMultiplication() {
		const lyah::vec<4, std::double_t> expected = {3.0, 12.0, 18.0, -3.0};
		const lyah::vec<4, std::double_t> a = {1.0, 4.0, 6.0, -1.0};
		const std::double_t b = 3.0;

		const lyah::vec<4, std::double_t> result = b * a;

		test::assert(test::eq(result, expected));
	}

	void testVectorScalarMultiplicationAssignment() {
		const lyah::vec<4, std::double_t> expected = {3.0, 12.0, 18.0, -3.0};
		const std::double_t a = 3.0;
		lyah::vec<4, std::double_t> result = {1.0, 4.0, 6.0, -1.0};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testVectorVectorMultiplication() {
		const lyah::vec<4, std::double_t> expected = {5.0, 12.0, 12.0, -7.0};
		const lyah::vec<4, std::double_t> a = {1.0, 4.0, 6.0, -1.0};
		const lyah::vec<4, std::double_t> b = {5.0, 3.0, 2.0, 7.0};

		const lyah::vec<4, std::double_t> result = a * b;

		test::assert(test::eq(result, expected));
	}

	void testVectorVectorMultiplicationAssignment() {
		const lyah::vec<4, std::double_t> expected = {5.0, 12.0, 12.0, -7.0};
		const lyah::vec<4, std::double_t> a = {5.0, 3.0, 2.0, 7.0};
		lyah::vec<4, std::double_t> result = {1.0, 4.0, 6.0, -1.0};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testVectorMatrixMultiplication() {
		const lyah::vec<4, std::double_t> expected = {19.0, -36.0, 19.0, 44.0};
		const lyah::vec<4, std::double_t> a = {1.0, 4.0, 6.0, -1.0};
		const lyah::mat<4, 4, std::double_t> b = {
			1.0,  4.0,  6.0, -1.0,
			5.0,  3.0,  2.0,  7.0,
			0.0, -8.0,  0.5,  3.0,
			2.0,  4.0, -2.0,  1.0,
		};

		const lyah::vec<4, std::double_t> result = a * b;

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

	void testVectorScalarDivision() {
		const lyah::vec<4, std::double_t> expected = {0.333, 1.333, 2.0, -0.333};
		const lyah::vec<4, std::double_t> a = {1.0, 4.0, 6.0, -1.0};
		const std::double_t b = 3.0;

		const lyah::vec<4, std::double_t> result = a / b;

		test::assert(test::eq(result, expected, 0.001));
	}

	void testScalarVectorDivision() {
		const lyah::vec<4, std::double_t> expected = {lyah::infinity<std::double_t>(), 0.75, 0.5, -3.0};
		const lyah::vec<4, std::double_t> a = {0.0, 4.0, 6.0, -1.0};
		const std::double_t b = 3.0;

		const lyah::vec<4, std::double_t> result = b / a;

		test::assert(test::eq(result, expected, 0.001));
	}

	void testVectorScalarDivisionAssignment() {
		const lyah::vec<4, std::double_t> expected = {0.333, 1.333, 2.0, -0.333};
		const std::double_t a = 3.0;
		lyah::vec<4, std::double_t> result = {1.0, 4.0, 6.0, -1.0};

		result /= a;

		test::assert(test::eq(result, expected, 0.001));
	}

	void testVectorVectorDivision() {
		const lyah::vec<4, std::double_t> expected = {lyah::infinity<std::double_t>(), 1.333, 3.0, -0.143};
		const lyah::vec<4, std::double_t> a = {1.0, 4.0, 6.0, -1.0};
		const lyah::vec<4, std::double_t> b = {0.0, 3.0, 2.0, 7.0};

		const lyah::vec<4, std::double_t> result = a / b;

		test::assert(test::eq(result, expected, 0.001));
	}

	void testVectorVectorDivisionAssignment() {
		const lyah::vec<4, std::double_t> expected = {lyah::infinity<std::double_t>(), 1.333, 3.0, -0.143};
		const lyah::vec<4, std::double_t> a = {0.0, 3.0, 2.0, 7.0};
		lyah::vec<4, std::double_t> result = {1.0, 4.0, 6.0, -1.0};

		result /= a;

		test::assert(test::eq(result, expected, 0.001));
	}

	/* void testFloor() {
		const lyah::vec<4, std::double_t> expected = {1.0, 4.0, 6.0, -1.0};
		const lyah::vec<4, std::double_t> a = {1.999, 4.0, 6.111, -0.5};

		const lyah::vec<4, std::double_t> result = lyah::floor(a);

		test::assert(test::eq(result, expected));
	} */

	/* void testCeil() {
		const lyah::vec<4, std::double_t> expected = {1.0, 4.0, 6.0, -1.0};
		const lyah::vec<4, std::double_t> a = {0.999, 4.0, 5.111, -1.5};

		const lyah::vec<4, std::double_t> result = lyah::ceil(a);

		test::assert(test::eq(result, expected));
	} */

	/* void testRound() {
		const lyah::vec<4, std::double_t> expected = {1.0, 4.0, 7.0, 0.0};
		const lyah::vec<4, std::double_t> a = {1.3279, 4.007, 6.897, -0.5};

		const lyah::vec<4, std::double_t> result = lyah::round(a);

		test::assert(test::eq(result, expected));
	} */

	void testVerticalMax() {
		const lyah::vec<4, std::double_t> expected = {5.0, 4.0, 6.0, 7.0};
		const lyah::vec<4, std::double_t> a = {5.0, 3.0, 2.0, 7.0};
		const lyah::vec<4, std::double_t> b = {1.0, 4.0, 6.0, 2.0};

		const lyah::vec<4, std::double_t> result = lyah::max(a, b);

		test::assert(test::eq(result, expected));
	}

	void testVerticalMin() {
		const lyah::vec<4, std::double_t> expected = {1.0, 3.0, 2.0, 2.0};
		const lyah::vec<4, std::double_t> a = {5.0, 3.0, 2.0, 7.0};
		const lyah::vec<4, std::double_t> b = {1.0, 4.0, 6.0, 2.0};

		const lyah::vec<4, std::double_t> result = lyah::min(a, b);

		test::assert(test::eq(result, expected));
	}

	void testLerpScalarInterpolator() {
		const lyah::vec<4, std::double_t> expected = {2.2, 3.7, 4.8, 1.4};
		const lyah::vec<4, std::double_t> a = {1.0, 4.0, 6.0, -1.0};
		const lyah::vec<4, std::double_t> b = {5.0, 3.0, 2.0, 7.0};
		const std::double_t t = 0.3;

		const lyah::vec<4, std::double_t> result = lyah::lerp(a, b, t);

		test::assert(test::eq(result, expected, 0.001));
	}

	void testLerpVectorInterpolator() {
		const lyah::vec<4, std::double_t> expected = {2.2, 3.7, 4.8, 1.4};
		const lyah::vec<4, std::double_t> a = {1.0, 4.0, 6.0, -1.0};
		const lyah::vec<4, std::double_t> b = {5.0, 3.0, 2.0, 7.0};
		const lyah::vec<4, std::double_t> t(0.3);

		const lyah::vec<4, std::double_t> result = lyah::lerp(a, b, t);

		test::assert(test::eq(result, expected, 0.001));
	}

	void testSum() {
		const std::double_t expected = 13.0;
		const lyah::vec<4, std::double_t> a = {1.0, 4.0, 6.0, 2.0};

		const std::double_t result = lyah::sum(a);

		test::assert(test::eq(result, expected));
	}

	void testPow() {
		const lyah::vec<4, std::double_t> expected = {1.0, 64.0, 36.0, -1.0};
		const lyah::vec<4, std::double_t> a = {1.0, 4.0, 6.0, -1.0};
		const lyah::vec<4, std::double_t> b = {5.0, 3.0, 2.0, 7.0};

		const lyah::vec<4, std::double_t> result = lyah::pow(a, b);

		test::assert(test::eq(result, expected));
	}

	void testRcp() {
		const lyah::vec<4, std::double_t> expected = {lyah::infinity<std::double_t>(), 0.25, 0.167, -1.0};
		const lyah::vec<4, std::double_t> a = {0.0, 4.0, 6.0, -1.0};

		const lyah::vec<4, std::double_t> result = lyah::rcp(a);

		test::assert(test::eq(result, expected, 0.001));
	}

	void testSqrt() {
		const lyah::vec<4, std::double_t> expected = {1.0, 2.0, 2.449, 0.707};
		const lyah::vec<4, std::double_t> a = {1.0, 4.0, 6.0, 0.5};

		const lyah::vec<4, std::double_t> result = lyah::sqrt(a);

		test::assert(test::eq(result, expected, 0.001));
	}

	void testRsqrt() {
		const lyah::vec<4, std::double_t> expected = {1.0, 0.5, 0.408, 1.414};
		const lyah::vec<4, std::double_t> a = {1.0, 4.0, 6.0, 0.5};

		const lyah::vec<4, std::double_t> result = lyah::rsqrt(a);

		test::assert(test::eq(result, expected, 0.001));
	}

	void testDotProduct() {
		const std::double_t expected = 22.0;
		const lyah::vec<4, std::double_t> a = {1.0, 4.0, 6.0, -1.0};
		const lyah::vec<4, std::double_t> b = {5.0, 3.0, 2.0, 7.0};

		const std::double_t result = lyah::dot(a, b);

		test::assert(test::eq(result, expected));
	}

	void testLength() {
		const std::double_t expected = 7.348;
		const lyah::vec<4, std::double_t> a = {1.0, 4.0, 6.0, -1.0};

		const std::double_t result = lyah::length(a);

		test::assert(test::eq(result, expected, 0.001));
	}

	void testDistance() {
		const std::double_t expected = 9.849;
		const lyah::vec<4, std::double_t> a = {1.0, 4.0, 6.0, -1.0};
		const lyah::vec<4, std::double_t> b = {5.0, 3.0, 2.0, 7.0};

		const std::double_t result = lyah::distance(a, b);

		test::assert(test::eq(result, expected, 0.001));
	}

	void testNormalization() {
		const lyah::vec<4, std::double_t> expected = {0.136, 0.544, 0.816, -0.136};
		const lyah::vec<4, std::double_t> a = {1.0, 4.0, 6.0, -1.0};

		const lyah::vec<4, std::double_t> result = lyah::normalized(a);

		test::assert(test::eq(result, expected, 0.001));
	}

	void testDegrees() {
		const lyah::vec<4, std::double_t> expected = {180.0, -45.0, 0.0, 360.0};
		const lyah::vec<4, std::double_t> a = {lyah::pi<std::double_t>(), -lyah::pi<std::double_t>() * 0.25, 0.0, 2.0 * lyah::pi<std::double_t>()};

		const lyah::vec<4, std::double_t> result = lyah::degrees(a);

		test::assert(test::eq(result, expected, 0.001));
	}

	void testRadians() {
		const lyah::vec<4, std::double_t> expected = {lyah::pi<std::double_t>(), -lyah::pi<std::double_t>() * 0.25, 0.0, 2.0 * lyah::pi<std::double_t>()};
		const lyah::vec<4, std::double_t> a = {180.0, -45.0, 0.0, 360.0};

		const lyah::vec<4, std::double_t> result = lyah::radians(a);

		test::assert(test::eq(result, expected, 0.001));
	}

	void testSin() {
		const lyah::vec<4, std::double_t> expected = {0.841, 0.479, 0.894, 0.0};
		const lyah::vec<4, std::double_t> a = {1.0, 0.5, 90.0, 0.0};

		const lyah::vec<4, std::double_t> result = lyah::sin(a);

		test::assert(test::eq(result, expected, 0.001));
	}

	void testCos() {
		const lyah::vec<4, std::double_t> expected = {0.540, 0.878, -0.448, 1.0};
		const lyah::vec<4, std::double_t> a = {1.0, 0.5, 90.0, 0.0};

		const lyah::vec<4, std::double_t> result = lyah::cos(a);

		test::assert(test::eq(result, expected, 0.001));
	}

	void testTan() {
		const lyah::vec<4, std::double_t> expected = {1.557, 0.546, -1.995, 0.0};
		const lyah::vec<4, std::double_t> a = {1.0, 0.5, 90.0, 0.0};

		const lyah::vec<4, std::double_t> result = lyah::tan(a);

		test::assert(test::eq(result, expected, 0.001));
	}

	void runAll() {
		test::printTestCategory("lyah::vec<4, std::double_t> - 4-component double floating-point vector");

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
		test::runTest(&testVectorMatrixMultiplication, "Vector-matrix multiplication (*)");
		test::runTest(&testVectorMatrixMultiplicationAssignment, "Vector-matrix multiplication assignment (*=)");

		test::runTest(&testVectorScalarDivision, "Vector-scalar division (/)");
		test::runTest(&testScalarVectorDivision, "Scalar-vector division (/)");
		test::runTest(&testVectorScalarDivisionAssignment, "Vector-scalar division assignment (/=)");
		test::runTest(&testVectorVectorDivision, "Vector-vector division (/)");
		test::runTest(&testVectorVectorDivisionAssignment, "Vector-vector division assignment (/=)");

		// test::runTest(&testFloor, "Floor");
		// test::runTest(&testCeil, "Ceil");
		// test::runTest(&testRound, "Round");
		test::runTest(&testVerticalMax, "Vertical max");
		test::runTest(&testVerticalMin, "Vertical min");
		test::runTest(&testLerpScalarInterpolator, "Linear interpolation (scalar interpolator)");
		test::runTest(&testLerpVectorInterpolator, "Linear interpolation (vector interpolator)");
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
		test::runTest(&testTan, "Tan");
	}
}