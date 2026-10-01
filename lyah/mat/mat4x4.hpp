// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

#include "lyah/mat/mat.hpp"

namespace lyah {
	#define MAT4X4(T) \
		template<> \
		struct mat<4, 4, T> { \
			LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR static mat<4, 4, T> LYAH_CALL identity(); \
			\
			LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR static mat<4, 4, T> LYAH_CALL translation(vec<3, T> a); \
			\
			LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 static mat<4, 4, T> LYAH_CALL rotation(vec<3, T> axis, T angle); \
			\
			LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR static mat<4, 4, T> LYAH_CALL scaling(vec<3, T> a); \
			\
			LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR static mat<4, 4, T> LYAH_CALL orthographic(T left, T right, T bottom, T top, T near, T far); \
			\
			LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR static mat<4, 4, T> LYAH_CALL lookAt(vec<3, T> eye, vec<3, T> target, vec<3, T> up); \
			\
			LYAH_INLINE LYAH_CONSTEXPR mat(); \
			\
			LYAH_INLINE LYAH_CONSTEXPR mat(T m00, T m01, T m02, T m03, T m10, T m11, T m12, T m13, T m20, T m21, T m22, T m23, T m30, T m31, T m32, T m33); \
			\
			LYAH_INLINE LYAH_CONSTEXPR mat(vec<4, T> m0, vec<4, T> m1, vec<4, T> m2, vec<4, T> m3); \
			\
			LYAH_INLINE LYAH_CONSTEXPR mat(quat<T> a); \
			\
			template<typename U> \
			LYAH_INLINE LYAH_CONSTEXPR explicit mat(mat<4, 4, U> a); \
			\
			LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR const vec<4, T>& LYAH_CALL operator[](std::size_t index) const; \
			\
			LYAH_NODISCARD LYAH_INLINE vec<4, T>& LYAH_CALL operator[](std::size_t index); \
			\
			vec<4, T> m[4]; \
		};

	MAT4X4(std::float_t);
	MAT4X4(std::double_t);

	#undef MAT4X4
}

#include "lyah/mat/mat4x4_float.ipp"
#include "lyah/mat/mat4x4_double.ipp"
#include "lyah/mat/mat4x4.ipp"