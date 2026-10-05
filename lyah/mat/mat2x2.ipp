// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

namespace lyah {
	template<typename T, typename>
	LYAH_CONSTEXPR lyah::mat<2, 2, T> identity() {
		return {
			1, 0,
			0, 1,
		};
	}
}

template<typename T>
LYAH_CONSTEXPR lyah::mat<2, 2, T>::mat() :
	m{}
{}

template<typename T>
LYAH_CONSTEXPR lyah::mat<2, 2, T>::mat(T m00, T m01, T m10, T m11) :
	m{
		{m00, m01},
		{m10, m11}
	}
{}

template<typename T>
LYAH_CONSTEXPR lyah::mat<2, 2, T>::mat(vec<2, T> m0, vec<2, T> m1) :
	m{
		m0,
		m1
	}
{}

template<typename T>
template<typename U>
LYAH_CONSTEXPR lyah::mat<2, 2, T>::mat(mat<2, 2, U> a) :
	m{
		vec<2, T>(a[0]),
		vec<2, T>(a[1]),
	}
{}

template<typename T>
LYAH_CONSTEXPR lyah::vec<2, T> lyah::mat<2, 2, T>::operator[](std::size_t index) const {
	LYAH_ASSERT(index < 2);

	return m[index];
}

template<typename T>
lyah::vec<2, T>& lyah::mat<2, 2, T>::operator[](std::size_t index) {
	LYAH_ASSERT(index < 2);

	return m[index];
}

namespace lyah {
	template<typename T, typename>
	LYAH_CONSTEXPR mat<2, 2, T> operator*(mat<2, 2, T> a, mat<2, 2, T> b) {
		return {
			a[0][0] * b[0][0] + a[0][1] * b[1][0], a[0][0] * b[0][1] + a[0][1] * b[1][1],
			a[1][0] * b[0][0] + a[1][1] * b[1][0], a[1][0] * b[0][1] + a[1][1] * b[1][1],
		};
	}

	template<typename T, typename>
	LYAH_CONSTEXPR T determinant(mat<2, 2, T> a) {
		return a[0][0] * a[1][1] - a[0][1] * a[1][0];
	}

	template<typename T, typename>
	LYAH_CONSTEXPR mat<2, 2, T> adjugate(mat<2, 2, T> a) {
		return {
			 a[1][1], -a[0][1],
			-a[1][0],  a[0][0],
		};
	}

	template<typename T, typename>
	LYAH_CONSTEXPR mat<2, 2, T> transpose(mat<2, 2, T> a) {
		T t;

		t = a[0][1];
		a[0][1] = a[1][0];
		a[1][0] = t;

		return a;
	}
}