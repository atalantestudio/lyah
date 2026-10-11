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