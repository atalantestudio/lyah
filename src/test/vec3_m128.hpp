#pragma once

#include "pch.hpp"

namespace vec3_m128 {
	void testDefaultConstructor() {
		const std::float_t expected[3] = {0.0f, 0.0f, 0.0f};

		const lyah::vec<3, std::float_t> result;

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
		test::assert(test::eq(result[2], expected[2]));
	}

	void testComponentConstructor() {
		const std::float_t expected[3] = {1.0f, 4.0f, 6.0f};

		const lyah::vec<3, std::float_t> result = {1.0f, 4.0f, 6.0f};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
		test::assert(test::eq(result[2], expected[2]));
	}

	void testRegisterConstructor() {
		const lyah::vec<3, std::float_t> expected = {1.0f, 4.0f, 6.0f};
		const __m128 m = _mm_set_ps(0.0f, 6.0f, 4.0f, 1.0f);

		const lyah::vec<3, std::float_t> result(m);

		test::assert(test::eq(result, expected));
	}

	void testEquality() {
		const bool expected[2] = {true, false};
		const lyah::vec<3, std::float_t> a = {1.0f, 4.0f, 6.0f};
		const lyah::vec<3, std::float_t> b = {1.0f, 0.0f, 6.0f};

		const bool result[2] = {a == a, a == b};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
	}

	void testInequality() {
		const bool expected[2] = {false, true};
		const lyah::vec<3, std::float_t> a = {1.0f, 4.0f, 6.0f};
		const lyah::vec<3, std::float_t> b = {1.0f, 0.0f, 6.0f};

		const bool result[2] = {a != a, a != b};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
	}

	void testUnaryPlus() {
		const lyah::vec<3, std::float_t> expected = {1.0f, 4.0f, 6.0f};
		const lyah::vec<3, std::float_t> a = {1.0f, 4.0f, 6.0f};

		const lyah::vec<3, std::float_t> result = +a;

		test::assert(test::eq(result, expected));
	}

	void testUnaryMinus() {
		const lyah::vec<3, std::float_t> expected = {-1.0f, -4.0f, -6.0f};
		const lyah::vec<3, std::float_t> a = {1.0f, 4.0f, 6.0f};

		const lyah::vec<3, std::float_t> result = -a;

		test::assert(test::eq(result, expected));
	}

	void testAddition() {
		const lyah::vec<3, std::float_t> expected = {6.0f, 7.0f, 8.0f};
		const lyah::vec<3, std::float_t> a = {1.0f, 4.0f, 6.0f};
		const lyah::vec<3, std::float_t> b = {5.0f, 3.0f, 2.0f};

		const lyah::vec<3, std::float_t> result = a + b;

		test::assert(test::eq(result, expected));
	}

	void testAdditionAssignment() {
		const lyah::vec<3, std::float_t> expected = {6.0f, 7.0f, 8.0f};
		const lyah::vec<3, std::float_t> a = {5.0f, 3.0f, 2.0f};
		lyah::vec<3, std::float_t> result = {1.0f, 4.0f, 6.0f};

		result += a;

		test::assert(test::eq(result, expected));
	}

	void testSubtraction() {
		const lyah::vec<3, std::float_t> expected = {-4.0f, 1.0f, 4.0f};
		const lyah::vec<3, std::float_t> a = {1.0f, 4.0f, 6.0f};
		const lyah::vec<3, std::float_t> b = {5.0f, 3.0f, 2.0f};

		const lyah::vec<3, std::float_t> result = a - b;

		test::assert(test::eq(result, expected));
	}

	void testSubtractionAssignment() {
		const lyah::vec<3, std::float_t> expected = {-4.0f, 1.0f, 4.0f};
		const lyah::vec<3, std::float_t> a = {5.0f, 3.0f, 2.0f};
		lyah::vec<3, std::float_t> result = {1.0f, 4.0f, 6.0f};

		result -= a;

		test::assert(test::eq(result, expected));
	}

