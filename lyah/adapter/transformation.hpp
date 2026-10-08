// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace lyah {
	template<typename T, typename U>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL translation(U translation);

	/// Returns a 3x3 transformation matrix translated by `translation`.
	template<>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR mat<3, 3, std::float_t> LYAH_CALL translation(vec<2, std::float_t> translation);

	/// Returns a 3x3 transformation matrix translated by `translation`.
	template<>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR mat<3, 3, std::double_t> LYAH_CALL translation(vec<2, std::double_t> translation);

	/// Returns a 4x4 transformation matrix translated by `translation`.
	template<>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR mat<4, 4, std::float_t> LYAH_CALL translation(vec<3, std::float_t> translation);

	/// Returns a 4x4 transformation matrix translated by `translation`.
	template<>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR mat<4, 4, std::double_t> LYAH_CALL translation(vec<3, std::double_t> translation);

	template<typename T, typename U>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 T LYAH_CALL rotationAngle(U angle);

	/// Returns a 2x2 rotation matrix.
	/// `angle` must be in radians.
	template<>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 mat<2, 2, std::float_t> LYAH_CALL rotationAngle(std::float_t angle);

	/// Returns a 2x2 rotation matrix.
	/// `angle` must be in radians.
	template<>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 mat<2, 2, std::double_t> LYAH_CALL rotationAngle(std::double_t angle);

	/// Returns a 2x2 rotation matrix as part of a 3x3 transformation matrix.
	/// `angle` must be in radians.
	template<>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 mat<3, 3, std::float_t> LYAH_CALL rotationAngle(std::float_t angle);

	/// Returns a 2x2 rotation matrix as part of a 3x3 transformation matrix.
	/// `angle` must be in radians.
	template<>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 mat<3, 3, std::double_t> LYAH_CALL rotationAngle(std::double_t angle);

	// TODO: Improve documentation.
	// `axis` is assumed to be normalized.
	// `angle` is in radians.
	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 mat<4, 4, T> LYAH_CALL rotationAxisAngle(vec<3, T> axis, T angle);

	template<typename T, typename U>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL scaling(U scale);

	/// Returns a 3x3 transformation matrix scaled by `scale`.
	template<>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR mat<3, 3, std::float_t> LYAH_CALL scaling(vec<2, std::float_t> scale);

	/// Returns a 3x3 transformation matrix scaled by `scale`.
	template<>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR mat<3, 3, std::double_t> LYAH_CALL scaling(vec<2, std::double_t> scale);

	/// Returns a 4x4 transformation matrix scaled by `scale`.
	template<>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR mat<4, 4, std::float_t> LYAH_CALL scaling(vec<3, std::float_t> scale);

	/// Returns a 4x4 transformation matrix scaled by `scale`.
	template<>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR mat<4, 4, std::double_t> LYAH_CALL scaling(vec<3, std::double_t> scale);

	// TODO: Improve documentation.
	// Returns a left-handed matrix.
	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 mat<4, 4, T> LYAH_CALL lookAt(vec<3, T> eye, vec<3, T> target, vec<3, T> up);
}