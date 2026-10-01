// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

namespace lyah {
	LYAH_CONSTEXPR vec<2, std::float_t>::vec() :
		x(0.0f),
		y(0.0f)
	{}

	LYAH_CONSTEXPR vec<2, std::float_t>::vec(std::float_t x, std::float_t y) :
		x(x),
		y(y)
	{}

	LYAH_CONSTEXPR vec<2, std::float_t>::vec(std::float_t a) :
		x(a),
		y(a)
	{}

	template<typename U>
	LYAH_CONSTEXPR vec<2, std::float_t>::vec(vec<2, U> a) :
		x(static_cast<std::float_t>(a.x)),
		y(static_cast<std::float_t>(a.y))
	{}

	LYAH_CONSTEXPR std::float_t vec<2, std::float_t>::operator[](std::size_t index) const {
		LYAH_ASSERT(index < 2);

		return static_cast<const std::float_t*>(static_cast<const void*>(this))[index];
	}

	std::float_t& vec<2, std::float_t>::operator[](std::size_t index) {
		LYAH_ASSERT(index < 2);

		return static_cast<std::float_t*>(static_cast<void*>(this))[index];
	}
}