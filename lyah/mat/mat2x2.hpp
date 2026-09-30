// Copyright 2025 Atalante Studio.
// Distributed under the MIT License.

#pragma once

#include "lyah/mat/mat.hpp"

namespace lyah {
	template<typename T>
	struct mat<2, 2, T> {
		/// Creates and returns a 2x2 identity matrix.
		LYAH_NODISCARD static mat<2, 2, T> LYAH_CALL identity();

		LYAH_NODISCARD LYAH_INLINE static mat<2, 2, T> LYAH_CALL rotation(T a);

		LYAH_NODISCARD mat();

		LYAH_NODISCARD LYAH_INLINE mat(T m00, T m01, T m10, T m11) :
			m{
				{m00, m01},
				{m10, m11}
			}
		{}

		LYAH_NODISCARD LYAH_INLINE mat(vec<2, T> m0, vec<2, T> m1) :
			m{
				m0,
				m1
			}
		{}

		template<typename U>
		LYAH_NODISCARD LYAH_INLINE explicit mat(mat<2, 2, U> a) :
			m{
				vec<2, T>(a[0]),
				vec<2, T>(a[1]),
			}
		{}

		LYAH_NODISCARD LYAH_CONSTEXPR LYAH_INLINE vec<2, T> LYAH_CALL operator[](std::size_t index) const LYAH_NOEXCEPT {
			LYAH_ASSERT(index < 2);

			return m[index];
		}

		LYAH_NODISCARD LYAH_CONSTEXPR LYAH_INLINE vec<2, T>& LYAH_CALL operator[](std::size_t index) LYAH_NOEXCEPT {
			LYAH_ASSERT(index < 2);

			return m[index];
		}

		vec<2, T> m[2];
	};

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE mat<2, 2, T> LYAH_CALL mat<2, 2, T>::identity() {
		return {
			static_cast<T>(1), static_cast<T>(0),
			static_cast<T>(0), static_cast<T>(1),
		};
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE mat<2, 2, T> LYAH_CALL mat<2, 2, T>::rotation(T a) {
		const T c = cos(a);
		const T s = sin(a);

		return {
			c, -s,
			s,  c,
		};
	}

	template<typename T>
	LYAH_INLINE mat<2, 2, T>::mat() :
		m{}
	{}

	template<typename T>
	LYAH_INLINE mat<2, 2, T>& LYAH_CALL operator*=(mat<2, 2, T>& A, mat<2, 2, T> B) {
		A = {
			A[0][0] * B[0][0] + A[0][1] * B[1][0], A[0][0] * B[0][1] + A[0][1] * B[1][1],
			A[1][0] * B[0][0] + A[1][1] * B[1][0], A[1][0] * B[0][1] + A[1][1] * B[1][1],
		};

		return A;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE T LYAH_CALL determinant(mat<2, 2, T> A) {
		return A[0][0] * A[1][1] - A[0][1] * A[1][0];
	}

	// https://www.dr-lex.be/random/matrix-inv.html
	template<typename T>
	LYAH_NODISCARD LYAH_INLINE mat<2, 2, T> LYAH_CALL inverse(mat<2, 2, T> A) {
		static constexpr T e = static_cast<T>(1e-4);

		const T d = determinant(A);

		LYAH_ASSERT(abs(d) >= e);

		A = {
			 A[1][1], -A[0][1],
			-A[1][0],  A[0][0],
		};

		return A / d;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE mat<2, 2, T> LYAH_CALL transpose(mat<2, 2, T> A) {
		std::swap(A[0][1], A[1][0]);

		return A;
	}
}