#include "pch.hpp"

#include "test/constants.hpp"
#include "test/vec2_m128.hpp"

int main() {
	test::Logger::initialize();

	constants::runAll();
	vec2_m128::runAll();

	return 0;
}