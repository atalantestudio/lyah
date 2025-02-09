#pragma once

#include "pch.hpp"

namespace mat4x4_m256d {
	void testDefaultConstructor() {
		const std::double_t expected[4 * 4] = {
			0.0, 0.0, 0.0, 0.0,
			0.0, 0.0, 0.0, 0.0,
			0.0, 0.0, 0.0, 0.0,
			0.0, 0.0, 0.0, 0.0,
		};

		const lyah::mat<4, 4, std::double_t> result;

		for (std::size_t i = 0; i < 4; i++) {
			for (std::size_t j = 0; j < 4; j++) {
				test::assert(test::eq(result[i][j], expected[i * 4 + j]));
			}
		}
	}

	void testComponentConstructor() {
		const std::double_t expected[4 * 4] = {
			1.0,  4.0,  6.0, -1.0,
			5.0,  3.0,  2.0,  7.0,
			0.0, -8.0,  0.5,  3.0,
			2.0,  4.0, -2.0,  1.0,
		};

		const lyah::mat<4, 4, std::double_t> result = {
			1.0,  4.0,  6.0, -1.0,
			5.0,  3.0,  2.0,  7.0,
			0.0, -8.0,  0.5,  3.0,
			2.0,  4.0, -2.0,  1.0,
		};

		for (std::size_t i = 0; i < 4; i++) {
			for (std::size_t j = 0; j < 4; j++) {
				test::assert(test::eq(result[i][j], expected[i * 4 + j]));
			}
		}
	}

	void testRowConstructor() {
		const std::double_t expected[4 * 4] = {
			1.0,  4.0,  6.0, -1.0,
			5.0,  3.0,  2.0,  7.0,
			0.0, -8.0,  0.5,  3.0,
			2.0,  4.0, -2.0,  1.0,
		};

		const lyah::mat<4, 4, std::double_t> result = {
			{1.0,  4.0,  6.0, -1.0},
			{5.0,  3.0,  2.0,  7.0},
			{0.0, -8.0,  0.5,  3.0},
			{2.0,  4.0, -2.0,  1.0},
		};

		for (std::size_t i = 0; i < 4; i++) {
			for (std::size_t j = 0; j < 4; j++) {
				test::assert(test::eq(result[i][j], expected[i * 4 + j]));
			}
		}
	}

	void testConvertingConstructor() {
		const lyah::mat<4, 4, std::double_t> expected = {
			1.0,  4.0,  6.0, -1.0,
			5.0,  3.0,  2.0,  7.0,
			0.0, -8.0,  0.5,  3.0,
			2.0,  4.0, -2.0,  1.0,
		};
		const lyah::mat<4, 4, std::float_t> a = {
			1.0f,  4.0f,  6.0f, -1.0f,
			5.0f,  3.0f,  2.0f,  7.0f,
			0.0f, -8.0f,  0.5f,  3.0f,
			2.0f,  4.0f, -2.0f,  1.0f,
		};

		const lyah::mat<4, 4, std::double_t> result(a);

		test::assert(test::eq(result, expected));
	}

	void testIdentity() {
		const lyah::mat<4, 4, std::double_t> expected = {
			1.0, 0.0, 0.0, 0.0,
			0.0, 1.0, 0.0, 0.0,
			0.0, 0.0, 1.0, 0.0,
			0.0, 0.0, 0.0, 1.0,
		};

		const lyah::mat<4, 4, std::double_t> result = lyah::mat<4, 4, std::double_t>::identity();

		test::assert(test::eq(result, expected));
	}

	void testTranslation() {
		const lyah::mat<4, 4, std::double_t> expected = {
			1.0, 0.0, 0.0, 0.0,
			0.0, 1.0, 0.0, 0.0,
			0.0, 0.0, 1.0, 0.0,
			1.0, 4.0, 6.0, 1.0,
		};
		const lyah::vec<3, std::double_t> a = {1.0, 4.0, 6.0};

		const lyah::mat<4, 4, std::double_t> result = lyah::mat<4, 4, std::double_t>::translation(a);

		test::assert(test::eq(result, expected));
	}

