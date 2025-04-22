// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

#pragma once

#include "base.hpp"

namespace lyah {
	// A MxN row-major matrix.
	// M is the row count.
	// N is the column count.
	template<std::size_t M, std::size_t N, typename T>
	struct mat;
}

#include "mat/mat.ipp"