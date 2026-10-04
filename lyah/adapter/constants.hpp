// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace lyah {
	/// Returns the machine epsilon for type T.
	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL epsilon();

	/// Returns the positive infinity for type T.
	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL infinity();

	/// Returns the quiet NaN for type T.
	template<typename T>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL nan();

	/// Returns pi.
	template<typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL pi();

	/// Returns tau (2 * pi).
	template<typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL tau();
}