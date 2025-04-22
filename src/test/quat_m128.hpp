#pragma once

#include "pch.hpp"

namespace quat_m128 {
	void testDefaultConstructor() {
		const std::float_t expected[4] = {0.0f, 0.0f, 0.0f, 0.0f};

		const lyah::quat<std::float_t> result;

		for (std::size_t i = 0; i < 4; i += 1) {
			test::assert(test::eq(result[i], expected[i]));
		}
	}

	void testComponentConstructor() {
		const std::float_t expected[4] = {1.0f, 4.0f, 6.0f, -1.0f};

		const lyah::quat<std::float_t> result = {1.0f, 4.0f, 6.0f, -1.0f};

		for (std::size_t i = 0; i < 4; i += 1) {
			test::assert(test::eq(result[i], expected[i]));
		}
	}

	void testSimdConstructor() {
		const lyah::quat<std::float_t> expected = {1.0f, 4.0f, 6.0f, -1.0f};
		const __m128 m = _mm_set_ps(-1.0f, 6.0f, 4.0f, 1.0f);

		const lyah::quat<std::float_t> result(m);

		test::assert(test::eq(result, expected));
	}

	void testConvertingConstructor() {
		const lyah::quat<std::float_t> expected = {1.0f, 4.0f, 6.0f, -1.0f};
		const lyah::quat<std::double_t> a = {1.0, 4.0, 6.0, -1.0};

		const lyah::quat<std::float_t> result(a);

		test::assert(test::eq(result, expected));
	}

	void testIdentity() {
		const lyah::quat<std::float_t> expected = {1.0f, 0.0f, 0.0f, 0.0f};

		const lyah::quat<std::float_t> result = lyah::quat<std::float_t>::identity();

		test::assert(test::eq(result, expected));
	}

