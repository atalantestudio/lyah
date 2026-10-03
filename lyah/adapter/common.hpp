// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace lyah {
	/// Returns the absolute value of `x`.
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 std::float_t LYAH_CALL abs(std::float_t x);
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 std::double_t LYAH_CALL abs(std::double_t x);
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 std::int32_t LYAH_CALL abs(std::int32_t x);
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 std::int64_t LYAH_CALL abs(std::int64_t x);

	/// Returns `x` * `y` + `z`.
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 std::float_t LYAH_CALL fma(std::float_t x, std::float_t y, std::float_t z);
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 std::double_t LYAH_CALL fma(std::double_t x, std::double_t y, std::double_t z);
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 vec<2, std::float_t> LYAH_CALL fma(vec<2, std::float_t> x, vec<2, std::float_t> y, vec<2, std::float_t> z);
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 vec<2, std::double_t> LYAH_CALL fma(vec<2, std::double_t> x, vec<2, std::double_t> y, vec<2, std::double_t> z);
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 vec<3, std::float_t> LYAH_CALL fma(vec<3, std::float_t> x, vec<3, std::float_t> y, vec<3, std::float_t> z);
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 vec<3, std::double_t> LYAH_CALL fma(vec<3, std::double_t> x, vec<3, std::double_t> y, vec<3, std::double_t> z);
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 vec<4, std::float_t> LYAH_CALL fma(vec<4, std::float_t> x, vec<4, std::float_t> y, vec<4, std::float_t> z);
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 vec<4, std::double_t> LYAH_CALL fma(vec<4, std::double_t> x, vec<4, std::double_t> y, vec<4, std::double_t> z);

	/// Returns the linear interpolation of `t` between `a` and `b`.
	template<typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL lerp(T a, T b, T t);

	/// Returns the linear interpolation of `t` between `a` and `b`.
	/// `t` is applied to every component of `a` and `b`.
	template<std::size_t C, typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<C, T> LYAH_CALL lerp(vec<C, T> a, vec<C, T> b, T t);

	/// Returns the linear interpolation of `t` between `a` and `b`.
	template<std::size_t C, typename T, typename = std::enable_if<std::is_floating_point<T>::value>::type>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<C, T> LYAH_CALL lerp(vec<C, T> a, vec<C, T> b, vec<C, T> t);

	// TODO: min/max/clamp
}