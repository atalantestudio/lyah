#pragma once

#include "pch.hpp"

namespace quat_m128 {
	void testDefaultConstructor() {
		const std::float_t expected[4] = {0.0f, 0.0f, 0.0f, 0.0f};

		const lyah::quat<std::float_t> result;

		for (std::size_t i = 0; i < 4; i += 1) {
			test::assert(test::eq(result[i], expected[i]));
		}
	}

	void testComponentConstructor() {
		const std::float_t expected[4] = {1.0f, 4.0f, 6.0f, -1.0f};

		const lyah::quat<std::float_t> result = {1.0f, 4.0f, 6.0f, -1.0f};

		for (std::size_t i = 0; i < 4; i += 1) {
			test::assert(test::eq(result[i], expected[i]));
		}
	}

	void testConvertingConstructor() {
		const lyah::quat<std::float_t> expected = {1.0f, 4.0f, 6.0f, -1.0f};
		const lyah::quat<std::double_t> a = {1.0, 4.0, 6.0, -1.0};

		const lyah::quat<std::float_t> result(a);

		test::assert(test::eq(result, expected));
	}

	void testAdditionAssignment() {
		const lyah::quat<std::float_t> expected = {6.0f, 7.0f, 8.0f, 3.0f};
		const lyah::quat<std::float_t> a = {5.0f, 3.0f, 2.0f, 4.0f};
		lyah::quat<std::float_t> result = {1.0f, 4.0f, 6.0f, -1.0f};

		result += a;

		test::assert(test::eq(result, expected));
	}

	void testSubtractionAssignment() {
		const lyah::quat<std::float_t> expected = {-4.0f, 1.0f, 4.0f, -8.0f};
		const lyah::quat<std::float_t> a = {5.0f, 3.0f, 2.0f, 7.0f};
		lyah::quat<std::float_t> result = {1.0f, 4.0f, 6.0f, -1.0f};

		result -= a;

		test::assert(test::eq(result, expected));
	}

	void testQuaternionScalarMultiplicationAssignment() {
		const lyah::quat<std::float_t> expected = {3.0f, 12.0f, 18.0f, -3.0f};
		const std::float_t a = 3.0f;
		lyah::quat<std::float_t> result = {1.0f, 4.0f, 6.0f, -1.0f};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testQuaternionQuaternionMultiplicationAssignment() {
		const lyah::quat<std::float_t> expected = {-12.0f, -21.0f, 63.0f, 12.0f};
		const lyah::quat<std::float_t> a = {1.0f, 4.0f, 6.0f, -1.0f};
		lyah::quat<std::float_t> result = {5.0f, 3.0f, 2.0f, 7.0f};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testQuaternionScalarDivisionAssignment() {
		const lyah::quat<std::float_t> expected = {0.333f, 1.333f, 2.0f, -0.333f};
		const std::float_t a = 3.0f;
		lyah::quat<std::float_t> result = {1.0f, 4.0f, 6.0f, -1.0f};

		result /= a;

		test::assert(test::eq(result, expected, 0.001f));
	}

	void testQuaternionQuaternionDivisionAssignment() {
		const lyah::quat<std::float_t> expected = {0.253f, -0.310f, 0.678f, -0.023f};
		const lyah::quat<std::float_t> a = {5.0f, 3.0f, 2.0f, 7.0f};
		lyah::quat<std::float_t> result = {1.0f, 4.0f, 6.0f, -1.0f};

		result /= a;

		test::assert(test::eq(result, expected, 0.001f));
	}

	void runAll() {
		test::printTestCategory("lyah::quat<std::float_t> - Single floating-point quaternion");

		test::runTest(&testDefaultConstructor, "Default constructor");
		test::runTest(&testComponentConstructor, "Component constructor");
		test::runTest(&testConvertingConstructor, "Converting constructor");

		test::runTest(&testAdditionAssignment, "Addition assignment (+=)");
		test::runTest(&testSubtractionAssignment, "Subtraction assignment (-=)");
		test::runTest(&testQuaternionScalarMultiplicationAssignment, "Quaternion-scalar multiplication assignment (*=)");
		test::runTest(&testQuaternionQuaternionMultiplicationAssignment, "Quaternion-quaternion multiplication assignment (*=)");
		test::runTest(&testQuaternionScalarDivisionAssignment, "Quaternion-scalar division assignment (/=)");
		test::runTest(&testQuaternionQuaternionDivisionAssignment, "Quaternion-quaternion division assignment (/=)");
	}
}