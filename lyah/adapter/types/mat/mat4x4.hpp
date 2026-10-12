// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace lyah {
	/// A 4x4 row-major matrix of type T.
	template<typename T>
	struct mat<4, 4, T> {
		/// Constructs a default-initialized 4x4 matrix.
		LYAH_INLINE LYAH_CONSTEXPR mat();

		/// Constructs a 4x4 matrix from individual components.
		LYAH_INLINE LYAH_CONSTEXPR mat(T m00, T m01, T m02, T m03, T m10, T m11, T m12, T m13, T m20, T m21, T m22, T m23, T m30, T m31, T m32, T m33);

		/// Constructs a 4x4 matrix from individual row vectors.
		LYAH_INLINE LYAH_CONSTEXPR mat(vec<4, T> m0, vec<4, T> m1, vec<4, T> m2, vec<4, T> m3);

		/// Constructs a 4x4 matrix converted from `A`.
		template<typename U>
		LYAH_INLINE LYAH_CONSTEXPR explicit mat(mat<4, 4, U> A);

		/// Returns the row vector at the provided index.
		/// `index` must be in [0, 4[.
		LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR const vec<4, T>& LYAH_CALL operator[](std::size_t index) const;

		/// Returns the row vector at the provided index.
		/// `index` must be in [0, 4[.
		LYAH_NODISCARD LYAH_INLINE vec<4, T>& LYAH_CALL operator[](std::size_t index);

		vec<4, T> m[4];
	};
}