#include "pch.hpp"

#include "test/constants.hpp"
#include "test/vec2_m128.hpp"
#include "test/vec3_m128.hpp"
#include "test/vec4_m128.hpp"

int main() {
	test::Logger::initialize();

	constants::runAll();
	vec2_m128::runAll();
	vec3_m128::runAll();
	vec4_m128::runAll();

	return 0;
}