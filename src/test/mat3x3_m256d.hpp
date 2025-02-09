#pragma once

#include "pch.hpp"

namespace mat3x3_m256d {
	void testDefaultConstructor() {
		const std::double_t expected[3 * 3] = {
			0.0, 0.0, 0.0,
			0.0, 0.0, 0.0,
			0.0, 0.0, 0.0,
		};

		const lyah::mat<3, 3, std::double_t> result;

		for (std::size_t i = 0; i < 3; i++) {
			for (std::size_t j = 0; j < 3; j++) {
				test::assert(test::eq(result[i][j], expected[i * 3 + j]));
			}
		}
	}

	void testComponentConstructor() {
		const std::double_t expected[3 * 3] = {
			1.0,  4.0,  6.0,
			5.0,  3.0,  2.0,
			0.0, -8.0,  0.5,
		};

		const lyah::mat<3, 3, std::double_t> result = {
			1.0,  4.0,  6.0,
			5.0,  3.0,  2.0,
			0.0, -8.0,  0.5,
		};

		for (std::size_t i = 0; i < 3; i++) {
			for (std::size_t j = 0; j < 3; j++) {
				test::assert(test::eq(result[i][j], expected[i * 3 + j]));
			}
		}
	}

	void testRowConstructor() {
		const std::double_t expected[3 * 3] = {
			1.0,  4.0,  6.0,
			5.0,  3.0,  2.0,
			0.0, -8.0,  0.5,
		};

		const lyah::mat<3, 3, std::double_t> result = {
			{1.0,  4.0,  6.0},
			{5.0,  3.0,  2.0},
			{0.0, -8.0,  0.5},
		};

		for (std::size_t i = 0; i < 3; i++) {
			for (std::size_t j = 0; j < 3; j++) {
				test::assert(test::eq(result[i][j], expected[i * 3 + j]));
			}
		}
	}

	void testConvertingConstructor() {
		const lyah::mat<3, 3, std::double_t> expected = {
			1.0,  4.0,  6.0,
			5.0,  3.0,  2.0,
			0.0, -8.0,  0.5,
		};
		const lyah::mat<3, 3, std::float_t> a = {
			1.0f,  4.0f,  6.0f,
			5.0f,  3.0f,  2.0f,
			0.0f, -8.0f,  0.5f,
		};

		const lyah::mat<3, 3, std::double_t> result(a);

		test::assert(test::eq(result, expected));
	}

	void testIdentity() {
		const lyah::mat<3, 3, std::double_t> expected = {
			1.0, 0.0, 0.0,
			0.0, 1.0, 0.0,
			0.0, 0.0, 1.0,
		};

		const lyah::mat<3, 3, std::double_t> result = lyah::mat<3, 3, std::double_t>::identity();

		test::assert(test::eq(result, expected));
	}

	void testTranslation() {
		const lyah::mat<3, 3, std::double_t> expected = {
			1.0, 0.0, 0.0,
			0.0, 1.0, 0.0,
			1.0, 4.0, 1.0,
		};
		const lyah::vec<2, std::double_t> a = {1.0, 4.0};

		const lyah::mat<3, 3, std::double_t> result = lyah::mat<3, 3, std::double_t>::translation(a);

		test::assert(test::eq(result, expected));
	}

	void testRotation() {
		const lyah::mat<3, 3, std::double_t> expected = {
			0.070, -0.997,  0.0,
			0.997,  0.070,  0.0,
			0.0,    0.0,    1.0,
		};
		const std::double_t angle = 1.5;

		const lyah::mat<3, 3, std::double_t> result = lyah::mat<3, 3, std::double_t>::rotation(angle);

		test::assert(test::eq(result, expected, 0.001));
	}

	void testScaling() {
		const lyah::mat<3, 3, std::double_t> expected = {
			1.0, 0.0, 0.0,
			0.0, 4.0, 0.0,
			0.0, 0.0, 1.0,
		};
		const lyah::vec<2, std::double_t> scale = {1.0, 4.0};

		const lyah::mat<3, 3, std::double_t> result = lyah::mat<3, 3, std::double_t>::scaling(scale);

		test::assert(test::eq(result, expected));
	}

	void testEquality() {
		const bool expected[2] = {true, false};
		const lyah::mat<3, 3, std::double_t> a = {
			1.0,  4.0,  6.0,
			5.0,  3.0,  2.0,
			0.0, -8.0,  0.5,
		};
		const lyah::mat<3, 3, std::double_t> b = {
			1.0,  4.0,  6.0,
			5.0,  0.0,  2.0,
			0.0, -8.0,  0.5,
		};

		const bool result[2] = {a == a, a == b};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
	}

	void testInequality() {
		const bool expected[2] = {false, true};
		const lyah::mat<3, 3, std::double_t> a = {
			1.0,  4.0,  6.0,
			5.0,  3.0,  2.0,
			0.0, -8.0,  0.5,
		};
		const lyah::mat<3, 3, std::double_t> b = {
			1.0,  4.0,  6.0,
			5.0,  0.0,  2.0,
			0.0, -8.0,  0.5,
		};

		const bool result[2] = {a != a, a != b};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
	}

