// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace lyah {
	/// A C-component vector of type T.
	template<std::size_t C, typename T>
	struct vec;

	/// A MxN row-major matrix of type T.
	/// M is the row count and N is the column count.
	template<std::size_t M, std::size_t N, typename T>
	struct mat;

	/// A quaternion of type T.
	template<typename T>
	struct quat;
}