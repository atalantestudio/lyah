// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

namespace lyah {
	template<typename T>
	LYAH_CONSTEXPR mat<4, 4, T> operator*(mat<4, 4, T> a, mat<4, 4, T> b) {
		const vec<4, T> a0 = a[0];
		const vec<4, T> a1 = a[1];
		const vec<4, T> a2 = a[2];
		const vec<4, T> a3 = a[3];
		const vec<4, T> b0 = b[0];
		const vec<4, T> b1 = b[1];
		const vec<4, T> b2 = b[2];
		const vec<4, T> b3 = b[3];

		a[0] = fma(b3, vec<4, T>(a0.w), fma(b2, vec<4, T>(a0.z), fma(b1, vec<4, T>(a0.y), b0 * a0.x)));
		a[1] = fma(b3, vec<4, T>(a1.w), fma(b2, vec<4, T>(a1.z), fma(b1, vec<4, T>(a1.y), b0 * a1.x)));
		a[2] = fma(b3, vec<4, T>(a2.w), fma(b2, vec<4, T>(a2.z), fma(b1, vec<4, T>(a2.y), b0 * a2.x)));
		a[3] = fma(b3, vec<4, T>(a3.w), fma(b2, vec<4, T>(a3.z), fma(b1, vec<4, T>(a3.y), b0 * a3.x)));

		return a;
	}

	/// See https://stackoverflow.com/a/30006505/17136841.
	template<typename T>
	LYAH_CONSTEXPR T determinant(mat<4, 4, T> a) {
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

	template<typename T>
	LYAH_CONSTEXPR mat<4, 4, T> adjugate(mat<4, 4, T> a) {
		// TODO: Implement 4x4 matrix adjugate.
		__debugbreak();

		return a;
	}

	/*template<typename T>
	LYAH_NODISCARD LYAH_INLINE mat<4, 4, T> inverse(mat<4, 4, T> M) {
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
	}*/

	template<typename T>
	LYAH_CONSTEXPR mat<4, 4, T> transpose(mat<4, 4, T> a) {
		T t;

		t = a[0][1];
		a[0][1] = a[1][0];
		a[1][0] = t;

		t = a[0][2];
		a[0][2] = a[2][0];
		a[2][0] = t;

		t = a[0][3];
		a[0][3] = a[3][0];
		a[3][0] = t;

		t = a[1][2];
		a[1][2] = a[2][1];
		a[2][1] = t;

		t = a[1][3];
		a[1][3] = a[3][1];
		a[3][1] = t;

		t = a[2][3];
		a[2][3] = a[3][2];
		a[3][2] = t;

		return a;
	}
}