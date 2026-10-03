// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

class ClassTest {
	public:
		static void logStart();

	private:
		template<typename TupleType, std::size_t ArgumentCount>
		inline static void generateParameters(TupleType& parameters) {}

		template<typename TupleType, std::size_t ArgumentIndex, typename CurrentArgumentType, typename... ArgumentType>
		inline static void generateParameters(TupleType& parameters, Generator<CurrentArgumentType>& generator, Generator<ArgumentType>&... generators) {
			std::get<ArgumentIndex>(parameters) = next(generator);

			generateParameters<TupleType, ArgumentIndex + 1, ArgumentType...>(parameters, std::forward<Generator<ArgumentType>&>(generators)...);
		}

		static void logTestName(const char* className, const char* testName);

		static void logFailed();

		static void logPassed();

		template<typename ReturnType, typename... ParameterType>
		inline static void logRun(std::size_t runIndex, std::tuple<ParameterType...> parameters, ReturnType result, ReturnType referenceResult) {
			std::cout << "\033[0;2m";
			std::cout << "  Run " << runIndex << '\n';
			std::cout << "    Parameters:\n";

			if constexpr (sizeof...(ParameterType) > 0) {
				std::apply(logParameters<ParameterType...>, parameters);
			}

			std::cout << "    Result: " << result << '\n';
			std::cout << "    Reference: " << referenceResult;
			std::cout << "\033[0m\n";
		}

		inline static void logParameters() {}

		template<typename CurrentParameterType, typename... ParameterType>
		inline static void logParameters(CurrentParameterType parameter, ParameterType... parameters) {
			std::cout << "      " << parameter << '\n';

			logParameters(std::forward<ParameterType>(parameters)...);
		}

	protected:
		virtual const char* getClassName() const = 0;

		virtual void runTests() const = 0;

		template<typename ReturnType, typename... ArgumentType>
		inline void runTest(const char* name, ReturnType (*function)(ArgumentType...), ReturnType (*referenceAdapter)(ArgumentType...), Generator<ArgumentType>&... generators) const {
			typedef std::tuple<ArgumentType...> TupleType;

			static constexpr std::size_t RunCount = 1;

			logTestName(getClassName(), name);

			TupleType parameters;
			std::size_t runIndex = 0;
			bool failedRuns = false;

			while (runIndex < RunCount) {
				generateParameters<TupleType, 0>(parameters, std::forward<Generator<ArgumentType>&>(generators)...);

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
			}

			std::cout << '\n';
		}
};

class SingleFloatingPointQuaternion : public ClassTest {
	public:
		using ClassTest::ClassTest;

		const char* getClassName() const final override;

		void runTests() const final override;
};