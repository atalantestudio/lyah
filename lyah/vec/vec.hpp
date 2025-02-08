#pragma once

#include "base.hpp"

namespace lyah {
	// fwd
	template<std::size_t R, std::size_t C, typename T>
	struct mat;

	// fwd
	template<typename T>
	struct quat;

	// A C-component vector.
	template<std::size_t C, typename T>
	struct vec;
}

#include "vec/vec.inl"