// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

LYAH_CONSTEXPR_CPP26 std::float_t lyah::log2(std::float_t x) {
	return std::log2f(x);
}

LYAH_CONSTEXPR_CPP26 std::double_t lyah::log2(std::double_t x) {
	return std::log2l(x);
}

LYAH_CONSTEXPR_CPP26 std::float_t lyah::pow(std::float_t x, std::float_t exponent) {
	return std::powf(x, exponent);
}

LYAH_CONSTEXPR_CPP26 std::double_t lyah::pow(std::double_t x, std::double_t exponent) {
	return std::powl(x, exponent);
}

template<typename T, typename>
LYAH_CONSTEXPR_CPP26 lyah::vec<2, T> lyah::pow(vec<2, T> x, T exponent) {
	x.x = pow(x.x, exponent);
	x.y = pow(x.y, exponent);

	return x;
}

template<typename T, typename>
LYAH_CONSTEXPR_CPP26 lyah::vec<3, T> lyah::pow(vec<3, T> x, T exponent) {
	x.x = pow(x.x, exponent);
	x.y = pow(x.y, exponent);
	x.z = pow(x.z, exponent);

	return x;
}

template<typename T, typename>
LYAH_CONSTEXPR_CPP26 lyah::vec<4, T> lyah::pow(vec<4, T> x, T exponent) {
	x.x = pow(x.x, exponent);
	x.y = pow(x.y, exponent);
	x.z = pow(x.z, exponent);
	x.w = pow(x.w, exponent);

	return x;
}

template<typename T, typename>
LYAH_CONSTEXPR_CPP26 lyah::vec<2, T> lyah::pow(vec<2, T> x, lyah::vec<2, T> exponent) {
	x.x = pow(x.x, exponent.x);
	x.y = pow(x.y, exponent.y);

	return x;
}

template<typename T, typename>
LYAH_CONSTEXPR_CPP26 lyah::vec<3, T> lyah::pow(vec<3, T> x, lyah::vec<3, T> exponent) {
	x.x = pow(x.x, exponent.x);
	x.y = pow(x.y, exponent.y);
	x.z = pow(x.z, exponent.z);

	return x;
}

template<typename T, typename>
LYAH_CONSTEXPR_CPP26 lyah::vec<4, T> lyah::pow(vec<4, T> x, lyah::vec<4, T> exponent) {
	x.x = pow(x.x, exponent.x);
	x.y = pow(x.y, exponent.y);
	x.z = pow(x.z, exponent.z);
	x.w = pow(x.w, exponent.w);

	return x;
}

LYAH_CONSTEXPR_CPP26 std::float_t lyah::sqrt(std::float_t x) {
	return std::sqrtf(x);
}

LYAH_CONSTEXPR_CPP26 std::double_t lyah::sqrt(std::double_t x) {
	return std::sqrtl(x);
}

template<typename T, typename>
LYAH_CONSTEXPR_CPP26 lyah::vec<2, T> lyah::sqrt(vec<2, T> x) {
	x.x = sqrt(x.x);
	x.y = sqrt(x.y);

	return x;
}

template<typename T, typename>
LYAH_CONSTEXPR_CPP26 lyah::vec<3, T> lyah::sqrt(vec<3, T> x) {
	x.x = sqrt(x.x);
	x.y = sqrt(x.y);
	x.z = sqrt(x.z);

	return x;
}

template<typename T, typename>
LYAH_CONSTEXPR_CPP26 lyah::vec<4, T> lyah::sqrt(vec<4, T> x) {
	x.x = sqrt(x.x);
	x.y = sqrt(x.y);
	x.z = sqrt(x.z);
	x.w = sqrt(x.w);

	return x;
}