#pragma once

#include "pch.hpp"

namespace quat_m256d {
	void testDefaultConstructor() {
		const std::double_t expected[4] = {0.0, 0.0, 0.0, 0.0};

		const lyah::quat<std::double_t> result;

		for (std::size_t i = 0; i < 4; i++) {
			test::assert(test::eq(result[i], expected[i]));
		}
	}

	void testComponentConstructor() {
		const std::double_t expected[4] = {1.0, 4.0, 6.0, -1.0};

		const lyah::quat<std::double_t> result = {1.0, 4.0, 6.0, -1.0};

		for (std::size_t i = 0; i < 4; i++) {
			test::assert(test::eq(result[i], expected[i]));
		}
	}

	void testSimdConstructor() {
		const lyah::quat<std::double_t> expected = {1.0, 4.0, 6.0, -1.0};
		const __m256d m = _mm256_set_pd(-1.0, 6.0, 4.0, 1.0);

		const lyah::quat<std::double_t> result(m);

		test::assert(test::eq(result, expected));
	}

	void testConvertingConstructor() {
		const lyah::quat<std::double_t> expected = {1.0, 4.0, 6.0, -1.0};
		const lyah::quat<std::float_t> a = {1.0f, 4.0f, 6.0f, -1.0f};

		const lyah::quat<std::double_t> result(a);

		test::assert(test::eq(result, expected));
	}

	void testIdentity() {
		const lyah::quat<std::double_t> expected = {1.0, 0.0, 0.0, 0.0};

		const lyah::quat<std::double_t> result = lyah::quat<std::double_t>::identity();

		test::assert(test::eq(result, expected));
	}

	void testAxisAngle() {
		const lyah::quat<std::double_t> expected = {0.924, 0.0, 0.383, 0.0};
		const lyah::vec<3, std::double_t> axis = {0.0, 1.0, 0.0};
		const std::double_t angle = lyah::radians(45.0);
		const lyah::quat<std::double_t> result = lyah::quat<std::double_t>::axisAngle(axis, angle);

		test::assert(test::eq(result, expected, 0.001));
	}

	void testWGetter() {
		const std::double_t expected = 1.0;
		const lyah::quat<std::double_t> a = {1.0, 4.0, 6.0, -1.0};

		const std::double_t result = a.w();

		test::assert(test::eq(result, expected));
	}

	void testXYZGetter() {
		const lyah::vec<3, std::double_t> expected = {4.0, 6.0, -1.0};
		const lyah::quat<std::double_t> a = {1.0, 4.0, 6.0, -1.0};

		lyah::vec<3, std::double_t> result = a.xyz();
		result.m.m256d_f64[3] = 0.0; // Reset upper (hidden) element

		test::assert(test::eq(result, expected));
	}

	void testEquality() {
		const bool expected[2] = {true, false};
		const lyah::quat<std::double_t> a = {1.0, 4.0, 6.0, -1.0};
		const lyah::quat<std::double_t> b = {1.0, 0.0, 6.0, -1.0};

		const bool result[2] = {a == a, a == b};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
	}

	void testInequality() {
		const bool expected[2] = {false, true};
		const lyah::quat<std::double_t> a = {1.0, 4.0, 6.0, -1.0};
		const lyah::quat<std::double_t> b = {1.0, 0.0, 6.0, -1.0};

		const bool result[2] = {a != a, a != b};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
	}

	void testUnaryPlus() {
		const lyah::quat<std::double_t> expected = {1.0, 4.0, 6.0, -1.0};
		const lyah::quat<std::double_t> a = {1.0, 4.0, 6.0, -1.0};

		const lyah::quat<std::double_t> result = +a;

		test::assert(test::eq(result, expected));
	}

	void testUnaryMinus() {
		const lyah::quat<std::double_t> expected = {-1.0, -4.0, -6.0, 1.0};
		const lyah::quat<std::double_t> a = {1.0, 4.0, 6.0, -1.0};

		const lyah::quat<std::double_t> result = -a;

		test::assert(test::eq(result, expected));
	}

	void testAddition() {
		const lyah::quat<std::double_t> expected = {6.0, 7.0, 8.0, 3.0};
		const lyah::quat<std::double_t> a = {1.0, 4.0, 6.0, -1.0};
		const lyah::quat<std::double_t> b = {5.0, 3.0, 2.0, 4.0};

		const lyah::quat<std::double_t> result = a + b;

		test::assert(test::eq(result, expected));
	}

