// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace lyah {
	/// A quaternion of type T.
	template<typename T>
	struct quat {
		/// Constructs a default-initialized quaternion.
		LYAH_INLINE LYAH_CONSTEXPR quat();

		/// Constructs a quaternion from individual components.
		LYAH_INLINE LYAH_CONSTEXPR quat(T w, T x, T y, T z);

		/// Constructs a quaternion converted from `q`.
		template<typename U>
		LYAH_INLINE LYAH_CONSTEXPR explicit quat(quat<U> q);

		/// Converts the quaternion to a 3x3 rotation matrix.
		/// The quaternion is assumed to be normalized.
		LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR LYAH_CALL operator mat<3, 3, T>() const;

		/// Converts the quaternion to a 4x4 transformation matrix.
		/// The quaternion is assumed to be normalized.
		LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR LYAH_CALL operator mat<4, 4, T>() const;

		/// Returns the component at the provided index.
		/// `index` must be in [0, 4[.
		LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL operator[](std::size_t index) const;

		/// Returns the component at the provided index.
		/// `index` must be in [0, 4[.
		LYAH_NODISCARD LYAH_INLINE T& LYAH_CALL operator[](std::size_t index);

		T w;
		T x;
		T y;
		T z;
	};
}