#pragma once
#include "Export.h"

class MATHS_API CVector3
{
public:
	CVector3();
	CVector3(const CVector3 &other);
	CVector3(float fX, float fY, float fZ);

	const CVector3& operator +=(const CVector3& other);
	const CVector3& operator -=(const CVector3& other);

	CVector3 operator+(const CVector3& vtOther) const;
	CVector3 operator-(const CVector3& vtOther) const;

	CVector3 operator*(float k) const;
	CVector3 operator/(float k) const;

	CVector3 operator-() const;

public:
	void Set(float fX, float fY, float fZ);
	void SetX(float fX);
	void SetY(float fY);
	void SetZ(float fZ);

public:
	CVector3 CrossProduct(const CVector3& vtOther) const;
	float DotProduct(const CVector3& vtOther) const;

	CVector3 Normalize() const;

public:
	float m_fX, m_fY, m_fZ;
};