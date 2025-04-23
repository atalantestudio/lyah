#include "pch.hpp"

#include "test/constants.hpp"
#include "test/float32_common.hpp"
#include "test/float32_exponential.hpp"
#include "test/float32_trigonometric.hpp"
#include "test/float64_common.hpp"
#include "test/float64_exponential.hpp"
#include "test/float64_trigonometric.hpp"
#include "test/int32_common.hpp"
#include "test/int64_common.hpp"
#include "test/mat2x2_m128.hpp"
#include "test/mat2x2_m128d.hpp"
#include "test/mat3x3_m128.hpp"
#include "test/mat3x3_m256d.hpp"
#include "test/mat4x4_m128.hpp"
#include "test/mat4x4_m256d.hpp"
#include "test/quat_m128.hpp"
#include "test/quat_m256d.hpp"
#include "test/vec2_m128.hpp"
#include "test/vec2_m128d.hpp"
#include "test/vec2_m128i.hpp"
#include "test/vec3_m128.hpp"
#include "test/vec3_m256d.hpp"
#include "test/vec4_m128.hpp"
#include "test/vec4_m128i.hpp"
#include "test/vec4_m256d.hpp"
#include "test/vec4_m256i.hpp"

int main() {
	test::Logger::initialize();

	constants::runAll();

	int32_common::runAll();
	int64_common::runAll();
	float32_common::runAll();
	float64_common::runAll();
	float32_exponential::runAll();
	float64_exponential::runAll();
	float32_trigonometric::runAll();
	float64_trigonometric::runAll();

	vec2_m128::runAll();
	vec2_m128d::runAll();
	vec2_m128i::runAll();
	vec3_m128::runAll();
	vec3_m256d::runAll();
	vec4_m128::runAll();
	vec4_m128i::runAll();
	vec4_m256d::runAll();
	vec4_m256i::runAll();

	quat_m128::runAll();
	quat_m256d::runAll();

	mat2x2_m128::runAll();
	mat2x2_m128d::runAll();
	mat3x3_m128::runAll();
	mat3x3_m256d::runAll();
	mat4x4_m128::runAll();
	mat4x4_m256d::runAll();

	test::summary();

	return 0;
}