// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace lyah {
	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR mat<3, 3, T> LYAH_CALL translation(vec<2, T> translation);

	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR mat<4, 4, T> LYAH_CALL translation(vec<3, T> translation);

	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 mat<2, 2, T> LYAH_CALL rotation(T angle);

	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 mat<3, 3, T> LYAH_CALL rotation(T angle);

	// TODO: Improve documentation.
	// `axis` is assumed to be normalized.
	// `angle` is in radians.
	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 mat<4, 4, T> LYAH_CALL rotation(vec<3, T> axis, T angle);

	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR mat<3, 3, T> LYAH_CALL scaling(vec<2, T> scale);

	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR mat<4, 4, T> LYAH_CALL scaling(vec<3, T> scale);

	// TODO: Improve documentation.
	// Returns a left-handed matrix.
	template<typename T, typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 mat<4, 4, T> LYAH_CALL lookAt(vec<3, T> eye, vec<3, T> target, vec<3, T> up);
}