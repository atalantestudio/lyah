// Copyright 2025 Atalante Studio.
// Distributed under the MIT License.

#pragma once

#include "lyah/base.hpp"
#include "lyah/convert.hpp"
#include "lyah/types.hpp"

namespace lyah {
	template<typename T>
	struct quat {
		public:
			using __m_t = typename internal::quat_t<T>::m_t;

		public:
			LYAH_NODISCARD static quat<T> LYAH_CALL identity();
			LYAH_NODISCARD static quat<T> LYAH_CALL axisAngle(vec<3, T> axis, T angle);

		public:
			LYAH_NODISCARD quat();
			LYAH_NODISCARD quat(T w, T x, T y, T z);

			LYAH_NODISCARD explicit quat(__m_t m);

			template<typename U>
			LYAH_NODISCARD explicit quat(quat<U> a);

			LYAH_NODISCARD T LYAH_CALL operator[](std::size_t index) const LYAH_NOEXCEPT;

			LYAH_NODISCARD T LYAH_CALL w() const;

			LYAH_NODISCARD vec<3, T> LYAH_CALL xyz() const;

		public:
			__m_t m;
	};
}

#include "lyah/quat/quat.ipp"