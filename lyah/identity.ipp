// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

template<typename T>
LYAH_CONSTEXPR T lyah::identity() {
	return apply<T>::identity();
}