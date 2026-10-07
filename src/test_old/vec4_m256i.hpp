#pragma once

#include "pch.hpp"

namespace vec4_m256i {
	void testDefaultConstructor() {
		const std::int64_t expected[4] = {0, 0, 0, 0};

		const lyah::vec<4, std::int64_t> result;

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
		test::assert(test::eq(result[2], expected[2]));
		test::assert(test::eq(result[3], expected[3]));
	}

	void testComponentConstructor() {
		const std::int64_t expected[4] = {1, 4, 6, -1};

		const lyah::vec<4, std::int64_t> result = {1, 4, 6, -1};

		test::assert(test::eq(result[0], expected[0]));
		test::assert(test::eq(result[1], expected[1]));
		test::assert(test::eq(result[2], expected[2]));
		test::assert(test::eq(result[3], expected[3]));
	}

	void testComponentBroadcastConstructor() {
		const std::int64_t expected = 1;

		const lyah::vec<4, std::int64_t> result = lyah::vec<4, std::int64_t>(1);

		test::assert(test::eq(result[0], expected));
		test::assert(test::eq(result[1], expected));
		test::assert(test::eq(result[2], expected));
		test::assert(test::eq(result[3], expected));
	}

	void testConvertingConstructor() {
		const lyah::vec<4, std::int64_t> expected = {1, 4, 6, -1};
		const lyah::vec<4, std::int32_t> a = {1, 4, 6, -1};

		const lyah::vec<4, std::int64_t> result(a);

		test::assert(test::eq(result, expected));
	}

	void testAdditionAssignment() {
		const lyah::vec<4, std::int64_t> expected = {6, 7, 8, 3};
		const lyah::vec<4, std::int64_t> a = {5, 3, 2, 4};
		lyah::vec<4, std::int64_t> result = {1, 4, 6, -1};

		result += a;

		test::assert(test::eq(result, expected));
	}

	void testSubtractionAssignment() {
		const lyah::vec<4, std::int64_t> expected = {-4, 1, 4, -8};
		const lyah::vec<4, std::int64_t> a = {5, 3, 2, 7};
		lyah::vec<4, std::int64_t> result = {1, 4, 6, -1};

		result -= a;

		test::assert(test::eq(result, expected));
	}

	void testVectorScalarMultiplicationAssignment() {
		const lyah::vec<4, std::int64_t> expected = {3, 12, 18, -3};
		const std::int64_t a = 3;
		lyah::vec<4, std::int64_t> result = {1, 4, 6, -1};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testVectorVectorMultiplicationAssignment() {
		const lyah::vec<4, std::int64_t> expected = {5, 12, 12, -7};
		const lyah::vec<4, std::int64_t> a = {5, 3, 2, 7};
		lyah::vec<4, std::int64_t> result = {1, 4, 6, -1};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void runAll() {
		test::printTestCategory("lyah::vec<4, std::int64_t> - 4-component 64-bit integer vector");

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