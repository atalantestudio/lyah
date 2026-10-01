// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

namespace lyah {
	LYAH_CONSTEXPR vec<4, std::float_t>::vec() :
		x(0.0f),
		y(0.0f),
		z(0.0f),
		w(0.0f)
	{}

	LYAH_CONSTEXPR vec<4, std::float_t>::vec(std::float_t x, std::float_t y, std::float_t z, std::float_t w) :
		x(x),
		y(y),
		z(z),
		w(w)
	{}

	LYAH_CONSTEXPR vec<4, std::float_t>::vec(std::float_t a) :
		x(a),
		y(a),
		z(a),
		w(a)
	{}

	template<typename U>
	LYAH_CONSTEXPR vec<4, std::float_t>::vec(vec<4, U> a) :
		x(static_cast<std::float_t>(a.x)),
		y(static_cast<std::float_t>(a.y)),
		z(static_cast<std::float_t>(a.z)),
		w(static_cast<std::float_t>(a.w))
	{}

	LYAH_CONSTEXPR std::float_t vec<4, std::float_t>::operator[](std::size_t index) const {
		LYAH_ASSERT(index < 4);

		return static_cast<const std::float_t*>(static_cast<const void*>(this))[index];
	}

	std::float_t& vec<4, std::float_t>::operator[](std::size_t index) {
		LYAH_ASSERT(index < 4);

		return static_cast<std::float_t*>(static_cast<void*>(this))[index];
	}
}