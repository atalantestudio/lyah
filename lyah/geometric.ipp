// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

template<typename T, typename>
LYAH_CONSTEXPR T lyah::parallelogramArea(vec<2, T> a, vec<2, T> b) {
	return a.x * b.y - a.y * b.x;
}

template<typename T, typename>
LYAH_CONSTEXPR lyah::vec<2, T> lyah::perpendicularLeft(vec<2, T> a) {
	return {-a.y, a.x};
}

template<typename T, typename>
LYAH_CONSTEXPR lyah::vec<2, T> lyah::perpendicularRight(vec<2, T> a) {
	return {a.y, -a.x};
}

template<typename T, typename>
LYAH_CONSTEXPR lyah::vec<3, T> lyah::cross(vec<3, T> a, vec<3, T> b) {
	return {
		a.y * b.z + -a.z * b.y,
		a.z * b.x + -a.x * b.z,
		a.x * b.y + -a.y * b.x,
	};
}

template<std::size_t C, typename T, typename>
LYAH_CONSTEXPR T lyah::dot(vec<C, T> a, vec<C, T> b) {
	return sum(a * b);
}

template<typename T>
LYAH_CONSTEXPR T lyah::dot(quat<T> a, quat<T> b) {
	return a.w * b.w + a.x * b.x + a.y * b.y + a.z * b.z;
}

template<std::size_t C, typename T, typename>
LYAH_CONSTEXPR_CPP26 T lyah::length(vec<C, T> a) {
	return sqrt(lengthSquared(a));
}

template<typename T>
LYAH_CONSTEXPR_CPP26 T lyah::length(quat<T> a) {
	return sqrt(lengthSquared(a));
}

template<std::size_t C, typename T, typename>
LYAH_CONSTEXPR T lyah::lengthSquared(vec<C, T> a) {
	return dot(a, a);
}

template<typename T>
LYAH_CONSTEXPR T lyah::lengthSquared(quat<T> a) {
	return dot(a, a);
}

template<std::size_t C, typename T, typename>
LYAH_CONSTEXPR_CPP26 T lyah::distance(vec<C, T> a, vec<C, T> b) {
	return length(b - a);
}

template<typename T>
LYAH_CONSTEXPR_CPP26 T lyah::distance(quat<T> a, quat<T> b) {
	return length(b - a);
}

template<std::size_t C, typename T, typename>
LYAH_CONSTEXPR T lyah::distanceSquared(vec<C, T> a, vec<C, T> b) {
	return lengthSquared(b - a);
}

template<typename T>
LYAH_CONSTEXPR T lyah::distanceSquared(quat<T> a, quat<T> b) {
	return lengthSquared(b - a);
}

template<std::size_t C, typename T, typename>
LYAH_CONSTEXPR_CPP26 lyah::vec<C, T> lyah::normalized(vec<C, T> a) {
	return a / length(a);
}

template<typename T>
LYAH_CONSTEXPR_CPP26 lyah::quat<T> lyah::normalized(quat<T> a) {
	return a / length(a);
}