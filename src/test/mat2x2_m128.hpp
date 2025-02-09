#pragma once

#include "pch.hpp"

namespace mat2x2_m128 {
	void testDefaultConstructor() {
		const std::float_t expected[2 * 2] = {
			0.0f, 0.0f,
			0.0f, 0.0f,
		};

		const lyah::mat<2, 2, std::float_t> result;

		for (std::size_t i = 0; i < 2; i++) {
			for (std::size_t j = 0; j < 2; j++) {
				test::assert(test::eq(result[i][j], expected[i * 2 + j]));
			}
		}
	}

	void testComponentConstructor() {
		const std::float_t expected[2 * 2] = {
			1.0f, 4.0f,
			5.0f, 3.0f,
		};

		const lyah::mat<2, 2, std::float_t> result = {
			1.0f, 4.0f,
			5.0f, 3.0f,
		};

		for (std::size_t i = 0; i < 2; i++) {
			for (std::size_t j = 0; j < 2; j++) {
				test::assert(test::eq(result[i][j], expected[i * 2 + j]));
			}
		}
	}

	void testRowConstructor() {
		const std::float_t expected[2 * 2] = {
			1.0f, 4.0f,
			5.0f, 3.0f,
		};

		const lyah::mat<2, 2, std::float_t> result = {
			{1.0f, 4.0f},
			{5.0f, 3.0f},
		};

		for (std::size_t i = 0; i < 2; i++) {
			for (std::size_t j = 0; j < 2; j++) {
				test::assert(test::eq(result[i][j], expected[i * 2 + j]));
			}
		}
	}

	void testConvertingConstructor() {
		const lyah::mat<2, 2, std::float_t> expected = {
			1.0f, 4.0f,
			5.0f, 3.0f,
		};
		const lyah::mat<2, 2, std::double_t> a = {
			1.0, 4.0,
			5.0, 3.0,
		};

		const lyah::mat<2, 2, std::float_t> result(a);

		test::assert(test::eq(result, expected));
	}

	void testIdentity() {
		const lyah::mat<2, 2, std::float_t> expected = {
			1.0f, 0.0f,
			0.0f, 1.0f,
		};

		const lyah::mat<2, 2, std::float_t> result = lyah::mat<2, 2, std::float_t>::identity();

		test::assert(test::eq(result, expected));
	}

	void testEquality() {
		const bool expected[2] = {true, false};
		const lyah::mat<2, 2, std::float_t> a = {
			1.0f, 4.0f,
			5.0f, 3.0f,
		};
		const lyah::mat<2, 2, std::float_t> b = {
			1.0f, 4.0f,
			5.0f, 0.0f,
		};

		const bool result[2] = {a == a, a == b};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
	}

	void testInequality() {
		const bool expected[2] = {false, true};
		const lyah::mat<2, 2, std::float_t> a = {
			1.0f, 4.0f,
			5.0f, 3.0f,
		};
		const lyah::mat<2, 2, std::float_t> b = {
			1.0f, 4.0f,
			5.0f, 0.0f,
		};

		const bool result[2] = {a != a, a != b};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
	}

	void testUnaryPlus() {
		const lyah::mat<2, 2, std::float_t> expected = {
			1.0f, 4.0f,
			5.0f, 3.0f,
		};
		const lyah::mat<2, 2, std::float_t> a = {
			1.0f, 4.0f,
			5.0f, 3.0f,
		};

		const lyah::mat<2, 2, std::float_t> result = +a;

		test::assert(test::eq(result, expected));
	}

	void testUnaryMinus() {
		const lyah::mat<2, 2, std::float_t> expected = {
			-1.0f, -4.0f,
			-5.0f, -3.0f,
		};
		const lyah::mat<2, 2, std::float_t> a = {
			1.0f, 4.0f,
			5.0f, 3.0f,
		};

		const lyah::mat<2, 2, std::float_t> result = -a;

		test::assert(test::eq(result, expected));
	}

	void testAddition() {
		const lyah::mat<2, 2, std::float_t> expected = {
			-2.0f, 6.5f,
			 9.0f, 12.0f,
		};
		const lyah::mat<2, 2, std::float_t> a = {
			1.0f, 4.0f,
			5.0f, 3.0f,
		};
		const lyah::mat<2, 2, std::float_t> b = {
			-3.0f, 2.5f,
			 4.0f, 9.0f,
		};

		const lyah::mat<2, 2, std::float_t> result = a + b;

		test::assert(test::eq(result, expected));
	}

	void testAdditionAssignment() {
		const lyah::mat<2, 2, std::float_t> expected = {
			-2.0f, 6.5f,
			 9.0f, 12.0f,
		};
		const lyah::mat<2, 2, std::float_t> a = {
			-3.0f, 2.5f,
			 4.0f, 9.0f,
		};
		lyah::mat<2, 2, std::float_t> result = {
			1.0f, 4.0f,
			5.0f, 3.0f,
		};

		result += a;

		test::assert(test::eq(result, expected));
	}

	void testSubtraction() {
		const lyah::mat<2, 2, std::float_t> expected = {
			 4.0f,  1.5f,
			 1.0f, -6.0f,
		};
		const lyah::mat<2, 2, std::float_t> a = {
			1.0f, 4.0f,
			5.0f, 3.0f,
		};
		const lyah::mat<2, 2, std::float_t> b = {
			-3.0f, 2.5f,
			 4.0f, 9.0f,
		};

		const lyah::mat<2, 2, std::float_t> result = a - b;

		test::assert(test::eq(result, expected));
	}

