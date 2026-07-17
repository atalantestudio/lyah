// Copyright 2025 Atalante Studio.
// Distributed under the MIT License.

#pragma once

#include "lyah/vec/vec.hpp"
#include "lyah/convert.hpp"
#include "lyah/types.hpp"

namespace lyah {
	template<typename T>
	struct vec<3, T> {
		public:
			using __m_t = typename internal::vec_t<3, T>::m_t;

		public:
			LYAH_NODISCARD vec();
			LYAH_NODISCARD vec(T x, T y, T z);
			LYAH_NODISCARD explicit vec(T a);

			LYAH_NODISCARD explicit vec(__m_t m) :
				m(m)
			{}

			template<typename U>
			LYAH_NODISCARD explicit vec(vec<3, U> a) : m(internal::convert<typename vec<3, U>::__m_t, __m_t>(a.m)) {}

			LYAH_NODISCARD T LYAH_CALL operator [](std::size_t index) const LYAH_NOEXCEPT;

		public:
			__m_t m;
	};
}

#include "lyah/vec/vec3_m128.ipp"
#include "lyah/vec/vec3_m256d.ipp"