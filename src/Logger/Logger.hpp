#pragma once

#include "Logger/LogLevel.hpp"
#include "Logger/LogStructure.hpp"

namespace test {
	class Logger {
		private:
			static constexpr std::size_t TIME_PADDING = 14;
			static constexpr std::size_t LEVEL_NAME_PADDING = 5;
			static constexpr std::uint8_t LOG_LEVEL_BACKGROUND_COLORS[] = {0, 0, 0, 0, 101, 107};
			static constexpr std::uint8_t LOG_LEVEL_FOREGROUND_COLORS[] = {97, 37, 94, 93, 97, 30};
			static constexpr const char* LOG_LEVEL_NAMES[] = {"TRACE", "DEBUG", "INFO", "WARN", "ERROR", "FATAL"};
			static std::ostream* LOG_LEVEL_OUTPUT_STREAMS[];

			static std::size_t namePadding;

		public:
			static Logger instance;

		private:
			std::ostringstream stream;

		public:
			std::string name;
			LogLevel minimumLogLevel;
			LogStructure logStructure = LogStructure::TIME | LogStructure::LOGGER_NAME | LogStructure::LOG_LEVEL_NAME;
			std::size_t spacing = 3;
			std::string argumentInjectionPattern = "[]";

		public:
			static void initialize();

		private:
			void clear();

			template<typename T>
			void format(T&& argument) {
				stream << argument;
			}

			template<typename T, typename... U>
			void format(std::string_view pattern, T&& argument, U&&... arguments) {
				const std::size_t offset = pattern.find(argumentInjectionPattern);

				if (offset == std::string::npos) {
					return;
				}

				stream << pattern.substr(0, offset);
				stream << argument;

				format(pattern.substr(offset + argumentInjectionPattern.size()), arguments...);
			}

			void writeTime();

			template<typename... T>
			void log(LogLevel logLevel, std::string_view pattern, T&&... arguments) {
				if (logLevel < minimumLogLevel) {
					return;
				}

				format(pattern, arguments...);

				std::string log = stream.str();

				clear();

				const std::int32_t logLevelIndex = static_cast<std::int32_t>(logLevel) - 1;
				const std::string ansiSet = "\033[" + std::to_string(LOG_LEVEL_BACKGROUND_COLORS[logLevelIndex]) + ';' + std::to_string(LOG_LEVEL_FOREGROUND_COLORS[logLevelIndex]) + 'm';
				std::size_t padding = 0;
				std::size_t indentSize = 0;

				stream << ansiSet;

				if (logStructure & LogStructure::TIME) {
					writeTime();

					padding = spacing;
					indentSize += TIME_PADDING + spacing;
				}

				if (logStructure & LogStructure::LOGGER_NAME) {
					stream << std::setw(padding + namePadding);
					stream << name;

					padding = spacing;
					indentSize += namePadding + spacing;
				}

				if (logStructure & LogStructure::LOG_LEVEL_NAME) {
					stream << std::setw(padding + LEVEL_NAME_PADDING);
					stream << LOG_LEVEL_NAMES[logLevelIndex];

					padding = spacing;
					indentSize += LEVEL_NAME_PADDING + spacing;
				}

				const std::string indent = "\033[m\n" + ansiSet + std::string(indentSize, ' ');
				std::size_t offset = log.find('\n');

				while (offset != std::string::npos) {
					log.replace(offset, 1, indent);

					offset = log.find('\n', offset + indent.size());
				}

				stream << std::setw(padding + log.size());
				stream << log;
				stream << "\033[m";

				*LOG_LEVEL_OUTPUT_STREAMS[logLevelIndex] << stream.str() << std::endl;

				clear();
			}

		public:
			Logger(std::string_view name, LogLevel minimumLogLevel = LogLevel::ALL);

			~Logger() = default;

			template<typename T>
			void trace(T&& argument) {
				log(LogLevel::TRACE, argumentInjectionPattern, argument);
			}

			template<typename... T>
			void trace(std::string_view pattern, T&&... arguments) {
				log(LogLevel::TRACE, pattern, arguments...);
			}

			template<typename T>
			void debug(T&& argument) {
				log(LogLevel::DEBUG, argumentInjectionPattern, argument);
			}

			template<typename... T>
			void debug(std::string_view pattern, T&&... arguments) {
				log(LogLevel::DEBUG, pattern, arguments...);
			}

			template<typename T>
			void info(T&& argument) {
				log(LogLevel::INFO, argumentInjectionPattern, argument);
			}

			template<typename... T>
			void info(std::string_view pattern, T&&... arguments) {
				log(LogLevel::INFO, pattern, arguments...);
			}

			template<typename T>
			void warn(T&& argument) {
				log(LogLevel::WARN, argumentInjectionPattern, argument);
			}

			template<typename... T>
			void warn(std::string_view pattern, T&&... arguments) {
				log(LogLevel::WARN, pattern, arguments...);
			}

			template<typename T>
			void error(T&& argument) {
				log(LogLevel::ERROR, argumentInjectionPattern, argument);
			}

			template<typename... T>
			void error(std::string_view pattern, T&&... arguments) {
				log(LogLevel::ERROR, pattern, arguments...);
			}

			template<typename T>
			void fatal(T&& argument) {
				log(LogLevel::FATAL, argumentInjectionPattern, argument);
			}

			template<typename... T>
			void fatal(std::string_view pattern, T&&... arguments) {
				log(LogLevel::FATAL, pattern, arguments...);
			}
	};
}