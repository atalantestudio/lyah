#pragma once

#include "pch.hpp"

namespace vec4_m128i {
	void testDefaultConstructor() {
		const std::int32_t expected[4] = {0, 0, 0, 0};

		const lyah::vec<4, std::int32_t> result;

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
		test::assert(test::eq(result[2], expected[2]));
		test::assert(test::eq(result[3], expected[3]));
	}

	void testComponentConstructor() {
		const std::int32_t expected[4] = {1, 4, 6, -1};

		const lyah::vec<4, std::int32_t> result = {1, 4, 6, -1};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
		test::assert(test::eq(result[2], expected[2]));
		test::assert(test::eq(result[3], expected[3]));
	}

	void testComponentBroadcastConstructor() {
		const std::int32_t expected = 1;

		const lyah::vec<4, std::int32_t> result = lyah::vec<4, std::int32_t>(1);

		test::assert(test::eq(result[0], expected));
		test::assert(test::eq(result[1], expected));
		test::assert(test::eq(result[2], expected));
		test::assert(test::eq(result[3], expected));
	}

	void testSimdConstructor() {
		const lyah::vec<4, std::int32_t> expected = {1, 4, 6, -1};
		const __m128i m = _mm_set_epi32(-1, 6, 4, 1);

		const lyah::vec<4, std::int32_t> result(m);

		test::assert(test::eq(result, expected));
	}

	void testConvertingConstructor() {
		const lyah::vec<4, std::int32_t> expected = {1, 4, 6, -1};
		const lyah::vec<4, std::int64_t> a = {1, 4, 6, -1};

		const lyah::vec<4, std::int32_t> result(a);

		test::assert(test::eq(result, expected));
	}

	void testEquality() {
		const bool expected[2] = {true, false};
		const lyah::vec<4, std::int32_t> a = {1, 4, 6, -1};
		const lyah::vec<4, std::int32_t> b = {1, 0, 6, -1};

		const bool result[2] = {a == a, a == b};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
	}

	void testInequality() {
		const bool expected[2] = {false, true};
		const lyah::vec<4, std::int32_t> a = {1, 4, 6, -1};
		const lyah::vec<4, std::int32_t> b = {1, 0, 6, -1};

		const bool result[2] = {a != a, a != b};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
	}

	void testUnaryPlus() {
		const lyah::vec<4, std::int32_t> expected = {1, 4, 6, -1};
		const lyah::vec<4, std::int32_t> a = {1, 4, 6, -1};

		const lyah::vec<4, std::int32_t> result = +a;

		test::assert(test::eq(result, expected));
	}

	void testUnaryMinus() {
		const lyah::vec<4, std::int32_t> expected = {-1, -4, -6, 1};
		const lyah::vec<4, std::int32_t> a = {1, 4, 6, -1};

		const lyah::vec<4, std::int32_t> result = -a;

		test::assert(test::eq(result, expected));
	}

	void testAddition() {
		const lyah::vec<4, std::int32_t> expected = {6, 7, 8, 3};
		const lyah::vec<4, std::int32_t> a = {1, 4, 6, -1};
		const lyah::vec<4, std::int32_t> b = {5, 3, 2, 4};

		const lyah::vec<4, std::int32_t> result = a + b;

		test::assert(test::eq(result, expected));
	}

	void testAdditionAssignment() {
		const lyah::vec<4, std::int32_t> expected = {6, 7, 8, 3};
		const lyah::vec<4, std::int32_t> a = {5, 3, 2, 4};
		lyah::vec<4, std::int32_t> result = {1, 4, 6, -1};

		result += a;

		test::assert(test::eq(result, expected));
	}

	void testSubtraction() {
		const lyah::vec<4, std::int32_t> expected = {-4, 1, 4, -8};
		const lyah::vec<4, std::int32_t> a = {1, 4, 6, -1};
		const lyah::vec<4, std::int32_t> b = {5, 3, 2, 7};

		const lyah::vec<4, std::int32_t> result = a - b;

		test::assert(test::eq(result, expected));
	}

	void testSubtractionAssignment() {
		const lyah::vec<4, std::int32_t> expected = {-4, 1, 4, -8};
		const lyah::vec<4, std::int32_t> a = {5, 3, 2, 7};
		lyah::vec<4, std::int32_t> result = {1, 4, 6, -1};

		result -= a;

		test::assert(test::eq(result, expected));
	}

	void testVectorScalarMultiplication() {
		const lyah::vec<4, std::int32_t> expected = {3, 12, 18, -3};
		const lyah::vec<4, std::int32_t> a = {1, 4, 6, -1};
		const std::int32_t b = 3;

		const lyah::vec<4, std::int32_t> result = a * b;

		test::assert(test::eq(result, expected));
	}

	void testScalarVectorMultiplication() {
		const lyah::vec<4, std::int32_t> expected = {3, 12, 18, -3};
		const lyah::vec<4, std::int32_t> a = {1, 4, 6, -1};
		const std::int32_t b = 3;

		const lyah::vec<4, std::int32_t> result = b * a;

		test::assert(test::eq(result, expected));
	}

	void testVectorScalarMultiplicationAssignment() {
		const lyah::vec<4, std::int32_t> expected = {3, 12, 18, -3};
		const std::int32_t a = 3;
		lyah::vec<4, std::int32_t> result = {1, 4, 6, -1};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testVectorVectorMultiplication() {
		const lyah::vec<4, std::int32_t> expected = {5, 12, 12, -7};
		const lyah::vec<4, std::int32_t> a = {1, 4, 6, -1};
		const lyah::vec<4, std::int32_t> b = {5, 3, 2, 7};

		const lyah::vec<4, std::int32_t> result = a * b;

		test::assert(test::eq(result, expected));
	}

	void testVectorVectorMultiplicationAssignment() {
		const lyah::vec<4, std::int32_t> expected = {5, 12, 12, -7};
		const lyah::vec<4, std::int32_t> a = {5, 3, 2, 7};
		lyah::vec<4, std::int32_t> result = {1, 4, 6, -1};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void runAll() {
		test::printTestCategory("lyah::vec<4, std::int32_t> - 4-component 32-bit integer vector");

		test::runTest(&testDefaultConstructor, "Default constructor");
		test::runTest(&testComponentConstructor, "Component constructor");
		test::runTest(&testComponentBroadcastConstructor, "Component broadcast constructor");
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

		test::runTest(&testVectorScalarMultiplication, "Vector-scalar multiplication (*)");
		test::runTest(&testScalarVectorMultiplication, "Scalar-vector multiplication (*)");
		test::runTest(&testVectorScalarMultiplicationAssignment, "Vector-scalar multiplication assignment (*=)");
		test::runTest(&testVectorVectorMultiplication, "Vector-vector multiplication (*)");
		test::runTest(&testVectorVectorMultiplicationAssignment, "Vector-vector multiplication assignment (*=)");
	}
}