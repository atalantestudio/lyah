#include "pch.hpp"

#include "test/constants.hpp"

int main() {
	test::Logger::initialize();

	constants::runAll();

	return 0;
}