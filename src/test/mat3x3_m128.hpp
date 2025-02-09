#pragma once

#include "pch.hpp"

namespace mat3x3_m128 {
	void testDefaultConstructor() {
		const std::float_t expected[3 * 3] = {
			0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f,
		};

		const lyah::mat<3, 3, std::float_t> result;

		for (std::size_t i = 0; i < 3; i++) {
			for (std::size_t j = 0; j < 3; j++) {
				test::assert(test::eq(result[i][j], expected[i * 3 + j]));
			}
		}
	}

	void testComponentConstructor() {
		const std::float_t expected[3 * 3] = {
			1.0f,  4.0f,  6.0f,
			5.0f,  3.0f,  2.0f,
			0.0f, -8.0f,  0.5f,
		};

		const lyah::mat<3, 3, std::float_t> result = {
			1.0f,  4.0f,  6.0f,
			5.0f,  3.0f,  2.0f,
			0.0f, -8.0f,  0.5f,
		};

		for (std::size_t i = 0; i < 3; i++) {
			for (std::size_t j = 0; j < 3; j++) {
				test::assert(test::eq(result[i][j], expected[i * 3 + j]));
			}
		}
	}

	void testRowConstructor() {
		const std::float_t expected[3 * 3] = {
			1.0f,  4.0f,  6.0f,
			5.0f,  3.0f,  2.0f,
			0.0f, -8.0f,  0.5f,
		};

		const lyah::mat<3, 3, std::float_t> result = {
			{1.0f,  4.0f,  6.0f},
			{5.0f,  3.0f,  2.0f},
			{0.0f, -8.0f,  0.5f},
		};

		for (std::size_t i = 0; i < 3; i++) {
			for (std::size_t j = 0; j < 3; j++) {
				test::assert(test::eq(result[i][j], expected[i * 3 + j]));
			}
		}
	}

	void testConvertingConstructor() {
		const lyah::mat<3, 3, std::float_t> expected = {
			1.0f,  4.0f,  6.0f,
			5.0f,  3.0f,  2.0f,
			0.0f, -8.0f,  0.5f,
		};
		const lyah::mat<3, 3, std::double_t> a = {
			1.0,  4.0,  6.0,
			5.0,  3.0,  2.0,
			0.0, -8.0,  0.5,
		};

		const lyah::mat<3, 3, std::float_t> result(a);

		test::assert(test::eq(result, expected));
	}

	void testIdentity() {
		const lyah::mat<3, 3, std::float_t> expected = {
			1.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 1.0f,
		};

		const lyah::mat<3, 3, std::float_t> result = lyah::mat<3, 3, std::float_t>::identity();

		test::assert(test::eq(result, expected));
	}

	void testTranslation() {
		const lyah::mat<3, 3, std::float_t> expected = {
			1.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f,
			1.0f, 4.0f, 1.0f,
		};
		const lyah::vec<2, std::float_t> translation = {1.0f, 4.0f};

		const lyah::mat<3, 3, std::float_t> result = lyah::mat<3, 3, std::float_t>::translation(translation);

		test::assert(test::eq(result, expected));
	}

