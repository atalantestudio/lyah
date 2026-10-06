#pragma once

#include "pch.hpp"

namespace mat2x2_m128d {
	void testDefaultConstructor() {
		const std::double_t expected[2 * 2] = {
			0.0, 0.0,
			0.0, 0.0,
		};

		const lyah::mat<2, 2, std::double_t> result;

		for (std::size_t i = 0; i < 2; i += 1) {
			for (std::size_t j = 0; j < 2; j += 1) {
				test::assert(test::eq(result[i][j], expected[i * 2 + j]));
			}
		}
	}

	void testComponentConstructor() {
		const std::double_t expected[2 * 2] = {
			1.0, 4.0,
			5.0, 3.0,
		};

		const lyah::mat<2, 2, std::double_t> result = {
			1.0, 4.0,
			5.0, 3.0,
		};

		for (std::size_t i = 0; i < 2; i += 1) {
			for (std::size_t j = 0; j < 2; j += 1) {
				test::assert(test::eq(result[i][j], expected[i * 2 + j]));
			}
		}
	}

	void testRowConstructor() {
		const std::double_t expected[2 * 2] = {
			1.0, 4.0,
			5.0, 3.0,
		};

		const lyah::mat<2, 2, std::double_t> result = {
			{1.0, 4.0},
			{5.0, 3.0},
		};

		for (std::size_t i = 0; i < 2; i += 1) {
			for (std::size_t j = 0; j < 2; j += 1) {
				test::assert(test::eq(result[i][j], expected[i * 2 + j]));
			}
		}
	}

	void testConvertingConstructor() {
		const lyah::mat<2, 2, std::double_t> expected = {
			1.0, 4.0,
			5.0, 3.0,
		};
		const lyah::mat<2, 2, std::float_t> a = {
			1.0f, 4.0f,
			5.0f, 3.0f,
		};

		const lyah::mat<2, 2, std::double_t> result(a);

		test::assert(test::eq(result, expected));
	}

	void testRotation() {
		const lyah::mat<2, 2, std::double_t> expected = {
			0.070, -0.997,
			0.997,  0.070,
		};
		const std::double_t angle = 1.5;

		const lyah::mat<2, 2, std::double_t> result = lyah::mat<2, 2, std::double_t>::rotation(angle);

		test::assert(test::eq(result, expected, 0.001));
	}

	void testUnaryMinus() {
		const lyah::mat<2, 2, std::double_t> expected = {
			-1.0, -4.0,
			-5.0, -3.0,
		};
		const lyah::mat<2, 2, std::double_t> a = {
			1.0, 4.0,
			5.0, 3.0,
		};

		const lyah::mat<2, 2, std::double_t> result = -a;

		test::assert(test::eq(result, expected));
	}

	void testAdditionAssignment() {
		const lyah::mat<2, 2, std::double_t> expected = {
			-2.0, 6.5,
			 9.0, 12.0,
		};
		const lyah::mat<2, 2, std::double_t> a = {
			-3.0, 2.5,
			 4.0, 9.0,
		};
		lyah::mat<2, 2, std::double_t> result = {
			1.0, 4.0,
			5.0, 3.0,
		};

		result += a;

		test::assert(test::eq(result, expected));
	}

	void testSubtractionAssignment() {
		const lyah::mat<2, 2, std::double_t> expected = {
			 4.0,  1.5,
			 1.0, -6.0,
		};
		const lyah::mat<2, 2, std::double_t> a = {
			-3.0, 2.5,
			 4.0, 9.0,
		};
		lyah::mat<2, 2, std::double_t> result = {
			1.0, 4.0,
			5.0, 3.0,
		};

		result -= a;

		test::assert(test::eq(result, expected));
	}

	void testMatrixScalarMultiplicationAssignment() {
		const lyah::mat<2, 2, std::double_t> expected = {
			3.0,  12.0,
			15.0, 9.0,
		};
		const std::double_t a = 3.0;
		lyah::mat<2, 2, std::double_t> result = {
			1.0, 4.0,
			5.0, 3.0,
		};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testMatrixMatrixMultiplicationAssignment() {
		const lyah::mat<2, 2, std::double_t> expected = {
			 13.0, 38.5,
			-3.0,  39.5,
		};
		const lyah::mat<2, 2, std::double_t> a = {
			-3.0, 2.5,
			 4.0, 9.0,
		};
		lyah::mat<2, 2, std::double_t> result = {
			1.0, 4.0,
			5.0, 3.0,
		};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testMatrixScalarDivisionAssignment() {
		const lyah::mat<2, 2, std::double_t> expected = {
			0.333, 1.333,
			1.666, 1.0,
		};
		const std::double_t a = 3.0;
		lyah::mat<2, 2, std::double_t> result = {
			1.0, 4.0,
			5.0, 3.0,
		};

		result /= a;

		test::assert(test::eq(result, expected, 0.001));
	}

	void runAll() {
		test::printTestCategory("lyah::mat<2, 2, std::double_t> - 2x2 single floating-point matrix");

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