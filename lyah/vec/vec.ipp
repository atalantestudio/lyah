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
	LYAH_INLINE vec<C, T>& LYAH_CALL operator *=(vec<C, T>& a, T b) {
		a = a * vec<C, T>(b);

		return a;
	}

	template<std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE vec<C, T> LYAH_CALL operator *(vec<C, T> a, vec<C, T> b) {
		return a *= b;
	}

	template<std::size_t C, typename T>
	LYAH_INLINE vec<C, T>& LYAH_CALL operator *=(vec<C, T>& a, mat<C, C, T> b) {
		a = a * b;

		return a;
	}

	// NOTE: b is assumed to be normalized.
	// https://blog.molecular-matters.com/2013/05/24/a-faster-quaternion-vector-multiplication
	template<typename T>
	LYAH_NODISCARD LYAH_INLINE vec<3, T> LYAH_CALL operator *(vec<3, T> a, quat<T> b) {
		const vec<3, T> xyz = b.xyz();
		const T w = b.w();

		return static_cast<T>(2) * (dot(xyz, a) * xyz + w * (cross(xyz, a) + w * a)) - a;
	}

	template<typename T>
	LYAH_INLINE vec<3, T>& LYAH_CALL operator *=(vec<3, T>& a, quat<T> b) {
		return a = a * b;
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