	void testUnaryPlus() {
		const lyah::mat<3, 3, std::double_t> expected = {
			1.0,  4.0,  6.0,
			5.0,  3.0,  2.0,
			0.0, -8.0,  0.5,
		};
		const lyah::mat<3, 3, std::double_t> a = {
			1.0,  4.0,  6.0,
			5.0,  3.0,  2.0,
			0.0, -8.0,  0.5,
		};

		const lyah::mat<3, 3, std::double_t> result = +a;

		test::assert(test::eq(result, expected));
	}

	void testUnaryMinus() {
		const lyah::mat<3, 3, std::double_t> expected = {
			-1.0, -4.0, -6.0,
			-5.0, -3.0, -2.0,
			-0.0,  8.0, -0.5,
		};
		const lyah::mat<3, 3, std::double_t> a = {
			1.0,  4.0,  6.0,
			5.0,  3.0,  2.0,
			0.0, -8.0,  0.5,
		};

		const lyah::mat<3, 3, std::double_t> result = -a;

		test::assert(test::eq(result, expected));
	}

	void testAddition() {
		const lyah::mat<3, 3, std::double_t> expected = {
			-2.0,  6.5,  7.0,
			 9.0,  12.0, 0.0,
			 2.0, -8.0,  8.0,
		};
		const lyah::mat<3, 3, std::double_t> a = {
			1.0,  4.0,  6.0,
			5.0,  3.0,  2.0,
			0.0, -8.0,  0.5,
		};
		const lyah::mat<3, 3, std::double_t> b = {
			-3.0,  2.5,  1.0,
			 4.0,  9.0, -2.0,
			 2.0,  0.0,  7.5,
		};

		const lyah::mat<3, 3, std::double_t> result = a + b;

		test::assert(test::eq(result, expected));
	}

	void testAdditionAssignment() {
		const lyah::mat<3, 3, std::double_t> expected = {
			-2.0,  6.5,  7.0,
			 9.0,  12.0, 0.0,
			 2.0, -8.0,  8.0,
		};
		const lyah::mat<3, 3, std::double_t> a = {
			-3.0,  2.5,  1.0,
			 4.0,  9.0, -2.0,
			 2.0,  0.0,  7.5,
		};
		lyah::mat<3, 3, std::double_t> result = {
			1.0,  4.0,  6.0,
			5.0,  3.0,  2.0,
			0.0, -8.0,  0.5,
		};

		result += a;

		test::assert(test::eq(result, expected));
	}

	void testSubtraction() {
		const lyah::mat<3, 3, std::double_t> expected = {
			 4.0,  1.5,  5.0,
			 1.0, -6.0,  4.0,
			-2.0, -8.0, -7.0,
		};
		const lyah::mat<3, 3, std::double_t> a = {
			1.0,  4.0,  6.0,
			5.0,  3.0,  2.0,
			0.0, -8.0,  0.5,
	};
		const lyah::mat<3, 3, std::double_t> b = {
			-3.0,  2.5,  1.0,
			 4.0,  9.0, -2.0,
			 2.0,  0.0,  7.5,
		};

		const lyah::mat<3, 3, std::double_t> result = a - b;

		test::assert(test::eq(result, expected));
	}

	void testSubtractionAssignment() {
		const lyah::mat<3, 3, std::double_t> expected = {
			 4.0,  1.5,  5.0,
			 1.0, -6.0,  4.0,
			-2.0, -8.0, -7.0,
		};
		const lyah::mat<3, 3, std::double_t> a = {
			-3.0,  2.5,  1.0,
			 4.0,  9.0, -2.0,
			 2.0,  0.0,  7.5,
		};
		lyah::mat<3, 3, std::double_t> result = {
			1.0,  4.0,  6.0,
			5.0,  3.0,  2.0,
			0.0, -8.0,  0.5,
		};

		result -= a;

		test::assert(test::eq(result, expected));
	}

	void testScalarMultiplicationAB() {
		const lyah::mat<3, 3, std::double_t> expected = {
			3.0,   12.0,  18.0,
			15.0,  9.0,   6.0,
			0.0,  -24.0,  1.5,
		};
		const lyah::mat<3, 3, std::double_t> a = {
			1.0,  4.0,  6.0,
			5.0,  3.0,  2.0,
			0.0, -8.0,  0.5,
		};
		const std::double_t b = 3.0;

		const lyah::mat<3, 3, std::double_t> result = a * b;

		test::assert(test::eq(result, expected));
	}

	void testScalarMultiplicationBA() {
		const lyah::mat<3, 3, std::double_t> expected = {
			3.0,   12.0,  18.0,
			15.0,  9.0,   6.0,
			0.0,  -24.0,  1.5,
		};
		const lyah::mat<3, 3, std::double_t> a = {
			1.0,  4.0,  6.0,
			5.0,  3.0,  2.0,
			0.0, -8.0,  0.5,
		};
		const std::double_t b = 3.0;

		const lyah::mat<3, 3, std::double_t> result = b * a;

		test::assert(test::eq(result, expected));
	}

