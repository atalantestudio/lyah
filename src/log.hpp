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