	void testSubtractionAssignment() {
		const lyah::mat<2, 2, std::float_t> expected = {
			 4.0f,  1.5f,
			 1.0f, -6.0f,
		};
		const lyah::mat<2, 2, std::float_t> a = {
			-3.0f, 2.5f,
			 4.0f, 9.0f,
		};
		lyah::mat<2, 2, std::float_t> result = {
			1.0f, 4.0f,
			5.0f, 3.0f,
		};

		result -= a;

		test::assert(test::eq(result, expected));
	}

	void testScalarMultiplicationAB() {
		const lyah::mat<2, 2, std::float_t> expected = {
			3.0f,  12.0f,
			15.0f, 9.0f,
		};
		const lyah::mat<2, 2, std::float_t> a = {
			1.0f, 4.0f,
			5.0f, 3.0f,
		};
		const std::float_t b = 3.0f;

		const lyah::mat<2, 2, std::float_t> result = a * b;

		test::assert(test::eq(result, expected));
	}

	void testScalarMultiplicationBA() {
		const lyah::mat<2, 2, std::float_t> expected = {
			3.0f,  12.0f,
			15.0f, 9.0f,
		};
		const lyah::mat<2, 2, std::float_t> a = {
			1.0f, 4.0f,
			5.0f, 3.0f,
		};
		const std::float_t b = 3.0f;

		const lyah::mat<2, 2, std::float_t> result = b * a;

		test::assert(test::eq(result, expected));
	}

	void testScalarMultiplicationAssignment() {
		const lyah::mat<2, 2, std::float_t> expected = {
			3.0f,  12.0f,
			15.0f, 9.0f,
		};
		const std::float_t a = 3.0f;
		lyah::mat<2, 2, std::float_t> result = {
			1.0f, 4.0f,
			5.0f, 3.0f,
		};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testMatrixMatrixMultiplication() {
		const lyah::mat<2, 2, std::float_t> expected = {
			 13.0f, 38.5f,
			-3.0f,  39.5f,
		};
		const lyah::mat<2, 2, std::float_t> a = {
			1.0f, 4.0f,
			5.0f, 3.0f,
		};
		const lyah::mat<2, 2, std::float_t> b = {
			-3.0f, 2.5f,
			 4.0f, 9.0f,
		};

		const lyah::mat<2, 2, std::float_t> result = a * b;

		test::assert(test::eq(result, expected));
	}

	void testMatrixMatrixMultiplicationAssignment() {
		const lyah::mat<2, 2, std::float_t> expected = {
			 13.0f, 38.5f,
			-3.0f,  39.5f,
		};
		const lyah::mat<2, 2, std::float_t> a = {
			-3.0f, 2.5f,
			 4.0f, 9.0f,
		};
		lyah::mat<2, 2, std::float_t> result = {
			1.0f, 4.0f,
			5.0f, 3.0f,
		};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testDeterminant() {
		const std::float_t expected = -17.0f;
		const lyah::mat<2, 2, std::float_t> a = {
			1.0f, 4.0f,
			5.0f, 3.0f,
		};

		const std::float_t result = lyah::determinant(a);

		test::assert(test::eq(result, expected));
	}

	void testInverse() {
		const lyah::mat<2, 2, std::float_t> expected = {
			-0.176f,  0.235f,
			 0.294f, -0.059f,
		};
		const lyah::mat<2, 2, std::float_t> a = {
			1.0f, 4.0f,
			5.0f, 3.0f,
		};

		const lyah::mat<2, 2, std::float_t> result = inverse(a);

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testTranspose() {
		const lyah::mat<2, 2, std::float_t> expected = {
			1.0f, 5.0f,
			4.0f, 3.0f,
		};
		const lyah::mat<2, 2, std::float_t> a = {
			1.0f, 4.0f,
			5.0f, 3.0f,
		};

		lyah::mat<2, 2, std::float_t> result = transpose(a);
		result[0] = lyah::vec<2, std::float_t>(result[0][0], result[0][1]);
		result[1] = lyah::vec<2, std::float_t>(result[1][0], result[1][1]);

		test::assert(test::eq(result, expected, 0.001f));
	}

	void runAll() {
		test::printTestCategory("lyah::mat<2, 2, std::float_t> - 2x2 single floating-point matrix");

		test::runTest(&testDefaultConstructor, "Default constructor");
		test::runTest(&testComponentConstructor, "Component constructor");
		test::runTest(&testRowConstructor, "Row constructor");
		test::runTest(&testConvertingConstructor, "Converting constructor");

		test::runTest(&testIdentity, "Identity");

		test::runTest(&testEquality, "Equality (==)");
		test::runTest(&testInequality, "Inequality (!=)");

		test::runTest(&testUnaryPlus, "Unary plus (+)");
		test::runTest(&testUnaryMinus, "Unary minus (-)");

		test::runTest(&testAddition, "Addition (+)");
		test::runTest(&testAdditionAssignment, "Addition assignment (+=)");

		test::runTest(&testSubtraction, "Subtraction (-)");
		test::runTest(&testSubtractionAssignment, "Subtraction assignment (-)");

		test::runTest(&testScalarMultiplicationAB, "Scalar multiplication (*) - AB");
		test::runTest(&testScalarMultiplicationBA, "Scalar multiplication (*) - BA");
		test::runTest(&testScalarMultiplicationAssignment, "Scalar multiplication assignment (*=)");
		test::runTest(&testMatrixMatrixMultiplication, "Matrix-matrix multiplication (*)");
		test::runTest(&testMatrixMatrixMultiplicationAssignment, "Matrix-matrix multiplication assignment (*=)");

		test::runTest(&testDeterminant, "Determinant");
		test::runTest(&testInverse, "Inverse");
		test::runTest(&testTranspose, "Transpose");
	}
}