	void testScalarMultiplicationAB() {
		const lyah::vec<3, std::float_t> expected = {3.0f, 12.0f, 18.0f};
		const lyah::vec<3, std::float_t> a = {1.0f, 4.0f, 6.0f};
		const std::float_t b = 3.0f;

		const lyah::vec<3, std::float_t> result = a * b;

		test::assert(test::eq(result, expected));
	}

	void testScalarMultiplicationBA() {
		const lyah::vec<3, std::float_t> expected = {3.0f, 12.0f, 18.0f};
		const lyah::vec<3, std::float_t> a = {1.0f, 4.0f, 6.0f};
		const std::float_t b = 3.0f;

		const lyah::vec<3, std::float_t> result = b * a;

		test::assert(test::eq(result, expected));
	}

	void testScalarMultiplicationAssignment() {
		const lyah::vec<3, std::float_t> expected = {3.0f, 12.0f, 18.0f};
		const std::float_t a = 3.0f;
		lyah::vec<3, std::float_t> result = {1.0f, 4.0f, 6.0f};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testMultiplication() {
		const lyah::vec<3, std::float_t> expected = {5.0f, 12.0f, 12.0f};
		const lyah::vec<3, std::float_t> a = {1.0f, 4.0f, 6.0f};
		const lyah::vec<3, std::float_t> b = {5.0f, 3.0f, 2.0f};

		const lyah::vec<3, std::float_t> result = a * b;

		test::assert(test::eq(result, expected));
	}

	void testMultiplicationAssignment() {
		const lyah::vec<3, std::float_t> expected = {5.0f, 12.0f, 12.0f};
		const lyah::vec<3, std::float_t> a = {5.0f, 3.0f, 2.0f};
		lyah::vec<3, std::float_t> result = {1.0f, 4.0f, 6.0f};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testScalarDivisionAB() {
		const lyah::vec<3, std::float_t> expected = {0.333f, 1.333f, 2.0f};
		const lyah::vec<3, std::float_t> a = {1.0f, 4.0f, 6.0f};
		const std::float_t b = 3.0f;

		const lyah::vec<3, std::float_t> result = a / b;

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testScalarDivisionBA() {
		const lyah::vec<3, std::float_t> expected = {lyah::infinity<std::float_t>(), 0.75f, 0.5f};
		const lyah::vec<3, std::float_t> a = {0.0f, 4.0f, 6.0f};
		const std::float_t b = 3.0f;

		const lyah::vec<3, std::float_t> result = b / a;

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testScalarDivisionAssignment() {
		const lyah::vec<3, std::float_t> expected = {0.333f, 1.333f, 2.0f};
		const std::float_t a = 3.0f;
		lyah::vec<3, std::float_t> result = {1.0f, 4.0f, 6.0f};

		result /= a;

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testDivision() {
		const lyah::vec<3, std::float_t> expected = {lyah::infinity<std::float_t>(), 1.333f, 3.0f};
		const lyah::vec<3, std::float_t> a = {1.0f, 4.0f, 6.0f};
		const lyah::vec<3, std::float_t> b = {0.0f, 3.0f, 2.0f};

		const lyah::vec<3, std::float_t> result = a / b;

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testDivisionAssignment() {
		const lyah::vec<3, std::float_t> expected = {lyah::infinity<std::float_t>(), 1.333f, 3.0f};
		const lyah::vec<3, std::float_t> a = {0.0f, 3.0f, 2.0f};
		lyah::vec<3, std::float_t> result = {1.0f, 4.0f, 6.0f};

		result /= a;

		test::assert(test::eq(result, expected, 0.001f));
	}

	void runAll() {
		test::printTestCategory("lyah::vec<3, std::float_t> - 3-component single floating-point vector");

		test::runTest(&testDefaultConstructor, "Default constructor");
		test::runTest(&testComponentConstructor, "Component constructor");
		test::runTest(&testRegisterConstructor, "Register constructor");

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
	}
}