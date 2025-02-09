#pragma once

#include "pch.hpp"

namespace mat4x4_m128 {
	void testDefaultConstructor() {
		const std::float_t expected[4 * 4] = {
			0.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f,
		};

		const lyah::mat<4, 4, std::float_t> result;

		for (std::size_t i = 0; i < 4; i++) {
			for (std::size_t j = 0; j < 4; j++) {
				test::assert(test::eq(result[i][j], expected[i * 4 + j]));
			}
		}
	}

	void testComponentConstructor() {
		const std::float_t expected[4 * 4] = {
			1.0f,  4.0f,  6.0f, -1.0f,
			5.0f,  3.0f,  2.0f,  7.0f,
			0.0f, -8.0f,  0.5f,  3.0f,
			2.0f,  4.0f, -2.0f,  1.0f,
		};

		const lyah::mat<4, 4, std::float_t> result = {
			1.0f,  4.0f,  6.0f, -1.0f,
			5.0f,  3.0f,  2.0f,  7.0f,
			0.0f, -8.0f,  0.5f,  3.0f,
			2.0f,  4.0f, -2.0f,  1.0f,
		};

		for (std::size_t i = 0; i < 4; i++) {
			for (std::size_t j = 0; j < 4; j++) {
				test::assert(test::eq(result[i][j], expected[i * 4 + j]));
			}
		}
	}

	void testRowConstructor() {
		const std::float_t expected[4 * 4] = {
			1.0f,  4.0f,  6.0f, -1.0f,
			5.0f,  3.0f,  2.0f,  7.0f,
			0.0f, -8.0f,  0.5f,  3.0f,
			2.0f,  4.0f, -2.0f,  1.0f,
		};

		const lyah::mat<4, 4, std::float_t> result = {
			{1.0f,  4.0f,  6.0f, -1.0f},
			{5.0f,  3.0f,  2.0f,  7.0f},
			{0.0f, -8.0f,  0.5f,  3.0f},
			{2.0f,  4.0f, -2.0f,  1.0f},
		};

		for (std::size_t i = 0; i < 4; i++) {
			for (std::size_t j = 0; j < 4; j++) {
				test::assert(test::eq(result[i][j], expected[i * 4 + j]));
			}
		}
	}

	void testConvertingConstructor() {
		const lyah::mat<4, 4, std::float_t> expected = {
			1.0f,  4.0f,  6.0f, -1.0f,
			5.0f,  3.0f,  2.0f,  7.0f,
			0.0f, -8.0f,  0.5f,  3.0f,
			2.0f,  4.0f, -2.0f,  1.0f,
		};
		const lyah::mat<4, 4, std::double_t> a = {
			1.0,  4.0,  6.0, -1.0,
			5.0,  3.0,  2.0,  7.0,
			0.0, -8.0,  0.5,  3.0,
			2.0,  4.0, -2.0,  1.0,
		};

		const lyah::mat<4, 4, std::float_t> result(a);

		test::assert(test::eq(result, expected));
	}

	void testIdentity() {
		const lyah::mat<4, 4, std::float_t> expected = {
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f,
		};

		const lyah::mat<4, 4, std::float_t> result = lyah::mat<4, 4, std::float_t>::identity();

		test::assert(test::eq(result, expected));
	}

	void testTranslation() {
		const lyah::mat<4, 4, std::float_t> expected = {
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			1.0f, 4.0f, 6.0f, 1.0f,
		};
		const lyah::vec<3, std::float_t> a = {1.0f, 4.0f, 6.0f};

		const lyah::mat<4, 4, std::float_t> result = lyah::mat<4, 4, std::float_t>::translation(a);

		test::assert(test::eq(result, expected));
	}

