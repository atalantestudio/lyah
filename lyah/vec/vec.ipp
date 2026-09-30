// Copyright 2025 Atalante Studio.
// Distributed under the MIT License.

namespace lyah {
	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_CONSTEXPR LYAH_INLINE vec<C, T> LYAH_CALL operator+(vec<C, T> a) {
		return a;
	}

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE vec<C, T> LYAH_CALL operator+(vec<C, T> a, vec<C, T> b) {
		return a += b;
	}

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE vec<C, T> LYAH_CALL operator-(vec<C, T> a, vec<C, T> b) {
		return a -= b;
	}

	template<std::size_t C, typename T>
	LYAH_INLINE vec<C, T>& LYAH_CALL operator-=(vec<C, T>& a, vec<C, T> b) {
		return a += -b;
	}

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE vec<C, T> LYAH_CALL operator*(vec<C, T> a, T b) {
		return a *= b;
	}

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE vec<C, T> LYAH_CALL operator*(T a, vec<C, T> b) {
		return b *= a;
	}

	template<std::size_t C, typename T>
	LYAH_INLINE vec<C, T>& LYAH_CALL operator*=(vec<C, T>& a, T b) {
		a = a * vec<C, T>(b);

		return a;
	}

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE vec<C, T> LYAH_CALL operator*(vec<C, T> a, vec<C, T> b) {
		return a *= b;
	}

	/// Post-multiply
	template<std::size_t C, typename T>
	LYAH_INLINE vec<C, T> LYAH_CALL operator*(vec<C, T> a, mat<C, C, T> b) {
		return a *= b;
	}

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE vec<C, T> LYAH_CALL operator/(vec<C, T> a, T b) {
		return a /= b;
	}

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE vec<C, T> LYAH_CALL operator/(T b, vec<C, T> a) {
		return vec<C, T>(b) / a;
	}

	template<std::size_t C, typename T>
	LYAH_INLINE vec<C, T>& LYAH_CALL operator/=(vec<C, T>& a, T b) {
		return a /= vec<C, T>(b);
	}

	template<typename T>
	LYAH_INLINE vec<2, T>& LYAH_CALL operator/=(vec<2, T>& a, vec<2, T> b) {
		a.x /= b.x;
		a.y /= b.y;

		return a;
	}

	template<typename T>
	LYAH_INLINE vec<3, T>& LYAH_CALL operator/=(vec<3, T>& a, vec<3, T> b) {
		a.x /= b.x;
		a.y /= b.y;
		a.z /= b.z;

		return a;
	}

	template<typename T>
	LYAH_INLINE vec<4, T>& LYAH_CALL operator/=(vec<4, T>& a, vec<4, T> b) {
		a.x /= b.x;
		a.y /= b.y;
		a.z /= b.z;
		a.w /= b.w;

		return a;
	}

	/*template<std::size_t C, typename T>
	LYAH_INLINE vec<C, T>& LYAH_CALL operator/=(vec<C, T>& a, vec<C, T> b) {
		return a *= static_cast<T>(1) / b;
	}*/

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE vec<C, T> LYAH_CALL operator/(vec<C, T> a, vec<C, T> b) {
		return a /= b;
	}
}