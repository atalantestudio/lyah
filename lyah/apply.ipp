// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

template<typename T>
lyah::vec<2, T> lyah::apply<2, T>::modifier(vec<2, T> x, T (*modifier)(T)) {
	x.x = modifier(x.x);
	x.y = modifier(x.y);

	return x;
}

template<typename T>
lyah::vec<2, T> lyah::apply<2, T>::modifier(vec<2, T> x, T y, T (*modifier)(T, T)) {
	x.x = modifier(x.x, y);
	x.y = modifier(x.y, y);

	return x;
}

template<typename T>
lyah::vec<2, T> lyah::apply<2, T>::modifier(vec<2, T> x, vec<2, T> y, T (*modifier)(T, T)) {
	x.x = modifier(x.x, y.x);
	x.y = modifier(x.y, y.y);

	return x;
}

template<typename T>
lyah::vec<3, T> lyah::apply<3, T>::modifier(vec<3, T> x, T (*modifier)(T)) {
	x.x = modifier(x.x);
	x.y = modifier(x.y);
	x.z = modifier(x.z);

	return x;
}

template<typename T>
lyah::vec<3, T> lyah::apply<3, T>::modifier(vec<3, T> x, T y, T (*modifier)(T, T)) {
	x.x = modifier(x.x, y);
	x.y = modifier(x.y, y);
	x.z = modifier(x.z, y);

	return x;
}

template<typename T>
lyah::vec<3, T> lyah::apply<3, T>::modifier(vec<3, T> x, vec<3, T> y, T (*modifier)(T, T)) {
	x.x = modifier(x.x, y.x);
	x.y = modifier(x.y, y.y);
	x.z = modifier(x.z, y.z);

	return x;
}

template<typename T>
lyah::vec<4, T> lyah::apply<4, T>::modifier(vec<4, T> x, T (*modifier)(T)) {
	x.x = modifier(x.x);
	x.y = modifier(x.y);
	x.z = modifier(x.z);
	x.w = modifier(x.w);

	return x;
}

template<typename T>
lyah::vec<4, T> lyah::apply<4, T>::modifier(vec<4, T> x, T y, T (*modifier)(T, T)) {
	x.x = modifier(x.x, y);
	x.y = modifier(x.y, y);
	x.z = modifier(x.z, y);
	x.w = modifier(x.w, y);

	return x;
}

template<typename T>
lyah::vec<4, T> lyah::apply<4, T>::modifier(vec<4, T> x, vec<4, T> y, T (*modifier)(T, T)) {
	x.x = modifier(x.x, y.x);
	x.y = modifier(x.y, y.y);
	x.z = modifier(x.z, y.z);
	x.w = modifier(x.w, y.w);

	return x;
}