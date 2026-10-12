// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace lyah {
	/// A 3x3 row-major matrix of type T.
	template<typename T>
	struct mat<3, 3, T> {
		/// Constructs a default-initialized 3x3 matrix.
		LYAH_INLINE LYAH_CONSTEXPR mat();

		/// Constructs a 3x3 matrix from individual components.
		LYAH_INLINE LYAH_CONSTEXPR mat(T m00, T m01, T m02, T m10, T m11, T m12, T m20, T m21, T m22);

		/// Constructs a 3x3 matrix from individual row vectors.
		LYAH_INLINE LYAH_CONSTEXPR mat(vec<3, T> m0, vec<3, T> m1, vec<3, T> m2);

		/// Constructs a 3x3 matrix converted from `A`.
		template<typename U>
		LYAH_INLINE LYAH_CONSTEXPR explicit mat(mat<3, 3, U> A);

		/// Returns the row vector at the provided index.
		/// `index` must be in [0, 3[.
		LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR const vec<3, T>& LYAH_CALL operator[](std::size_t index) const;

		/// Returns the row vector at the provided index.
		/// `index` must be in [0, 3[.
		LYAH_NODISCARD LYAH_INLINE vec<3, T>& LYAH_CALL operator[](std::size_t index);

		vec<3, T> m[3];
	};
}