// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

struct BaseGenerator {
	explicit BaseGenerator(std::mt19937& engine) :
		engine(engine)
	{}

	std::mt19937& engine;
};

template<typename T>
struct Generator;

//template<typename T>
//struct IntervalGenerator;

template<typename T>
inline T next(Generator<T>& generator);

//template<typename T>
//inline T next(IntervalGenerator<T>& generator);

#include "test/generator/float.cpp"