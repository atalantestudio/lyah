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

	void testConvertingConstructor() {
		const lyah::vec<2, std::int64_t> expected = {1, 4};

		// There is no vec<2, std::int32_t> type.
		const lyah::vec<2, std::float_t> a = {1.0f, 4.0f};

		const lyah::vec<2, std::int64_t> result(a);

		test::assert(test::eq(result, expected));
	}

	void testAdditionAssignment() {
		const lyah::vec<2, std::int64_t> expected = {6, 7};
		const lyah::vec<2, std::int64_t> a = {5, 3};
		lyah::vec<2, std::int64_t> result = {1, 4};

		result += a;

		test::assert(test::eq(result, expected));
	}

	void testSubtractionAssignment() {
		const lyah::vec<2, std::int64_t> expected = {-4, 1};
		const lyah::vec<2, std::int64_t> a = {5, 3};
		lyah::vec<2, std::int64_t> result = {1, 4};

		result -= a;

		test::assert(test::eq(result, expected));
	}

	void testVectorScalarMultiplicationAssignment() {
		const lyah::vec<2, std::int64_t> expected = {3, 12};
		const std::int64_t a = 3;
		lyah::vec<2, std::int64_t> result = {1, 4};

		result *= a;

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
		test::runTest(&testConvertingConstructor, "Converting constructor");

		test::runTest(&testAdditionAssignment, "Addition assignment (+=)");
		test::runTest(&testSubtractionAssignment, "Subtraction assignment (-=)");
		test::runTest(&testVectorScalarMultiplicationAssignment, "Vector-scalar multiplication assignment (*=)");
		test::runTest(&testVectorVectorMultiplicationAssignment, "Vector-vector multiplication assignment (*=)");
	}
}