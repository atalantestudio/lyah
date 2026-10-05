// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace lyah {
	template<typename T>
	struct apply;
}

template<typename T>
struct lyah::apply<lyah::vec<2, T>> {
	LYAH_NODISCARD LYAH_INLINE static vec<2, T> LYAH_CALL modifier(vec<2, T> x, T (*modifier)(T));
	LYAH_NODISCARD LYAH_INLINE static vec<2, T> LYAH_CALL modifier(vec<2, T> x, T y, T (*modifier)(T, T));
	LYAH_NODISCARD LYAH_INLINE static vec<2, T> LYAH_CALL modifier(vec<2, T> x, vec<2, T> y, T (*modifier)(T, T));
};

template<typename T>
struct lyah::apply<lyah::vec<3, T>> {
	LYAH_NODISCARD LYAH_INLINE static vec<3, T> LYAH_CALL modifier(vec<3, T> x, T (*modifier)(T));
	LYAH_NODISCARD LYAH_INLINE static vec<3, T> LYAH_CALL modifier(vec<3, T> x, T y, T (*modifier)(T, T));
	LYAH_NODISCARD LYAH_INLINE static vec<3, T> LYAH_CALL modifier(vec<3, T> x, vec<3, T> y, T (*modifier)(T, T));
};

template<typename T>
struct lyah::apply<lyah::vec<4, T>> {
	LYAH_NODISCARD LYAH_INLINE static vec<4, T> LYAH_CALL modifier(vec<4, T> x, T (*modifier)(T));
	LYAH_NODISCARD LYAH_INLINE static vec<4, T> LYAH_CALL modifier(vec<4, T> x, T y, T (*modifier)(T, T));
	LYAH_NODISCARD LYAH_INLINE static vec<4, T> LYAH_CALL modifier(vec<4, T> x, vec<4, T> y, T (*modifier)(T, T));
};

template<typename T>
struct lyah::apply<lyah::mat<2, 2, T>> {
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR static mat<2, 2, T> LYAH_CALL identity();
};

template<typename T>
struct lyah::apply<lyah::mat<3, 3, T>> {
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR static mat<3, 3, T> LYAH_CALL identity();
};

template<typename T>
struct lyah::apply<lyah::mat<4, 4, T>> {
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR static mat<4, 4, T> LYAH_CALL identity();
};

template<typename T>
struct lyah::apply<lyah::quat<T>> {
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR static quat<T> LYAH_CALL identity();
};

#include "lyah/apply/apply.ipp"