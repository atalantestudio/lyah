// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

template<typename T>
LYAH_CONSTEXPR lyah::mat<3, 3, T> lyah::apply<lyah::mat<3, 3, T>>::identity() {
	return {
		1, 0, 0,
		0, 1, 0,
		0, 0, 1,
	};
}

template<typename T>
LYAH_CONSTEXPR lyah::mat<3, 3, T> lyah::apply<lyah::mat<3, 3, T>>::translation(vec<2, T> translation) {
	const T x = translation.x;
	const T y = translation.y;

	return {
		1, 0, 0,
		0, 1, 0,
		x, y, 1,
	};
}

template<typename T>
LYAH_CONSTEXPR_CPP26 lyah::mat<3, 3, T> lyah::apply<lyah::mat<3, 3, T>>::rotationAngle(T angle) {
	const T c = cos(angle);
	const T s = sin(angle);

	return {
		 c, -s,  0,
		 s,  c,  0,
		 0,  0,  1,
	};
}

template<typename T>
LYAH_CONSTEXPR lyah::mat<3, 3, T> lyah::apply<lyah::mat<3, 3, T>>::scaling(vec<2, T> scale) {
	const T x = scale.x;
	const T y = scale.y;

	return {
		x, 0, 0,
		0, y, 0,
		0, 0, 1,
	};
}

template<typename T>
LYAH_CONSTEXPR lyah::mat<3, 3, T> lyah::apply<lyah::mat<3, 3, T>>::uniformScaling(T x) {
	return {
		x, 0, 0,
		0, x, 0,
		0, 0, 1,
	};
}