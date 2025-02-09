// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

namespace lyah {
	template<std::size_t R, std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE bool LYAH_CALL operator ==(mat<R, C, T> a, mat<R, C, T> b) {
		for (std::size_t i = 0; i < R; i++) {
			if (a[i] != b[i]) {
				return false;
			}
		}

		return true;
	}

	template<std::size_t R, std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE bool LYAH_CALL operator !=(mat<R, C, T> a, mat<R, C, T> b) {
		for (std::size_t i = 0; i < R; i++) {
			if (a[i] != b[i]) {
				return true;
			}
		}

		return false;
	}

	template<std::size_t R, std::size_t C, typename T>
	LYAH_NODISCARD LYAH_CONSTEXPR LYAH_INLINE mat<R, C, T> LYAH_CALL operator +(mat<R, C, T> a) {
		return a;
	}

	template<std::size_t R, std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE mat<R, C, T> LYAH_CALL operator -(mat<R, C, T> a) {
		for (std::size_t i = 0; i < R; i++) {
			a[i] = -a[i];
		}

		return a;
	}

	template<std::size_t R, std::size_t C, typename T>
	LYAH_NODISCARD LYAH_INLINE mat<R, C, T> LYAH_CALL operator +(mat<R, C, T> a, mat<R, C, T> b) {
		return a += b;
	}

	template<std::size_t R, std::size_t C, typename T>
	LYAH_INLINE mat<R, C, T>& LYAH_CALL operator +=(mat<R, C, T>& a, mat<R, C, T> b) {
		for (std::size_t i = 0; i < R; i++) {
			a[i] += b[i];
		}

		return a;
	}

	template<std::size_t C, std::size_t R, typename T>
	LYAH_NODISCARD LYAH_INLINE mat<R, C, T> LYAH_CALL operator -(mat<R, C, T> a, mat<R, C, T> b) {
		return a -= b;
	}

	template<std::size_t R, std::size_t C, typename T>
	LYAH_INLINE mat<R, C, T>& LYAH_CALL operator -=(mat<R, C, T>& a, mat<R, C, T> b) {
		for (std::size_t i = 0; i < R; i++) {
			a[i] -= b[i];
		}

		return a;
	}

	template<std::size_t C, std::size_t R, typename T>
	LYAH_NODISCARD LYAH_INLINE mat<R, C, T> LYAH_CALL operator *(mat<R, C, T> a, T b) {
		return a *= b;
	}

	template<std::size_t C, std::size_t R, typename T>
	LYAH_NODISCARD LYAH_INLINE mat<R, C, T> LYAH_CALL operator *(T a, mat<R, C, T> b) {
		return b *= a;
	}

	template<std::size_t R, std::size_t C, typename T>
	LYAH_INLINE mat<R, C, T>& LYAH_CALL operator *=(mat<R, C, T>& a, T b) {
		for (std::size_t i = 0; i < R; i++) {
			a[i] *= b;
		}

		return a;
	}

	template<std::size_t R, std::size_t C, typename T>
	LYAH_INLINE mat<R, C, T>& LYAH_CALL operator *=(mat<R, C, T>& a, mat<R, C, T> b) {
		return a = a * b;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_CONSTEXPR LYAH_INLINE T LYAH_CALL determinant(mat<2, 2, T> a) {
		return a[0][0] * a[1][1] - a[0][1] * a[1][0];
	}

	// https://www.dr-lex.be/random/matrix-inv.html
	template<typename T>
	LYAH_NODISCARD LYAH_INLINE mat<2, 2, T> LYAH_CALL inverse(mat<2, 2, T> a) {
		const T d = determinant(a);

		LYAH_ASSERT(abs(d) >= epsilon<T>());

		return static_cast<T>(1) / d * mat<2, 2, T>(
			 a[1][1], -a[0][1],
			-a[1][0],  a[0][0]
		);
	}
}