	void testScalarMultiplicationAssignment() {
		const lyah::mat<3, 3, std::double_t> expected = {
			3.0,   12.0,  18.0,
			15.0,  9.0,   6.0,
			0.0,  -24.0,  1.5,
		};
		const std::double_t a = 3.0;
		lyah::mat<3, 3, std::double_t> result = {
			1.0,  4.0,  6.0,
			5.0,  3.0,  2.0,
			0.0, -8.0,  0.5,
		};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testMatrixMatrixMultiplication() {
		const lyah::mat<3, 3, std::double_t> expected = {
			 25.0,  38.5,   38.0,
			 1.0,   39.5,   14.0,
			-31.0, -72.0,   19.75,
		};
		const lyah::mat<3, 3, std::double_t> a = {
			1.0,  4.0,  6.0,
			5.0,  3.0,  2.0,
			0.0, -8.0,  0.5,
		};
		const lyah::mat<3, 3, std::double_t> b = {
			-3.0,  2.5,  1.0,
			 4.0,  9.0, -2.0,
			 2.0,  0.0,  7.5,
		};

		const lyah::mat<3, 3, std::double_t> result = a * b;

		test::assert(test::eq(result, expected));
	}

	void testMatrixMatrixMultiplicationAssignment() {
		const lyah::mat<3, 3, std::double_t> expected = {
			 25.0,  38.5,   38.0,
			 1.0,   39.5,   14.0,
			-31.0, -72.0,   19.75,
		};
		const lyah::mat<3, 3, std::double_t> a = {
			-3.0,  2.5,  1.0,
			 4.0,  9.0, -2.0,
			 2.0,  0.0,  7.5,
		};
		lyah::mat<3, 3, std::double_t> result = {
			1.0,  4.0,  6.0,
			5.0,  3.0,  2.0,
			0.0, -8.0,  0.5,
		};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testDeterminant() {
		const std::double_t expected = -232.5;
		const lyah::mat<3, 3, std::double_t> a = {
			1.0,  4.0,  6.0,
			5.0,  3.0,  2.0,
			0.0, -8.0,  0.5,
		};

		const std::double_t result = lyah::determinant(a);

		test::assert(test::eq(result, expected));
	}

	void testInverse() {
		const lyah::mat<3, 3, std::double_t> expected = {
			-0.075,  0.215,  0.043,
			 0.011, -0.002, -0.120,
			 0.172, -0.034,  0.073,
		};
		const lyah::mat<3, 3, std::double_t> a = {
			1.0,  4.0,  6.0,
			5.0,  3.0,  2.0,
			0.0, -8.0,  0.5,
		};

		lyah::mat<3, 3, std::double_t> result = inverse(a);
		result[0] = lyah::vec<3, std::double_t>(result[0][0], result[0][1], result[0][2]);
		result[1] = lyah::vec<3, std::double_t>(result[1][0], result[1][1], result[1][2]);
		result[2] = lyah::vec<3, std::double_t>(result[2][0], result[2][1], result[2][2]);

		test::assert(test::eq(result, expected, 0.001));
	}

	void testTranspose() {
		const lyah::mat<3, 3, std::double_t> expected = {
			1.0,  5.0,  0.0,
			4.0,  3.0, -8.0,
			6.0,  2.0,  0.5,
		};
		const lyah::mat<3, 3, std::double_t> a = {
			1.0,  4.0,  6.0,
			5.0,  3.0,  2.0,
			0.0, -8.0,  0.5,
		};

		lyah::mat<3, 3, std::double_t> result = transpose(a);
		result[0] = lyah::vec<3, std::double_t>(result[0][0], result[0][1], result[0][2]);
		result[1] = lyah::vec<3, std::double_t>(result[1][0], result[1][1], result[1][2]);
		result[2] = lyah::vec<3, std::double_t>(result[2][0], result[2][1], result[2][2]);

		test::assert(test::eq(result, expected));
	}

	void runAll() {
		test::printTestCategory("lyah::mat<3, 3, std::double_t> - 3x3 double floating-point matrix");

		test::runTest(&testDefaultConstructor, "Default constructor");
		test::runTest(&testComponentConstructor, "Component constructor");
		test::runTest(&testRowConstructor, "Row constructor");
		test::runTest(&testConvertingConstructor, "Converting constructor");

		test::runTest(&testIdentity, "Identity");
		test::runTest(&testTranslation, "Translation");
		test::runTest(&testRotation, "Rotation");
		test::runTest(&testScaling, "Scaling");

		test::runTest(&testEquality, "Equality (==)");
		test::runTest(&testInequality, "Inequality (!=)");

		test::runTest(&testUnaryMinus, "Unary plus (+)");
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