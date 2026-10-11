// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

template<typename T>
struct lyah::apply<lyah::mat<3, 3, T>> {
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR static mat<3, 3, T> LYAH_CALL identity();

	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR static mat<3, 3, T> LYAH_CALL translation(vec<2, T> translation);

	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 static mat<3, 3, T> LYAH_CALL rotationAngle(T angle);

	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR static mat<3, 3, T> LYAH_CALL scaling(vec<2, T> scale);

	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR static mat<3, 3, T> LYAH_CALL uniformScaling(T scale);
};

#include "lyah/apply/mat3x3.ipp"