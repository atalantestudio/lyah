// Copyright 2025 Atalante Studio.
// Distributed under the MIT License.

#pragma once

#include "lyah/vec/vec.hpp"
#include "lyah/common.hpp"
#include "lyah/exponential.hpp"
#include "lyah/geometric.hpp"
#include "lyah/limits.hpp"
#include "lyah/trigonometric.hpp"

namespace lyah {
	template<typename T>
	struct vec<2, T> {
		/// Creates and returns a 2-component vector with all components set to 0.
		LYAH_NODISCARD vec();

		/// Creates and returns a 2-component vector with the firt component set to `x` and the second component set to `y`.
		LYAH_NODISCARD vec(T x, T y);

		/// Creates and returns a 2-component vector with all components set to `a`.
		LYAH_NODISCARD explicit vec(T a);

		/// Creates and returns a 2-component vector by casting the values of `a`.
		template<typename U>
		LYAH_NODISCARD explicit vec(vec<2, U> a) :
			x(static_cast<T>(a.x)),
			y(static_cast<T>(a.y))
		{}

		LYAH_NODISCARD T LYAH_CALL operator[](std::size_t index) const LYAH_NOEXCEPT;

		LYAH_NODISCARD T& LYAH_CALL operator[](std::size_t index) LYAH_NOEXCEPT;

		T x;
		T y;
	};

	template<typename T>
	LYAH_INLINE vec<2, T>::vec() :
		x(static_cast<T>(0)),
		y(static_cast<T>(0))
	{}

	template<typename T>
	LYAH_INLINE vec<2, T>::vec(T x, T y) :
		x(x),
		y(y)
	{}

	template<typename T>
	LYAH_INLINE vec<2, T>::vec(T a) :
		x(a),
		y(a)
	{}

	template<typename T>
	LYAH_INLINE T vec<2, T>::operator[](std::size_t index) const LYAH_NOEXCEPT {
		LYAH_ASSERT(index < 2);

		return reinterpret_cast<const T*>(this)[index];
	}

	template<typename T>
	LYAH_INLINE T& vec<2, T>::operator[](std::size_t index) LYAH_NOEXCEPT {
		LYAH_ASSERT(index < 2);

		return reinterpret_cast<T*>(this)[index];
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE bool LYAH_CALL operator==(vec<2, T> a, vec<2, T> b) {
		return a.x == b.x && a.y == b.y;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE bool LYAH_CALL operator!=(vec<2, T> a, vec<2, T> b) {
		return a.x != b.x || a.y != b.y;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE vec<2, T> LYAH_CALL operator-(vec<2, T> a) {
		a.x = -a.x;
		a.y = -a.y;

		return a;
	}

	template<typename T>
	LYAH_INLINE vec<2, T>& LYAH_CALL operator+=(vec<2, T>& a, vec<2, T> b) {
		a.x += b.x;
		a.y += b.y;

		return a;
	}

	template<typename T>
	LYAH_INLINE vec<2, T>& LYAH_CALL operator*=(vec<2, T>& a, vec<2, T> b) {
		a.x *= b.x;
		a.y *= b.y;

		return a;
	}

	/// Post-multiply
	template<typename T>
	LYAH_INLINE vec<2, T>& LYAH_CALL operator*=(vec<2, T>& a, mat<2, 2, T> A) {
		a = {
			dot({A[0][0], A[1][0]}, a),
			dot({A[0][1], A[1][1]}, a),
		};

		return a;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_CONSTEXPR_CPP23 LYAH_INLINE vec<2, T> LYAH_CALL fma(vec<2, T> a, vec<2, T> b, vec<2, T> c) {
		a.x = fma(a.x, b.x, c.x);
		a.y = fma(a.y, b.y, c.y);

		return a;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE vec<2, T> LYAH_CALL max(vec<2, T> a, vec<2, T> b) {
		a.x = max(a.x, b.x);
		a.y = max(a.y, b.y);

		return a;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE vec<2, T> LYAH_CALL min(vec<2, T> a, vec<2, T> b) {
		a.x = min(a.x, b.x);
		a.y = min(a.y, b.y);

		return a;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE T LYAH_CALL sum(vec<2, T> a) {
		return a.x + a.y;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE vec<2, T> LYAH_CALL pow(vec<2, T> a, vec<2, T> b) {
		a.x = pow(a.x, b.x);
		a.y = pow(a.y, b.y);

		return a;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE vec<2, T> LYAH_CALL sqrt(vec<2, T> a) {
		a.x = sqrt(a.x);
		a.y = sqrt(a.y);

		return a;
	}

	template<typename T>
	LYAH_INLINE vec<2, T> LYAH_CALL cos(vec<2, T> a) {
		a.x = cos(a.x);
		a.y = cos(a.y);

		return a;
	}

	template<typename T>
	LYAH_INLINE vec<2, T> LYAH_CALL sin(vec<2, T> a) {
		a.x = sin(a.x);
		a.y = sin(a.y);

		return a;
	}

	template<typename T>
	LYAH_INLINE vec<2, T> LYAH_CALL tan(vec<2, T> a) {
		a.x = tan(a.x);
		a.y = tan(a.y);

		return a;
	}
}