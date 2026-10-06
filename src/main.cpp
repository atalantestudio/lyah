// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#include "pch.hpp"

int main() {
	std::random_device device;
	std::mt19937 engine(device());

	std::cout << "\033[0;2mStarting tests...\033[0m\n\n";

	TestGroup<std::float_t>::runTests(engine);
	TestGroup<std::double_t>::runTests(engine);
	TestGroup<std::int32_t>::runTests(engine);
	TestGroup<std::int64_t>::runTests(engine);

	TestGroup<lyah::vec<2, std::float_t>>::runTests(engine);
	TestGroup<lyah::vec<2, std::double_t>>::runTests(engine);

	TestGroup<lyah::vec<3, std::float_t>>::runTests(engine);
	TestGroup<lyah::vec<3, std::double_t>>::runTests(engine);

	TestGroup<lyah::vec<4, std::float_t>>::runTests(engine);
	TestGroup<lyah::vec<4, std::double_t>>::runTests(engine);

	TestGroup<lyah::mat<2, 2, std::float_t>>::runTests(engine);
	TestGroup<lyah::mat<2, 2, std::double_t>>::runTests(engine);

	TestGroup<lyah::mat<3, 3, std::float_t>>::runTests(engine);
	TestGroup<lyah::mat<3, 3, std::double_t>>::runTests(engine);

	TestGroup<lyah::mat<4, 4, std::float_t>>::runTests(engine);
	TestGroup<lyah::mat<4, 4, std::double_t>>::runTests(engine);

	TestGroup<lyah::quat<std::float_t>>::runTests(engine);
	TestGroup<lyah::quat<std::double_t>>::runTests(engine);

	std::cout << "\033[0;2m" << TestCounter::passedTestCount << " passed, " << TestCounter::failedTestCount << " failed.\033[0m\n";

	return 0;
}