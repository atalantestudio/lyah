// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace lyah {
	/// Returns a 3x3 orthographic projection matrix with top-left origin.
	template<typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR mat<3, 3, T> LYAH_CALL orthographicTopLeft(vec<2, T> viewport);

	/// Returns a 4x4 orthographic projection matrix.
	template<typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR mat<4, 4, T> LYAH_CALL orthographic(T left, T right, T bottom, T top, T near, T far);

	/// Returns a 4x4 perspective projection matrix.
	template<typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 mat<4, 4, T> LYAH_CALL perspective(
		/// Vertical field of view in radians.
		T fieldOfView,

		T aspectRatio,
		T nearPlane,
		T farPlane,

		/// Coordinate system sign. 1 for left-handed and -1 for right-handed.
		T C
	);

	/// Returns a 4x4 Reversed-Z perspective projection matrix (flips the depth and defines an infinite far plane).
	/// See https://nlguillemot.wordpress.com/2016/12/07/reversed-z-in-opengl.
	template<typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 mat<4, 4, T> LYAH_CALL perspectiveReversedZ(
		/// Vertical field of view in radians.
		T fieldOfView,

		T aspectRatio,
		T nearPlane,

		/// Coordinate system sign. 1 for left-handed and -1 for right-handed.
		T C
	);
}