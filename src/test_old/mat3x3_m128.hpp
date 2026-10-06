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

		for (std::size_t i = 0; i < 3; i += 1) {
			for (std::size_t j = 0; j < 3; j += 1) {
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

		for (std::size_t i = 0; i < 3; i += 1) {
			for (std::size_t j = 0; j < 3; j += 1) {
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

		for (std::size_t i = 0; i < 3; i += 1) {
			for (std::size_t j = 0; j < 3; j += 1) {
				test::assert(test::eq(result[i][j], expected[i * 3 + j]));
			}
		}
	}

	void testQuaternionConstructor() {
		const lyah::mat<3, 3, std::float_t> expected = {
			-0.370f,  0.926f,  0.074f,
			 0.852f,  0.370f, -0.370f,
			-0.370f, -0.074f, -0.926f,
		};
		const lyah::quat<std::float_t> a = lyah::normalized(lyah::quat<std::float_t>(1.0f, 4.0f, 6.0f, -1.0f));

		const lyah::mat<3, 3, std::float_t> result = lyah::mat<3, 3, std::float_t>(a);

		test::assert(test::eq(result, expected, 0.001f));
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

	void testMatrixScalarMultiplicationAssignment() {
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

	void testMatrixScalarDivisionAssignment() {
		const lyah::mat<3, 3, std::float_t> expected = {
			 0.333f,  1.333f,  2.0f,
			 1.666f,  1.0f,    0.666f,
			 0.0f,   -2.666f,  0.166f,
		};
		const std::float_t a = 3.0f;
		lyah::mat<3, 3, std::float_t> result = {
			1.0f,  4.0f,  6.0f,
			5.0f,  3.0f,  2.0f,
			0.0f, -8.0f,  0.5f,
		};

		result /= a;

		test::assert(test::eq(result, expected, 0.001f));
	}

	void runAll() {
		test::printTestCategory("lyah::mat<3, 3, std::float_t> - 3x3 single floating-point matrix");

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