#pragma once
#include "Export.h"

class MATHS_API CSfmathVector3
{
public:
	CSfmathVector3();
	CSfmathVector3(const CSfmathVector3 &other);
	CSfmathVector3(float fX, float fY, float fZ);

	const CSfmathVector3& operator +=(const CSfmathVector3& other);
	const CSfmathVector3& operator -=(const CSfmathVector3& other);

	CSfmathVector3 operator+(const CSfmathVector3& vtOther) const;
	CSfmathVector3 operator-(const CSfmathVector3& vtOther) const;

	CSfmathVector3 operator*(float k) const;
	CSfmathVector3 operator/(float k) const;

	CSfmathVector3 operator-() const;

public:
	void Set(float fX, float fY, float fZ);
	void SetX(float fX);
	void SetY(float fY);
	void SetZ(float fZ);

public:
	CSfmathVector3 CrossProduct(const CSfmathVector3& vtOther) const;
	float DotProduct(const CSfmathVector3& vtOther) const;

	CSfmathVector3 Normalize() const;

public:
	float m[3];
};