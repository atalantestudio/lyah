// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace lyah {
	/// A 2x2 row-major matrix of type T.
	template<typename T>
	struct mat<2, 2, T> {
		/// Constructs a default-initialized 2x2 matrix.
		LYAH_INLINE LYAH_CONSTEXPR mat();

		/// Constructs a 2x2 matrix from individual components.
		LYAH_INLINE LYAH_CONSTEXPR mat(T m00, T m01, T m10, T m11);

		/// Constructs a 2x2 matrix from individual row vectors.
		LYAH_INLINE LYAH_CONSTEXPR mat(vec<2, T> m0, vec<2, T> m1);

		/// Constructs a 2x2 matrix converted from `A`.
		template<typename U>
		LYAH_INLINE LYAH_CONSTEXPR explicit mat(mat<2, 2, U> A);

		/// Returns the row vector at the provided index.
		/// `index` must be in [0, 2[.
		LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<2, T> LYAH_CALL operator[](std::size_t index) const;

		/// Returns the row vector at the provided index.
		/// `index` must be in [0, 2[.
		LYAH_NODISCARD LYAH_INLINE vec<2, T>& LYAH_CALL operator[](std::size_t index);

		vec<2, T> m[2];
	};
}