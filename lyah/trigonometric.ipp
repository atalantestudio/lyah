// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

namespace lyah {
	template<typename T, typename>
	LYAH_CONSTEXPR T degrees(T radians) {
		return radians * static_cast<T>(57.295779513082321);
	}

	template<std::size_t C, typename T, typename>
	LYAH_CONSTEXPR vec<C, T> degrees(vec<C, T> radians) {
		return radians * static_cast<T>(57.295779513082321);
	}

	template<typename T, typename>
	LYAH_CONSTEXPR T radians(T degrees) {
		return degrees * static_cast<T>(0.017453292519943);
	}

	template<std::size_t C, typename T, typename>
	LYAH_CONSTEXPR vec<C, T> radians(vec<C, T> degrees) {
		return degrees * static_cast<T>(0.017453292519943);
	}

	LYAH_CONSTEXPR_CPP26 std::float_t sin(std::float_t a) {
		return std::sinf(a);
	}

	LYAH_CONSTEXPR_CPP26 std::double_t sin(std::double_t a) {
		return std::sinl(a);
	}

	template<typename T>
	LYAH_CONSTEXPR_CPP26 vec<2, T> sin(vec<2, T> a) {
		a.x = sin(a.x);
		a.y = sin(a.y);

		return a;
	}

	template<typename T>
	LYAH_CONSTEXPR_CPP26 vec<3, T> sin(vec<3, T> a) {
		a.x = sin(a.x);
		a.y = sin(a.y);
		a.z = sin(a.z);

		return a;
	}

	template<typename T>
	LYAH_CONSTEXPR_CPP26 vec<4, T> sin(vec<4, T> a) {
		a.x = sin(a.x);
		a.y = sin(a.y);
		a.z = sin(a.z);
		a.w = sin(a.w);

		return a;
	}

	LYAH_CONSTEXPR_CPP26 std::float_t cos(std::float_t a) {
		return std::cosf(a);
	}

	LYAH_CONSTEXPR_CPP26 std::double_t cos(std::double_t a) {
		return std::cosl(a);
	}

	template<typename T>
	LYAH_CONSTEXPR_CPP26 vec<2, T> cos(vec<2, T> a) {
		a.x = cos(a.x);
		a.y = cos(a.y);

		return a;
	}

	template<typename T>
	LYAH_CONSTEXPR_CPP26 vec<3, T> cos(vec<3, T> a) {
		a.x = cos(a.x);
		a.y = cos(a.y);
		a.z = cos(a.z);

		return a;
	}

	template<typename T>
	LYAH_CONSTEXPR_CPP26 vec<4, T> cos(vec<4, T> a) {
		a.x = cos(a.x);
		a.y = cos(a.y);
		a.z = cos(a.z);
		a.w = cos(a.w);

		return a;
	}

	LYAH_CONSTEXPR_CPP26 std::float_t tan(std::float_t a) {
		return std::tanf(a);
	}

	LYAH_CONSTEXPR_CPP26 std::double_t tan(std::double_t a) {
		return std::tanl(a);
	}

	template<typename T>
	LYAH_CONSTEXPR_CPP26 vec<2, T> tan(vec<2, T> a) {
		a.x = tan(a.x);
		a.y = tan(a.y);

		return a;
	}

	template<typename T>
	LYAH_CONSTEXPR_CPP26 vec<3, T> tan(vec<3, T> a) {
		a.x = tan(a.x);
		a.y = tan(a.y);
		a.z = tan(a.z);

		return a;
	}

	template<typename T>
	LYAH_CONSTEXPR_CPP26 vec<4, T> tan(vec<4, T> a) {
		a.x = tan(a.x);
		a.y = tan(a.y);
		a.z = tan(a.z);
		a.w = tan(a.w);

		return a;
	}
}