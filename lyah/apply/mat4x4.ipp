// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

template<typename T>
LYAH_CONSTEXPR lyah::mat<4, 4, T> lyah::apply<lyah::mat<4, 4, T>>::identity() {
	return {
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1,
	};
}

template<typename T>
LYAH_CONSTEXPR lyah::mat<4, 4, T> lyah::apply<lyah::mat<4, 4, T>>::translation(vec<3, T> translation) {
	const T x = translation.x;
	const T y = translation.y;
	const T z = translation.z;

	return {
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		x, y, z, 1,
	};
}

template<typename T>
LYAH_CONSTEXPR_CPP26 lyah::mat<4, 4, T> lyah::apply<lyah::mat<4, 4, T>>::rotationAxisAngle(vec<3, T> axis, T angle) {
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

template<typename T>
LYAH_CONSTEXPR lyah::mat<4, 4, T> lyah::apply<lyah::mat<4, 4, T>>::scaling(vec<3, T> scale) {
	const T x = scale.x;
	const T y = scale.y;
	const T z = scale.z;

	return {
		x, 0, 0, 0,
		0, y, 0, 0,
		0, 0, z, 0,
		0, 0, 0, 1,
	};
}

template<typename T>
LYAH_CONSTEXPR lyah::mat<4, 4, T> lyah::apply<lyah::mat<4, 4, T>>::uniformScaling(T x) {
	return {
		x, 0, 0, 0,
		0, x, 0, 0,
		0, 0, x, 0,
		0, 0, 0, 1,
	};
}