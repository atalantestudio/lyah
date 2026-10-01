// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

#include "lyah/mat/mat.hpp"

namespace lyah {
	#define MAT3X3(T) \
		template<> \
		struct mat<3, 3, T> { \
			LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR static mat<3, 3, T> LYAH_CALL identity(); \
			\
			LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR static mat<3, 3, T> LYAH_CALL translation(vec<2, T> a); \
			\
			LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP26 static mat<3, 3, T> LYAH_CALL rotation(T a); \
			\
			LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR static mat<3, 3, T> LYAH_CALL scaling(vec<2, T> a); \
			\
			LYAH_INLINE LYAH_CONSTEXPR mat(); \
			\
			LYAH_INLINE LYAH_CONSTEXPR mat(T m00, T m01, T m02, T m10, T m11, T m12, T m20, T m21, T m22); \
			\
			LYAH_INLINE LYAH_CONSTEXPR mat(vec<3, T> m0, vec<3, T> m1, vec<3, T> m2); \
			\
			LYAH_INLINE LYAH_CONSTEXPR mat(quat<T> a); \
			\
			template<typename U> \
			LYAH_INLINE LYAH_CONSTEXPR explicit mat(mat<3, 3, U> a); \
			\
			LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR const vec<3, T>& LYAH_CALL operator[](std::size_t index) const; \
			\
			LYAH_NODISCARD LYAH_INLINE vec<3, T>& LYAH_CALL operator[](std::size_t index); \
			\
			vec<3, T> m[3]; \
		};

	MAT3X3(std::float_t);
	MAT3X3(std::double_t);

	#undef MAT3X3
}

#include "lyah/mat/mat3x3_float.ipp"
#include "lyah/mat/mat3x3_double.ipp"
#include "lyah/mat/mat3x3.ipp"