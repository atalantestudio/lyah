// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

namespace lyah {
	LYAH_CONSTEXPR quat<std::float_t> quat<std::float_t>::identity() {
		return {1.0f, 0.0f, 0.0f, 0.0f};
	}

	LYAH_CONSTEXPR_CPP26 quat<std::float_t> quat<std::float_t>::axisAngle(vec<3, std::float_t> axis, std::float_t angle) {
		angle *= 0.5f;
		axis *= sin(angle);

		return {cos(angle), axis.x, axis.y, axis.z};
	}

	LYAH_CONSTEXPR quat<std::float_t>::quat() :
		w(0.0f),
		x(0.0f),
		y(0.0f),
		z(0.0f)
	{}

	LYAH_CONSTEXPR quat<std::float_t>::quat(std::float_t w, std::float_t x, std::float_t y, std::float_t z) :
		w(w),
		x(x),
		y(y),
		z(z)
	{}

	template<typename U>
	LYAH_CONSTEXPR quat<std::float_t>::quat(quat<U> a) :
		w(static_cast<std::float_t>(a.w)),
		x(static_cast<std::float_t>(a.x)),
		y(static_cast<std::float_t>(a.y)),
		z(static_cast<std::float_t>(a.z))
	{}

	LYAH_CONSTEXPR std::float_t quat<std::float_t>::operator[](std::size_t index) const {
		LYAH_ASSERT(index < 4);

		return static_cast<const std::float_t*>(static_cast<const void*>(this))[index];
	}

	std::float_t& quat<std::float_t>::operator[](std::size_t index) {
		LYAH_ASSERT(index < 4);

		return static_cast<std::float_t*>(static_cast<void*>(this))[index];
	}
}