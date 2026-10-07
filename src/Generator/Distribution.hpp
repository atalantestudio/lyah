// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

template<typename T>
struct Distribution {
	using DistributionType = typename std::conditional<std::is_floating_point<T>::value, std::uniform_real_distribution<T>, std::uniform_int_distribution<T>>::type;

	explicit Distribution(std::mt19937& engine, T min, T max) :
		engine(engine),
		distribution(min, max)
	{}

	std::mt19937& engine;
	DistributionType distribution;
};