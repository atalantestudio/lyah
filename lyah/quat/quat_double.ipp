// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

namespace lyah {
	LYAH_CONSTEXPR quat<std::double_t> quat<std::double_t>::identity() {
		return {1.0, 0.0, 0.0, 0.0};
	}

	// TODO: Make constexpr.
	/*LYAH_CONSTEXPR*/ quat<std::double_t> quat<std::double_t>::axisAngle(vec<3, std::double_t> axis, std::double_t angle) {
		angle *= 0.5;
		axis *= sin(angle);

		return {cos(angle), axis.x, axis.y, axis.z};
	}

	LYAH_CONSTEXPR quat<std::double_t>::quat() :
		w(0.0),
		x(0.0),
		y(0.0),
		z(0.0)
	{}

	LYAH_CONSTEXPR quat<std::double_t>::quat(std::double_t w, std::double_t x, std::double_t y, std::double_t z) :
		w(w),
		x(x),
		y(y),
		z(z)
	{}

	template<typename U>
	LYAH_CONSTEXPR quat<std::double_t>::quat(quat<U> a) :
		w(static_cast<std::double_t>(a.w)),
		x(static_cast<std::double_t>(a.x)),
		y(static_cast<std::double_t>(a.y)),
		z(static_cast<std::double_t>(a.z))
	{}

	LYAH_CONSTEXPR std::double_t quat<std::double_t>::operator[](std::size_t index) const {
		LYAH_ASSERT(index < 4);

		return static_cast<const std::double_t*>(static_cast<const void*>(this))[index];
	}

	std::double_t& quat<std::double_t>::operator[](std::size_t index) {
		LYAH_ASSERT(index < 4);

		return static_cast<std::double_t*>(static_cast<void*>(this))[index];
	}
}