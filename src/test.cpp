#include "pch.hpp"

#include "test.hpp"

namespace test {
	static std::int32_t passedTestCount = 0;

	void printTestCategory(std::string_view name) {
		const std::string border(name.length() + 2, '=');

		TRACE("[]\n []\n[]\n", border, name, border);
	}

	void runTest(void (*test)(), std::string_view name) {
		const std::string border(name.length(), '-');

		TRACE("[]\n[]\n", name, border);

		test();

		passedTestCount += 1;
	}

	void summary() {
		INFO("[] tests passed.", passedTestCount);
	}
}