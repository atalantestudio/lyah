// Copyright 2025 Atalante Studio.
// Distributed under the MIT License.

namespace lyah {
	template<typename T>
	LYAH_NODISCARD LYAH_INLINE quat<T> quat<T>::identity() {
		return {static_cast<T>(1), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0)};
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE quat<T> quat<T>::axisAngle(vec<3, T> axis, T angle) {
		angle *= static_cast<T>(0.5);
		axis *= sin(angle);

		return {cos(angle), axis[0], axis[1], axis[2]};
	}

	template<typename T>
	LYAH_INLINE quat<T>::quat() :
		w(static_cast<T>(0)),
		x(static_cast<T>(0)),
		y(static_cast<T>(0)),
		z(static_cast<T>(0))
	{}

	template<typename T>
	LYAH_INLINE quat<T>::quat(T w, T x, T y, T z) :
		w(w),
		x(x),
		y(y),
		z(z)
	{}

	template<typename T>
	template<typename U>
	LYAH_NODISCARD LYAH_INLINE quat<T>::quat(quat<U> a) :
		w(static_cast<T>(a.w)),
		x(static_cast<T>(a.x)),
		y(static_cast<T>(a.y)),
		z(static_cast<T>(a.z))
	{}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE T LYAH_CALL quat<T>::operator[](std::size_t index) const LYAH_NOEXCEPT {
		LYAH_ASSERT(index < 4);

		return reinterpret_cast<const T*>(this)[index];
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE T& LYAH_CALL quat<T>::operator[](std::size_t index) LYAH_NOEXCEPT {
		LYAH_ASSERT(index < 4);

		return reinterpret_cast<T*>(this)[index];
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE bool LYAH_CALL operator==(quat<T> a, quat<T> b) {
		return a.w == b.w && a.x == b.x && a.y == b.y && a.z == b.z;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE bool LYAH_CALL operator!=(quat<T> a, quat<T> b) {
		return a.w != b.w || a.x != b.x || a.y != b.y || a.z != b.z;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_CONSTEXPR LYAH_INLINE quat<T> LYAH_CALL operator+(quat<T> a) {
		return a;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE quat<T> LYAH_CALL operator-(quat<T> a) {
		a.w = -a.w;
		a.x = -a.x;
		a.y = -a.y;
		a.z = -a.z;

		return a;
	}

	template<typename T>
	LYAH_INLINE quat<T>& LYAH_CALL operator+=(quat<T>& a, quat<T> b) {
		a.w += b.w;
		a.x += b.x;
		a.y += b.y;
		a.z += b.z;

		return a;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE quat<T> LYAH_CALL operator+(quat<T> a, quat<T> b) {
		return a += b;
	}

	template<typename T>
	LYAH_INLINE quat<T>& LYAH_CALL operator-=(quat<T>& a, quat<T> b) {
		a.w -= b.w;
		a.x -= b.x;
		a.y -= b.y;
		a.z -= b.z;

		return a;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE quat<T> LYAH_CALL operator-(quat<T> a, quat<T> b) {
		return a -= b;
	}

	template<typename T>
	LYAH_INLINE quat<T>& LYAH_CALL operator*=(quat<T>& a, T b) {
		a.w *= b;
		a.x *= b;
		a.y *= b;
		a.z *= b;

		return a;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE quat<T> LYAH_CALL operator*(quat<T> a, T b) {
		return a *= b;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE quat<T> LYAH_CALL operator*(T a, quat<T> b) {
		return b *= a;
	}

	template<typename T>
	LYAH_INLINE quat<T>& LYAH_CALL operator*=(quat<T>& a, quat<T> b) {
		a = {
			a.w * b.w - (a.x * b.x + a.y * b.y) - a.z * b.z,
			a.w * b.x +  a.x * b.w + a.y * b.z  - a.z * b.y,
			a.w * b.y +  a.y * b.w + a.z * b.x  - a.x * b.z,
			a.w * b.z +  a.z * b.w + a.x * b.y  - a.y * b.x,
		};

		return a;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE quat<T> LYAH_CALL operator*(quat<T> a, quat<T> b) {
		return a *= b;
	}

	template<typename T>
	LYAH_INLINE quat<T>& LYAH_CALL operator/=(quat<T>& a, T b) {
		return a *= static_cast<T>(1) / b;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE quat<T> LYAH_CALL operator/(quat<T> a, T b) {
		return a /= b;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE quat<T> LYAH_CALL operator/(T a, quat<T> b) {
		return inverse(b) * a;
	}

	template<typename T>
	LYAH_INLINE quat<T>& LYAH_CALL operator/=(quat<T>& a, quat<T> b) {
		return a *= inverse(b);
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE quat<T> LYAH_CALL operator/(quat<T> a, quat<T> b) {
		return a /= b;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE quat<T> LYAH_CALL conjugate(quat<T> a) {
		a.x = -a.x;
		a.y = -a.y;
		a.z = -a.z;

		return a;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE T LYAH_CALL dot(quat<T> a, quat<T> b) {
		return a.w * b.w + a.x * b.x + a.y * b.y + a.z * b.z;
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE quat<T> LYAH_CALL inverse(quat<T> a) {
		return conjugate(a) / dot(a, a);
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE T LYAH_CALL length(quat<T> a) {
		return sqrt(lengthSquared(a));
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE T LYAH_CALL lengthSquared(quat<T> a) {
		return dot(a, a);
	}

	template<typename T>
	LYAH_NODISCARD LYAH_INLINE quat<T> LYAH_CALL normalized(quat<T> a) {
		return a /= length(a);
	}
}