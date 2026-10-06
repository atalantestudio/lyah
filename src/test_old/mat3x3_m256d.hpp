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

		for (std::size_t i = 0; i < 3; i += 1) {
			for (std::size_t j = 0; j < 3; j += 1) {
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

		for (std::size_t i = 0; i < 3; i += 1) {
			for (std::size_t j = 0; j < 3; j += 1) {
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

		for (std::size_t i = 0; i < 3; i += 1) {
			for (std::size_t j = 0; j < 3; j += 1) {
				test::assert(test::eq(result[i][j], expected[i * 3 + j]));
			}
		}
	}

	void testQuaternionConstructor() {
		const lyah::mat<3, 3, std::double_t> expected = {
			-0.370,  0.926,  0.074,
			 0.852,  0.370, -0.370,
			-0.370, -0.074, -0.926,
		};
		const lyah::quat<std::double_t> a = lyah::normalized(lyah::quat<std::double_t>(1.0, 4.0, 6.0, -1.0));

		const lyah::mat<3, 3, std::double_t> result = lyah::mat<3, 3, std::double_t>(a);

		test::assert(test::eq(result, expected, 0.001));
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

	void testMatrixScalarMultiplicationAssignment() {
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

	void testMatrixScalarDivisionAssignment() {
		const lyah::mat<3, 3, std::double_t> expected = {
			 0.333,  1.333,  2.0,
			 1.666,  1.0,    0.666,
			 0.0,   -2.666,  0.166,
		};
		const std::double_t a = 3.0;
		lyah::mat<3, 3, std::double_t> result = {
			1.0,  4.0,  6.0,
			5.0,  3.0,  2.0,
			0.0, -8.0,  0.5,
		};

		result /= a;

		test::assert(test::eq(result, expected, 0.001));
	}

	void runAll() {
		test::printTestCategory("lyah::mat<3, 3, std::double_t> - 3x3 double floating-point matrix");

		test::runTest(&testDefaultConstructor, "Default constructor");
		test::runTest(&testComponentConstructor, "Component constructor");
		test::runTest(&testRowConstructor, "Row constructor");
		test::runTest(&testQuaternionConstructor, "Quaternion constructor");
		test::runTest(&testConvertingConstructor, "Converting constructor");

		test::runTest(&testTranslation, "Translation");
		test::runTest(&testRotation, "Rotation");
		test::runTest(&testScaling, "Scaling");

		test::runTest(&testAdditionAssignment, "Addition assignment (+=)");
		test::runTest(&testSubtractionAssignment, "Subtraction assignment (-)");
		test::runTest(&testMatrixScalarMultiplicationAssignment, "Matrix-scalar multiplication assignment (*=)");
		test::runTest(&testMatrixMatrixMultiplicationAssignment, "Matrix-matrix multiplication assignment (*=)");
		test::runTest(&testMatrixScalarDivisionAssignment, "Matrix-scalar division assignment (/=)");
	}
}