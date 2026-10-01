// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace lyah {
	/// A MxN row-major matrix of type T.
	/// M is the row count and N is the column count.
	template<std::size_t M, std::size_t N, typename T>
	struct mat;

	/// A 2x2 single floating point matrix.
	template<>
	struct mat<2, 2, std::float_t>;

	/// A 3x3 single floating point matrix.
	template<>
	struct mat<3, 3, std::float_t>;

	/// A 4x4 single floating point matrix.
	template<>
	struct mat<4, 4, std::float_t>;

	/// A 2x2 double floating point matrix.
	template<>
	struct mat<2, 2, std::double_t>;

	/// A 3x3 double floating point matrix.
	template<>
	struct mat<3, 3, std::double_t>;

	/// A 4x4 double floating point matrix.
	template<>
	struct mat<4, 4, std::double_t>;
}