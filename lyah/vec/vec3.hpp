// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

#pragma once

#include "vec/vec.hpp"
#include "convert.hpp"
#include "types.hpp"

namespace lyah {
	template<typename T>
	struct vec<3, T> {
		using __m_t = typename internal::vec_t<3, T>::m_t;

		__m_t m;

		LYAH_NODISCARD vec();
		LYAH_NODISCARD vec(T x, T y, T z);
		LYAH_NODISCARD explicit vec(T a);

		LYAH_NODISCARD explicit vec(__m_t m) :
			m(m)
		{}

		template<typename U>
		LYAH_NODISCARD explicit vec(vec<3, U> a) : m(internal::convert<typename vec<3, U>::__m_t, __m_t>(a.m)) {}

		LYAH_NODISCARD T LYAH_CALL operator [](std::size_t index) const LYAH_NOEXCEPT;
	};
}

#include "vec/vec3_m128.ipp"
#include "vec/vec3_m256d.ipp"