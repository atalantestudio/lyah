#pragma once

#include "Logger/Logger.hpp"

#define TRACE(...) test::Logger::instance.trace(__VA_ARGS__)
#define DEBUG(...) test::Logger::instance.debug(__VA_ARGS__)
#define INFO(...) test::Logger::instance.info(__VA_ARGS__)
#define WARN(...) test::Logger::instance.warn(__VA_ARGS__)
#define ERROR(...) test::Logger::instance.error(__VA_ARGS__)
#define FATAL(...) test::Logger::instance.fatal(__VA_ARGS__)

#define ASSERT(condition, ...) { \
	if (!(condition)) { \
		ERROR(__VA_ARGS__); \
		\
		__debugbreak(); \
	} \
}

namespace test {
	inline std::ostringstream& operator <<(std::ostringstream& stream, __m128 m) {
		const std::float_t* buffer = m.m128_f32;

		stream << buffer[0] << "  " << buffer[1] << "  " << buffer[2] << "  " << buffer[3];

		return stream;
	}

	inline std::ostringstream& operator <<(std::ostringstream& stream, __m128d m) {
		const std::double_t* buffer = m.m128d_f64;

		stream << buffer[0] << "  " << buffer[1];

		return stream;
	}

	inline std::ostringstream& operator <<(std::ostringstream& stream, __m256d m) {
		const std::double_t* buffer = m.m256d_f64;

		stream << buffer[0] << "  " << buffer[1] << "  " << buffer[2] << "  " << buffer[3];

		return stream;
	}

	template<std::size_t C, typename T>
	inline std::ostringstream& operator <<(std::ostringstream& stream, const lyah::vec<C, T>& a) {
		for (std::size_t index = 0; index < C - 1; index += 1) {
			stream << a[index] << "  ";
		}

		stream << a[C - 1];

		return stream;
	}

	template<std::size_t R, std::size_t C, typename T>
	inline std::ostringstream& operator <<(std::ostringstream& stream, const lyah::mat<R, C, T>& a) {
		for (std::size_t index = 0; index < R - 1; index += 1) {
			stream << a[index] << std::endl;
		}

		stream << a[R - 1];

		return stream;
	}

	template<typename T>
	inline std::ostringstream& operator <<(std::ostringstream& stream, const lyah::quat<T>& a) {
		stream << a[0] << "  " << a[1] << "  " << a[2] << "  " << a[3];

		return stream;
	}
}