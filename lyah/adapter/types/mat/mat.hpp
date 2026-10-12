// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace lyah {
	/// A MxN row-major matrix of type T.
	template<std::size_t M, std::size_t N, typename T>
	struct mat {
		vec<M, T> m[N];
	};
}