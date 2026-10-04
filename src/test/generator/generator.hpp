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

template<>
struct Generator<std::float_t> : public BaseGenerator {
	explicit Generator(std::mt19937& engine, std::float_t min = 0.0f, std::float_t max = 1.0f) :
		BaseGenerator(engine),
		distribution(min, max)
	{}

	std::uniform_real_distribution<std::float_t> distribution;
};

template<>
struct Generator<std::double_t> : public BaseGenerator {
	explicit Generator(std::mt19937& engine, std::double_t min = 0.0, std::double_t max = 1.0) :
		BaseGenerator(engine),
		distribution(min, max)
	{}

	std::uniform_real_distribution<std::double_t> distribution;
};

template<std::size_t C, typename T>
struct Generator<lyah::vec<C, T>> : public BaseGenerator {
	explicit Generator(std::mt19937& engine, T min = 0, T max = 1) :
		BaseGenerator(engine),
		distribution(min, max)
	{}

	std::uniform_real_distribution<T> distribution;
};

template<typename T>
struct Generator<lyah::quat<T>> : public BaseGenerator {
	explicit Generator(std::mt19937& engine, T min = 0, T max = 1) :
		BaseGenerator(engine),
		distribution(min, max)
	{}

	std::uniform_real_distribution<T> distribution;
};

template<typename T>
T next(Generator<T>& generator);

template<typename T>
lyah::vec<2, T> next(Generator<lyah::vec<2, T>>& generator) {
	return {
		generator.distribution(generator.engine),
		generator.distribution(generator.engine),
	};
}

template<typename T>
lyah::vec<3, T> next(Generator<lyah::vec<3, T>>& generator) {
	return {
		generator.distribution(generator.engine),
		generator.distribution(generator.engine),
		generator.distribution(generator.engine),
	};
}

template<typename T>
lyah::vec<4, T> next(Generator<lyah::vec<4, T>>& generator) {
	return {
		generator.distribution(generator.engine),
		generator.distribution(generator.engine),
		generator.distribution(generator.engine),
		generator.distribution(generator.engine),
	};
}

template<typename T>
lyah::quat<T> next(Generator<lyah::quat<T>>& generator) {
	return {
		generator.distribution(generator.engine),
		generator.distribution(generator.engine),
		generator.distribution(generator.engine),
		generator.distribution(generator.engine),
	};
}