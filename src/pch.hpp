// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <sstream>

#include <lyah/lyah.hpp>
#include <lyah/common.hpp>
#include <lyah/constants.hpp>
#include <lyah/exponential.hpp>
#include <lyah/geometric.hpp>
#include <lyah/rounding.hpp>
#include <lyah/transformation.hpp>

#define GLM_FORCE_CTOR_INIT
#define GLM_ENABLE_EXPERIMENTAL
#define GLM_FORCE_QUAT_DATA_WXYZ

#include <glm/glm.hpp>
#include <glm/gtc/round.hpp>
#include <glm/gtx/compatibility.hpp>
#include <glm/gtx/matrix_operation.hpp>
#include <glm/gtx/matrix_transform_2d.hpp>
#include <glm/gtx/norm.hpp>
#include <glm/gtx/perpendicular.hpp>

#include "Adapter/adapter.hpp"
#include "Generator/Generator.hpp"
#include "TestGroup.hpp"