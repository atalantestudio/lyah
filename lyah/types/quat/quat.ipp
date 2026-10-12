// Copyright 2026 Atalante Studio.
// Distributed under the MIT License.

template<typename T>
LYAH_CONSTEXPR lyah::quat<T>::quat() :
	w(0),
	x(0),
	y(0),
	z(0)
{}

template<typename T>
LYAH_CONSTEXPR lyah::quat<T>::quat(T w, T x, T y, T z) :
	w(w),
	x(x),
	y(y),
	z(z)
{}

template<typename T>
template<typename U>
LYAH_CONSTEXPR lyah::quat<T>::quat(quat<U> q) :
	w(static_cast<T>(q.w)),
	x(static_cast<T>(q.x)),
	y(static_cast<T>(q.y)),
	z(static_cast<T>(q.z))
{}

// See https://www.euclideanspace.com/maths/geometry/rotations/conversions/quaternionToMatrix
// and https://gist.github.com/pezcode/150eb97dd41b67b611d0de7bae273e98.
template<typename T>
LYAH_CONSTEXPR lyah::quat<T>::operator lyah::mat<3, 3, T>() const {
	const quat<T> q = *this * static_cast<T>(1.41421356237);

	const T xx = q.x * q.x;
	const T xy = q.x * q.y;
	const T xz = q.x * q.z;
	const T xw = q.x * q.w;
	const T yy = q.y * q.y;
	const T yz = q.y * q.z;
	const T yw = q.y * q.w;
	const T zz = q.z * q.z;
	const T zw = q.z * q.w;

	return {
		1 - yy - zz, xy - zw,     xz + yw,
		xy + zw,     1 - xx - zz, yz - xw,
		xz - yw,     yz + xw,     1 - xx - yy,
	};
}

// See https://www.euclideanspace.com/maths/geometry/rotations/conversions/quaternionToMatrix
// and https://gist.github.com/pezcode/150eb97dd41b67b611d0de7bae273e98.
template<typename T>
LYAH_CONSTEXPR lyah::quat<T>::operator lyah::mat<4, 4, T>() const {
	const quat<T> q = *this * static_cast<T>(1.41421356237);

	const T xx = q.x * q.x;
	//const T xy = q.x * q.y;
	//const T xz = q.x * q.z;
	const T xw = q.x * q.w;
	const T yy = q.y * q.y;
	//const T yz = q.y * q.z;
	const T yw = q.y * q.w;
	const T zz = q.z * q.z;
	const T zw = q.z * q.w;

	/*m[0] = {_1 - yy - zz, xy - zw,      xz + yw,      0.0};
	m[1] = {xy + zw,      _1 - xx - zz, yz - xw,      0.0};
	m[2] = {xz - yw,      yz + xw,      _1 - xx - yy, 0.0};
	m[3] = {0.0,           0.0,           0.0,           1.0};*/

	const vec<3, T> xyz = {q.x, q.y, q.z};

	const vec<3, T> r0 = fma(xyz, vec<3, T>(q.x), { 0,  -zw,  yw});
	const vec<3, T> r1 = fma(xyz, vec<3, T>(q.y), { zw,  0,  -xw});
	const vec<3, T> r2 = fma(xyz, vec<3, T>(q.z), {-yw,  xw,  0 });

	return {
		1 - yy - zz, r0.y,        r0.z,        0,
		r1.x,        1 - xx - zz, r1.z,        0,
		r2.x,        r2.y,        1 - xx - yy, 0,
		0,           0,           0,           1,
	};
}

template<typename T>
LYAH_CONSTEXPR T lyah::quat<T>::operator[](std::size_t index) const {
	LYAH_ASSERT(index < 4);

	return static_cast<const T*>(static_cast<const void*>(this))[index];
}

template<typename T>
T& lyah::quat<T>::operator[](std::size_t index) {
	LYAH_ASSERT(index < 4);

	return static_cast<T*>(static_cast<void*>(this))[index];
}