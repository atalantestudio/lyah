// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

template<typename T>
lyah::vec<2, T> lyah::apply<2, T>::scalarModifier(vec<2, T> x, T (*modifier)(T)) {
	x.x = modifier(x.x);
	x.y = modifier(x.y);

	return x;
}

template<typename T>
lyah::vec<3, T> lyah::apply<3, T>::scalarModifier(vec<3, T> x, T (*modifier)(T)) {
	x.x = modifier(x.x);
	x.y = modifier(x.y);
	x.z = modifier(x.z);

	return x;
}

template<typename T>
lyah::vec<4, T> lyah::apply<4, T>::scalarModifier(vec<4, T> x, T (*modifier)(T)) {
	x.x = modifier(x.x);
	x.y = modifier(x.y);
	x.z = modifier(x.z);
	x.w = modifier(x.w);

	return x;
}