#include "pch.hpp"

#include "Logger/Logger.hpp"

namespace test {
	std::ostream* Logger::LOG_LEVEL_OUTPUT_STREAMS[] = {&std::cerr, &std::cerr, &std::cout, &std::cerr, &std::cerr, &std::cerr};

	std::size_t Logger::namePadding = 0;

	Logger Logger::instance = Logger("Instance");

	void Logger::initialize() {
		instance.logStructure = LogStructure::LOG_LEVEL_NAME;
	}

	void Logger::clear() {
		stream.str("");
	}

	void Logger::writeTime() {
		const std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
		const std::time_t time = std::chrono::system_clock::to_time_t(now);
		const std::chrono::milliseconds milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now - std::chrono::time_point_cast<std::chrono::seconds>(now));
		std::tm buffer;

		localtime_s(&buffer, &time);

		stream << '[';
		stream << std::put_time(&buffer, "%H:%M:%S");
		stream << '.';
		stream << std::setw(3);
		stream << std::setfill('0');
		stream << milliseconds.count();
		stream << std::setfill(' ');
		stream << ']';
	}

	Logger::Logger(std::string_view name, LogLevel minimumLogLevel) : name(name), minimumLogLevel(minimumLogLevel) {
		if (name.size() > namePadding) {
			namePadding = name.size();
		}
	}
}