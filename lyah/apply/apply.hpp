// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace lyah {
	template<std::size_t C, typename T>
	struct apply;
}

template<typename T>
struct lyah::apply<2, T> {
	LYAH_NODISCARD LYAH_INLINE static vec<2, T> LYAH_CALL modifier(vec<2, T> x, T (*modifier)(T));
	LYAH_NODISCARD LYAH_INLINE static vec<2, T> LYAH_CALL modifier(vec<2, T> x, T y, T (*modifier)(T, T));
	LYAH_NODISCARD LYAH_INLINE static vec<2, T> LYAH_CALL modifier(vec<2, T> x, vec<2, T> y, T (*modifier)(T, T));
};

template<typename T>
struct lyah::apply<3, T> {
	LYAH_NODISCARD LYAH_INLINE static vec<3, T> LYAH_CALL modifier(vec<3, T> x, T (*modifier)(T));
	LYAH_NODISCARD LYAH_INLINE static vec<3, T> LYAH_CALL modifier(vec<3, T> x, T y, T (*modifier)(T, T));
	LYAH_NODISCARD LYAH_INLINE static vec<3, T> LYAH_CALL modifier(vec<3, T> x, vec<3, T> y, T (*modifier)(T, T));
};

template<typename T>
struct lyah::apply<4, T> {
	LYAH_NODISCARD LYAH_INLINE static vec<4, T> LYAH_CALL modifier(vec<4, T> x, T (*modifier)(T));
	LYAH_NODISCARD LYAH_INLINE static vec<4, T> LYAH_CALL modifier(vec<4, T> x, T y, T (*modifier)(T, T));
	LYAH_NODISCARD LYAH_INLINE static vec<4, T> LYAH_CALL modifier(vec<4, T> x, vec<4, T> y, T (*modifier)(T, T));
};

#include "lyah/apply/apply.ipp"