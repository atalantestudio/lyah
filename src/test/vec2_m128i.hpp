#pragma once

#include "pch.hpp"

namespace vec2_m128i {
	void testDefaultConstructor() {
		const std::int64_t expected[2] = {0, 0};

		const lyah::vec<2, std::int64_t> result;

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
	}

	void testComponentConstructor() {
		const std::int64_t expected[2] = {1, 4};

		const lyah::vec<2, std::int64_t> result = {1, 4};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
	}

	void testComponentBroadcastConstructor() {
		const std::int64_t expected = 1;

		const lyah::vec<2, std::int64_t> result = lyah::vec<2, std::int64_t>(1);

		test::assert(test::eq(result[0], expected));
		test::assert(test::eq(result[1], expected));
	}

	void testSimdConstructor() {
		const lyah::vec<2, std::int64_t> expected = {1, 4};
		const __m128i m = _mm_set_epi64x(4, 1);

		const lyah::vec<2, std::int64_t> result(m);

		test::assert(test::eq(result, expected));
	}

	void testConvertingConstructor() {
		const lyah::vec<2, std::int64_t> expected = {1, 4};

		// There is no vec<2, std::int32_t> type.
		const lyah::vec<2, std::float_t> a = {1.0f, 4.0f};

		const lyah::vec<2, std::int64_t> result(a);

		test::assert(test::eq(result, expected));
	}

	void testEquality() {
		const bool expected[2] = {true, false};
		const lyah::vec<2, std::int64_t> a = {1, 4};
		const lyah::vec<2, std::int64_t> b = {1, 0};

		const bool result[2] = {a == a, a == b};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
	}

	void testInequality() {
		const bool expected[2] = {false, true};
		const lyah::vec<2, std::int64_t> a = {1, 4};
		const lyah::vec<2, std::int64_t> b = {1, 0};

		const bool result[2] = {a != a, a != b};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
	}

	void testUnaryPlus() {
		const lyah::vec<2, std::int64_t> expected = {1, 4};
		const lyah::vec<2, std::int64_t> a = {1, 4};

		const lyah::vec<2, std::int64_t> result = +a;

		test::assert(test::eq(result, expected));
	}

	void testUnaryMinus() {
		const lyah::vec<2, std::int64_t> expected = {-1, -4};
		const lyah::vec<2, std::int64_t> a = {1, 4};

		const lyah::vec<2, std::int64_t> result = -a;

		test::assert(test::eq(result, expected));
	}

	void testAddition() {
		const lyah::vec<2, std::int64_t> expected = {6, 7};
		const lyah::vec<2, std::int64_t> a = {1, 4};
		const lyah::vec<2, std::int64_t> b = {5, 3};

		const lyah::vec<2, std::int64_t> result = a + b;

		test::assert(test::eq(result, expected));
	}

	void testAdditionAssignment() {
		const lyah::vec<2, std::int64_t> expected = {6, 7};
		const lyah::vec<2, std::int64_t> a = {5, 3};
		lyah::vec<2, std::int64_t> result = {1, 4};

		result += a;

		test::assert(test::eq(result, expected));
	}

	void testSubtraction() {
		const lyah::vec<2, std::int64_t> expected = {-4, 1};
		const lyah::vec<2, std::int64_t> a = {1, 4};
		const lyah::vec<2, std::int64_t> b = {5, 3};

		const lyah::vec<2, std::int64_t> result = a - b;

		test::assert(test::eq(result, expected));
	}

	void testSubtractionAssignment() {
		const lyah::vec<2, std::int64_t> expected = {-4, 1};
		const lyah::vec<2, std::int64_t> a = {5, 3};
		lyah::vec<2, std::int64_t> result = {1, 4};

		result -= a;

		test::assert(test::eq(result, expected));
	}

	void testVectorScalarMultiplication() {
		const lyah::vec<2, std::int64_t> expected = {3, 12};
		const lyah::vec<2, std::int64_t> a = {1, 4};
		const std::int64_t b = 3;

		const lyah::vec<2, std::int64_t> result = a * b;

		test::assert(test::eq(result, expected));
	}

	void testScalarVectorMultiplication() {
		const lyah::vec<2, std::int64_t> expected = {3, 12};
		const lyah::vec<2, std::int64_t> a = {1, 4};
		const std::int64_t b = 3;

		const lyah::vec<2, std::int64_t> result = b * a;

		test::assert(test::eq(result, expected));
	}

	void testVectorScalarMultiplicationAssignment() {
		const lyah::vec<2, std::int64_t> expected = {3, 12};
		const std::int64_t a = 3;
		lyah::vec<2, std::int64_t> result = {1, 4};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testVectorVectorMultiplication() {
		const lyah::vec<2, std::int64_t> expected = {5, 12};
		const lyah::vec<2, std::int64_t> a = {1, 4};
		const lyah::vec<2, std::int64_t> b = {5, 3};

		const lyah::vec<2, std::int64_t> result = a * b;

		test::assert(test::eq(result, expected));
	}

	void testVectorVectorMultiplicationAssignment() {
		const lyah::vec<2, std::int64_t> expected = {5, 12};
		const lyah::vec<2, std::int64_t> a = {5, 3};
		lyah::vec<2, std::int64_t> result = {1, 4};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void runAll() {
		test::printTestCategory("lyah::vec<2, std::int64_t> - 2-component 64-bit integer vector");

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