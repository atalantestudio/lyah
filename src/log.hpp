#pragma once

#include "Logger/Logger.hpp"

namespace test {
	template<std::size_t C, typename T>
	inline std::ostringstream& operator<<(std::ostringstream& stream, const lyah::vec<C, T>& a) {
		for (std::size_t index = 0; index < C - 1; index += 1) {
			stream << a[index] << "  ";
		}

		stream << a[C - 1];

		return stream;
	}

	template<std::size_t M, std::size_t N, typename T>
	inline std::ostringstream& operator<<(std::ostringstream& stream, const lyah::mat<M, N, T>& a) {
		for (std::size_t index = 0; index < M - 1; index += 1) {
			stream << a[index] << '\n';
		}

		stream << a[M - 1];

		return stream;
	}

	template<typename T>
	inline std::ostringstream& operator<<(std::ostringstream& stream, const lyah::quat<T>& a) {
		stream << a[0] << "  " << a[1] << "  " << a[2] << "  " << a[3];

		return stream;
	}
}