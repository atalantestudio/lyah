// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

template<typename T>
struct lyah::apply<lyah::mat<4, 4, T>> {
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR static mat<4, 4, T> LYAH_CALL identity();

	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR static mat<4, 4, T> LYAH_CALL translation(vec<3, T> translation);

	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR static mat<4, 4, T> LYAH_CALL scaling(vec<3, T> scale);

	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR static mat<4, 4, T> LYAH_CALL uniformScaling(T scale);
};

#include "lyah/apply/mat4x4.ipp"