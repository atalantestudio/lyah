// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace lyah {
	/// A C-dimensional vector of type T.
	template<std::size_t C, typename T>
	struct vec;

	/// A MxN row-major matrix of type T.
	template<std::size_t M, std::size_t N, typename T>
	struct mat;

	/// A quaternion of type T.
	template<typename T>
	struct quat;
}

#include "lyah/adapter/types/apply.hpp"
#include "lyah/adapter/types/vec.hpp"
#include "lyah/adapter/types/quat.hpp"
#include "lyah/adapter/types/mat.hpp"

#include "lyah/adapter/apply.hpp"
#include "lyah/adapter/common.hpp"
#include "lyah/adapter/constants.hpp"
#include "lyah/adapter/exponential.hpp"
#include "lyah/adapter/geometric.hpp"
#include "lyah/adapter/rounding.hpp"
#include "lyah/adapter/trigonometric.hpp"