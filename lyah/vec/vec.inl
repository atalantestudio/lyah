// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

namespace lyah {
	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_CONSTEXPR LYAH_INLINE vec<C, T> LYAH_CALL operator +(vec<C, T> a) {
		return a;
	}

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE vec<C, T> LYAH_CALL operator +(vec<C, T> a, vec<C, T> b) {
		return a += b;
	}

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE vec<C, T> LYAH_CALL operator -(vec<C, T> a, vec<C, T> b) {
		return a -= b;
	}

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE vec<C, T> LYAH_CALL operator *(vec<C, T> a, T b) {
		return a *= b;
	}

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE vec<C, T> LYAH_CALL operator *(T a, vec<C, T> b) {
		return b *= a;
	}

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE vec<C, T> LYAH_CALL operator *(vec<C, T> a, vec<C, T> b) {
		return a *= b;
	}

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE vec<C, T> LYAH_CALL operator /(vec<C, T> a, T b) {
		return a /= b;
	}

	template<std::size_t C, typename T>
	LYAH_INLINE vec<C, T>& LYAH_CALL operator /=(vec<C, T>& a, T b) {
		return a *= static_cast<T>(1) / b;
	}

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE vec<C, T> LYAH_CALL operator /(vec<C, T> a, vec<C, T> b) {
		return a /= b;
	}
}