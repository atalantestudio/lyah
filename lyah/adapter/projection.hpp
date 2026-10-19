// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace lyah {
	/// Returns a 3x3 orthographic projection matrix with Y pointing upwards.
	/// `origin` adds an offset to the center of the viewport.
	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR mat<3, 3, T> LYAH_CALL orthographic(vec<2, T> origin, vec<2, T> viewport);

	/// Returns a 3x3 orthographic projection matrix with the origin at the top-left corner of the viewport and Y pointing downwards.
	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR mat<3, 3, T> LYAH_CALL orthographicScreen(vec<2, T> viewport);

	/// Returns a 4x4 orthographic projection matrix.
	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR mat<4, 4, T> LYAH_CALL orthographic(T left, T right, T bottom, T top, T near, T far);

	/// Returns a 4x4 perspective projection matrix.
	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 mat<4, 4, T> LYAH_CALL perspective(
		/// Vertical field of view in radians.
		T fieldOfView,

		/// Must be positive.
		T aspectRatio,

		/// Must be positive.
		T nearPlane,

		/// Must be larger than the near plane.
		T farPlane
	);

	/// Returns a 4x4 Reversed-Z perspective projection matrix (flips the depth and defines an infinite far plane).
	/// See https://nlguillemot.wordpress.com/2016/12/07/reversed-z-in-opengl.
	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 mat<4, 4, T> LYAH_CALL perspectiveReversedZ(
		/// Vertical field of view in radians.
		T fieldOfView,

		/// Must be positive.
		T aspectRatio,

		/// Must be positive.
		T nearPlane
	);
}