// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

namespace lyah {
	LYAH_CONSTEXPR vec<4, std::int64_t>::vec() :
		x(0),
		y(0),
		z(0),
		w(0)
	{}

	LYAH_CONSTEXPR vec<4, std::int64_t>::vec(std::int64_t x, std::int64_t y, std::int64_t z, std::int64_t w) :
		x(x),
		y(y),
		z(z),
		w(w)
	{}

	LYAH_CONSTEXPR vec<4, std::int64_t>::vec(std::int64_t a) :
		x(a),
		y(a),
		z(a),
		w(a)
	{}

	template<typename U>
	LYAH_CONSTEXPR vec<4, std::int64_t>::vec(vec<4, U> a) :
		x(static_cast<std::int64_t>(a.x)),
		y(static_cast<std::int64_t>(a.y)),
		z(static_cast<std::int64_t>(a.z)),
		w(static_cast<std::int64_t>(a.w))
	{}

	LYAH_CONSTEXPR std::int64_t vec<4, std::int64_t>::operator[](std::size_t index) const {
		LYAH_ASSERT(index < 4);

		return static_cast<const std::int64_t*>(static_cast<const void*>(this))[index];
	}

	std::int64_t& vec<4, std::int64_t>::operator[](std::size_t index) {
		LYAH_ASSERT(index < 4);

		return static_cast<std::int64_t*>(static_cast<void*>(this))[index];
	}
}