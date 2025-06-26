// Copyright 2025 Matteo Legagneux.
// Licensed under the MIT License.

namespace lyah {
	template<typename T>
	LYAH_NODISCARD LYAH_INLINE quat<T> quat<T>::identity() {
		return {static_cast<T>(1), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0)};
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE quat<T> quat<T>::axisAngle(vec<3, T> axis, T angle) {
		angle *= 0.5;
		axis *= sin(angle);

		return {cos(angle), axis[0], axis[1], axis[2]};
	}

	template<typename T>
	LYAH_NODISCARD LYAH_CONSTEXPR LYAH_INLINE quat<T>::quat(__m_t m) :
		m(m)
	{}

	template<typename T>
	template<typename U>
	LYAH_NODISCARD LYAH_INLINE quat<T>::quat(quat<U> a) :
		m(internal::convert<typename quat<U>::__m_t, __m_t>(a.m))
	{}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE T quat<T>::w() const {
		return (*this)[0];
	}

	template<typename T>
	LYAH_NODISCARD LYAH_CONSTEXPR LYAH_INLINE quat<T> LYAH_CALL operator +(quat<T> a) {
		return a;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE quat<T> LYAH_CALL operator +(quat<T> a, quat<T> b) {
		return a += b;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE quat<T> LYAH_CALL operator -(quat<T> a, quat<T> b) {
		return a -= b;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE quat<T> LYAH_CALL operator *(quat<T> a, T b) {
		return a *= b;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE quat<T> LYAH_CALL operator *(T a, quat<T> b) {
		return b *= a;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE quat<T> LYAH_CALL operator *(quat<T> a, quat<T> b) {
		return a *= b;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE quat<T> LYAH_CALL operator /(quat<T> a, T b) {
		return a /= b;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE quat<T> LYAH_CALL operator /(T a, quat<T> b) {
		return inverse(b) * a;
	}

	template<typename T>
	LYAH_INLINE quat<T>& LYAH_CALL operator /=(quat<T>& a, T b) {
		return a *= static_cast<T>(1) / b;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE quat<T> LYAH_CALL operator /(quat<T> a, quat<T> b) {
		return a /= b;
	}

	template<typename T>
	LYAH_INLINE quat<T>& LYAH_CALL operator /=(quat<T>& a, quat<T> b) {
		return a *= inverse(b);
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE quat<T> LYAH_CALL inverse(quat<T> a) {
		return conjugate(a) / dot(a, a);
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE T LYAH_CALL length(quat<T> a) {
		return sqrt(dot(a, a));
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE quat<T> LYAH_CALL normalized(quat<T> a) {
		return a /= length(a);
	}
}