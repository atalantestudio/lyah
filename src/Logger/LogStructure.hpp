#pragma once

namespace test {
	enum class LogStructure : std::uint8_t {
		NONE = 0,
		TIME = 1 << 0,
		LOGGER_NAME = 1 << 1,
		LOG_LEVEL_NAME = 1 << 2,
	};

	AS_FLAG(LogStructure);
}