// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

template<typename U, std::size_t C, typename T, typename>
LYAH_CONSTEXPR U lyah::translation(vec<C, T> translation) {
	return apply<U>::translation(translation);
}

template<typename U, typename T, typename>
LYAH_CONSTEXPR_CPP26 U lyah::rotationAngle(T angle) {
	return apply<U>::rotationAngle(angle);
}

template<typename U, typename T, typename>
LYAH_CONSTEXPR_CPP26 U lyah::rotationAxisAngle(vec<3, T> axis, T angle) {
	return apply<U>::rotationAxisAngle(axis, angle);
}

template<typename U, std::size_t C, typename T, typename>
LYAH_CONSTEXPR U lyah::scaling(vec<C, T> scale) {
	return apply<U>::scaling(scale);
}

template<typename U, typename T, typename>
LYAH_CONSTEXPR U lyah::uniformScaling(T scale) {
	return apply<U>::uniformScaling(scale);
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