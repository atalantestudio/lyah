#pragma once

#include "pch.hpp"

namespace quat_m256d {
	void testDefaultConstructor() {
		const std::double_t expected[4] = {0.0, 0.0, 0.0, 0.0};

		const lyah::quat<std::double_t> result;

		for (std::size_t i = 0; i < 4; i += 1) {
			test::assert(test::eq(result[i], expected[i]));
		}
	}

	void testComponentConstructor() {
		const std::double_t expected[4] = {1.0, 4.0, 6.0, -1.0};

		const lyah::quat<std::double_t> result = {1.0, 4.0, 6.0, -1.0};

		for (std::size_t i = 0; i < 4; i += 1) {
			test::assert(test::eq(result[i], expected[i]));
		}
	}

	void testConvertingConstructor() {
		const lyah::quat<std::double_t> expected = {1.0, 4.0, 6.0, -1.0};
		const lyah::quat<std::float_t> a = {1.0f, 4.0f, 6.0f, -1.0f};

		const lyah::quat<std::double_t> result(a);

		test::assert(test::eq(result, expected));
	}

	void testAdditionAssignment() {
		const lyah::quat<std::double_t> expected = {6.0, 7.0, 8.0, 3.0};
		const lyah::quat<std::double_t> a = {5.0, 3.0, 2.0, 4.0};
		lyah::quat<std::double_t> result = {1.0, 4.0, 6.0, -1.0};

		result += a;

		test::assert(test::eq(result, expected));
	}

	void testSubtractionAssignment() {
		const lyah::quat<std::double_t> expected = {-4.0, 1.0, 4.0, -8.0};
		const lyah::quat<std::double_t> a = {5.0, 3.0, 2.0, 7.0};
		lyah::quat<std::double_t> result = {1.0, 4.0, 6.0, -1.0};

		result -= a;

		test::assert(test::eq(result, expected));
	}

	void testQuaternionScalarMultiplicationAssignment() {
		const lyah::quat<std::double_t> expected = {3.0, 12.0, 18.0, -3.0};
		const std::double_t a = 3.0;
		lyah::quat<std::double_t> result = {1.0, 4.0, 6.0, -1.0};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testQuaternionQuaternionMultiplicationAssignment() {
		const lyah::quat<std::double_t> expected = {-12.0, -21.0, 63.0, 12.0};
		const lyah::quat<std::double_t> a = {1.0, 4.0, 6.0, -1.0};
		lyah::quat<std::double_t> result = {5.0, 3.0, 2.0, 7.0};

		result *= a;

		test::assert(test::eq(result, expected));
	}

	void testQuaternionScalarDivisionAssignment() {
		const lyah::quat<std::double_t> expected = {0.333, 1.333, 2.0, -0.333};
		const std::double_t a = 3.0;
		lyah::quat<std::double_t> result = {1.0, 4.0, 6.0, -1.0};

		result /= a;

		test::assert(test::eq(result, expected, 0.001));
	}

	void testQuaternionQuaternionDivisionAssignment() {
		const lyah::quat<std::double_t> expected = {0.253, -0.310, 0.678, -0.023};
		const lyah::quat<std::double_t> a = {5.0, 3.0, 2.0, 7.0};
		lyah::quat<std::double_t> result = {1.0, 4.0, 6.0, -1.0};

		result /= a;

		test::assert(test::eq(result, expected, 0.001));
	}

	void runAll() {
		test::printTestCategory("lyah::quat<std::double_t> - Double floating-point quaternion");

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