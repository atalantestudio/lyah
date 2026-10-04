// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

#include "lyah/mat/mat.hpp"

template<typename T>
struct lyah::mat<2, 2, T> {
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR static mat<2, 2, T> LYAH_CALL identity();

	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 static mat<2, 2, T> LYAH_CALL rotation(T a);

	LYAH_INLINE LYAH_CONSTEXPR mat();

	LYAH_INLINE LYAH_CONSTEXPR mat(T m00, T m01, T m10, T m11);

	LYAH_INLINE LYAH_CONSTEXPR mat(vec<2, T> m0, vec<2, T> m1);

	template<typename U>
	LYAH_INLINE LYAH_CONSTEXPR explicit mat(mat<2, 2, U> a);

	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<2, T> LYAH_CALL operator[](std::size_t index) const;

	LYAH_NODISCARD LYAH_INLINE vec<2, T>& LYAH_CALL operator[](std::size_t index);

	vec<2, T> m[2];
};

template struct lyah::mat<2, 2, std::float_t>;
template struct lyah::mat<2, 2, std::double_t>;

#include "lyah/mat/mat2x2.ipp"