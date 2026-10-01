// Copyright 2025 Atalante Studio.
// Distributed under the MIT License.

#pragma once

#include "lyah/base.hpp"

namespace lyah {
	template<typename T/*, typename std::enable_if<std::is_same<T, std::float_t>::value || std::is_same<T, std::double_t>::value, T>::type*/>
	struct quat {
		LYAH_NODISCARD static quat<T> LYAH_CALL identity();

		LYAH_NODISCARD static quat<T> LYAH_CALL axisAngle(vec<3, T> axis, T angle);

		LYAH_NODISCARD quat();

		LYAH_NODISCARD quat(T w, T x, T y, T z);

		template<typename U>
		LYAH_NODISCARD explicit quat(quat<U> a);

		LYAH_NODISCARD T LYAH_CALL operator[](std::size_t index) const LYAH_NOEXCEPT;

		LYAH_NODISCARD T& LYAH_CALL operator[](std::size_t index) LYAH_NOEXCEPT;

		T w;
		T x;
		T y;
		T z;
	};
}

#include "lyah/quat/quat.ipp"