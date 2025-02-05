#include <iostream>

#include <lyah/lyah.hpp>

int main() {
	std::cout << "test: " << lyah::pi<std::float_t>() << std::endl;
	std::cin.get();

	return 0;
}