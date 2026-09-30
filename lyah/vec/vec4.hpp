// Copyright 2025 Atalante Studio.
// Distributed under the MIT License.

#pragma once

#include "lyah/vec/vec.hpp"
#include "lyah/common.hpp"
#include "lyah/convert.hpp"
#include "lyah/geometric.hpp"
#include "lyah/limits.hpp"
#include "lyah/trigonometric.hpp"
#include "lyah/types.hpp"

namespace lyah {
	template<typename T>
	struct vec<4, T> {
		LYAH_NODISCARD vec();

		LYAH_NODISCARD vec(T x, T y, T z, T w);

		LYAH_NODISCARD explicit vec(T a);

		template<typename U>
		LYAH_NODISCARD explicit vec(vec<4, U> a) :
			x(static_cast<T>(a.x)),
			y(static_cast<T>(a.y)),
			z(static_cast<T>(a.z)),
			w(static_cast<T>(a.w))
		{}

		LYAH_NODISCARD T LYAH_CALL operator[](std::size_t index) const LYAH_NOEXCEPT;

		LYAH_NODISCARD T& LYAH_CALL operator[](std::size_t index) LYAH_NOEXCEPT;

		T x;
		T y;
		T z;
		T w;
	};

	template<typename T>
	LYAH_INLINE vec<4, T>::vec() :
		x(static_cast<T>(0)),
		y(static_cast<T>(0)),
		z(static_cast<T>(0)),
		w(static_cast<T>(0))
	{}

	template<typename T>
	LYAH_INLINE vec<4, T>::vec(T x, T y, T z, T w) :
		x(x),
		y(y),
		z(z),
		w(w)
	{}

	template<typename T>
	LYAH_INLINE vec<4, T>::vec(T a) :
		x(a),
		y(a),
		z(a),
		w(a)
	{}

	template<typename T>
	LYAH_INLINE T vec<4, T>::operator[](std::size_t index) const LYAH_NOEXCEPT {
		LYAH_ASSERT(index < 4);

		return reinterpret_cast<const T*>(this)[index];
	}

	template<typename T>
	LYAH_INLINE T& vec<4, T>::operator[](std::size_t index) LYAH_NOEXCEPT {
		LYAH_ASSERT(index < 4);

		return reinterpret_cast<T*>(this)[index];
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE bool LYAH_CALL operator==(vec<4, T> a, vec<4, T> b) {
		return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE bool LYAH_CALL operator!=(vec<4, T> a, vec<4, T> b) {
		return a.x != b.x || a.y != b.y || a.z != b.z || a.w != b.w;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE vec<4, T> LYAH_CALL operator-(vec<4, T> a) {
		a.x = -a.x;
		a.y = -a.y;
		a.z = -a.z;
		a.w = -a.w;

		return a;
	}

	template<typename T>
	LYAH_INLINE vec<4, T>& LYAH_CALL operator+=(vec<4, T>& a, vec<4, T> b) {
		a.x += b.x;
		a.y += b.y;
		a.z += b.z;
		a.w += b.w;

		return a;
	}

	template<typename T>
	LYAH_INLINE vec<4, T>& LYAH_CALL operator*=(vec<4, T>& a, vec<4, T> b) {
		a.x *= b.x;
		a.y *= b.y;
		a.z *= b.z;
		a.w *= b.w;

		return a;
	}

	/// Post-multiply
	template<typename T>
	LYAH_INLINE vec<4, T>& LYAH_CALL operator*=(vec<4, T>& a, mat<4, 4, T> A) {
		a = {
			dot({A[0][0], A[1][0], A[2][0], A[3][0]}, a),
			dot({A[0][1], A[1][1], A[2][1], A[3][1]}, a),
			dot({A[0][2], A[1][2], A[2][2], A[3][2]}, a),
			dot({A[0][3], A[1][3], A[2][3], A[3][3]}, a),
		};

		return a;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_CONSTEXPR_CPP23 LYAH_INLINE vec<4, T> LYAH_CALL fma(vec<4, T> a, vec<4, T> b, vec<4, T> c) {
		a.x = fma(a.x, b.x, c.x);
		a.y = fma(a.y, b.y, c.y);
		a.z = fma(a.z, b.z, c.z);
		a.w = fma(a.w, b.w, c.w);

		return a;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE vec<4, T> LYAH_CALL max(vec<4, T> a, vec<4, T> b) {
		a.x = max(a.x, b.x);
		a.y = max(a.y, b.y);
		a.z = max(a.z, b.z);
		a.w = max(a.w, b.w);

		return a;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE vec<4, T> LYAH_CALL min(vec<4, T> a, vec<4, T> b) {
		a.x = min(a.x, b.x);
		a.y = min(a.y, b.y);
		a.z = min(a.z, b.z);
		a.w = min(a.w, b.w);

		return a;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE T LYAH_CALL sum(vec<4, T> a) {
		return a.x + a.y + a.z + a.w;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE vec<4, T> LYAH_CALL pow(vec<4, T> a, vec<4, T> b) {
		a.x = pow(a.x, b.x);
		a.y = pow(a.y, b.y);
		a.z = pow(a.z, b.z);
		a.w = pow(a.w, b.w);

		return a;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE vec<4, T> LYAH_CALL sqrt(vec<4, T> a) {
		a.x = sqrt(a.x);
		a.y = sqrt(a.y);
		a.z = sqrt(a.z);
		a.w = sqrt(a.w);

		return a;
	}

	template<typename T>
	LYAH_INLINE vec<4, T> LYAH_CALL cos(vec<4, T> a) {
		a.x = cos(a.x);
		a.y = cos(a.y);
		a.z = cos(a.z);
		a.w = cos(a.w);

		return a;
	}

	template<typename T>
	LYAH_INLINE vec<4, T> LYAH_CALL sin(vec<4, T> a) {
		a.x = sin(a.x);
		a.y = sin(a.y);
		a.z = sin(a.z);
		a.w = sin(a.w);

		return a;
	}

	template<typename T>
	LYAH_INLINE vec<4, T> LYAH_CALL tan(vec<4, T> a) {
		a.x = tan(a.x);
		a.y = tan(a.y);
		a.z = tan(a.z);
		a.w = tan(a.w);

		return a;
	}
}