	void testRotation() {
		const lyah::mat<4, 4, std::double_t> expected = {
			 0.713,  0.605, -0.355,  0.0,
			-0.561,  0.796,  0.230,  0.0,
			 0.422,  0.036,  0.906,  0.0,
			 0.0,    0.0,    0.0,    1.0,
		};
		const lyah::vec<3, std::double_t> axis = lyah::normalized(lyah::vec<3, std::double_t>(1.0, 4.0, 6.0));
		const std::double_t angle = lyah::radians(45.0);

		const lyah::mat<4, 4, std::double_t> result = lyah::mat<4, 4, std::double_t>::rotation(axis, angle);

		test::assert(test::eq(result, expected, 0.001));
	}

	void testScaling() {
		const lyah::mat<4, 4, std::double_t> expected = {
			1.0, 0.0, 0.0, 0.0,
			0.0, 4.0, 0.0, 0.0,
			0.0, 0.0, 6.0, 0.0,
			0.0, 0.0, 0.0, 1.0,
		};
		const lyah::vec<3, std::double_t> a = {1.0, 4.0, 6.0};

		const lyah::mat<4, 4, std::double_t> result = lyah::mat<4, 4, std::double_t>::scaling(a);

		test::assert(test::eq(result, expected));
	}

	void testOrthographic() {
		const lyah::mat<4, 4, std::double_t> expected = {
			0.125, 0.0,   0.0,  -0.0,
			0.0,   0.222, 0.0,  -0.0,
			0.0,   0.0,   1.0,  -0.0,
			0.0,   0.0,   0.0,   1.0,
		};
		const std::double_t left = -8.0;
		const std::double_t right = 8.0;
		const std::double_t bottom = -4.5;
		const std::double_t top = 4.5;
		const std::double_t near = -1.0;
		const std::double_t far = 1.0;

		const lyah::mat<4, 4, std::double_t> result = lyah::mat<4, 4, std::double_t>::orthographic(left, right, bottom, top, near, far);

		test::assert(test::eq(result, expected, 0.001));
	}

	void testLookAt() {
		const lyah::mat<4, 4, std::double_t> expected = {
			-0.707,  0.123,  0.696,  0.0,
			 0.0,    0.985, -0.174,  0.0,
			-0.707, -0.123, -0.696,  0.0,
			 4.950, -3.323,  4.178,  1.0,
		};
		const lyah::vec<3, std::double_t> eye = {1.0, 4.0, 6.0};
		const lyah::vec<3, std::double_t> center = {5.0, 3.0, 2.0};
		const lyah::vec<3, std::double_t> up = {0.0, 1.0, 0.0};

		const lyah::mat<4, 4, std::double_t> result = lyah::mat<4, 4, std::double_t>::lookAt(eye, center, up);

		test::assert(test::eq(result, expected, 0.001));
	}

	void testEquality() {
		const bool expected[2] = {true, false};
		const lyah::mat<4, 4, std::double_t> a = {
			1.0,  4.0,  6.0, -1.0,
			5.0,  3.0,  2.0,  7.0,
			0.0, -8.0,  0.5,  3.0,
			2.0,  4.0, -2.0,  1.0,
		};
		const lyah::mat<4, 4, std::double_t> b = {
			1.0,  4.0,  6.0, -1.0,
			5.0,  0.0,  2.0,  7.0,
			0.0, -8.0,  0.5,  3.0,
			2.0,  4.0, -2.0,  1.0,
		};

		const bool result[2] = {a == a, a == b};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
	}

	void testInequality() {
		const bool expected[2] = {false, true};
		const lyah::mat<4, 4, std::double_t> a = {
			1.0,  4.0,  6.0, -1.0,
			5.0,  3.0,  2.0,  7.0,
			0.0, -8.0,  0.5,  3.0,
			2.0,  4.0, -2.0,  1.0,
		};
		const lyah::mat<4, 4, std::double_t> b = {
			1.0,  4.0,  6.0, -1.0,
			5.0,  0.0,  2.0,  7.0,
			0.0, -8.0,  0.5,  3.0,
			2.0,  4.0, -2.0,  1.0,
		};

		const bool result[2] = {a != a, a != b};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
	}

	void testUnaryPlus() {
		const lyah::mat<4, 4, std::double_t> expected = {
			1.0,  4.0,  6.0, -1.0,
			5.0,  3.0,  2.0,  7.0,
			0.0, -8.0,  0.5,  3.0,
			2.0,  4.0, -2.0,  1.0,
		};
		const lyah::mat<4, 4, std::double_t> a = {
			1.0,  4.0,  6.0, -1.0,
			5.0,  3.0,  2.0,  7.0,
			0.0, -8.0,  0.5,  3.0,
			2.0,  4.0, -2.0,  1.0,
		};

		const lyah::mat<4, 4, std::double_t> result = +a;

		test::assert(test::eq(result, expected));
	}

