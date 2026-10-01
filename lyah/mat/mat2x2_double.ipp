// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

namespace lyah {
	LYAH_CONSTEXPR mat<2, 2, std::double_t> mat<2, 2, std::double_t>::identity() {
		return {
			1.0, 0.0,
			0.0, 1.0,
		};
	}

	LYAH_CONSTEXPR_CPP26 mat<2, 2, std::double_t> mat<2, 2, std::double_t>::rotation(std::double_t a) {
		const std::double_t c = cos(a);
		const std::double_t s = sin(a);

		return {
			c, -s,
			s,  c,
		};
	}

	LYAH_CONSTEXPR mat<2, 2, std::double_t>::mat() :
		m{}
	{}

	LYAH_CONSTEXPR mat<2, 2, std::double_t>::mat(std::double_t m00, std::double_t m01, std::double_t m10, std::double_t m11) :
		m{
			{m00, m01},
			{m10, m11}
		}
	{}

	LYAH_CONSTEXPR mat<2, 2, std::double_t>::mat(vec<2, std::double_t> m0, vec<2, std::double_t> m1) :
		m{
			m0,
			m1
		}
	{}

	template<typename U>
	LYAH_CONSTEXPR mat<2, 2, std::double_t>::mat(mat<2, 2, U> a) :
		m{
			vec<2, std::double_t>(a[0]),
			vec<2, std::double_t>(a[1]),
		}
	{}

	LYAH_CONSTEXPR vec<2, std::double_t> mat<2, 2, std::double_t>::operator[](std::size_t index) const {
		LYAH_ASSERT(index < 2);

		return m[index];
	}

	vec<2, std::double_t>& mat<2, 2, std::double_t>::operator[](std::size_t index) {
		LYAH_ASSERT(index < 2);

		return m[index];
	}
}