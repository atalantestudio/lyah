// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

namespace lyah {
	LYAH_CONSTEXPR vec<3, std::float_t>::vec() :
		x(0.0f),
		y(0.0f),
		z(0.0f)
	{}

	LYAH_CONSTEXPR vec<3, std::float_t>::vec(std::float_t x, std::float_t y, std::float_t z) :
		x(x),
		y(y),
		z(z)
	{}

	LYAH_CONSTEXPR vec<3, std::float_t>::vec(std::float_t a) :
		x(a),
		y(a),
		z(a)
	{}

	template<typename U>
	LYAH_CONSTEXPR vec<3, std::float_t>::vec(vec<3, U> a) :
		x(static_cast<std::float_t>(a.x)),
		y(static_cast<std::float_t>(a.y)),
		z(static_cast<std::float_t>(a.z))
	{}

	LYAH_CONSTEXPR std::float_t vec<3, std::float_t>::operator[](std::size_t index) const {
		LYAH_ASSERT(index < 3);

		return static_cast<const std::float_t*>(static_cast<const void*>(this))[index];
	}

	std::float_t& vec<3, std::float_t>::operator[](std::size_t index) {
		LYAH_ASSERT(index < 3);

		return static_cast<std::float_t*>(static_cast<void*>(this))[index];
	}
}