	void testUnaryMinus() {
		const lyah::mat<4, 4, std::double_t> expected = {
			-1.0, -4.0, -6.0,  1.0,
			-5.0, -3.0, -2.0, -7.0,
			-0.0,  8.0, -0.5, -3.0,
			-2.0, -4.0,  2.0, -1.0,
		};
		const lyah::mat<4, 4, std::double_t> a = {
			1.0,  4.0,  6.0, -1.0,
			5.0,  3.0,  2.0,  7.0,
			0.0, -8.0,  0.5,  3.0,
			2.0,  4.0, -2.0,  1.0,
		};

		const lyah::mat<4, 4, std::double_t> result = -a;

		test::assert(test::eq(result, expected));
	}

	void testAddition() {
		const lyah::mat<4, 4, std::double_t> expected = {
			-2.0,  6.5,  7.0,  7.0,
			 9.0,  12.0, 0.0,  7.0,
			 2.0, -8.0,  8.0,  9.0,
			 3.0,  9.0,  6.0, -3.0,
		};
		const lyah::mat<4, 4, std::double_t> a = {
			1.0,  4.0,  6.0, -1.0,
			5.0,  3.0,  2.0,  7.0,
			0.0, -8.0,  0.5,  3.0,
			2.0,  4.0, -2.0,  1.0,
		};
		const lyah::mat<4, 4, std::double_t> b = {
			-3.0,  2.5,  1.0,  8.0,
			 4.0,  9.0, -2.0,  0.0,
			 2.0,  0.0,  7.5,  6.0,
			 1.0,  5.0,  8.0, -4.0,
		};

		const lyah::mat<4, 4, std::double_t> result = a + b;

		test::assert(test::eq(result, expected));
	}

	void testAdditionAssignment() {
		const lyah::mat<4, 4, std::double_t> expected = {
			-2.0,  6.5,  7.0,  7.0,
			 9.0,  12.0, 0.0,  7.0,
			 2.0, -8.0,  8.0,  9.0,
			 3.0,  9.0,  6.0, -3.0,
		};
		const lyah::mat<4, 4, std::double_t> a = {
			-3.0,  2.5,  1.0,  8.0,
			 4.0,  9.0, -2.0,  0.0,
			 2.0,  0.0,  7.5,  6.0,
			 1.0,  5.0,  8.0, -4.0,
		};
		lyah::mat<4, 4, std::double_t> result = {
			1.0,  4.0,  6.0, -1.0,
			5.0,  3.0,  2.0,  7.0,
			0.0, -8.0,  0.5,  3.0,
			2.0,  4.0, -2.0,  1.0,
		};

		result += a;

		test::assert(test::eq(result, expected));
	}

	void testSubtraction() {
		const lyah::mat<4, 4, std::double_t> expected = {
			 4.0,  1.5,  5.0, -9.0,
			 1.0, -6.0,  4.0,  7.0,
			-2.0, -8.0, -7.0, -3.0,
			 1.0, -1.0, -10.0, 5.0,
		};
		const lyah::mat<4, 4, std::double_t> a = {
			1.0,  4.0,  6.0, -1.0,
			5.0,  3.0,  2.0,  7.0,
			0.0, -8.0,  0.5,  3.0,
			2.0,  4.0, -2.0,  1.0,
	};
		const lyah::mat<4, 4, std::double_t> b = {
			-3.0,  2.5,  1.0,  8.0,
			 4.0,  9.0, -2.0,  0.0,
			 2.0,  0.0,  7.5,  6.0,
			 1.0,  5.0,  8.0, -4.0,
		};

		const lyah::mat<4, 4, std::double_t> result = a - b;

		test::assert(test::eq(result, expected));
	}

