// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

template<typename T>
LYAH_CONSTEXPR lyah::quat<T> lyah::apply<lyah::quat<T>>::identity() {
	return {1, 0, 0, 0};
}

template<typename T>
LYAH_CONSTEXPR_CPP26 lyah::quat<T> lyah::apply<lyah::quat<T>>::rotationAxisAngle(vec<3, T> axis, T angle) {
	angle *= static_cast<T>(0.5);
	axis *= sin<T>(angle);

	return {cos(angle), axis.x, axis.y, axis.z};
}