	void testRotation() {
		const lyah::mat<4, 4, std::float_t> expected = {
			 0.713f,  0.605f, -0.355f,  0.0f,
			-0.561f,  0.796f,  0.230f,  0.0f,
			 0.422f,  0.036f,  0.906f,  0.0f,
			 0.0f,    0.0f,    0.0f,    1.0f,
		};
		const lyah::vec<3, std::float_t> axis = lyah::normalized(lyah::vec<3, std::float_t>(1.0f, 4.0f, 6.0f));
		const std::float_t angle = lyah::radians(45.0f);

		const lyah::mat<4, 4, std::float_t> result = lyah::mat<4, 4, std::float_t>::rotation(axis, angle);

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testScaling() {
		const lyah::mat<4, 4, std::float_t> expected = {
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 4.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 6.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f,
		};
		const lyah::vec<3, std::float_t> a = {1.0f, 4.0f, 6.0f};

		const lyah::mat<4, 4, std::float_t> result = lyah::mat<4, 4, std::float_t>::scaling(a);

		test::assert(test::eq(result, expected));
	}

	void testOrthographic() {
		const lyah::mat<4, 4, std::float_t> expected = {
			0.125f, 0.0f,   0.0f,  -0.0f,
			0.0f,   0.222f, 0.0f,  -0.0f,
			0.0f,   0.0f,   1.0f,  -0.0f,
			0.0f,   0.0f,   0.0f,   1.0f,
		};
		const std::float_t left = -8.0f;
		const std::float_t right = 8.0f;
		const std::float_t bottom = -4.5f;
		const std::float_t top = 4.5f;
		const std::float_t near = -1.0f;
		const std::float_t far = 1.0f;

		const lyah::mat<4, 4, std::float_t> result = lyah::mat<4, 4, std::float_t>::orthographic(left, right, bottom, top, near, far);

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testLookAt() {
		const lyah::mat<4, 4, std::float_t> expected = {
			-0.707f,  0.123f,  0.696f,  0.0f,
			 0.0f,    0.985f, -0.174f,  0.0f,
			-0.707f, -0.123f, -0.696f,  0.0f,
			 4.950f, -3.323f,  4.178f,  1.0f,
		};
		const lyah::vec<3, std::float_t> eye = {1.0f, 4.0f, 6.0f};
		const lyah::vec<3, std::float_t> center = {5.0f, 3.0f, 2.0f};
		const lyah::vec<3, std::float_t> up = {0.0f, 1.0f, 0.0f};

		const lyah::mat<4, 4, std::float_t> result = lyah::mat<4, 4, std::float_t>::lookAt(eye, center, up);

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testEquality() {
		const bool expected[2] = {true, false};
		const lyah::mat<4, 4, std::float_t> a = {
			1.0f,  4.0f,  6.0f, -1.0f,
			5.0f,  3.0f,  2.0f,  7.0f,
			0.0f, -8.0f,  0.5f,  3.0f,
			2.0f,  4.0f, -2.0f,  1.0f,
		};
		const lyah::mat<4, 4, std::float_t> b = {
			1.0f,  4.0f,  6.0f, -1.0f,
			5.0f,  0.0f,  2.0f,  7.0f,
			0.0f, -8.0f,  0.5f,  3.0f,
			2.0f,  4.0f, -2.0f,  1.0f,
		};

		const bool result[2] = {a == a, a == b};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
	}

	void testInequality() {
		const bool expected[2] = {false, true};
		const lyah::mat<4, 4, std::float_t> a = {
			1.0f,  4.0f,  6.0f, -1.0f,
			5.0f,  3.0f,  2.0f,  7.0f,
			0.0f, -8.0f,  0.5f,  3.0f,
			2.0f,  4.0f, -2.0f,  1.0f,
		};
		const lyah::mat<4, 4, std::float_t> b = {
			1.0f,  4.0f,  6.0f, -1.0f,
			5.0f,  0.0f,  2.0f,  7.0f,
			0.0f, -8.0f,  0.5f,  3.0f,
			2.0f,  4.0f, -2.0f,  1.0f,
		};

		const bool result[2] = {a != a, a != b};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
	}

	void testUnaryPlus() {
		const lyah::mat<4, 4, std::float_t> expected = {
			1.0f,  4.0f,  6.0f, -1.0f,
			5.0f,  3.0f,  2.0f,  7.0f,
			0.0f, -8.0f,  0.5f,  3.0f,
			2.0f,  4.0f, -2.0f,  1.0f,
		};
		const lyah::mat<4, 4, std::float_t> a = {
			1.0f,  4.0f,  6.0f, -1.0f,
			5.0f,  3.0f,  2.0f,  7.0f,
			0.0f, -8.0f,  0.5f,  3.0f,
			2.0f,  4.0f, -2.0f,  1.0f,
		};

		const lyah::mat<4, 4, std::float_t> result = +a;

		test::assert(test::eq(result, expected));
	}

	void testUnaryMinus() {
		const lyah::mat<4, 4, std::float_t> expected = {
			-1.0f, -4.0f, -6.0f,  1.0f,
			-5.0f, -3.0f, -2.0f, -7.0f,
			-0.0f,  8.0f, -0.5f, -3.0f,
			-2.0f, -4.0f,  2.0f, -1.0f,
		};
		const lyah::mat<4, 4, std::float_t> a = {
			1.0f,  4.0f,  6.0f, -1.0f,
			5.0f,  3.0f,  2.0f,  7.0f,
			0.0f, -8.0f,  0.5f,  3.0f,
			2.0f,  4.0f, -2.0f,  1.0f,
		};

		const lyah::mat<4, 4, std::float_t> result = -a;

		test::assert(test::eq(result, expected));
	}

	void testAddition() {
		const lyah::mat<4, 4, std::float_t> expected = {
			-2.0f,  6.5f,  7.0f,  7.0f,
			 9.0f,  12.0f, 0.0f,  7.0f,
			 2.0f, -8.0f,  8.0f,  9.0f,
			 3.0f,  9.0f,  6.0f, -3.0f,
		};
		const lyah::mat<4, 4, std::float_t> a = {
			1.0f,  4.0f,  6.0f, -1.0f,
			5.0f,  3.0f,  2.0f,  7.0f,
			0.0f, -8.0f,  0.5f,  3.0f,
			2.0f,  4.0f, -2.0f,  1.0f,
		};
		const lyah::mat<4, 4, std::float_t> b = {
			-3.0f,  2.5f,  1.0f,  8.0f,
			 4.0f,  9.0f, -2.0f,  0.0f,
			 2.0f,  0.0f,  7.5f,  6.0f,
			 1.0f,  5.0f,  8.0f, -4.0f,
		};

		const lyah::mat<4, 4, std::float_t> result = a + b;

		test::assert(test::eq(result, expected));
	}

	void testAdditionAssignment() {
		const lyah::mat<4, 4, std::float_t> expected = {
			-2.0f,  6.5f,  7.0f,  7.0f,
			 9.0f,  12.0f, 0.0f,  7.0f,
			 2.0f, -8.0f,  8.0f,  9.0f,
			 3.0f,  9.0f,  6.0f, -3.0f,
		};
		const lyah::mat<4, 4, std::float_t> a = {
			-3.0f,  2.5f,  1.0f,  8.0f,
			 4.0f,  9.0f, -2.0f,  0.0f,
			 2.0f,  0.0f,  7.5f,  6.0f,
			 1.0f,  5.0f,  8.0f, -4.0f,
		};
		lyah::mat<4, 4, std::float_t> result = {
			1.0f,  4.0f,  6.0f, -1.0f,
			5.0f,  3.0f,  2.0f,  7.0f,
			0.0f, -8.0f,  0.5f,  3.0f,
			2.0f,  4.0f, -2.0f,  1.0f,
		};

		result += a;

		test::assert(test::eq(result, expected));
	}

	void testSubtraction() {
		const lyah::mat<4, 4, std::float_t> expected = {
			 4.0f,  1.5f,  5.0f, -9.0f,
			 1.0f, -6.0f,  4.0f,  7.0f,
			-2.0f, -8.0f, -7.0f, -3.0f,
			 1.0f, -1.0f, -10.0f, 5.0f,
		};
		const lyah::mat<4, 4, std::float_t> a = {
			1.0f,  4.0f,  6.0f, -1.0f,
			5.0f,  3.0f,  2.0f,  7.0f,
			0.0f, -8.0f,  0.5f,  3.0f,
			2.0f,  4.0f, -2.0f,  1.0f,
		};
		const lyah::mat<4, 4, std::float_t> b = {
			-3.0f,  2.5f,  1.0f,  8.0f,
			 4.0f,  9.0f, -2.0f,  0.0f,
			 2.0f,  0.0f,  7.5f,  6.0f,
			 1.0f,  5.0f,  8.0f, -4.0f,
		};

		const lyah::mat<4, 4, std::float_t> result = a - b;

		test::assert(test::eq(result, expected));
	}

	void testSubtractionAssignment() {
		const lyah::mat<4, 4, std::float_t> expected = {
			 4.0f,  1.5f,  5.0f, -9.0f,
			 1.0f, -6.0f,  4.0f,  7.0f,
			-2.0f, -8.0f, -7.0f, -3.0f,
			 1.0f, -1.0f, -10.0f, 5.0f,
		};
		const lyah::mat<4, 4, std::float_t> a = {
			-3.0f,  2.5f,  1.0f,  8.0f,
			 4.0f,  9.0f, -2.0f,  0.0f,
			 2.0f,  0.0f,  7.5f,  6.0f,
			 1.0f,  5.0f,  8.0f, -4.0f,
		};
		lyah::mat<4, 4, std::float_t> result = {
			1.0f,  4.0f,  6.0f, -1.0f,
			5.0f,  3.0f,  2.0f,  7.0f,
			0.0f, -8.0f,  0.5f,  3.0f,
			2.0f,  4.0f, -2.0f,  1.0f,
		};

		result -= a;

		test::assert(test::eq(result, expected));
	}

	void testScalarMultiplicationAB() {
		const lyah::mat<4, 4, std::float_t> expected = {
			3.0f,   12.0f,  18.0f, -3.0f,
			15.0f,  9.0f,   6.0f,   21.0f,
			0.0f,  -24.0f,  1.5f,   9.0f,
			6.0f,   12.0f, -6.0f,   3.0f,
		};
		const lyah::mat<4, 4, std::float_t> a = {
			1.0f,  4.0f,  6.0f, -1.0f,
			5.0f,  3.0f,  2.0f,  7.0f,
			0.0f, -8.0f,  0.5f,  3.0f,
			2.0f,  4.0f, -2.0f,  1.0f,
		};
		const std::float_t b = 3.0f;

		const lyah::mat<4, 4, std::float_t> result = a * b;

		test::assert(test::eq(result, expected));
	}

	void testScalarMultiplicationBA() {
		const lyah::mat<4, 4, std::float_t> expected = {
			3.0f,   12.0f,  18.0f, -3.0f,
			15.0f,  9.0f,   6.0f,   21.0f,
			0.0f,  -24.0f,  1.5f,   9.0f,
			6.0f,   12.0f, -6.0f,   3.0f,
		};
		const lyah::mat<4, 4, std::float_t> a = {
			1.0f,  4.0f,  6.0f, -1.0f,
			5.0f,  3.0f,  2.0f,  7.0f,
			0.0f, -8.0f,  0.5f,  3.0f,
			2.0f,  4.0f, -2.0f,  1.0f,
		};
		const std::float_t b = 3.0f;

		const lyah::mat<4, 4, std::float_t> result = b * a;

		test::assert(test::eq(result, expected));
	}

	void testScalarMultiplicationAssignment() {
		const lyah::mat<4, 4, std::float_t> expected = {
			3.0f,   12.0f,  18.0f, -3.0f,
			15.0f,  9.0f,   6.0f,   21.0f,
			0.0f,  -24.0f,  1.5f,   9.0f,
			6.0f,   12.0f, -6.0f,   3.0f,
		};
		const std::float_t a = 3.0f;
		lyah::mat<4, 4, std::float_t> result = {
			1.0f,  4.0f,  6.0f, -1.0f,
			5.0f,  3.0f,  2.0f,  7.0f,
			0.0f, -8.0f,  0.5f,  3.0f,
			2.0f,  4.0f, -2.0f,  1.0f,
		};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testMatrixMatrixMultiplication() {
		const lyah::mat<4, 4, std::float_t> expected = {
			 24.0f,  33.5f,  30.0f,   48.0f,
			 8.0f,   74.5f,  70.0f,   24.0f,
			-28.0f, -57.0f,  43.75f, -9.0f,
			 7.0f,   46.0f, -13.0f,   0.0f,
		};
		const lyah::mat<4, 4, std::float_t> a = {
			1.0f,  4.0f,  6.0f, -1.0f,
			5.0f,  3.0f,  2.0f,  7.0f,
			0.0f, -8.0f,  0.5f,  3.0f,
			2.0f,  4.0f, -2.0f,  1.0f,
		};
		const lyah::mat<4, 4, std::float_t> b = {
			-3.0f,  2.5f,  1.0f,  8.0f,
			 4.0f,  9.0f, -2.0f,  0.0f,
			 2.0f,  0.0f,  7.5f,  6.0f,
			 1.0f,  5.0f,  8.0f, -4.0f,
		};

		const lyah::mat<4, 4, std::float_t> result = a * b;

		test::assert(test::eq(result, expected));
	}

	void testMatrixMatrixMultiplicationAssignment() {
		const lyah::mat<4, 4, std::float_t> expected = {
			 24.0f,  33.5f,  30.0f,   48.0f,
			 8.0f,   74.5f,  70.0f,   24.0f,
			-28.0f, -57.0f,  43.75f, -9.0f,
			 7.0f,   46.0f, -13.0f,   0.0f,
		};
		const lyah::mat<4, 4, std::float_t> a = {
			-3.0f,  2.5f,  1.0f,  8.0f,
			 4.0f,  9.0f, -2.0f,  0.0f,
			 2.0f,  0.0f,  7.5f,  6.0f,
			 1.0f,  5.0f,  8.0f, -4.0f,
		};
		lyah::mat<4, 4, std::float_t> result = {
			1.0f,  4.0f,  6.0f, -1.0f,
			5.0f,  3.0f,  2.0f,  7.0f,
			0.0f, -8.0f,  0.5f,  3.0f,
			2.0f,  4.0f, -2.0f,  1.0f,
		};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testDeterminant() {
		const std::float_t expected = 292.5f;
		const lyah::mat<4, 4, std::float_t> a = {
			1.0f,  4.0f,  6.0f, -1.0f,
			5.0f,  3.0f,  2.0f,  7.0f,
			0.0f, -8.0f,  0.5f,  3.0f,
			2.0f,  4.0f, -2.0f,  1.0f,
		};

		const std::float_t result = determinant(a);

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testInverse() {
		const lyah::mat<4, 4, std::float_t> expected = {
			 0.538f, -0.451f,  0.779f,  1.359f,
			-0.128f,  0.149f, -0.287f, -0.308f,
			 0.103f,  0.041f, -0.010f, -0.154f,
			-0.359f,  0.390f, -0.431f, -0.794f,
		};
		const lyah::mat<4, 4, std::float_t> a = {
			1.0f,  4.0f,  6.0f, -1.0f,
			5.0f,  3.0f,  2.0f,  7.0f,
			0.0f, -8.0f,  0.5f,  3.0f,
			2.0f,  4.0f, -2.0f,  1.0f,
		};

		const lyah::mat<4, 4, std::float_t> result = inverse(a);

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testTranspose() {
		const lyah::mat<4, 4, std::float_t> expected = {
			 1.0f,  5.0f,  0.0f,  2.0f,
			 4.0f,  3.0f, -8.0f,  4.0f,
			 6.0f,  2.0f,  0.5f, -2.0f,
			-1.0f,  7.0f,  3.0f,  1.0f,
		};
		const lyah::mat<4, 4, std::float_t> a = {
			1.0f,  4.0f,  6.0f, -1.0f,
			5.0f,  3.0f,  2.0f,  7.0f,
			0.0f, -8.0f,  0.5f,  3.0f,
			2.0f,  4.0f, -2.0f,  1.0f,
		};

		const lyah::mat<4, 4, std::float_t> result = transpose(a);

		test::assert(test::eq(result, expected));
	}

	void runAll() {
		test::printTestCategory("lyah::mat<4, 4, std::float_t> - 4x4 single floating-point matrix");

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