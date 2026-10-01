// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

#include "lyah/base.hpp"

#include "lyah/adapter/vec.hpp"
#include "lyah/adapter/quat.hpp"
#include "lyah/adapter/mat.hpp"

#include "lyah/adapter/trigonometric.hpp"

namespace lyah {
	// TODO
	std::float_t fma(std::float_t a, std::float_t b, std::float_t c);
	std::double_t fma(std::double_t a, std::double_t b, std::double_t c);
}