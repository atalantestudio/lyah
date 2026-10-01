// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

namespace lyah {
	LYAH_CONSTEXPR vec<3, std::double_t>::vec() :
		x(0.0),
		y(0.0),
		z(0.0)
	{}

	LYAH_CONSTEXPR vec<3, std::double_t>::vec(std::double_t x, std::double_t y, std::double_t z) :
		x(x),
		y(y),
		z(z)
	{}

	LYAH_CONSTEXPR vec<3, std::double_t>::vec(std::double_t a) :
		x(a),
		y(a),
		z(a)
	{}

	template<typename U>
	LYAH_CONSTEXPR vec<3, std::double_t>::vec(vec<3, U> a) :
		x(static_cast<std::double_t>(a.x)),
		y(static_cast<std::double_t>(a.y)),
		z(static_cast<std::double_t>(a.z))
	{}

	LYAH_CONSTEXPR std::double_t vec<3, std::double_t>::operator[](std::size_t index) const {
		LYAH_ASSERT(index < 3);

		return static_cast<const std::double_t*>(static_cast<const void*>(this))[index];
	}

	std::double_t& vec<3, std::double_t>::operator[](std::size_t index) {
		LYAH_ASSERT(index < 3);

		return static_cast<std::double_t*>(static_cast<void*>(this))[index];
	}
}