#include "pch.hpp"

#include "test/constants.hpp"
#include "test/vec2_m128.hpp"
#include "test/vec2_m128d.hpp"
#include "test/vec3_m128.hpp"
#include "test/vec3_m256d.hpp"
#include "test/vec4_m128.hpp"

int main() {
	test::Logger::initialize();

	constants::runAll();
	vec2_m128::runAll();
	vec2_m128d::runAll();
	vec3_m128::runAll();
	vec3_m256d::runAll();
	vec4_m128::runAll();

	return 0;
}