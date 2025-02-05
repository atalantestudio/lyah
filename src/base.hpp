#pragma once

#define AS_FLAG(T) \
	inline bool operator &(T a, T b) { \
		return static_cast<bool>(static_cast<std::int32_t>(a) & static_cast<std::int32_t>(b)); \
	} \
	\
	inline T operator |(T a, T b) { \
		return static_cast<T>(static_cast<std::int32_t>(a) | static_cast<std::int32_t>(b)); \
	}