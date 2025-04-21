// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

#pragma once

#include "base.hpp"

namespace lyah {
	// A RxC row-major matrix.
	template<std::size_t R, std::size_t C, typename T>
	struct mat;
}

#include "mat/mat.ipp"