	void testSubtractionAssignment() {
		const lyah::mat<4, 4, std::double_t> expected = {
			 4.0,  1.5,  5.0, -9.0,
			 1.0, -6.0,  4.0,  7.0,
			-2.0, -8.0, -7.0, -3.0,
			 1.0, -1.0, -10.0, 5.0,
		};
		const lyah::mat<4, 4, std::double_t> a = {
			-3.0,  2.5,  1.0,  8.0,
			 4.0,  9.0, -2.0,  0.0,
			 2.0,  0.0,  7.5,  6.0,
			 1.0,  5.0,  8.0, -4.0,
		};
		lyah::mat<4, 4, std::double_t> result = {
			1.0,  4.0,  6.0, -1.0,
			5.0,  3.0,  2.0,  7.0,
			0.0, -8.0,  0.5,  3.0,
			2.0,  4.0, -2.0,  1.0,
		};

		result -= a;

		test::assert(test::eq(result, expected));
	}

	void testScalarMultiplicationAB() {
		const lyah::mat<4, 4, std::double_t> expected = {
			3.0,   12.0,  18.0, -3.0,
			15.0,  9.0,   6.0,   21.0,
			0.0,  -24.0,  1.5,   9.0,
			6.0,   12.0, -6.0,   3.0,
		};
		const lyah::mat<4, 4, std::double_t> a = {
			1.0,  4.0,  6.0, -1.0,
			5.0,  3.0,  2.0,  7.0,
			0.0, -8.0,  0.5,  3.0,
			2.0,  4.0, -2.0,  1.0,
		};
		const std::double_t b = 3.0;

		const lyah::mat<4, 4, std::double_t> result = a * b;

		test::assert(test::eq(result, expected));
	}

	void testScalarMultiplicationBA() {
		const lyah::mat<4, 4, std::double_t> expected = {
			3.0,   12.0,  18.0, -3.0,
			15.0,  9.0,   6.0,   21.0,
			0.0,  -24.0,  1.5,   9.0,
			6.0,   12.0, -6.0,   3.0,
		};
		const lyah::mat<4, 4, std::double_t> a = {
			1.0,  4.0,  6.0, -1.0,
			5.0,  3.0,  2.0,  7.0,
			0.0, -8.0,  0.5,  3.0,
			2.0,  4.0, -2.0,  1.0,
		};
		const std::double_t b = 3.0;

		const lyah::mat<4, 4, std::double_t> result = b * a;

		test::assert(test::eq(result, expected));
	}

