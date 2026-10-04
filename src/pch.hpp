// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <sstream>

#include <lyah/lyah.hpp>

#define GLM_FORCE_CTOR_INIT
#define GLM_ENABLE_EXPERIMENTAL
#define GLM_FORCE_QUAT_DATA_WXYZ

#include <glm/glm.hpp>
#include <glm/gtx/compatibility.hpp>
#include <glm/gtx/norm.hpp>
#include <glm/gtx/perpendicular.hpp>

#include "glm_adapter/adapter.hpp"
#include "glm_adapter/serialization.hpp"
#include "glm_adapter/common.hpp"
#include "glm_adapter/scalar.hpp"
#include "glm_adapter/vec2.hpp"

#include "test/Generator/Generator.hpp"
#include "test/ClassTest.hpp"