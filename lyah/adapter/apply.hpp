// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace lyah {
	template<typename T>
	struct apply<2, T> {
		LYAH_NODISCARD LYAH_INLINE static vec<2, T> LYAH_CALL scalarModifier(vec<2, T> x, T (*modifier)(T));
	};

	template<typename T>
	struct apply<3, T> {
		LYAH_NODISCARD LYAH_INLINE static vec<3, T> LYAH_CALL scalarModifier(vec<3, T> x, T (*modifier)(T));
	};

	template<typename T>
	struct apply<4, T> {
		LYAH_NODISCARD LYAH_INLINE static vec<4, T> LYAH_CALL scalarModifier(vec<4, T> x, T (*modifier)(T));
	};
}