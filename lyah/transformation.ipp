// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

template<std::size_t M, typename T, typename>
LYAH_CONSTEXPR lyah::mat<M, M, T> lyah::translation(vec<M - 1, T> translation) {
	return apply<mat<M, M, T>>::translation(translation);
}

template<std::size_t M, typename T, typename>
LYAH_CONSTEXPR_CPP26 lyah::mat<M, M, T> lyah::rotationAngle(T angle) {
	return apply<mat<M, M, T>>::rotationAngle(angle);
}

template<typename T, typename>
LYAH_CONSTEXPR_CPP26 lyah::mat<4, 4, T> lyah::rotationAxisAngle(vec<3, T> axis, T angle) {
	const T x = axis.x;
	const T y = axis.y;
	const T z = axis.z;
	const T c = cos(angle);
	const T s = sin(angle);
	const T _1_c = 1 - c;

	return {
		x * x * _1_c + c,     x * y * _1_c + z * s, x * z * _1_c - y * s, 0,
		x * y * _1_c - z * s, y * y * _1_c + c,     y * z * _1_c + x * s, 0,
		x * z * _1_c + y * s, y * z * _1_c - x * s, z * z * _1_c + c,     0,
		0,                    0,                    0,                    1,
	};
}

template<typename T, typename>
LYAH_CONSTEXPR_CPP26 lyah::quat<T> lyah::rotationAxisAngle(vec<3, T> axis, T angle) {
	angle *= static_cast<T>(0.5);
	axis *= sin<T>(angle);

	return {cos(angle), axis.x, axis.y, axis.z};
}

template<std::size_t M, typename T, typename>
LYAH_CONSTEXPR lyah::mat<M, M, T> lyah::scaling(vec<M - 1, T> scale) {
	return apply<mat<M, M, T>>::scaling(scale);
}

template<std::size_t M, typename T, typename>
LYAH_CONSTEXPR lyah::mat<M, M, T> lyah::uniformScaling(T scale) {
	return apply<mat<M, M, T>>::uniformScaling(scale);
}

template<typename T, typename>
LYAH_CONSTEXPR_CPP26 lyah::mat<4, 4, T> lyah::lookAt(vec<3, T> eye, vec<3, T> target, vec<3, T> up) {
	const vec<3, T> f = normalized(target - eye);
	const vec<3, T> r = normalized(cross(up, f));
	const vec<3, T> u = cross(f, r);

	return {
		 r.x,          u.x,          f.x,          0,
		 r.y,          u.y,          f.y,          0,
		 r.z,          u.z,          f.z,          0,
		-dot(r, eye), -dot(u, eye), -dot(f, eye),  1,
	};
}