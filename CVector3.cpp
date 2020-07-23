#include "stdafx.h"
#include "CVector3.h"
#include <intrin.h>

inline float rsqrt(float f)
{
	_mm_store_ss(&f, _mm_rsqrt_ps(_mm_load1_ps(&f)));

	return f;
}

CVector3::CVector3() :m_fX(0.0), m_fY(0.0), m_fZ(0.0)
{

}

CVector3::CVector3(const CVector3 &other):m_fX(other.m_fX), m_fY(other.m_fY), m_fZ(other.m_fY)
{

}

CVector3::CVector3(float fX, float fY, float fZ):m_fX(fX), m_fY(fY), m_fZ(fZ)
{

}

const CVector3& CVector3::operator+=(const CVector3& other)
{
	m_fX += other.m_fX;
	m_fY += other.m_fY;
	m_fZ += other.m_fZ;

	return *this;
}

CVector3 CVector3::operator+(const CVector3& vtOther) const
{
	return CVector3(m_fX + vtOther.m_fX, m_fY + vtOther.m_fY, m_fZ + vtOther.m_fZ);
}

const CVector3& CVector3::operator-=(const CVector3& other)
{
	m_fX -= other.m_fX;
	m_fY -= other.m_fY;
	m_fZ -= other.m_fZ;

	return *this;
}

CVector3 CVector3::operator-(const CVector3& vtOther) const
{
	return CVector3(m_fX - vtOther.m_fX, m_fY - vtOther.m_fY, m_fZ - vtOther.m_fZ);
}

CVector3 CVector3::operator-() const
{
	return CVector3(-m_fX, -m_fX, -m_fX);
}

CVector3 CVector3::operator*(float k) const
{
	return CVector3(m_fX * k, m_fY * k, m_fZ * k);
}

CVector3 CVector3::operator/(float k) const
{
	return *this * (1.0f / k);
}

void CVector3::Set(float fX, float fY, float fZ)
{
	m_fX=fX;
	m_fY=fY;
	m_fZ=fZ;
}

void CVector3::SetX(float fX)
{
	m_fX = fX;
}

void CVector3::SetY(float fY)
{
	m_fY = fY;
}

void CVector3::SetZ(float fZ)
{
	m_fZ = fZ;
}

CVector3 CVector3::CrossProduct(const CVector3& vtOther) const
{
	return CVector3(m_fY * vtOther.m_fZ - m_fZ * vtOther.m_fY,
		m_fZ * vtOther.m_fX - m_fX * vtOther.m_fZ,
		m_fX * vtOther.m_fY - m_fY * vtOther.m_fX);
}

float CVector3::DotProduct(const CVector3& vtOther) const
{
	return m_fX * vtOther.m_fX + m_fY * vtOther.m_fY + m_fZ * vtOther.m_fZ;
}

CVector3 CVector3::Normalize() const
{
	return *this * rsqrt(this->DotProduct(*this));
}
