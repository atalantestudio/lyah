// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

inline void logStart() {
	std::cout << "\033[0;2mStarting tests...\033[0m\n\n";
}

inline void logTestName(const char* name) {
	std::cout << "\033[0;1m" << name << "\033[0m ";
}

inline void logFailed() {
	std::cout << "\033[101;97m FAILED \033[0m\n";
}

inline void logPassed() {
	std::cout << "\033[42;30m PASSED \033[0m\n";
}

inline void logRunStep(const char* description) {
	std::cout << "  \033[0;2m  " << description << "\033[0m\n";
}

inline void logParameters() {}

template<typename CurrentParameterType, typename... ParameterType>
inline void logParameters(CurrentParameterType parameter, ParameterType... parameters) {
	std::cout << "      " << parameter << '\n';

	logParameters(std::forward<ParameterType>(parameters)...);
}

template<typename ReturnType, typename... ParameterType>
inline void logRun(std::size_t runIndex, std::tuple<ParameterType...> parameters, ReturnType result, ReturnType referenceResult) {
	std::cout << "\033[0;2m";
	std::cout << "  Run " << runIndex << '\n';
	std::cout << "    Parameters:\n";

	std::apply(logParameters<ParameterType...>, parameters);

	std::cout << "    Result: " << result << '\n';
	std::cout << "    Reference: " << referenceResult;
	std::cout << "\033[0m\n";
}