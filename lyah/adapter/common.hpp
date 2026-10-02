// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace lyah {
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 std::float_t LYAH_CALL abs(std::float_t a);
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 std::double_t LYAH_CALL abs(std::double_t a);
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 std::int32_t LYAH_CALL abs(std::int32_t a);
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 std::int64_t LYAH_CALL abs(std::int64_t a);

	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 std::float_t LYAH_CALL ceil(std::float_t a);
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 std::double_t LYAH_CALL ceil(std::double_t a);

	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 std::float_t LYAH_CALL floor(std::float_t a);
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 std::double_t LYAH_CALL floor(std::double_t a);

	//LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 std::float_t LYAH_CALL round(std::float_t a);
	//LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 std::double_t LYAH_CALL round(std::double_t a);

	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 std::float_t LYAH_CALL fma(std::float_t a, std::float_t b, std::float_t c);
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 std::double_t LYAH_CALL fma(std::double_t a, std::double_t b, std::double_t c);
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 vec<2, std::float_t> LYAH_CALL fma(vec<2, std::float_t> a, vec<2, std::float_t> b, vec<2, std::float_t> c);
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 vec<2, std::double_t> LYAH_CALL fma(vec<2, std::double_t> a, vec<2, std::double_t> b, vec<2, std::double_t> c);
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 vec<3, std::float_t> LYAH_CALL fma(vec<3, std::float_t> a, vec<3, std::float_t> b, vec<3, std::float_t> c);
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 vec<3, std::double_t> LYAH_CALL fma(vec<3, std::double_t> a, vec<3, std::double_t> b, vec<3, std::double_t> c);
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 vec<4, std::float_t> LYAH_CALL fma(vec<4, std::float_t> a, vec<4, std::float_t> b, vec<4, std::float_t> c);
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR_CPP23 vec<4, std::double_t> LYAH_CALL fma(vec<4, std::double_t> a, vec<4, std::double_t> b, vec<4, std::double_t> c);

	template<typename T, typename = std::enable_if<std::is_floating_point<T>::value>>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR T LYAH_CALL lerp(T a, T b, T t);

	template<std::size_t C, typename T, typename = std::enable_if<std::is_floating_point<T>::value>>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<C, T> LYAH_CALL lerp(vec<C, T> a, vec<C, T> b, T t);

	template<std::size_t C, typename T, typename = std::enable_if<std::is_floating_point<T>::value>>
	LYAH_NODISCARD LYAH_INLINE LYAH_CONSTEXPR vec<C, T> LYAH_CALL lerp(vec<C, T> a, vec<C, T> b, vec<C, T> t);
}