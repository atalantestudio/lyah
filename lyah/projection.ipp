// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

template<typename T, typename>
LYAH_CONSTEXPR lyah::mat<3, 3, T> lyah::orthographic(vec<2, T> o, vec<2, T> v) {
	return {
		 2 / v.x,  0,        0,
		 0,        2 / v.y,  0,
		 o.x,      o.y,      1,
	};
}

template<typename T, typename>
LYAH_CONSTEXPR lyah::mat<3, 3, T> lyah::orthographicScreen(vec<2, T> v) {
	return {
		 2 / v.x,  0,        0,
		 0,       -2 / v.y,  0,
		-1,        1,        1,
	};
}

template<typename T, typename>
LYAH_CONSTEXPR lyah::mat<4, 4, T> lyah::orthographic(T l, T r, T b, T t, T n, T f) {
	const T r_l = r - l;
	const T t_b = t - b;
	const T f_n = f - n;

	return {
		 2 / r_l,        0,              0,        0,
		 0,              2 / t_b,        0,        0,
		 0,              0,              1 / f_n,  0,
		-(r + l) / r_l, -(t + b) / t_b, -n / f_n,  1,
	};
}

template<typename T, typename>
LYAH_CONSTEXPR_CPP26 lyah::mat<4, 4, T> lyah::perspective(T fov, T r, T n, T f) {
	const T h = 1 / tan(fov / 2);
	const T f_n = f - n;

	return {
		 h / r,  0,  0,              0,
		 0,      h,  0,              0,
		 0,      0,  f / f_n,        1,
		 0,      0, -(n * f) / f_n,  0,
	};
}

template<typename T, typename>
LYAH_CONSTEXPR_CPP26 lyah::mat<4, 4, T> lyah::perspectiveReversedZ(T fov, T r, T n) {
	const T h = 1 / tan(fov / 2);

	return {
		 h / r, 0,  0,  0,
		 0,     h,  0,  0,
		 0,     0,  0,  1,
		 0,     0,  n,  0,
	};
}