// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

#include "test/generator/generator.hpp"

template<typename TupleType, std::size_t ArgumentCount, typename... ArgumentType>
void generateParameters(TupleType& parameters) {}

template<typename TupleType, std::size_t ArgumentIndex, typename CurrentArgumentType, typename... ArgumentType>
void generateParameters(TupleType& parameters, Generator<CurrentArgumentType>& generator, Generator<ArgumentType>&... generators) {
	std::get<ArgumentIndex>(parameters) = next(generator);

	generateParameters<TupleType, ArgumentIndex - 1, ArgumentType...>(parameters, std::forward<Generator<ArgumentType>&>(generators)...);
}

template<std::size_t RunCount, typename ReturnType, typename... ArgumentType>
void runTest(ReturnType (*function)(ArgumentType...), ReturnType (*referenceAdapter)(ArgumentType...), const char* name, Generator<ArgumentType>&... generators) {
	typedef std::tuple<ArgumentType...> TupleType;

	constexpr std::size_t parameterCount = sizeof...(ArgumentType);

	logTestName(name);

	TupleType parameters;
	std::size_t runIndex = 0;
	bool failedRuns = false;

	while (runIndex < RunCount) {
		generateParameters<TupleType, parameterCount - 1>(parameters, std::forward<Generator<ArgumentType>&>(generators)...);

		const ReturnType result = std::apply(function, parameters);
		const ReturnType referenceResult = std::apply(referenceAdapter, parameters);

		if (result == referenceResult) {
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