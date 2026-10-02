// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

namespace lyah {
	LYAH_CONSTEXPR_CPP26 std::float_t log2(std::float_t a) {
		return std::log2f(a);
	}

	LYAH_CONSTEXPR_CPP26 std::double_t log2(std::double_t a) {
		return std::log2l(a);
	}

	LYAH_CONSTEXPR_CPP26 std::float_t pow(std::float_t a, std::float_t e) {
		return std::powf(a, e);
	}

	LYAH_CONSTEXPR_CPP26 std::double_t pow(std::double_t a, std::double_t e) {
		return std::powl(a, e);
	}

	LYAH_CONSTEXPR_CPP26 std::float_t sqrt(std::float_t a) {
		return std::sqrtf(a);
	}

	LYAH_CONSTEXPR_CPP26 std::double_t sqrt(std::double_t a) {
		return std::sqrtl(a);
	}
}