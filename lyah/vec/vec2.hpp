// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

template<typename T>
struct lyah::vec<2, T> {
	LYAH_INLINE LYAH_CONSTEXPR vec();

	LYAH_INLINE LYAH_CONSTEXPR vec(T x, T y);

	LYAH_INLINE LYAH_CONSTEXPR explicit vec(T a);

	template<typename U>
	LYAH_INLINE LYAH_CONSTEXPR explicit vec(vec<2, U> a);

	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL operator[](std::size_t index) const;

	LYAH_NODISCARD LYAH_INLINE T& LYAH_CALL operator[](std::size_t index);

	T x;
	T y;
};

template struct lyah::vec<2, std::float_t>;
template struct lyah::vec<2, std::double_t>;
template struct lyah::vec<2, std::int32_t>;
template struct lyah::vec<2, std::int64_t>;
template struct lyah::vec<2, std::uint32_t>;
template struct lyah::vec<2, std::uint64_t>;

#include "lyah/vec/vec2.ipp"