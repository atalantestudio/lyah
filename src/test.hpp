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
	inline bool eq(T a, T b) {
		return a == b;
	}

	inline bool eq(std::float_t a, std::float_t b, std::float_t precision = 0.0f) {
		return std::abs(a - b) <= precision;
	}

	inline bool eq(std::double_t a, std::double_t b, std::double_t precision = 0.0) {
		return std::abs(a - b) <= precision;
	}

	template<typename T>
	inline bool eq(const T* a, const T* b, T precision = static_cast<T>(0)) {
		for (std::size_t i = 0; i < 4; i += 1) {
			if (std::abs(a[i] - b[i]) > precision) {
				return false;
			}
		}

		return true;
	}

	template<std::size_t C>
	inline bool eq(const lyah::vec<C, std::int32_t>& a, const lyah::vec<C, std::int32_t>& b) {
		const std::int32_t* bufferA = a.m.m128i_i32;
		const std::int32_t* bufferB = b.m.m128i_i32;

		for (std::size_t i = 0; i < C; i += 1) {
			if (bufferA[i] != bufferB[i]) {
				return false;
			}
		}

		return true;
	}

	template<std::size_t C>
	inline bool eq(const lyah::vec<C, std::int64_t>& a, const lyah::vec<C, std::int64_t>& b) {
		const std::int64_t* bufferA = a.m.m256i_i64;
		const std::int64_t* bufferB = b.m.m256i_i64;

		for (std::size_t i = 0; i < C; i += 1) {
			if (bufferA[i] != bufferB[i]) {
				return false;
			}
		}

		return true;
	}

	template<std::size_t C>
	inline bool eq(const lyah::vec<C, std::float_t>& a, const lyah::vec<C, std::float_t>& b, std::float_t precision = 0.0f) {
		const std::float_t* bufferA = a.m.m128_f32;
		const std::float_t* bufferB = b.m.m128_f32;

		for (std::size_t i = 0; i < C; i += 1) {
			if (std::abs(bufferA[i] - bufferB[i]) > precision) {
				return false;
			}
		}

		return true;
	}

	inline bool eq(const lyah::vec<2, std::double_t>& a, const lyah::vec<2, std::double_t>& b, std::double_t precision = 0.0) {
		const std::double_t* bufferA = a.m.m128d_f64;
		const std::double_t* bufferB = b.m.m128d_f64;

		for (std::size_t i = 0; i < 2; i += 1) {
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

		for (std::size_t i = 0; i < C; i += 1) {
			if (std::abs(bufferA[i] - bufferB[i]) > precision) {
				return false;
			}
		}

		return true;
	}

	template<std::size_t R, std::size_t C, typename T>
	inline bool eq(const lyah::mat<R, C, T>& a, const lyah::mat<R, C, T>& b, T precision = static_cast<T>(0)) {
		for (std::size_t i = 0; i < R; i += 1) {
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