// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

namespace lyah {
	LYAH_CONSTEXPR vec<2, std::int64_t>::vec() :
		x(0),
		y(0)
	{}

	LYAH_CONSTEXPR vec<2, std::int64_t>::vec(std::int64_t x, std::int64_t y) :
		x(x),
		y(y)
	{}

	LYAH_CONSTEXPR vec<2, std::int64_t>::vec(std::int64_t a) :
		x(a),
		y(a)
	{}

	template<typename U>
	LYAH_CONSTEXPR vec<2, std::int64_t>::vec(vec<2, U> a) :
		x(static_cast<std::int64_t>(a.x)),
		y(static_cast<std::int64_t>(a.y))
	{}

	LYAH_CONSTEXPR std::int64_t vec<2, std::int64_t>::operator[](std::size_t index) const {
		LYAH_ASSERT(index < 2);

		return static_cast<const std::int64_t*>(static_cast<const void*>(this))[index];
	}

	std::int64_t& vec<2, std::int64_t>::operator[](std::size_t index) {
		LYAH_ASSERT(index < 2);

		return static_cast<std::int64_t*>(static_cast<void*>(this))[index];
	}
}