	void testAdditionAssignment() {
		const lyah::quat<std::double_t> expected = {6.0, 7.0, 8.0, 3.0};
		const lyah::quat<std::double_t> a = {5.0, 3.0, 2.0, 4.0};
		lyah::quat<std::double_t> result = {1.0, 4.0, 6.0, -1.0};

		result += a;

		test::assert(test::eq(result, expected));
	}

	void testSubtraction() {
		const lyah::quat<std::double_t> expected = {-4.0, 1.0, 4.0, -8.0};
		const lyah::quat<std::double_t> a = {1.0, 4.0, 6.0, -1.0};
		const lyah::quat<std::double_t> b = {5.0, 3.0, 2.0, 7.0};

		const lyah::quat<std::double_t> result = a - b;

		test::assert(test::eq(result, expected));
	}

	void testSubtractionAssignment() {
		const lyah::quat<std::double_t> expected = {-4.0, 1.0, 4.0, -8.0};
		const lyah::quat<std::double_t> a = {5.0, 3.0, 2.0, 7.0};
		lyah::quat<std::double_t> result = {1.0, 4.0, 6.0, -1.0};

		result -= a;

		test::assert(test::eq(result, expected));
	}

	void testQuaternionScalarMultiplication() {
		const lyah::quat<std::double_t> expected = {3.0, 12.0, 18.0, -3.0};
		const lyah::quat<std::double_t> a = {1.0, 4.0, 6.0, -1.0};
		const std::double_t b = 3.0;

		const lyah::quat<std::double_t> result = a * b;

		test::assert(test::eq(result, expected));
	}

	void testScalarQuaternionMultiplication() {
		const lyah::quat<std::double_t> expected = {3.0, 12.0, 18.0, -3.0};
		const lyah::quat<std::double_t> a = {1.0, 4.0, 6.0, -1.0};
		const std::double_t b = 3.0;

		const lyah::quat<std::double_t> result = b * a;

		test::assert(test::eq(result, expected));
	}

