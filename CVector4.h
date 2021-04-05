#pragma once
#include "CVector3.h"

class MATHS_API CVector4
{
public:
	CVector4();
	CVector4(const CVector4& vt);
	CVector4(const CVector3& vt,float fW);
	CVector4(float fX, float fY, float fZ, float fW);

	operator const float*() const;

public:
	void Set(const CVector4& vt);
	void Set(const CVector3& vt, float fW);
	void Set(float fX, float fY, float fZ, float fW);

public:
	float m_fX, m_fY, m_fZ, m_fW;
};

CVector4 operator *(const CVector4& V, float k);
