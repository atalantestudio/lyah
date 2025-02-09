#pragma once

#undef assert

namespace test {
	void printTestCategory(std::string_view name);

	void runTest(void (*test)(), std::string_view name);

	void summary();

	inline void assert(bool condition) {
		ASSERT(condition, "Assertion failed");
	}

	inline bool eq(bool a, bool b) {
		return a == b;
	}

	template<typename T>
	inline bool eq(T a, T b, T precision = 0) {
		return std::abs(a - b) <= precision;
	}

	template<typename T>
	inline bool eq(const T* a, const T* b, T precision = 0) {
		for (std::size_t i = 0; i < 4; i++) {
			if (std::abs(a[i] - b[i]) > precision) {
				return false;
			}
		}

		return true;
	}

	template<std::size_t C>
	inline bool eq(const lyah::vec<C, std::float_t>& a, const lyah::vec<C, std::float_t>& b, std::float_t precision = 0.0f) {
		const std::float_t* bufferA = a.m.m128_f32;
		const std::float_t* bufferB = b.m.m128_f32;

		for (std::size_t i = 0; i < 4; i++) {
			if (std::abs(bufferA[i] - bufferB[i]) > precision) {
				return false;
			}
		}

		return true;
	}

	inline bool eq(const lyah::vec<2, std::double_t>& a, const lyah::vec<2, std::double_t>& b, std::double_t precision = 0.0) {
		const std::double_t* bufferA = a.m.m128d_f64;
		const std::double_t* bufferB = b.m.m128d_f64;

		for (std::size_t i = 0; i < 2; i++) {
			if (std::abs(bufferA[i] - bufferB[i]) > precision) {
				return false;
			}
		}

		return true;
	}

	template<std::size_t C>
	inline bool eq(const lyah::vec<C, std::double_t>& a, const lyah::vec<C, std::double_t>& b, std::double_t precision = 0.0) {
		const std::double_t* bufferA = a.m.m256d_f64;
		const std::double_t* bufferB = b.m.m256d_f64;

		for (std::size_t i = 0; i < 4; i++) {
			if (std::abs(bufferA[i] - bufferB[i]) > precision) {
				return false;
			}
		}

		return true;
	}

	template<std::size_t R, std::size_t C, typename T>
	inline bool eq(const lyah::mat<R, C, T>& a, const lyah::mat<R, C, T>& b, T precision = 0) {
		for (std::size_t i = 0; i < R; i++) {
			if (!eq(a[i], b[i], precision)) {
				return false;
			}
		}

		return true;
	}

	inline bool eq(const lyah::quat<std::float_t>& a, const lyah::quat<std::float_t>& b, std::float_t precision = 0.0f) {
		return eq(a.m.m128_f32, b.m.m128_f32, precision);
	}

	inline bool eq(const lyah::quat<std::double_t>& a, const lyah::quat<std::double_t>& b, std::double_t precision = 0.0) {
		return eq(a.m.m256d_f64, b.m.m256d_f64, precision);
	}
}