	void testAxisAngle() {
		const lyah::quat<std::float_t> expected = {0.924f, 0.0f, 0.383f, 0.0f};
		const lyah::vec<3, std::float_t> axis = {0.0f, 1.0f, 0.0f};
		const std::float_t angle = lyah::radians(45.0f);
		const lyah::quat<std::float_t> result = lyah::quat<std::float_t>::axisAngle(axis, angle);

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testWGetter() {
		const std::float_t expected = 1.0f;
		const lyah::quat<std::float_t> a = {1.0f, 4.0f, 6.0f, -1.0f};

		const std::float_t result = a.w();

		test::assert(test::eq(result, expected));
	}

	void testXYZGetter() {
		const lyah::vec<3, std::float_t> expected = {4.0f, 6.0f, -1.0f};
		const lyah::quat<std::float_t> a = {1.0f, 4.0f, 6.0f, -1.0f};

		lyah::vec<3, std::float_t> result = a.xyz();
		result.m.m128_f32[3] = 0.0f; // Reset upper (hidden) element

		test::assert(test::eq(result, expected));
	}

	void testEquality() {
		const bool expected[2] = {true, false};
		const lyah::quat<std::float_t> a = {1.0f, 4.0f, 6.0f, -1.0f};
		const lyah::quat<std::float_t> b = {1.0f, 0.0f, 6.0f, -1.0f};

		const bool result[2] = {a == a, a == b};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
	}

	void testInequality() {
		const bool expected[2] = {false, true};
		const lyah::quat<std::float_t> a = {1.0f, 4.0f, 6.0f, -1.0f};
		const lyah::quat<std::float_t> b = {1.0f, 0.0f, 6.0f, -1.0f};

		const bool result[2] = {a != a, a != b};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
	}

	void testUnaryPlus() {
		const lyah::quat<std::float_t> expected = {1.0f, 4.0f, 6.0f, -1.0f};
		const lyah::quat<std::float_t> a = {1.0f, 4.0f, 6.0f, -1.0f};

		const lyah::quat<std::float_t> result = +a;

		test::assert(test::eq(result, expected));
	}

	void testUnaryMinus() {
		const lyah::quat<std::float_t> expected = {-1.0f, -4.0f, -6.0f, 1.0f};
		const lyah::quat<std::float_t> a = {1.0f, 4.0f, 6.0f, -1.0f};

		const lyah::quat<std::float_t> result = -a;

		test::assert(test::eq(result, expected));
	}

	void testAddition() {
		const lyah::quat<std::float_t> expected = {6.0f, 7.0f, 8.0f, 3.0f};
		const lyah::quat<std::float_t> a = {1.0f, 4.0f, 6.0f, -1.0f};
		const lyah::quat<std::float_t> b = {5.0f, 3.0f, 2.0f, 4.0f};

		const lyah::quat<std::float_t> result = a + b;

		test::assert(test::eq(result, expected));
	}

	void testAdditionAssignment() {
		const lyah::quat<std::float_t> expected = {6.0f, 7.0f, 8.0f, 3.0f};
		const lyah::quat<std::float_t> a = {5.0f, 3.0f, 2.0f, 4.0f};
		lyah::quat<std::float_t> result = {1.0f, 4.0f, 6.0f, -1.0f};

		result += a;

		test::assert(test::eq(result, expected));
	}

	void testSubtraction() {
		const lyah::quat<std::float_t> expected = {-4.0f, 1.0f, 4.0f, -8.0f};
		const lyah::quat<std::float_t> a = {1.0f, 4.0f, 6.0f, -1.0f};
		const lyah::quat<std::float_t> b = {5.0f, 3.0f, 2.0f, 7.0f};

		const lyah::quat<std::float_t> result = a - b;

		test::assert(test::eq(result, expected));
	}

	void testSubtractionAssignment() {
		const lyah::quat<std::float_t> expected = {-4.0f, 1.0f, 4.0f, -8.0f};
		const lyah::quat<std::float_t> a = {5.0f, 3.0f, 2.0f, 7.0f};
		lyah::quat<std::float_t> result = {1.0f, 4.0f, 6.0f, -1.0f};

		result -= a;

		test::assert(test::eq(result, expected));
	}

	void testQuaternionScalarMultiplication() {
		const lyah::quat<std::float_t> expected = {3.0f, 12.0f, 18.0f, -3.0f};
		const lyah::quat<std::float_t> a = {1.0f, 4.0f, 6.0f, -1.0f};
		const std::float_t b = 3.0f;

		const lyah::quat<std::float_t> result = a * b;

		test::assert(test::eq(result, expected));
	}

	void testScalarQuaternionMultiplication() {
		const lyah::quat<std::float_t> expected = {3.0f, 12.0f, 18.0f, -3.0f};
		const lyah::quat<std::float_t> a = {1.0f, 4.0f, 6.0f, -1.0f};
		const std::float_t b = 3.0f;

		const lyah::quat<std::float_t> result = b * a;

		test::assert(test::eq(result, expected));
	}

	void testQuaternionScalarMultiplicationAssignment() {
		const lyah::quat<std::float_t> expected = {3.0f, 12.0f, 18.0f, -3.0f};
		const std::float_t a = 3.0f;
		lyah::quat<std::float_t> result = {1.0f, 4.0f, 6.0f, -1.0f};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testQuaternionQuaternionMultiplication() {
		const lyah::quat<std::float_t> expected = {-12.0f, 67.0f, 1.0f, -8.0f};
		const lyah::quat<std::float_t> a = {1.0f, 4.0f, 6.0f, -1.0f};
		lyah::quat<std::float_t> b = {5.0f, 3.0f, 2.0f, 7.0f};

		const lyah::quat<std::float_t> result = a * b;

		test::assert(test::eq(result, expected));
	}

	void testQuaternionQuaternionMultiplicationAssignment() {
		const lyah::quat<std::float_t> expected = {-12.0f, -21.0f, 63.0f, 12.0f};
		const lyah::quat<std::float_t> a = {1.0f, 4.0f, 6.0f, -1.0f};
		lyah::quat<std::float_t> result = {5.0f, 3.0f, 2.0f, 7.0f};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testQuaternionScalarDivision() {
		const lyah::quat<std::float_t> expected = {0.333f, 1.333f, 2.0f, -0.333f};
		const lyah::quat<std::float_t> a = {1.0f, 4.0f, 6.0f, -1.0f};
		const std::float_t b = 3.0f;

		const lyah::quat<std::float_t> result = a / b;

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testScalarQuaternionDivision() {
		const lyah::quat<std::float_t> expected = {0.056f, -0.222f, -0.333f, 0.056f};
		const lyah::quat<std::float_t> a = {1.0f, 4.0f, 6.0f, -1.0f};
		const std::float_t b = 3.0f;

		const lyah::quat<std::float_t> result = b / a;

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testQuaternionScalarDivisionAssignment() {
		const lyah::quat<std::float_t> expected = {0.333f, 1.333f, 2.0f, -0.333f};
		const std::float_t a = 3.0f;
		lyah::quat<std::float_t> result = {1.0f, 4.0f, 6.0f, -1.0f};

		result /= a;

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testQuaternionQuaternionDivision() {
		const lyah::quat<std::float_t> expected = {0.253f, -0.310f, 0.678f, -0.023f};
		const lyah::quat<std::float_t> a = {1.0f, 4.0f, 6.0f, -1.0f};
		const lyah::quat<std::float_t> b = {5.0f, 3.0f, 2.0f, 7.0f};

		const lyah::quat<std::float_t> result = a / b;

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testQuaternionQuaternionDivisionAssignment() {
		const lyah::quat<std::float_t> expected = {0.253f, -0.310f, 0.678f, -0.023f};
		const lyah::quat<std::float_t> a = {5.0f, 3.0f, 2.0f, 7.0f};
		lyah::quat<std::float_t> result = {1.0f, 4.0f, 6.0f, -1.0f};

		result /= a;

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testConjugate() {
		const lyah::quat<std::float_t> expected = {1.0f, -4.0f, -6.0f, 1.0f};
		const lyah::quat<std::float_t> a = {1.0f, 4.0f, 6.0f, -1.0f};

		const lyah::quat<std::float_t> result = lyah::conjugate(a);

		test::assert(test::eq(result, expected));
	}

	void testDotProduct() {
		const std::float_t expected = 22.0f;
		const lyah::quat<std::float_t> a = {1.0f, 4.0f, 6.0f, -1.0f};
		const lyah::quat<std::float_t> b = {5.0f, 3.0f, 2.0f, 7.0f};

		const std::float_t result = lyah::dot(a, b);

		test::assert(test::eq(result, expected));
	}

	void testInverse() {
		const lyah::quat<std::float_t> expected = {0.019f, -0.074f, -0.111f, 0.019f};
		const lyah::quat<std::float_t> a = {1.0f, 4.0f, 6.0f, -1.0f};

		const lyah::quat<std::float_t> result = lyah::inverse(a);

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testLength() {
		const std::float_t expected = 7.348f;
		const lyah::quat<std::float_t> a = {1.0f, 4.0f, 6.0f, -1.0f};

		const std::float_t result = lyah::length(a);

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testNormalization() {
		const lyah::quat<std::float_t> expected = {0.136f, 0.544f, 0.816f, -0.136f};
		const lyah::quat<std::float_t> a = {1.0f, 4.0f, 6.0f, -1.0f};

		const lyah::quat<std::float_t> result = lyah::normalized(a);

		test::assert(test::eq(result, expected, 0.001f));
	}

	void runAll() {
		test::printTestCategory("lyah::quat<std::float_t> - Single floating-point quaternion");

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