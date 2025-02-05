#pragma once

namespace test {
	enum class LogLevel : std::uint8_t {
		ALL,
		TRACE,
		DEBUG,
		INFO,
		WARN,
		ERROR,
		FATAL,
		NONE,
	};
}