	void testScalarMultiplicationAssignment() {
		const lyah::mat<4, 4, std::double_t> expected = {
			3.0,   12.0,  18.0, -3.0,
			15.0,  9.0,   6.0,   21.0,
			0.0,  -24.0,  1.5,   9.0,
			6.0,   12.0, -6.0,   3.0,
		};
		const std::double_t a = 3.0;
		lyah::mat<4, 4, std::double_t> result = {
			1.0,  4.0,  6.0, -1.0,
			5.0,  3.0,  2.0,  7.0,
			0.0, -8.0,  0.5,  3.0,
			2.0,  4.0, -2.0,  1.0,
		};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testMatrixMatrixMultiplication() {
		const lyah::mat<4, 4, std::double_t> expected = {
			 24.0,  33.5,  30.0,   48.0,
			 8.0,   74.5,  70.0,   24.0,
			-28.0, -57.0,  43.75, -9.0,
			 7.0,   46.0, -13.0,   0.0,
		};
		const lyah::mat<4, 4, std::double_t> a = {
			1.0,  4.0,  6.0, -1.0,
			5.0,  3.0,  2.0,  7.0,
			0.0, -8.0,  0.5,  3.0,
			2.0,  4.0, -2.0,  1.0,
		};
		const lyah::mat<4, 4, std::double_t> b = {
			-3.0,  2.5,  1.0,  8.0,
			 4.0,  9.0, -2.0,  0.0,
			 2.0,  0.0,  7.5,  6.0,
			 1.0,  5.0,  8.0, -4.0,
		};

		const lyah::mat<4, 4, std::double_t> result = a * b;

		test::assert(test::eq(result, expected));
	}

	void testMatrixMatrixMultiplicationAssignment() {
		const lyah::mat<4, 4, std::double_t> expected = {
			 24.0,  33.5,  30.0,   48.0,
			 8.0,   74.5,  70.0,   24.0,
			-28.0, -57.0,  43.75, -9.0,
			 7.0,   46.0, -13.0,   0.0,
		};
		const lyah::mat<4, 4, std::double_t> a = {
			-3.0,  2.5,  1.0,  8.0,
			 4.0,  9.0, -2.0,  0.0,
			 2.0,  0.0,  7.5,  6.0,
			 1.0,  5.0,  8.0, -4.0,
		};
		lyah::mat<4, 4, std::double_t> result = {
			1.0,  4.0,  6.0, -1.0,
			5.0,  3.0,  2.0,  7.0,
			0.0, -8.0,  0.5,  3.0,
			2.0,  4.0, -2.0,  1.0,
		};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testDeterminant() {
		const std::double_t expected = 292.5;
		const lyah::mat<4, 4, std::double_t> a = {
			1.0,  4.0,  6.0, -1.0,
			5.0,  3.0,  2.0,  7.0,
			0.0, -8.0,  0.5,  3.0,
			2.0,  4.0, -2.0,  1.0,
		};

		const std::double_t result = determinant(a);

		test::assert(test::eq(result, expected, 0.001));
	}

	void testInverse() {
		const lyah::mat<4, 4, std::double_t> expected = {
			 0.538, -0.451,  0.779,  1.359,
			-0.128,  0.149, -0.287, -0.308,
			 0.103,  0.041, -0.010, -0.154,
			-0.359,  0.390, -0.431, -0.794,
		};
		const lyah::mat<4, 4, std::double_t> a = {
			1.0,  4.0,  6.0, -1.0,
			5.0,  3.0,  2.0,  7.0,
			0.0, -8.0,  0.5,  3.0,
			2.0,  4.0, -2.0,  1.0,
		};

		const lyah::mat<4, 4, std::double_t> result = inverse(a);

		test::assert(test::eq(result, expected, 0.001));
	}

	void testTranspose() {
		const lyah::mat<4, 4, std::double_t> expected = {
			 1.0,  5.0,  0.0,  2.0,
			 4.0,  3.0, -8.0,  4.0,
			 6.0,  2.0,  0.5, -2.0,
			-1.0,  7.0,  3.0,  1.0,
		};
		const lyah::mat<4, 4, std::double_t> a = {
			1.0,  4.0,  6.0, -1.0,
			5.0,  3.0,  2.0,  7.0,
			0.0, -8.0,  0.5,  3.0,
			2.0,  4.0, -2.0,  1.0,
		};

		const lyah::mat<4, 4, std::double_t> result = transpose(a);

		test::assert(test::eq(result, expected));
	}

	void runAll() {
		test::printTestCategory("lyah::mat<4, 4, std::double_t> - 4x4 double floating-point matrix");

		test::runTest(&testDefaultConstructor, "Default constructor");
		test::runTest(&testComponentConstructor, "Component constructor");
		test::runTest(&testRowConstructor, "Row constructor");
		test::runTest(&testConvertingConstructor, "Converting constructor");

		test::runTest(&testIdentity, "Identity");
		test::runTest(&testTranslation, "Translation");
		test::runTest(&testRotation, "Rotation");
		test::runTest(&testScaling, "Scaling");
		test::runTest(&testOrthographic, "Orthographic");
		test::runTest(&testLookAt, "Look At");

		test::runTest(&testEquality, "Equality (==)");
		test::runTest(&testInequality, "Inequality (!=)");

		test::runTest(&testUnaryPlus, "Unary plus (+)");
		test::runTest(&testUnaryMinus, "Unary minus (-)");

		test::runTest(&testAddition, "Addition (+)");
		test::runTest(&testAdditionAssignment, "Addition assignment (+=)");

		test::runTest(&testSubtraction, "Subtraction (-)");
		test::runTest(&testSubtractionAssignment, "Subtraction assignment (-)");

		test::runTest(&testScalarMultiplicationAB, "Scalar multiplication (*) - matrix * scalar");
		test::runTest(&testScalarMultiplicationBA, "Scalar multiplication (*) - scalar * matrix");
		test::runTest(&testScalarMultiplicationAssignment, "Scalar multiplication assignment (*=)");
		test::runTest(&testMatrixMatrixMultiplication, "Matrix-matrix multiplication (*)");
		test::runTest(&testMatrixMatrixMultiplicationAssignment, "Matrix-matrix multiplication assignment (*=)");

		test::runTest(&testDeterminant, "Determinant");
		test::runTest(&testInverse, "Inverse");
		test::runTest(&testTranspose, "Transpose");
	}
}