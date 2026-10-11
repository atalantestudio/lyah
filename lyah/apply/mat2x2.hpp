// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

template<typename T>
struct lyah::apply<lyah::mat<2, 2, T>> {
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR static mat<2, 2, T> LYAH_CALL identity();

	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 static mat<2, 2, T> LYAH_CALL rotationAngle(T angle);
};

#include "lyah/apply/mat2x2.ipp"