// Copyright 2025 Atalante Studio.
// Distributed under the MIT License.

#pragma once

#include "lyah/vec/vec.hpp"
#include "lyah/common.hpp"
#include "lyah/geometric.hpp"
#include "lyah/limits.hpp"
#include "lyah/trigonometric.hpp"

namespace lyah {
	template<typename T>
	struct vec<3, T> {
		LYAH_NODISCARD vec();

		LYAH_NODISCARD vec(T x, T y, T z);

		LYAH_NODISCARD explicit vec(T a);

		template<typename U>
		LYAH_NODISCARD explicit vec(vec<3, U> a) :
			x(static_cast<T>(a.x)),
			y(static_cast<T>(a.y)),
			z(static_cast<T>(a.z))
		{}

		LYAH_NODISCARD T LYAH_CALL operator[](std::size_t index) const LYAH_NOEXCEPT;

		LYAH_NODISCARD T& LYAH_CALL operator[](std::size_t index) LYAH_NOEXCEPT;

		T x;
		T y;
		T z;
	};

	template<typename T>
	LYAH_INLINE vec<3, T>::vec() :
		x(static_cast<T>(0)),
		y(static_cast<T>(0)),
		z(static_cast<T>(0))
	{}

	template<typename T>
	LYAH_INLINE vec<3, T>::vec(T x, T y, T z) :
		x(x),
		y(y),
		z(z)
	{}

	template<typename T>
	LYAH_INLINE vec<3, T>::vec(T a) :
		x(a),
		y(a),
		z(a)
	{}

	template<typename T>
	LYAH_INLINE T vec<3, T>::operator[](std::size_t index) const LYAH_NOEXCEPT {
		LYAH_ASSERT(index < 3);

		return reinterpret_cast<const T*>(this)[index];
	}

	template<typename T>
	LYAH_INLINE T& vec<3, T>::operator[](std::size_t index) LYAH_NOEXCEPT {
		LYAH_ASSERT(index < 3);

		return reinterpret_cast<T*>(this)[index];
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE bool LYAH_CALL operator==(vec<3, T> a, vec<3, T> b) {
		return a.x == b.x && a.y == b.y && a.z == b.z;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE bool LYAH_CALL operator!=(vec<3, T> a, vec<3, T> b) {
		return a.x != b.x || a.y != b.y || a.z != b.z;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE vec<3, T> LYAH_CALL operator-(vec<3, T> a) {
		a.x = -a.x;
		a.y = -a.y;
		a.z = -a.z;

		return a;
	}

	template<typename T>
	LYAH_INLINE vec<3, T>& LYAH_CALL operator+=(vec<3, T>& a, vec<3, T> b) {
		a.x += b.x;
		a.y += b.y;
		a.z += b.z;

		return a;
	}

	template<typename T>
	LYAH_INLINE vec<3, T>& LYAH_CALL operator*=(vec<3, T>& a, vec<3, T> b) {
		a.x *= b.x;
		a.y *= b.y;
		a.z *= b.z;

		return a;
	}

	/// Post-multiply
	template<typename T>
	LYAH_INLINE vec<3, T>& LYAH_CALL operator*=(vec<3, T>& a, mat<3, 3, T> A) {
		a = {
			dot({A[0][0], A[1][0], A[2][0]}, a),
			dot({A[0][1], A[1][1], A[2][1]}, a),
			dot({A[0][2], A[1][2], A[2][2]}, a),
		};

		return a;
	}

	/// `b` is assumed to be normalized.
	/// See https://blog.molecular-matters.com/2013/05/24/a-faster-quaternion-vector-multiplication.
	template<typename T>
	LYAH_INLINE vec<3, T>& LYAH_CALL operator*=(vec<3, T>& a, quat<T> b) {
		const vec<3, T> xyz = {b.x, b.y, b.z};

		a = static_cast<T>(2) * (dot(xyz, a) * xyz + b.w * (cross(xyz, a) + b.w * a)) - a;

		return a;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE vec<3, T> LYAH_CALL operator*(vec<3, T> a, quat<T> b) {
		return a *= b;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_CONSTEXPR_CPP23 LYAH_INLINE vec<3, T> LYAH_CALL fma(vec<3, T> a, vec<3, T> b, vec<3, T> c) {
		a.x = fma(a.x, b.x, c.x);
		a.y = fma(a.y, b.y, c.y);
		a.z = fma(a.z, b.z, c.z);

		return a;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE vec<3, T> LYAH_CALL max(vec<3, T> a, vec<3, T> b) {
		a.x = max(a.x, b.x);
		a.y = max(a.y, b.y);
		a.z = max(a.z, b.z);

		return a;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE vec<3, T> LYAH_CALL min(vec<3, T> a, vec<3, T> b) {
		a.x = min(a.x, b.x);
		a.y = min(a.y, b.y);
		a.z = min(a.z, b.z);

		return a;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE T LYAH_CALL sum(vec<3, T> a) {
		return a.x + a.y + a.z;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE vec<3, T> LYAH_CALL cross(vec<3, T> a, vec<3, T> b) {
		return {
			fma(a.y, b.z, -a.z * b.y),
			fma(a.z, b.x, -a.x * b.z),
			fma(a.x, b.y, -a.y * b.x),
		};
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE vec<3, T> LYAH_CALL pow(vec<3, T> a, vec<3, T> b) {
		a.x = pow(a.x, b.x);
		a.y = pow(a.y, b.y);
		a.z = pow(a.z, b.z);

		return a;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE vec<3, T> LYAH_CALL sqrt(vec<3, T> a) {
		a.x = sqrt(a.x);
		a.y = sqrt(a.y);
		a.z = sqrt(a.z);

		return a;
	}

	template<typename T>
	LYAH_INLINE vec<3, T> LYAH_CALL cos(vec<3, T> a) {
		a.x = cos(a.x);
		a.y = cos(a.y);
		a.z = cos(a.z);

		return a;
	}

	template<typename T>
	LYAH_INLINE vec<3, T> LYAH_CALL sin(vec<3, T> a) {
		a.x = sin(a.x);
		a.y = sin(a.y);
		a.z = sin(a.z);

		return a;
	}

	template<typename T>
	LYAH_INLINE vec<3, T> LYAH_CALL tan(vec<3, T> a) {
		a.x = tan(a.x);
		a.y = tan(a.y);
		a.z = tan(a.z);

		return a;
	}
}