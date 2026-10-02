// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

namespace lyah {
	LYAH_CONSTEXPR vec<2, std::float_t> perpendicularLeft(vec<2, std::float_t> a) {
		return {-a.y, a.x};
	}

	LYAH_CONSTEXPR vec<2, std::double_t> perpendicularLeft(vec<2, std::double_t> a) {
		return {-a.y, a.x};
	}

	LYAH_CONSTEXPR vec<2, std::float_t> perpendicularRight(vec<2, std::float_t> a) {
		return {a.y, -a.x};
	}

	LYAH_CONSTEXPR vec<2, std::double_t> perpendicularRight(vec<2, std::double_t> a) {
		return {a.y, -a.x};
	}

	template<typename T, typename>
	LYAH_CONSTEXPR T parallelogramArea(vec<2, T> a, vec<2, T> b) {
		return a.x * b.y - a.y * b.x;
	}

	// TODO: Keep?
	// Returns the "2D cross product" of a and b.
	// If b is -1, the perpendicular vector to the left of a is returned.
	// If b is 1, the perpendicular vector to the right of a is returned.
	template<typename T>
	constexpr vec<2, T> cross(vec<2, T> a, T b) {
		return {a.y * b, a.x * -b};
	}

	template<typename T, typename>
	LYAH_CONSTEXPR_CPP23 vec<3, T> cross(vec<3, T> a, vec<3, T> b) {
		return {
			fma(a.y, b.z, -a.z * b.y),
			fma(a.z, b.x, -a.x * b.z),
			fma(a.x, b.y, -a.y * b.x),
		};
	}

	template<std::size_t C, typename T, typename>
	LYAH_CONSTEXPR T dot(vec<C, T> a, vec<C, T> b) {
		return sum(a * b);
	}

	template<typename T>
	LYAH_CONSTEXPR T dot(quat<T> a, quat<T> b) {
		return a.w * b.w + a.x * b.x + a.y * b.y + a.z * b.z;
	}

	template<std::size_t C, typename T, typename>
	LYAH_CONSTEXPR_CPP26 T length(vec<C, T> a) {
		return sqrt(lengthSquared(a));
	}

	template<typename T>
	LYAH_CONSTEXPR_CPP26 T length(quat<T> a) {
		return sqrt(lengthSquared(a));
	}

	template<std::size_t C, typename T, typename>
	LYAH_CONSTEXPR T lengthSquared(vec<C, T> a) {
		return dot(a, a);
	}

	template<typename T>
	LYAH_CONSTEXPR T lengthSquared(quat<T> a) {
		return dot(a, a);
	}

	template<std::size_t C, typename T, typename>
	LYAH_CONSTEXPR_CPP26 T distance(vec<C, T> a, vec<C, T> b) {
		return length(b - a);
	}

	template<typename T>
	LYAH_CONSTEXPR_CPP26 T distance(quat<T> a, quat<T> b) {
		return length(b - a);
	}

	template<std::size_t C, typename T, typename>
	LYAH_CONSTEXPR T distanceSquared(vec<C, T> a, vec<C, T> b) {
		return lengthSquared(b - a);
	}

	template<typename T>
	LYAH_CONSTEXPR T distanceSquared(quat<T> a, quat<T> b) {
		return lengthSquared(b - a);
	}

	template<std::size_t C, typename T, typename>
	LYAH_CONSTEXPR_CPP26 vec<C, T> normalized(vec<C, T> a) {
		return a / length(a);
	}

	template<typename T>
	LYAH_CONSTEXPR_CPP26 quat<T> normalized(quat<T> a) {
		return a / length(a);
	}
}