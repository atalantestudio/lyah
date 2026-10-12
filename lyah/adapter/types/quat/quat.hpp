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