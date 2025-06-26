// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

#include "quat/quat.hpp"

namespace lyah {
	// NOTE: SSE
	LYAH_INLINE quat<std::float_t>::quat() :
		m(_mm_setzero_ps())
	{}

	// NOTE: SSE
	template<>
	LYAH_INLINE quat<std::float_t>::quat(std::float_t w, std::float_t x, std::float_t y, std::float_t z) :
		m(_mm_set_ps(z, y, x, w))
	{}

	// NOTE: SSE
	LYAH_INLINE std::float_t quat<std::float_t>::operator [](std::size_t index) const LYAH_NOEXCEPT {
		LYAH_ASSERT(index < 4);

		switch (index) {
			default:
			case 0: return _mm_cvtss_f32(m);
			case 1: return _mm_cvtss_f32(_mm_shuffle_ps(m, m, _MM_SHUFFLE(0, 0, 0, 1)));
			case 2: return _mm_cvtss_f32(_mm_shuffle_ps(m, m, _MM_SHUFFLE(0, 0, 0, 2)));
			case 3: return _mm_cvtss_f32(_mm_shuffle_ps(m, m, _MM_SHUFFLE(0, 0, 0, 3)));
		}
	}

	// NOTE: SSE
	LYAH_INLINE vec<3, std::float_t> quat<std::float_t>::xyz() const {
		return vec<3, std::float_t>(_mm_shuffle_ps(m, m, _MM_SHUFFLE(0, 3, 2, 1)));
	}

	// NOTE: SSE
	LYAH_NODISCARD LYAH_INLINE bool LYAH_CALL operator ==(quat<std::float_t> a, quat<std::float_t> b) {
		const __m128 m = _mm_cmpneq_ps(a.m, b.m);

		return _mm_movemask_ps(m) == 0;
	}

	// NOTE: SSE
	LYAH_NODISCARD LYAH_INLINE bool LYAH_CALL operator !=(quat<std::float_t> a, quat<std::float_t> b) {
		const __m128 m = _mm_cmpneq_ps(a.m, b.m);

		return _mm_movemask_ps(m) != 0;
	}

	// NOTE: SSE
	// https://stackoverflow.com/a/20084034/17136841
	LYAH_NODISCARD LYAH_INLINE quat<std::float_t> LYAH_CALL operator -(quat<std::float_t> a) {
		a.m = _mm_xor_ps(a.m, _mm_set1_ps(-0.0f));

		return a;
	}

	// NOTE: SSE
	LYAH_INLINE quat<std::float_t>& LYAH_CALL operator +=(quat<std::float_t>& a, quat<std::float_t> b) {
		a.m = _mm_add_ps(a.m, b.m);

		return a;
	}

	// NOTE: SSE
	LYAH_INLINE quat<std::float_t>& LYAH_CALL operator -=(quat<std::float_t>& a, quat<std::float_t> b) {
		a.m = _mm_sub_ps(a.m, b.m);

		return a;
	}

	// NOTE: SSE
	LYAH_INLINE quat<std::float_t>& LYAH_CALL operator *=(quat<std::float_t>& a, std::float_t b) {
		a.m = _mm_mul_ps(a.m, _mm_set1_ps(b));

		return a;
	}

	// NOTE: SSE
	LYAH_INLINE quat<std::float_t>& LYAH_CALL operator *=(quat<std::float_t>& a, quat<std::float_t> b) {
		const __m128 m0l = a.m;
		const __m128 m0r = _mm_set1_ps(_mm_cvtss_f32(b.m));
		const __m128 m0 = _mm_mul_ps(m0l, m0r);

		const __m128 m1l = _mm_shuffle_ps(a.m, a.m, _MM_SHUFFLE(0, 0, 2, 2));
		const __m128 m1r = _mm_movehl_ps(b.m, b.m);
		const __m128 m1 = _mm_mul_ps(m1l, m1r);

		const __m128 m2l = _mm_shuffle_ps(a.m, a.m, _MM_SHUFFLE(1, 3, 0, 1));
		const __m128 m2r = _mm_shuffle_ps(b.m, b.m, _MM_SHUFFLE(2, 1, 1, 1));
		const __m128 m2 = _mm_mul_ps(m2l, m2r);

		const __m128 m3l = _mm_shuffle_ps(a.m, a.m, _MM_SHUFFLE(2, 1, 3, 3));
		const __m128 m3r = _mm_shuffle_ps(b.m, b.m, _MM_SHUFFLE(1, 3, 2, 3));
		const __m128 m3 = _mm_mul_ps(m3l, m3r);

		a.m = _mm_add_ps(m1, m2);
		a.m = _mm_xor_ps(a.m, internal::quat_t<std::float_t>::wmask()); // flip w sign
		a.m = _mm_add_ps(a.m, m0);
		a.m = _mm_sub_ps(a.m, m3);

		return a;
	}

	// NOTE: SSE
	LYAH_NODISCARD LYAH_INLINE quat<std::float_t> LYAH_CALL conjugate(quat<std::float_t> a) {
		a.m = _mm_xor_ps(a.m, internal::quat_t<std::float_t>::cnjmask());

		return a;
	}

	// NOTE: SSE3
	LYAH_NODISCARD LYAH_INLINE std::float_t LYAH_CALL dot(quat<std::float_t> a, quat<std::float_t> b) {
		const __m128 ab = _mm_mul_ps(a.m, b.m);

		__m128 h = _mm_movehdup_ps(ab);
		__m128 m = _mm_add_ps(ab, h);
		h = _mm_movehl_ps(h, m);
		m = _mm_add_ss(m, h);

		return _mm_cvtss_f32(m);
	}
}