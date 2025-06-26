// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

#include "quat/quat.hpp"

namespace lyah {
	// NOTE: AVX
	LYAH_INLINE quat<std::double_t>::quat() :
		m(_mm256_setzero_pd())
	{}

	// NOTE: AVX
	template<>
	LYAH_INLINE quat<std::double_t>::quat(std::double_t w, std::double_t x, std::double_t y, std::double_t z) :
		m(_mm256_set_pd(z, y, x, w))
	{}

	// NOTE: AVX2
	LYAH_INLINE std::double_t quat<std::double_t>::operator [](std::size_t index) const LYAH_NOEXCEPT {
		LYAH_ASSERT(index < 4);

		switch (index) {
			default:
			case 0: return _mm256_cvtsd_f64(m);
			case 1: return _mm256_cvtsd_f64(_mm256_shuffle_pd(m, m, _MM_SHUFFLE(0, 0, 0, 1)));
			case 2: return _mm256_cvtsd_f64(_mm256_permute4x64_pd(m, _MM_SHUFFLE(0, 0, 0, 2)));
			case 3: return _mm256_cvtsd_f64(_mm256_permute4x64_pd(m, _MM_SHUFFLE(0, 0, 0, 3)));
		}
	}

	// NOTE: AVX2
	LYAH_INLINE vec<3, std::double_t> quat<std::double_t>::xyz() const {
		return vec<3, std::double_t>(_mm256_permute4x64_pd(m, _MM_SHUFFLE(0, 3, 2, 1)));
	}

	// NOTE: AVX
	LYAH_NODISCARD LYAH_INLINE bool LYAH_CALL operator ==(quat<std::double_t> a, quat<std::double_t> b) {
		const __m256d m = _mm256_cmp_pd(a.m, b.m, _CMP_NEQ_OQ);

		return _mm256_movemask_pd(m) == 0;
	}

	// NOTE: AVX
	LYAH_NODISCARD LYAH_INLINE bool LYAH_CALL operator !=(quat<std::double_t> a, quat<std::double_t> b) {
		const __m256d m = _mm256_cmp_pd(a.m, b.m, _CMP_NEQ_OQ);

		return _mm256_movemask_pd(m) != 0;
	}

	// NOTE: AVX
	// https://stackoverflow.com/a/20084034/17136841
	LYAH_NODISCARD LYAH_INLINE quat<std::double_t> LYAH_CALL operator -(quat<std::double_t> a) {
		a.m = _mm256_xor_pd(a.m, _mm256_set1_pd(-0.0));

		return a;
	}

	// NOTE: AVX
	LYAH_INLINE quat<std::double_t>& LYAH_CALL operator +=(quat<std::double_t>& a, quat<std::double_t> b) {
		a.m = _mm256_add_pd(a.m, b.m);

		return a;
	}

	// NOTE: AVX
	LYAH_INLINE quat<std::double_t>& LYAH_CALL operator -=(quat<std::double_t>& a, quat<std::double_t> b) {
		a.m = _mm256_sub_pd(a.m, b.m);

		return a;
	}

	// NOTE: AVX
	LYAH_INLINE quat<std::double_t>& LYAH_CALL operator *=(quat<std::double_t>& a, std::double_t b) {
		a.m = _mm256_mul_pd(a.m, _mm256_set1_pd(b));

		return a;
	}

	// NOTE: AVX2
	LYAH_INLINE quat<std::double_t>& LYAH_CALL operator *=(quat<std::double_t>& a, quat<std::double_t> b) {
		const __m256d m0l = a.m;
		const __m256d m0r = _mm256_set1_pd(_mm256_cvtsd_f64(b.m));
		const __m256d m0 = _mm256_mul_pd(m0l, m0r);

		const __m256d m1l = _mm256_permute4x64_pd(a.m, _MM_SHUFFLE(0, 0, 2, 2));
		const __m256d m1r = _mm256_permute4x64_pd(b.m, _MM_SHUFFLE(3, 2, 3, 2));
		const __m256d m1 = _mm256_mul_pd(m1l, m1r);

		const __m256d m2l = _mm256_permute4x64_pd(a.m, _MM_SHUFFLE(1, 3, 0, 1));
		const __m256d m2r = _mm256_permute4x64_pd(b.m, _MM_SHUFFLE(2, 1, 1, 1));
		const __m256d m2 = _mm256_mul_pd(m2l, m2r);

		const __m256d m3l = _mm256_permute4x64_pd(a.m, _MM_SHUFFLE(2, 1, 3, 3));
		const __m256d m3r = _mm256_permute4x64_pd(b.m, _MM_SHUFFLE(1, 3, 2, 3));
		const __m256d m3 = _mm256_mul_pd(m3l, m3r);

		a.m = _mm256_add_pd(m1, m2);
		a.m = _mm256_xor_pd(a.m, internal::quat_t<std::double_t>::wmask()); // flip w sign
		a.m = _mm256_add_pd(a.m, m0);
		a.m = _mm256_sub_pd(a.m, m3);

		return a;
	}

	// NOTE: AVX
	LYAH_NODISCARD LYAH_INLINE quat<std::double_t> LYAH_CALL conjugate(quat<std::double_t> a) {
		a.m = _mm256_xor_pd(a.m, internal::quat_t<std::double_t>::cnjmask());

		return a;
	}

	// NOTE: AVX
	LYAH_NODISCARD LYAH_INLINE std::double_t LYAH_CALL dot(quat<std::double_t> a, quat<std::double_t> b) {
		const __m256d ab = _mm256_mul_pd(a.m, b.m);

		__m128d h = _mm256_extractf128_pd(ab, 1);
		__m128d m = _mm256_castpd256_pd128(ab);

		m = _mm_add_pd(m, h);
		h = _mm_unpackhi_pd(m, m);
		m = _mm_add_sd(m, h);

		return _mm_cvtsd_f64(m);
	}
}