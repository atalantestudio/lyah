// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#include "pch.hpp"

void ClassTest::logStart() {
	std::cout << "\033[0;2mStarting tests...\033[0m\n\n";
}

void ClassTest::logTestName(const char* className, const char* testName) {
	std::cout << "\033[0;1m" << className << " - " << testName << "\033[0m ";
}

void ClassTest::logFailed() {
	std::cout << "\033[101;97m FAILED \033[0m\n";
}

void ClassTest::logPassed() {
	std::cout << "\033[42;30m PASSED \033[0m\n";
}