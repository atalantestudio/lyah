// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

#include "test/compare.hpp"

struct TestCounter {
	inline static std::size_t passedTestCount = 0;
	inline static std::size_t failedTestCount = 0;
};

template<typename T>
class TestGroup : public TestCounter {
	public:
		inline static constexpr std::size_t RUN_COUNT = 20;

	private:
		template<typename TupleType, std::size_t ArgumentCount>
		inline static void generateParameters(TupleType& parameters) {}

		template<typename TupleType, std::size_t ArgumentIndex, typename CurrentArgumentType, typename... ArgumentType, bool CurrentNormalized, bool... Normalized>
		inline static void generateParameters(TupleType& parameters, Generator<CurrentArgumentType, CurrentNormalized>& generator, Generator<ArgumentType, Normalized>&... generators) {
			std::get<ArgumentIndex>(parameters) = next(generator);

			generateParameters<TupleType, ArgumentIndex + 1, ArgumentType...>(parameters, std::forward<Generator<ArgumentType, Normalized>&>(generators)...);
		}

		static void logTestName(const char* className, const char* testName) {
			std::cout << "\033[0;1m" << className << " - " << testName << "\033[0m ";
		}

		static void logFailed() {
			std::cout << "\033[101;97m FAILED \033[0m\n";
		}

		static void logPassed() {
			std::cout << "\033[42;30m PASSED \033[0m\n";
		}

		template<typename ReturnType, typename... ParameterType>
		inline static void logRun(std::size_t runIndex, std::tuple<ParameterType...> parameters, ReturnType result, ReturnType referenceResult) {
			std::cout << "\033[0;2m";
			std::cout << "  Run " << runIndex << '\n';

			if constexpr (sizeof...(ParameterType) > 0) {
				std::cout << "    Parameters:\n";

				std::apply(logParameters<ParameterType...>, parameters);
			}

			std::cout << "    Result:\n      " << result << '\n';
			std::cout << "    Reference:\n      " << referenceResult << "\033[0m\n";
		}

		static void logParameters() {}

		template<typename CurrentParameterType, typename... ParameterType>
		inline static void logParameters(CurrentParameterType parameter, ParameterType... parameters) {
			std::cout << "      " << parameter << '\n';

			logParameters(std::forward<ParameterType>(parameters)...);
		}

		static const char* getGroupName();

	public:
		inline static void runTests(std::mt19937& engine) {
			runTestsInternal(engine);

			std::cout << '\n';
		}

	protected:
		static void runTestsInternal(std::mt19937& engine);

		template<typename ReturnType, typename... ArgumentType, bool... Normalized>
		inline static void runTest(const char* name, ReturnType (*function)(ArgumentType...), ReturnType (*referenceAdapter)(ArgumentType...), Generator<ArgumentType, Normalized>&... generators) {
			typedef std::tuple<ArgumentType...> TupleType;

			logTestName(getGroupName(), name);

			TupleType parameters;
			std::size_t runIndex = 0;
			bool failedRuns = false;

			while (runIndex < RUN_COUNT) {
				generateParameters<TupleType, 0>(parameters, std::forward<Generator<ArgumentType, Normalized>&>(generators)...);

				const ReturnType result = std::apply(function, parameters);
				const ReturnType referenceResult = std::apply(referenceAdapter, parameters);

				if (compare(result, referenceResult)) {
					runIndex += 1;

					continue;
				}

				if (!failedRuns) {
					failedRuns = true;

					logFailed();
				}

				logRun<ReturnType, ArgumentType...>(runIndex, parameters, result, referenceResult);

				runIndex += 1;
			}

			if (!failedRuns) {
				logPassed();

				passedTestCount += 1;
			}
			else {
				failedTestCount += 1;
			}
		}
};