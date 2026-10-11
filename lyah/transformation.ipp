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

template<typename U, typename T, typename>
LYAH_CONSTEXPR_CPP26 U lyah::rotationAxisAngle(vec<3, T> axis, T angle) {
	return apply<U>::rotationAxisAngle(axis, angle);
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