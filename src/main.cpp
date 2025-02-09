#include "pch.hpp"

#include "test/constants.hpp"
#include "test/mat2x2_m128.hpp"
#include "test/mat2x2_m128d.hpp"
#include "test/mat3x3_m128.hpp"
#include "test/mat3x3_m256d.hpp"
#include "test/mat4x4_m128.hpp"
#include "test/mat4x4_m256d.hpp"
#include "test/scalar_common.hpp"
#include "test/scalar_exponential.hpp"
#include "test/scalar_trigonometric.hpp"
#include "test/vec2_m128.hpp"
#include "test/vec2_m128d.hpp"
#include "test/vec3_m128.hpp"
#include "test/vec3_m256d.hpp"
#include "test/vec4_m128.hpp"
#include "test/vec4_m256d.hpp"

int main() {
	test::Logger::initialize();

	constants::runAll();

	scalar_common::runAll();
	scalar_exponential::runAll();
	scalar_trigonometric::runAll();

	vec2_m128::runAll();
	vec2_m128d::runAll();
	vec3_m128::runAll();
	vec3_m256d::runAll();
	vec4_m128::runAll();
	vec4_m256d::runAll();

	mat2x2_m128::runAll();
	mat2x2_m128d::runAll();
	mat3x3_m128::runAll();
	mat3x3_m256d::runAll();
	mat4x4_m128::runAll();
	mat4x4_m256d::runAll();

	INFO("All tests passed.");

	return 0;
}