	void testRotation() {
		const lyah::mat<3, 3, std::float_t> expected = {
			0.070f, -0.997f,  0.0f,
			0.997f,  0.070f,  0.0f,
			0.0f,    0.0f,    1.0f,
		};
		const std::float_t angle = 1.5f;

		const lyah::mat<3, 3, std::float_t> result = lyah::mat<3, 3, std::float_t>::rotation(angle);

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testScaling() {
		const lyah::mat<3, 3, std::float_t> expected = {
			1.0f, 0.0f, 0.0f,
			0.0f, 4.0f, 0.0f,
			0.0f, 0.0f, 1.0f,
		};
		const lyah::vec<2, std::float_t> scale = {1.0f, 4.0f};

		const lyah::mat<3, 3, std::float_t> result = lyah::mat<3, 3, std::float_t>::scaling(scale);

		test::assert(test::eq(result, expected));
	}

	void testEquality() {
		const bool expected[2] = {true, false};
		const lyah::mat<3, 3, std::float_t> a = {
			1.0f,  4.0f,  6.0f,
			5.0f,  3.0f,  2.0f,
			0.0f, -8.0f,  0.5f,
		};
		const lyah::mat<3, 3, std::float_t> b = {
			1.0f,  4.0f,  6.0f,
			5.0f,  0.0f,  2.0f,
			0.0f, -8.0f,  0.5f,
		};

		const bool result[2] = {a == a, a == b};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
	}

	void testInequality() {
		const bool expected[2] = {false, true};
		const lyah::mat<3, 3, std::float_t> a = {
			1.0f,  4.0f,  6.0f,
			5.0f,  3.0f,  2.0f,
			0.0f, -8.0f,  0.5f,
		};
		const lyah::mat<3, 3, std::float_t> b = {
			1.0f,  4.0f,  6.0f,
			5.0f,  0.0f,  2.0f,
			0.0f, -8.0f,  0.5f,
		};

		const bool result[2] = {a != a, a != b};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
	}

	void testUnaryPlus() {
		const lyah::mat<3, 3, std::float_t> expected = {
			1.0f,  4.0f,  6.0f,
			5.0f,  3.0f,  2.0f,
			0.0f, -8.0f,  0.5f,
		};
		const lyah::mat<3, 3, std::float_t> a = {
			1.0f,  4.0f,  6.0f,
			5.0f,  3.0f,  2.0f,
			0.0f, -8.0f,  0.5f,
		};

		const lyah::mat<3, 3, std::float_t> result = +a;

		test::assert(test::eq(result, expected));
	}

	void testUnaryMinus() {
		const lyah::mat<3, 3, std::float_t> expected = {
			-1.0f, -4.0f, -6.0f,
			-5.0f, -3.0f, -2.0f,
			-0.0f,  8.0f, -0.5f,
		};
		const lyah::mat<3, 3, std::float_t> a = {
			1.0f,  4.0f,  6.0f,
			5.0f,  3.0f,  2.0f,
			0.0f, -8.0f,  0.5f,
		};

		const lyah::mat<3, 3, std::float_t> result = -a;

		test::assert(test::eq(result, expected));
	}

	void testAddition() {
		const lyah::mat<3, 3, std::float_t> expected = {
			-2.0f,  6.5f,  7.0f,
			 9.0f,  12.0f, 0.0f,
			 2.0f, -8.0f,  8.0f,
		};
		const lyah::mat<3, 3, std::float_t> a = {
			1.0f,  4.0f,  6.0f,
			5.0f,  3.0f,  2.0f,
			0.0f, -8.0f,  0.5f,
		};
		const lyah::mat<3, 3, std::float_t> b = {
			-3.0f,  2.5f,  1.0f,
			 4.0f,  9.0f, -2.0f,
			 2.0f,  0.0f,  7.5f,
		};

		const lyah::mat<3, 3, std::float_t> result = a + b;

		test::assert(test::eq(result, expected));
	}

	void testAdditionAssignment() {
		const lyah::mat<3, 3, std::float_t> expected = {
			-2.0f,  6.5f,  7.0f,
			 9.0f,  12.0f, 0.0f,
			 2.0f, -8.0f,  8.0f,
		};
		const lyah::mat<3, 3, std::float_t> a = {
			-3.0f,  2.5f,  1.0f,
			 4.0f,  9.0f, -2.0f,
			 2.0f,  0.0f,  7.5f,
		};
		lyah::mat<3, 3, std::float_t> result = {
			1.0f,  4.0f,  6.0f,
			5.0f,  3.0f,  2.0f,
			0.0f, -8.0f,  0.5f,
		};

		result += a;

		test::assert(test::eq(result, expected));
	}

	void testSubtraction() {
		const lyah::mat<3, 3, std::float_t> expected = {
			 4.0f,  1.5f,  5.0f,
			 1.0f, -6.0f,  4.0f,
			-2.0f, -8.0f, -7.0f,
		};
		const lyah::mat<3, 3, std::float_t> a = {
			1.0f,  4.0f,  6.0f,
			5.0f,  3.0f,  2.0f,
			0.0f, -8.0f,  0.5f,
		};
		const lyah::mat<3, 3, std::float_t> b = {
			-3.0f,  2.5f,  1.0f,
			 4.0f,  9.0f, -2.0f,
			 2.0f,  0.0f,  7.5f,
		};

		const lyah::mat<3, 3, std::float_t> result = a - b;

		test::assert(test::eq(result, expected));
	}

	void testSubtractionAssignment() {
		const lyah::mat<3, 3, std::float_t> expected = {
			 4.0f,  1.5f,  5.0f,
			 1.0f, -6.0f,  4.0f,
			-2.0f, -8.0f, -7.0f,
		};
		const lyah::mat<3, 3, std::float_t> a = {
			-3.0f,  2.5f,  1.0f,
			 4.0f,  9.0f, -2.0f,
			 2.0f,  0.0f,  7.5f,
		};
		lyah::mat<3, 3, std::float_t> result = {
			1.0f,  4.0f,  6.0f,
			5.0f,  3.0f,  2.0f,
			0.0f, -8.0f,  0.5f,
		};

		result -= a;

		test::assert(test::eq(result, expected));
	}

	void testScalarMultiplicationAB() {
		const lyah::mat<3, 3, std::float_t> expected = {
			3.0f,   12.0f,  18.0f,
			15.0f,  9.0f,   6.0f,
			0.0f,  -24.0f,  1.5f,
		};
		const lyah::mat<3, 3, std::float_t> a = {
			1.0f,  4.0f,  6.0f,
			5.0f,  3.0f,  2.0f,
			0.0f, -8.0f,  0.5f,
		};
		const std::float_t b = 3.0f;

		const lyah::mat<3, 3, std::float_t> result = a * b;

		test::assert(test::eq(result, expected));
	}

	void testScalarMultiplicationBA() {
		const lyah::mat<3, 3, std::float_t> expected = {
			3.0f,   12.0f,  18.0f,
			15.0f,  9.0f,   6.0f,
			0.0f,  -24.0f,  1.5f,
		};
		const lyah::mat<3, 3, std::float_t> a = {
			1.0f,  4.0f,  6.0f,
			5.0f,  3.0f,  2.0f,
			0.0f, -8.0f,  0.5f,
		};
		const std::float_t b = 3.0f;

		const lyah::mat<3, 3, std::float_t> result = b * a;

		test::assert(test::eq(result, expected));
	}

	void testScalarMultiplicationAssignment() {
		const lyah::mat<3, 3, std::float_t> expected = {
			3.0f,   12.0f,  18.0f,
			15.0f,  9.0f,   6.0f,
			0.0f,  -24.0f,  1.5f,
		};
		const std::float_t a = 3.0f;
		lyah::mat<3, 3, std::float_t> result = {
			1.0f,  4.0f,  6.0f,
			5.0f,  3.0f,  2.0f,
			0.0f, -8.0f,  0.5f,
		};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testMatrixMatrixMultiplication() {
		const lyah::mat<3, 3, std::float_t> expected = {
			 25.0f,  38.5f,   38.0f,
			 1.0f,   39.5f,   14.0f,
			-31.0f, -72.0f,   19.75f,
		};
		const lyah::mat<3, 3, std::float_t> a = {
			1.0f,  4.0f,  6.0f,
			5.0f,  3.0f,  2.0f,
			0.0f, -8.0f,  0.5f,
		};
		const lyah::mat<3, 3, std::float_t> b = {
			-3.0f,  2.5f,  1.0f,
			 4.0f,  9.0f, -2.0f,
			 2.0f,  0.0f,  7.5f,
		};

		const lyah::mat<3, 3, std::float_t> result = a * b;

		test::assert(test::eq(result, expected));
	}

	void testMatrixMatrixMultiplicationAssignment() {
		const lyah::mat<3, 3, std::float_t> expected = {
			 25.0f,  38.5f,   38.0f,
			 1.0f,   39.5f,   14.0f,
			-31.0f, -72.0f,   19.75f,
		};
		const lyah::mat<3, 3, std::float_t> a = {
			-3.0f,  2.5f,  1.0f,
			 4.0f,  9.0f, -2.0f,
			 2.0f,  0.0f,  7.5f,
		};
		lyah::mat<3, 3, std::float_t> result = {
			1.0f,  4.0f,  6.0f,
			5.0f,  3.0f,  2.0f,
			0.0f, -8.0f,  0.5f,
		};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testDeterminant() {
		const std::float_t expected = -232.5f;
		const lyah::mat<3, 3, std::float_t> a = {
			1.0f,  4.0f,  6.0f,
			5.0f,  3.0f,  2.0f,
			0.0f, -8.0f,  0.5f,
		};

		const std::float_t result = lyah::determinant(a);

		test::assert(test::eq(result, expected));
	}

	void testInverse() {
		const lyah::mat<3, 3, std::float_t> expected = {
			-0.075f,  0.215f,  0.043f,
			 0.011f, -0.002f, -0.120f,
			 0.172f, -0.034f,  0.073f,
		};
		const lyah::mat<3, 3, std::float_t> a = {
			1.0f,  4.0f,  6.0f,
			5.0f,  3.0f,  2.0f,
			0.0f, -8.0f,  0.5f,
		};

		lyah::mat<3, 3, std::float_t> result = inverse(a);
		result[0] = lyah::vec<3, std::float_t>(result[0][0], result[0][1], result[0][2]);
		result[1] = lyah::vec<3, std::float_t>(result[1][0], result[1][1], result[1][2]);
		result[2] = lyah::vec<3, std::float_t>(result[2][0], result[2][1], result[2][2]);

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testTranspose() {
		const lyah::mat<3, 3, std::float_t> expected = {
			1.0f,  5.0f,  0.0f,
			4.0f,  3.0f, -8.0f,
			6.0f,  2.0f,  0.5f,
		};
		const lyah::mat<3, 3, std::float_t> a = {
			1.0f,  4.0f,  6.0f,
			5.0f,  3.0f,  2.0f,
			0.0f, -8.0f,  0.5f,
		};

		lyah::mat<3, 3, std::float_t> result = transpose(a);
		result[0] = lyah::vec<3, std::float_t>(result[0][0], result[0][1], result[0][2]);
		result[1] = lyah::vec<3, std::float_t>(result[1][0], result[1][1], result[1][2]);
		result[2] = lyah::vec<3, std::float_t>(result[2][0], result[2][1], result[2][2]);

		test::assert(test::eq(result, expected));
	}

	void runAll() {
		test::printTestCategory("lyah::mat<3, 3, std::float_t> - 3x3 single floating-point matrix");

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