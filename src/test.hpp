#pragma once

#undef assert

namespace test {
	void printTestCategory(std::string_view name);

	void runTest(void (*test)(), std::string_view name);

	inline void assert(bool condition) {
		ASSERT(condition, "Assertion failed");
	}

	inline bool eq(bool a, bool b) {
		return a == b;
	}

	template<typename T>
	inline bool eq(T a, T b, T precision = 0) {
		return std::abs(a - b) <= precision;
	}

	template<typename T>
	inline bool eq(const T* a, const T* b, T precision = 0) {
		for (std::size_t i = 0; i < 4; i++) {
			if (std::abs(a[i] - b[i]) > precision) {
				return false;
			}
		}

		return true;
	}
}