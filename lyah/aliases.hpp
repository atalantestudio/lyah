// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

#pragma once

namespace lyah {
	template<typename T>
	using mat2x2 = mat<2, 2, T>;

	template<typename T>
	using mat3x3 = mat<3, 3, T>;

	template<typename T>
	using mat4x4 = mat<4, 4, T>;

	template<typename T>
	using vec2 = vec<2, T>;

	template<typename T>
	using vec3 = vec<3, T>;

	template<typename T>
	using vec4 = vec<4, T>;
}