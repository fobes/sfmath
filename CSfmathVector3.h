#pragma once
#include "Export.h"

class MATHS_API CSfmathVector3
{
public:
	CSfmathVector3() noexcept;
	CSfmathVector3(const CSfmathVector3& other) noexcept;
	CSfmathVector3(float fX, float fY, float fZ) noexcept;

	const CSfmathVector3& operator +=(const CSfmathVector3& other) noexcept;
	const CSfmathVector3& operator -=(const CSfmathVector3& other) noexcept;

	CSfmathVector3 operator+(const CSfmathVector3& vtOther) const noexcept;
	CSfmathVector3 operator-(const CSfmathVector3& vtOther) const noexcept;

	CSfmathVector3 operator*(float k) const noexcept;
	CSfmathVector3 operator/(float k) const noexcept;

	CSfmathVector3 operator-() const noexcept;

public:
	void Set(float fX, float fY, float fZ) noexcept;
	void SetX(float fX) noexcept;
	void SetY(float fY) noexcept;
	void SetZ(float fZ) noexcept;

public:
	CSfmathVector3 CrossProduct(const CSfmathVector3& vtOther) const noexcept;
	float DotProduct(const CSfmathVector3& vtOther) const noexcept;

	CSfmathVector3 Normalize() const noexcept;

	float Length() const noexcept;



public:
	float m[3];
};