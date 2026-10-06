#pragma once

#include "pch.hpp"

namespace mat2x2_m128 {
	void testDefaultConstructor() {
		const std::float_t expected[2 * 2] = {
			0.0f, 0.0f,
			0.0f, 0.0f,
		};

		const lyah::mat<2, 2, std::float_t> result;

		for (std::size_t i = 0; i < 2; i += 1) {
			for (std::size_t j = 0; j < 2; j += 1) {
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

		for (std::size_t i = 0; i < 2; i += 1) {
			for (std::size_t j = 0; j < 2; j += 1) {
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

		for (std::size_t i = 0; i < 2; i += 1) {
			for (std::size_t j = 0; j < 2; j += 1) {
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

	void testRotation() {
		const lyah::mat<2, 2, std::float_t> expected = {
			0.070f, -0.997f,
			0.997f,  0.070f,
		};
		const std::float_t angle = 1.5f;

		const lyah::mat<2, 2, std::float_t> result = lyah::mat<2, 2, std::float_t>::rotation(angle);

		test::assert(test::eq(result, expected, 0.001f));
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

	void testMatrixScalarMultiplicationAssignment() {
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

	void testMatrixScalarDivisionAssignment() {
		const lyah::mat<2, 2, std::float_t> expected = {
			0.333f, 1.333f,
			1.666f, 1.0f,
		};
		const std::float_t a = 3.0f;
		lyah::mat<2, 2, std::float_t> result = {
			1.0f, 4.0f,
			5.0f, 3.0f,
		};

		result /= a;

		test::assert(test::eq(result, expected, 0.001f));
	}

	void runAll() {
		test::printTestCategory("lyah::mat<2, 2, std::float_t> - 2x2 single floating-point matrix");

		test::runTest(&testDefaultConstructor, "Default constructor");
		test::runTest(&testComponentConstructor, "Component constructor");
		test::runTest(&testRowConstructor, "Row constructor");
		test::runTest(&testConvertingConstructor, "Converting constructor");

		test::runTest(&testRotation, "Rotation");

		test::runTest(&testAdditionAssignment, "Addition assignment (+=)");
		test::runTest(&testSubtractionAssignment, "Subtraction assignment (-)");
		test::runTest(&testMatrixScalarMultiplicationAssignment, "Matrix-scalar multiplication assignment (*=)");
		test::runTest(&testMatrixMatrixMultiplicationAssignment, "Matrix-matrix multiplication assignment (*=)");
		test::runTest(&testMatrixScalarDivisionAssignment, "Matrix-scalar division assignment (/=)");
	}
}