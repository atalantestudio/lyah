// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

template<>
LYAH_CONSTEXPR lyah::mat<3, 3, std::float_t> lyah::translation(vec<2, std::float_t> t) {
	return {
		1,   0,   0,
		0,   1,   0,
		t.x, t.y, 1,
	};
}

template<>
LYAH_CONSTEXPR lyah::mat<3, 3, std::double_t> lyah::translation(vec<2, std::double_t> t) {
	return {
		1,   0,   0,
		0,   1,   0,
		t.x, t.y, 1,
	};
}

template<>
LYAH_CONSTEXPR lyah::mat<4, 4, std::float_t> lyah::translation(vec<3, std::float_t> t) {
	return {
		1,   0,   0,   0,
		0,   1,   0,   0,
		0,   0,   1,   0,
		t.x, t.y, t.z, 1,
	};
}

template<>
LYAH_CONSTEXPR lyah::mat<4, 4, std::double_t> lyah::translation(vec<3, std::double_t> t) {
	return {
		1,   0,   0,   0,
		0,   1,   0,   0,
		0,   0,   1,   0,
		t.x, t.y, t.z, 1,
	};
}

template<>
LYAH_CONSTEXPR_CPP26 lyah::mat<2, 2, std::float_t> lyah::rotationAngle(std::float_t a) {
	const std::float_t c = cos(a);
	const std::float_t s = sin(a);

	return {
		 c, -s,
		 s,  c,
	};
}

template<>
LYAH_CONSTEXPR_CPP26 lyah::mat<2, 2, std::double_t> lyah::rotationAngle(std::double_t a) {
	const std::double_t c = cos(a);
	const std::double_t s = sin(a);

	return {
		 c, -s,
		 s,  c,
	};
}

template<>
LYAH_CONSTEXPR_CPP26 lyah::mat<3, 3, std::float_t> lyah::rotationAngle(std::float_t a) {
	const std::float_t c = cos(a);
	const std::float_t s = sin(a);

	return {
		 c, -s,  0,
		 s,  c,  0,
		 0,  0,  1,
	};
}

template<>
LYAH_CONSTEXPR_CPP26 lyah::mat<3, 3, std::double_t> lyah::rotationAngle(std::double_t a) {
	const std::double_t c = cos(a);
	const std::double_t s = sin(a);

	return {
		 c, -s,  0,
		 s,  c,  0,
		 0,  0,  1,
	};
}

template<typename T, typename>
LYAH_CONSTEXPR_CPP26 lyah::mat<4, 4, T> lyah::rotationAxisAngle(vec<3, T> axis, T angle) {
	const T x = axis.x;
	const T y = axis.y;
	const T z = axis.z;
	const T c = cos(angle);
	const T s = sin(angle);
	const T _1_c = 1 - c;

	return {
		x * x * _1_c + c,     x * y * _1_c + z * s, x * z * _1_c - y * s, 0,
		x * y * _1_c - z * s, y * y * _1_c + c,     y * z * _1_c + x * s, 0,
		x * z * _1_c + y * s, y * z * _1_c - x * s, z * z * _1_c + c,     0,
		0,                    0,                    0,                    1,
	};
}

template<>
LYAH_CONSTEXPR lyah::mat<3, 3, std::float_t> lyah::scaling(vec<2, std::float_t> s) {
	return {
		s.x, 0,   0,
		0,   s.y, 0,
		0,   0,   1,
	};
}

template<>
LYAH_CONSTEXPR lyah::mat<3, 3, std::double_t> lyah::scaling(vec<2, std::double_t> s) {
	return {
		s.x, 0,   0,
		0,   s.y, 0,
		0,   0,   1,
	};
}

template<>
LYAH_CONSTEXPR lyah::mat<4, 4, std::float_t> lyah::scaling(vec<3, std::float_t> s) {
	return {
		s.x, 0,   0,   0,
		0,   s.y, 0,   0,
		0,   0,   s.z, 0,
		0,   0,   0,   1,
	};
}

template<>
LYAH_CONSTEXPR lyah::mat<4, 4, std::double_t> lyah::scaling(vec<3, std::double_t> s) {
	return {
		s.x, 0,   0,   0,
		0,   s.y, 0,   0,
		0,   0,   s.z, 0,
		0,   0,   0,   1,
	};
}

template<typename T, typename>
LYAH_CONSTEXPR_CPP26 lyah::mat<4, 4, T> lyah::lookAt(vec<3, T> eye, vec<3, T> target, vec<3, T> up) {
	const vec<3, T> f = normalized(target - eye);
	const vec<3, T> r = normalized(cross(up, f));
	const vec<3, T> u = cross(f, r);

	return {
		 r.x,          u.x,          f.x,          0,
		 r.y,          u.y,          f.y,          0,
		 r.z,          u.z,          f.z,          0,
		-dot(r, eye), -dot(u, eye), -dot(f, eye),  1,
	};
}