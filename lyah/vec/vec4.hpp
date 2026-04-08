// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

#pragma once

#include "lyah/vec/vec.hpp"
#include "lyah/convert.hpp"
#include "lyah/types.hpp"

namespace lyah {
	template<typename T>
	struct vec<4, T> {
		public:
			using __m_t = typename internal::vec_t<4, T>::m_t;

		public:
			LYAH_NODISCARD vec();
			LYAH_NODISCARD vec(T x, T y, T z, T w);
			LYAH_NODISCARD explicit vec(T a);

			LYAH_NODISCARD LYAH_INLINE explicit vec(__m_t m) :
				m(m)
			{}

			template<typename U>
			LYAH_NODISCARD explicit vec(vec<4, U> a) : m(internal::convert<typename vec<4, U>::__m_t, __m_t>(a.m)) {}

			LYAH_NODISCARD T LYAH_CALL operator [](std::size_t index) const LYAH_NOEXCEPT;

		public:
			__m_t m;
	};
}

#include "lyah/vec/vec4_m128.ipp"
#include "lyah/vec/vec4_m128i.ipp"
#include "lyah/vec/vec4_m256d.ipp"
#include "lyah/vec/vec4_m256i.ipp"