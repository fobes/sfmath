#pragma once
#include "CVector3.h"

class CVector4
{
public:
	CVector4():m_fX(0), m_fY(0), m_fZ(0), m_fW(0){}

	CVector4(const CVector4& V)
	{
		Set(V);
	}
	CVector4(const CVector3& V,float fW)
	{
		Set(V.m_fX, V.m_fY, V.m_fZ, fW);
	}
	CVector4(float fX, float fY, float fZ, float fW)
	{
		Set(fX, fY, fZ, fW);
	}

	operator const float*() const
	{
		return &m_fX;
	}

public:
	void Set(const CVector4& V)
	{
		m_fX = V.m_fX; m_fY = V.m_fY; m_fZ = V.m_fZ; m_fW = V.m_fW;
	}

	void Set(const CVector3& V, float fW)
	{
		m_fX = V.m_fX; m_fY = V.m_fY; m_fZ = V.m_fZ; m_fW = fW;
	}

	void Set(float fX, float fY, float fZ, float fW)
	{
		m_fX = fX; m_fY = fY; m_fZ = fZ; m_fW = fW;
	}

public:
	float m_fX, m_fY, m_fZ, m_fW;
};

CVector4 operator *(const CVector4& V, float k);
