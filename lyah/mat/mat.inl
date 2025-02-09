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

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE T LYAH_CALL determinant(mat<3, 3, T> a) {
		return dot(a[0], cross(a[1], a[2]));
	}

	// https://stackoverflow.com/a/30006505/17136841
	template<typename T>
	LYAH_NODISCARD LYAH_INLINE T LYAH_CALL determinant(mat<4, 4, T> a) {
		const mat<2, 2, T> aa = {
			a[0][0], a[0][1],
			a[1][0], a[1][1],
		};
		const mat<2, 2, T> ab = {
			a[0][2], a[0][3],
			a[1][2], a[1][3],
		};
		const mat<2, 2, T> ac = {
			a[2][0], a[2][1],
			a[3][0], a[3][1],
		};
		const mat<2, 2, T> ad = {
			a[2][2], a[2][3],
			a[3][2], a[3][3],
		};

		return determinant(aa - ab * inverse(ad) * ac) * determinant(ad);
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

	// https://en.wikipedia.org/wiki/Invertible_matrix#Inversion_of_4_%C3%97_4_matrices
	template<typename T>
	LYAH_NODISCARD LYAH_INLINE mat<4, 4, T> LYAH_CALL inverse(mat<4, 4, T> M) {
		const T d = determinant(M);

		LYAH_ASSERT(abs(d) >= epsilon<T>());

		const mat<2, 2, T> A = {
			M[0][0], M[0][1],
			M[1][0], M[1][1],
		};
		const mat<2, 2, T> B = {
			M[0][2], M[0][3],
			M[1][2], M[1][3],
		};
		const mat<2, 2, T> C = {
			M[2][0], M[2][1],
			M[3][0], M[3][1],
		};
		const mat<2, 2, T> D = {
			M[2][2], M[2][3],
			M[3][2], M[3][3],
		};

		const mat<2, 2, T> a0 = inverse(A - B * inverse(D) * C);
		const mat<2, 2, T> a1 = inverse(D - C * inverse(A) * B);
		const mat<4, 4, T> a = {
			a0[0][0], a0[0][1], 0, 0,
			a0[1][0], a0[1][1], 0, 0,
			0, 0, a1[0][0], a1[0][1],
			0, 0, a1[1][0], a1[1][1],
		};

		const mat<2, 2, T> b0 = -B * inverse(D);
		const mat<2, 2, T> b1 = -C * inverse(A);
		const mat<4, 4, T> b = {
			1, 0, b0[0][0], b0[0][1],
			0, 1, b0[1][0], b0[1][1],
			b1[0][0], b1[0][1], 1, 0,
			b1[1][0], b1[1][1], 0, 1,
		};

		return a * b;
	}
}