	void testQuaternionScalarMultiplicationAssignment() {
		const lyah::quat<std::double_t> expected = {3.0, 12.0, 18.0, -3.0};
		const std::double_t a = 3.0;
		lyah::quat<std::double_t> result = {1.0, 4.0, 6.0, -1.0};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testQuaternionQuaternionMultiplication() {
		const lyah::quat<std::double_t> expected = {-12.0, 67.0, 1.0, -8.0};
		const lyah::quat<std::double_t> a = {1.0, 4.0, 6.0, -1.0};
		lyah::quat<std::double_t> b = {5.0, 3.0, 2.0, 7.0};

		const lyah::quat<std::double_t> result = a * b;

		test::assert(test::eq(result, expected));
	}

	void testQuaternionQuaternionMultiplicationAssignment() {
		const lyah::quat<std::double_t> expected = {-12.0, -21.0, 63.0, 12.0};
		const lyah::quat<std::double_t> a = {1.0, 4.0, 6.0, -1.0};
		lyah::quat<std::double_t> result = {5.0, 3.0, 2.0, 7.0};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testQuaternionScalarDivision() {
		const lyah::quat<std::double_t> expected = {0.333, 1.333, 2.0, -0.333};
		const lyah::quat<std::double_t> a = {1.0, 4.0, 6.0, -1.0};
		const std::double_t b = 3.0;

		const lyah::quat<std::double_t> result = a / b;

		test::assert(test::eq(result, expected, 0.001));
	}

	void testScalarQuaternionDivision() {
		const lyah::quat<std::double_t> expected = {0.056, -0.222, -0.333, 0.056};
		const lyah::quat<std::double_t> a = {1.0, 4.0, 6.0, -1.0};
		const std::double_t b = 3.0;

		const lyah::quat<std::double_t> result = b / a;

		test::assert(test::eq(result, expected, 0.001));
	}

	void testQuaternionScalarDivisionAssignment() {
		const lyah::quat<std::double_t> expected = {0.333, 1.333, 2.0, -0.333};
		const std::double_t a = 3.0;
		lyah::quat<std::double_t> result = {1.0, 4.0, 6.0, -1.0};

		result /= a;

		test::assert(test::eq(result, expected, 0.001));
	}

	void testQuaternionQuaternionDivision() {
		const lyah::quat<std::double_t> expected = {0.253, -0.310, 0.678, -0.023};
		const lyah::quat<std::double_t> a = {1.0, 4.0, 6.0, -1.0};
		const lyah::quat<std::double_t> b = {5.0, 3.0, 2.0, 7.0};

		const lyah::quat<std::double_t> result = a / b;

		test::assert(test::eq(result, expected, 0.001));
	}

	void testQuaternionQuaternionDivisionAssignment() {
		const lyah::quat<std::double_t> expected = {0.253, -0.310, 0.678, -0.023};
		const lyah::quat<std::double_t> a = {5.0, 3.0, 2.0, 7.0};
		lyah::quat<std::double_t> result = {1.0, 4.0, 6.0, -1.0};

		result /= a;

		test::assert(test::eq(result, expected, 0.001));
	}

	void testConjugate() {
		const lyah::quat<std::double_t> expected = {1.0, -4.0, -6.0, 1.0};
		const lyah::quat<std::double_t> a = {1.0, 4.0, 6.0, -1.0};

		const lyah::quat<std::double_t> result = lyah::conjugate(a);

		test::assert(test::eq(result, expected));
	}

	void testDotProduct() {
		const std::double_t expected = 22.0;
		const lyah::quat<std::double_t> a = {1.0, 4.0, 6.0, -1.0};
		const lyah::quat<std::double_t> b = {5.0, 3.0, 2.0, 7.0};

		const std::double_t result = lyah::dot(a, b);

		test::assert(test::eq(result, expected));
	}

	void testInverse() {
		const lyah::quat<std::double_t> expected = {0.019, -0.074, -0.111, 0.019};
		const lyah::quat<std::double_t> a = {1.0, 4.0, 6.0, -1.0};

		const lyah::quat<std::double_t> result = lyah::inverse(a);

		test::assert(test::eq(result, expected, 0.001));
	}

	void testLength() {
		const std::double_t expected = 7.348;
		const lyah::quat<std::double_t> a = {1.0, 4.0, 6.0, -1.0};

		const std::double_t result = lyah::length(a);

		test::assert(test::eq(result, expected, 0.001));
	}

	void testNormalization() {
		const lyah::quat<std::double_t> expected = {0.136, 0.544, 0.816, -0.136};
		const lyah::quat<std::double_t> a = {1.0, 4.0, 6.0, -1.0};

		const lyah::quat<std::double_t> result = lyah::normalized(a);

		test::assert(test::eq(result, expected, 0.001));
	}

	void runAll() {
		test::printTestCategory("lyah::quat<std::double_t> - Double floating-point quaternion");

		test::runTest(&testDefaultConstructor, "Default constructor");
		test::runTest(&testComponentConstructor, "Component constructor");
		test::runTest(&testSimdConstructor, "SIMD constructor");
		test::runTest(&testConvertingConstructor, "Converting constructor");

		test::runTest(&testIdentity, "Identity");
		test::runTest(&testAxisAngle, "Axis-angle");

		test::runTest(&testWGetter, "W getter");
		test::runTest(&testXYZGetter, "XYZ getter");

		test::runTest(&testEquality, "Equality (==)");
		test::runTest(&testInequality, "Inequality (!=)");

		test::runTest(&testUnaryPlus, "Unary plus (+)");
		test::runTest(&testUnaryMinus, "Unary minus (-)");

		test::runTest(&testAddition, "Addition (+)");
		test::runTest(&testAdditionAssignment, "Addition assignment (+=)");

		test::runTest(&testSubtraction, "Subtraction (-)");
		test::runTest(&testSubtractionAssignment, "Subtraction assignment (-=)");

		test::runTest(&testQuaternionScalarMultiplication, "Quaternion-scalar multiplication (*)");
		test::runTest(&testScalarQuaternionMultiplication, "Scalar-quaternion multiplication (*)");
		test::runTest(&testQuaternionScalarMultiplicationAssignment, "Quaternion-scalar multiplication assignment (*=)");
		test::runTest(&testQuaternionQuaternionMultiplication, "Quaternion-quaternion multiplication (*)");
		test::runTest(&testQuaternionQuaternionMultiplicationAssignment, "Quaternion-quaternion multiplication assignment (*=)");

		test::runTest(&testQuaternionScalarDivision, "Quaternion-scalar division (/)");
		test::runTest(&testScalarQuaternionDivision, "Scalar-quaternion division (/)");
		test::runTest(&testQuaternionScalarDivisionAssignment, "Quaternion-scalar division assignment (/=)");
		test::runTest(&testQuaternionQuaternionDivision, "Quaternion-quaternion division (/)");
		test::runTest(&testQuaternionQuaternionDivisionAssignment, "Quaternion-quaternion division assignment (/=)");

		test::runTest(&testConjugate, "Conjugate");
		test::runTest(&testDotProduct, "Dot product");
		test::runTest(&testInverse, "Inverse");
		test::runTest(&testLength, "Length");
		test::runTest(&testNormalization, "Normalization");
	}
}