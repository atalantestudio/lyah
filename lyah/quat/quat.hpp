// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

#pragma once

#include "base.hpp"
#include "convert.hpp"
#include "types.hpp"

namespace lyah {
	template<typename T>
	struct quat {
		using __m_t = typename internal::quat_t<T>::m_t;

		__m_t m;

		LYAH_NODISCARD static quat<T> LYAH_CALL identity();
		LYAH_NODISCARD static quat<T> LYAH_CALL axisAngle(vec<3, T> axis, T angle);

		LYAH_NODISCARD quat();
		LYAH_NODISCARD quat(T w, T x, T y, T z);

		LYAH_NODISCARD LYAH_CONSTEXPR explicit quat(__m_t m);

		template<typename U>
		LYAH_NODISCARD quat(quat<U> a);

		LYAH_NODISCARD T LYAH_CALL operator [](std::size_t index) const LYAH_NOEXCEPT;

		LYAH_NODISCARD T LYAH_CALL w() const;

		LYAH_NODISCARD vec<3, T> LYAH_CALL xyz() const;
	};
}

#include "quat/quat.ipp"