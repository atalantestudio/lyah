// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#include "pch.hpp"

int main() {
	std::random_device device;
	std::mt19937 engine(device());

	std::cout << "\033[0;2mStarting tests...\033[0m\n\n";

	TestGroup<std::float_t>::runTests(engine);
	TestGroup<std::double_t>::runTests(engine);

	TestGroup<lyah::vec<2, std::float_t>>::runTests(engine);
	TestGroup<lyah::vec<2, std::double_t>>::runTests(engine);

	TestGroup<lyah::quat<std::float_t>>::runTests(engine);
	TestGroup<lyah::quat<std::double_t>>::runTests(engine);

	return 0;
}