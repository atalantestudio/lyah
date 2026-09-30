// Copyright 2025 Atalante Studio.
// Distributed under the MIT License.

#pragma once

#include "lyah/base.hpp"

namespace lyah {
	/// A MxN row-major matrix.
	/// M is the row count and N is the column count.
	template<std::size_t M, std::size_t N, typename T>
	struct mat;
}

#include "lyah/mat/mat.ipp"
#include "lyah/mat/matMx2.ipp"
#include "lyah/mat/matMx3.ipp"
#include "lyah/mat/matMx4.ipp"