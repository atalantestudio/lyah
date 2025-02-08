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

	void testSimdConstructor() {
		const lyah::vec<2, std::double_t> expected = {1.0, 4.0};
		const __m128d m = _mm_set_pd(4.0, 1.0);

		const lyah::vec<2, std::double_t> result(m);

		test::assert(test::eq(result, expected));
	}

	void testConvertingConstructor() {
		const lyah::vec<2, std::double_t> expected = {1.0, 4.0};
		const lyah::vec<2, std::float_t> a = {1.0f, 4.0f};

		const lyah::vec<2, std::double_t> result(a);

		test::assert(test::eq(result, expected));
	}

	void testEquality() {
		const bool expected[2] = {true, false};
		const lyah::vec<2, std::double_t> a = {1.0, 4.0};
		const lyah::vec<2, std::double_t> b = {1.0, 0.0};

		const bool result[2] = {a == a, a == b};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
	}

	void testInequality() {
		const bool expected[2] = {false, true};
		const lyah::vec<2, std::double_t> a = {1.0, 4.0};
		const lyah::vec<2, std::double_t> b = {1.0, 0.0};

		const bool result[2] = {a != a, a != b};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
	}

	void testUnaryPlus() {
		const lyah::vec<2, std::double_t> expected = {1.0, 4.0};
		const lyah::vec<2, std::double_t> a = {1.0, 4.0};

		const lyah::vec<2, std::double_t> result = +a;

		test::assert(test::eq(result, expected));
	}

	void testUnaryMinus() {
		const lyah::vec<2, std::double_t> expected = {-1.0, -4.0};
		const lyah::vec<2, std::double_t> a = {1.0, 4.0};

		const lyah::vec<2, std::double_t> result = -a;

		test::assert(test::eq(result, expected));
	}

	void testAddition() {
		const lyah::vec<2, std::double_t> expected = {6.0, 7.0};
		const lyah::vec<2, std::double_t> a = {1.0, 4.0};
		const lyah::vec<2, std::double_t> b = {5.0, 3.0};

		const lyah::vec<2, std::double_t> result = a + b;

		test::assert(test::eq(result, expected));
	}

	void testAdditionAssignment() {
		const lyah::vec<2, std::double_t> expected = {6.0, 7.0};
		const lyah::vec<2, std::double_t> a = {5.0, 3.0};
		lyah::vec<2, std::double_t> result = {1.0, 4.0};

		result += a;

		test::assert(test::eq(result, expected));
	}

	void testSubtraction() {
		const lyah::vec<2, std::double_t> expected = {-4.0, 1.0};
		const lyah::vec<2, std::double_t> a = {1.0, 4.0};
		const lyah::vec<2, std::double_t> b = {5.0, 3.0};

		const lyah::vec<2, std::double_t> result = a - b;

		test::assert(test::eq(result, expected));
	}

	void testSubtractionAssignment() {
		const lyah::vec<2, std::double_t> expected = {-4.0, 1.0};
		const lyah::vec<2, std::double_t> a = {5.0, 3.0};
		lyah::vec<2, std::double_t> result = {1.0, 4.0};

		result -= a;

		test::assert(test::eq(result, expected));
	}

	void testScalarMultiplicationAB() {
		const lyah::vec<2, std::double_t> expected = {3.0, 12.0};
		const lyah::vec<2, std::double_t> a = {1.0, 4.0};
		const std::double_t b = 3.0;

		const lyah::vec<2, std::double_t> result = a * b;

		test::assert(test::eq(result, expected));
	}

	void testScalarMultiplicationBA() {
		const lyah::vec<2, std::double_t> expected = {3.0, 12.0};
		const lyah::vec<2, std::double_t> a = {1.0, 4.0};
		const std::double_t b = 3.0;

		const lyah::vec<2, std::double_t> result = b * a;

		test::assert(test::eq(result, expected));
	}

	void testScalarMultiplicationAssignment() {
		const lyah::vec<2, std::double_t> expected = {3.0, 12.0};
		const std::double_t a = 3.0;
		lyah::vec<2, std::double_t> result = {1.0, 4.0};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testMultiplication() {
		const lyah::vec<2, std::double_t> expected = {5.0, 12.0};
		const lyah::vec<2, std::double_t> a = {1.0, 4.0};
		const lyah::vec<2, std::double_t> b = {5.0, 3.0};

		const lyah::vec<2, std::double_t> result = a * b;

		test::assert(test::eq(result, expected));
	}

	void testMultiplicationAssignment() {
		const lyah::vec<2, std::double_t> expected = {5.0, 12.0};
		const lyah::vec<2, std::double_t> a = {5.0, 3.0};
		lyah::vec<2, std::double_t> result = {1.0, 4.0};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testScalarDivisionAB() {
		const lyah::vec<2, std::double_t> expected = {0.333, 1.3330};
		const lyah::vec<2, std::double_t> a = {1.0, 4.0};
		const std::double_t b = 3.0;

		const lyah::vec<2, std::double_t> result = a / b;

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testScalarDivisionBA() {
		const lyah::vec<2, std::double_t> expected = {lyah::infinity<std::double_t>(), 0.75};
		const lyah::vec<2, std::double_t> a = {0.0, 4.0};
		const std::double_t b = 3.0;

		const lyah::vec<2, std::double_t> result = b / a;

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testScalarDivisionAssignment() {
		const lyah::vec<2, std::double_t> expected = {0.333, 1.333};
		const std::double_t a = 3.0;
		lyah::vec<2, std::double_t> result = {1.0, 4.0};

		result /= a;

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testDivision() {
		const lyah::vec<2, std::double_t> expected = {lyah::infinity<std::double_t>(), 1.333};
		const lyah::vec<2, std::double_t> a = {1.0, 4.0};
		const lyah::vec<2, std::double_t> b = {0.0, 3.0};

		const lyah::vec<2, std::double_t> result = a / b;

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testDivisionAssignment() {
		const lyah::vec<2, std::double_t> expected = {lyah::infinity<std::double_t>(), 1.333};
		const lyah::vec<2, std::double_t> a = {0.0, 3.0};
		lyah::vec<2, std::double_t> result = {1.0, 4.0};

		result /= a;

		test::assert(test::eq(result, expected, 0.001f));
	}

	/* void testFloor() {
		const lyah::vec<2, std::double_t> expected = {1.0, 4.0};
		const lyah::vec<2, std::double_t> a = {1.999, 4.0};

		const lyah::vec<2, std::double_t> result = lyah::floor(a);

		test::assert(test::eq(result, expected));
	} */

	/* void testCeil() {
		const lyah::vec<2, std::double_t> expected = {1.0, 4.0};
		const lyah::vec<2, std::double_t> a = {0.999, 4.0};

		const lyah::vec<2, std::double_t> result = lyah::ceil(a);

		test::assert(test::eq(result, expected));
	} */

	/* void testRound() {
		const lyah::vec<2, std::double_t> expected = {1.0, 4.0};
		const lyah::vec<2, std::double_t> a = {1.3279, 4.007};

		const lyah::vec<2, std::double_t> result = lyah::round(a);

		test::assert(test::eq(result, expected));
	} */

	/* void testHorizontalMax() {
		const std::double_t expected = 4.0f;
		const lyah::vec<2, std::double_t> a = {1.0, 4.0};

		const std::double_t result = lyah::max(a);

		test::assert(test::eq(result, expected));
	} */

	/* void testHorizontalMin() {
		const std::double_t expected = 1.0;
		const lyah::vec<2, std::double_t> a = {1.0, 4.0};

		const std::double_t result = lyah::min(a);

		test::assert(test::eq(result, expected));
	} */

	void testVerticalMax() {
		const lyah::vec<2, std::double_t> expected = {5.0, 4.0};
		const lyah::vec<2, std::double_t> a = {5.0, 3.0};
		const lyah::vec<2, std::double_t> b = {1.0, 4.0};

		const lyah::vec<2, std::double_t> result = lyah::max(a, b);

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
		const lyah::vec<2, std::double_t> expected = {2.2, 3.7};
		const lyah::vec<2, std::double_t> a = {1.0, 4.0};
		const lyah::vec<2, std::double_t> b = {5.0, 3.0};
		const std::double_t t = 0.3;

		const lyah::vec<2, std::double_t> result = lyah::lerp(a, b, t);

		test::assert(test::eq(result, expected, 0.001));
	}

	void testSum() {
		const std::double_t expected = 5.0;
		const lyah::vec<2, std::double_t> a = {1.0, 4.0};

		const std::double_t result = lyah::sum(a);

		test::assert(test::eq(result, expected));
	}

	void runAll() {
		test::printTestCategory("lyah::vec<2, std::double_t> - 2-component double floating-point vector");

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
		// test::runTest(&testHorizontalMax, "Horizontal max");
		// test::runTest(&testHorizontalMin, "Horizontal min");
		test::runTest(&testVerticalMax, "Vertical max");
		test::runTest(&testVerticalMin, "Vertical min");
		test::runTest(&testLerp, "Linear interpolation");
		test::runTest(&testSum, "Sum");
	}
}