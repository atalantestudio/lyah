#pragma once

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
	inline bool eq(lyah::vec<C, std::float_t> a, lyah::vec<C, std::float_t> b, std::float_t precision = 0.0f) {
		const std::float_t* bufferA = static_cast<const std::float_t*>(static_cast<const void*>(&a));
		const std::float_t* bufferB = static_cast<const std::float_t*>(static_cast<const void*>(&b));

		for (std::size_t i = 0; i < C; i += 1) {
			if (std::abs(bufferA[i] - bufferB[i]) > precision) {
				return false;
			}
		}

		return true;
	}

	template<std::size_t C>
	inline bool eq(const lyah::vec<C, std::double_t>& a, const lyah::vec<C, std::double_t>& b, std::double_t precision = 0.0) {
		const std::double_t* bufferA = static_cast<const std::double_t*>(static_cast<const void*>(&a));
		const std::double_t* bufferB = static_cast<const std::double_t*>(static_cast<const void*>(&b));

		for (std::size_t i = 0; i < C; i += 1) {
			if (std::abs(bufferA[i] - bufferB[i]) > precision) {
				return false;
			}
		}

		return true;
	}

	template<std::size_t C>
	inline bool eq(lyah::vec<C, std::int32_t> a, lyah::vec<C, std::int32_t> b) {
		const std::int32_t* bufferA = static_cast<const std::int32_t*>(static_cast<const void*>(&a));
		const std::int32_t* bufferB = static_cast<const std::int32_t*>(static_cast<const void*>(&b));

		for (std::size_t i = 0; i < C; i += 1) {
			if (bufferA[i] != bufferB[i]) {
				return false;
			}
		}

		return true;
	}

	template<std::size_t C>
	inline bool eq(const lyah::vec<C, std::int64_t>& a, const lyah::vec<C, std::int64_t>& b) {
		const std::int64_t* bufferA = static_cast<const std::int64_t*>(static_cast<const void*>(&a));
		const std::int64_t* bufferB = static_cast<const std::int64_t*>(static_cast<const void*>(&b));

		for (std::size_t i = 0; i < C; i += 1) {
			if (bufferA[i] != bufferB[i]) {
				return false;
			}
		}

		return true;
	}

	template<std::size_t M, std::size_t N, typename T>
	inline bool eq(const lyah::mat<M, N, T>& a, const lyah::mat<M, N, T>& b, T precision = static_cast<T>(0)) {
		for (std::size_t i = 0; i < M; i += 1) {
			if (!eq(a[i], b[i], precision)) {
				return false;
			}
		}

		return true;
	}

	inline bool eq(lyah::quat<std::float_t> a, lyah::quat<std::float_t> b, std::float_t precision = 0.0f) {
		const std::float_t* bufferA = static_cast<const std::float_t*>(static_cast<const void*>(&a));
		const std::float_t* bufferB = static_cast<const std::float_t*>(static_cast<const void*>(&b));

		for (std::size_t i = 0; i < 4; i += 1) {
			if (std::abs(bufferA[i] - bufferB[i]) > precision) {
				return false;
			}
		}

		return true;
	}

	inline bool eq(lyah::quat<std::double_t> a, lyah::quat<std::double_t> b, std::double_t precision = 0.0) {
		const std::double_t* bufferA = static_cast<const std::double_t*>(static_cast<const void*>(&a));
		const std::double_t* bufferB = static_cast<const std::double_t*>(static_cast<const void*>(&b));

		for (std::size_t i = 0; i < 4; i += 1) {
			if (std::abs(bufferA[i] - bufferB[i]) > precision) {
				return false;
			}
		}

		return true;
	}
}