// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

#include "lyah/mat/mat.hpp"

template<typename T>
struct lyah::mat<4, 4, T> {
	LYAH_INLINE LYAH_CONSTEXPR mat();

	LYAH_INLINE LYAH_CONSTEXPR mat(T m00, T m01, T m02, T m03, T m10, T m11, T m12, T m13, T m20, T m21, T m22, T m23, T m30, T m31, T m32, T m33);

	LYAH_INLINE LYAH_CONSTEXPR mat(vec<4, T> m0, vec<4, T> m1, vec<4, T> m2, vec<4, T> m3);

	/// Constructs a 4x4 matrix from `a`.
	/// `a` is assumed to be normalized.
	LYAH_INLINE mat(quat<T> a);

	template<typename U>
	LYAH_INLINE LYAH_CONSTEXPR explicit mat(mat<4, 4, U> a);

	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR const vec<4, T>& LYAH_CALL operator[](std::size_t index) const;

	LYAH_NODISCARD LYAH_INLINE vec<4, T>& LYAH_CALL operator[](std::size_t index);

	vec<4, T> m[4];
};

template struct lyah::mat<4, 4, std::float_t>;
template struct lyah::mat<4, 4, std::double_t>;

#include "lyah/mat/mat4x4.ipp"