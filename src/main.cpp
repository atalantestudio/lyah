#include "pch.hpp"

int main() {
	test::Logger::initialize();

	INFO("test: []", lyah::pi<std::float_t>());

	std::cin.get();

	return 0;
}