// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

namespace lyah {
	// NOTE: AVX2
	// http://www.codersnotes.com/notes/maths-lib-2016
	// https://geometrian.com/programming/tutorials/cross-product/index.php
	// https://gist.github.com/garrettsickles/85a9ab8385172bd0e762f38e4cfb045f
	LYAH_NODISCARD LYAH_INLINE vec<3, std::double_t> LYAH_CALL cross(vec<3, std::double_t> a, vec<3, std::double_t> b) {
		const __m256d c = _mm256_mul_pd(b.m, _mm256_permute4x64_pd(a.m, _MM_SHUFFLE(3, 1, 0, 2)));
		const __m256d d = _mm256_mul_pd(a.m, _mm256_permute4x64_pd(b.m, _MM_SHUFFLE(3, 1, 0, 2)));
		const __m256d m = _mm256_sub_pd(c, d);

		a.m = _mm256_permute4x64_pd(m, _MM_SHUFFLE(3, 1, 0, 2));

		return a;
	}
}