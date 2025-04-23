// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

#pragma once

namespace lyah {
	// fwd
	template<std::size_t M, std::size_t N, typename T>
	struct mat;

	// fwd
	template<typename T>
	struct quat;

	// A C-component vector.
	template<std::size_t C, typename T>
	struct vec;
}

#include "vec/vec.ipp"