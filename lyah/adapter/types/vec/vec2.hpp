// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace lyah {
	/// A 2-dimensional vector of type T.
	template<typename T>
	struct vec<2, T> {
		/// Constructs a default-initialized 2-dimensional vector.
		LYAH_INLINE LYAH_CONSTEXPR vec();

		/// Constructs a 2-dimensional vector from individual components.
		LYAH_INLINE LYAH_CONSTEXPR vec(T x, T y);

		/// Constructs a 2-dimensional vector by broadcasting `x` to every component.
		LYAH_INLINE LYAH_CONSTEXPR explicit vec(T x);

		/// Constructs a 2-dimensional vector converted from `x`.
		template<typename U>
		LYAH_INLINE LYAH_CONSTEXPR explicit vec(vec<2, U> x);

		/// Returns the component at the provided index.
		/// `index` must be in [0, 2[.
		LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL operator[](std::size_t index) const;

		/// Returns the component at the provided index.
		/// `index` must be in [0, 2[.
		LYAH_NODISCARD LYAH_INLINE T& LYAH_CALL operator[](std::size_t index);

		T x;
		T y;
	};
}