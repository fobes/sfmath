#pragma once
#include "Export.h"

class MATHS_API CSfmathVector2
{
public:
	CSfmathVector2() noexcept;
	CSfmathVector2(const CSfmathVector2& other) noexcept;
	CSfmathVector2(float fX, float fY) noexcept;
	CSfmathVector2(const float* pArr) noexcept;

	operator const float* () const noexcept;

	const CSfmathVector2& operator+=(const CSfmathVector2& other) noexcept;
	const CSfmathVector2& operator-=(const CSfmathVector2& other) noexcept;

	CSfmathVector2 operator+(const CSfmathVector2& vtOther) const noexcept;
	CSfmathVector2 operator-(const CSfmathVector2& vtOther) const noexcept;

	CSfmathVector2 operator*(float k) const noexcept;
	CSfmathVector2 operator/(float k) const noexcept;

	CSfmathVector2 operator-() const noexcept;

public:
	CSfmathVector2 Normalize() const noexcept;

	float Square() const noexcept;
	float Length() const noexcept;

public:
	float m[2];
};