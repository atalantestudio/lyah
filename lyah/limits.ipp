// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

namespace lyah {
	template<typename T>
	LYAH_CONSTEXPR_CPP14 T min(T a, T b) {
		return std::min(a, b);
	}

	template<typename T>
	LYAH_CONSTEXPR_CPP14 vec<2, T> min(vec<2, T> a, vec<2, T> b) {
		a.x = min(a.x, b.x);
		a.y = min(a.y, b.y);

		return a;
	}

	template<typename T>
	LYAH_CONSTEXPR_CPP14 vec<3, T> min(vec<3, T> a, vec<3, T> b) {
		a.x = min(a.x, b.x);
		a.y = min(a.y, b.y);
		a.z = min(a.z, b.z);

		return a;
	}

	template<typename T>
	LYAH_CONSTEXPR_CPP14 vec<4, T> min(vec<4, T> a, vec<4, T> b) {
		a.x = min(a.x, b.x);
		a.y = min(a.y, b.y);
		a.z = min(a.z, b.z);
		a.w = min(a.w, b.w);

		return a;
	}

	template<typename T>
	LYAH_CONSTEXPR_CPP14 T max(T a, T b) {
		return std::max(a, b);
	}

	template<typename T>
	LYAH_CONSTEXPR_CPP14 vec<2, T> max(vec<2, T> a, vec<2, T> b) {
		a.x = max(a.x, b.x);
		a.y = max(a.y, b.y);

		return a;
	}

	template<typename T>
	LYAH_CONSTEXPR_CPP14 vec<3, T> max(vec<3, T> a, vec<3, T> b) {
		a.x = max(a.x, b.x);
		a.y = max(a.y, b.y);
		a.z = max(a.z, b.z);

		return a;
	}

	template<typename T>
	LYAH_CONSTEXPR_CPP14 vec<4, T> max(vec<4, T> a, vec<4, T> b) {
		a.x = max(a.x, b.x);
		a.y = max(a.y, b.y);
		a.z = max(a.z, b.z);
		a.w = max(a.w, b.w);

		return a;
	}

	template<typename T>
	LYAH_CONSTEXPR_CPP14 T clamp(T a, T b, T c) {
		return min(max(a, b), c);
	}
}