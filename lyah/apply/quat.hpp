// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

template<typename T>
struct lyah::apply<lyah::quat<T>> {
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR static quat<T> LYAH_CALL identity();

	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 static quat<T> LYAH_CALL rotationAxisAngle(vec<3, T> axis, T angle);
};

#include "lyah/apply/quat.ipp"