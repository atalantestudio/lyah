// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace lyah {
	/// Returns a transformation matrix translated by `translation`.
	template<typename U, std::size_t C, typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR U LYAH_CALL translation(vec<C, T> translation);

	/// Returns a transformation matrix rotated by `angle`.
	template<typename U, typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 U LYAH_CALL rotationAngle(T angle);

	/// Returns a 4x4 transformation matrix or a quaternion, rotated by `angle` towards `axis`.
	/// `axis` must be normalized.
	/// `angle` must be in radians.
	template<typename U, typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 U LYAH_CALL rotationAxisAngle(vec<3, T> axis, T angle);

	/// Returns a transformation matrix scaled by `scale`.
	template<typename U, std::size_t C, typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR U LYAH_CALL scaling(vec<C, T> scale);

	/// Returns a transformation matrix scaled uniformly by `scale`.
	template<typename U, typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR U LYAH_CALL uniformScaling(T scale);

	/// Returns a left-handed look-at matrix.
	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 mat<4, 4, T> LYAH_CALL lookAt(vec<3, T> eye, vec<3, T> target, vec<3, T> up);
}