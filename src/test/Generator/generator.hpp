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

template<typename T/*, typename = typename std::enable_if<std::is_scalar<T>::value && std::is_floating_point<T>::value>::type*/>
struct Generator : public BaseGenerator {
	explicit Generator(std::mt19937& engine, T min, T max) :
		BaseGenerator(engine),
		distribution(min, max)
	{}

	std::uniform_real_distribution<T> distribution;
};

/*template<typename T, typename = typename std::enable_if<std::is_scalar<T>::value && !std::is_floating_point<T>::value>::type>
struct Generator : public BaseGenerator {
	explicit Generator(std::mt19937& engine, T min, T max) :
		BaseGenerator(engine),
		distribution(min, max)
	{}

	std::uniform_int_distribution<T> distribution;
};*/

template<std::size_t C, typename T>
struct Generator<lyah::vec<C, T>> : public BaseGenerator {
	explicit Generator(std::mt19937& engine, T min, T max) :
		BaseGenerator(engine),
		distribution(min, max)
	{}

	std::uniform_real_distribution<T> distribution;
};

template<std::size_t M, std::size_t N, typename T>
struct Generator<lyah::mat<M, N, T>> : public BaseGenerator {
	explicit Generator(std::mt19937& engine, T min, T max) :
		BaseGenerator(engine),
		distribution(min, max)
	{}

	std::uniform_real_distribution<T> distribution;
};

template<typename T>
struct Generator<lyah::quat<T>> : public BaseGenerator {
	explicit Generator(std::mt19937& engine, T min, T max) :
		BaseGenerator(engine),
		distribution(min, max)
	{}

	std::uniform_real_distribution<T> distribution;
};
















//template<typename T, typename = std::enable_if<std::is_scalar<T>::value>::type>
template<typename T>
T next(Generator<T>& generator) {
	return generator.distribution(generator.engine);
}

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

template<std::size_t M, typename T>
lyah::mat<M, 2, T> next(Generator<lyah::mat<M, 2, T>>& generator) {
	return {
		generator.distribution(generator.engine), generator.distribution(generator.engine),
		generator.distribution(generator.engine), generator.distribution(generator.engine),
	};
}

template<std::size_t M, typename T>
lyah::mat<M, 3, T> next(Generator<lyah::mat<M, 3, T>>& generator) {
	return {
		generator.distribution(generator.engine), generator.distribution(generator.engine), generator.distribution(generator.engine),
		generator.distribution(generator.engine), generator.distribution(generator.engine), generator.distribution(generator.engine),
		generator.distribution(generator.engine), generator.distribution(generator.engine), generator.distribution(generator.engine),
	};
}

template<std::size_t M, typename T>
lyah::mat<M, 4, T> next(Generator<lyah::mat<M, 4, T>>& generator) {
	return {
		generator.distribution(generator.engine), generator.distribution(generator.engine), generator.distribution(generator.engine), generator.distribution(generator.engine),
		generator.distribution(generator.engine), generator.distribution(generator.engine), generator.distribution(generator.engine), generator.distribution(generator.engine),
		generator.distribution(generator.engine), generator.distribution(generator.engine), generator.distribution(generator.engine), generator.distribution(generator.engine),
		generator.distribution(generator.engine), generator.distribution(generator.engine), generator.distribution(generator.engine), generator.distribution(generator.engine),
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