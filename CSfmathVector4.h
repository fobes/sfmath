#pragma once
#include "CSfmathVector3.h"

class MATHS_API CSfmathVector4
{
public:
	CSfmathVector4() noexcept;
	CSfmathVector4(const CSfmathVector4& other) noexcept;
	CSfmathVector4(const CSfmathVector3& vt, float fW) noexcept;
	CSfmathVector4(float fX, float fY, float fZ, float fW) noexcept;
	CSfmathVector4(const float* pArr) noexcept;

	operator const float* () const noexcept;

	const CSfmathVector4& operator+=(const CSfmathVector4& other) noexcept;
	const CSfmathVector4& operator-=(const CSfmathVector4& other) noexcept;

	CSfmathVector4 operator+(const CSfmathVector4& vtOther) const noexcept;
	CSfmathVector4 operator-(const CSfmathVector4& vtOther) const noexcept;

	CSfmathVector4 operator*(float k) const noexcept;
	CSfmathVector4 operator/(float k) const noexcept;

	CSfmathVector4 operator-() const noexcept;

public:
	CSfmathVector4 Normalize() const noexcept;

	float Square() const noexcept;
	float Length() const noexcept;

public:
	float m[4];
};


