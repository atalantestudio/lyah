// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

template<typename T>
LYAH_CONSTEXPR lyah::mat<2, 2, T> lyah::apply<lyah::mat<2, 2, T>>::identity() {
	return {
		1, 0,
		0, 1,
	};
}

template<typename T>
LYAH_CONSTEXPR_CPP26 lyah::mat<2, 2, T> lyah::apply<lyah::mat<2, 2, T>>::rotationAngle(T angle) {
	const T c = cos(angle);
	const T s = sin(angle);

	return {
		 c, -s,
		 s,  c,
	};
}