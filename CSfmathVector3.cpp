#include "stdafx.h"
#include "CSfmathVector3.h"
#include <intrin.h>

inline float rsqrt(float f)
{
	_mm_store_ss(&f, _mm_rsqrt_ps(_mm_load1_ps(&f)));

	return f;
}

CSfmathVector3::CSfmathVector3()
{

}

CSfmathVector3::CSfmathVector3(const CSfmathVector3 &other):m_fX(other.m_fX), m_fY(other.m_fY), m_fZ(other.m_fZ)
{

}

CSfmathVector3::CSfmathVector3(float fX, float fY, float fZ):m_fX(fX), m_fY(fY), m_fZ(fZ)
{

}

const CSfmathVector3& CSfmathVector3::operator+=(const CSfmathVector3& other)
{
	m_fX += other.m_fX;
	m_fY += other.m_fY;
	m_fZ += other.m_fZ;

	return *this;
}

CSfmathVector3 CSfmathVector3::operator+(const CSfmathVector3& vtOther) const
{
	return CSfmathVector3(m_fX + vtOther.m_fX, m_fY + vtOther.m_fY, m_fZ + vtOther.m_fZ);
}

const CSfmathVector3& CSfmathVector3::operator-=(const CSfmathVector3& other)
{
	m_fX -= other.m_fX;
	m_fY -= other.m_fY;
	m_fZ -= other.m_fZ;

	return *this;
}

CSfmathVector3 CSfmathVector3::operator-(const CSfmathVector3& vtOther) const
{
	return CSfmathVector3(m_fX - vtOther.m_fX, m_fY - vtOther.m_fY, m_fZ - vtOther.m_fZ);
}

CSfmathVector3 CSfmathVector3::operator-() const
{
	return CSfmathVector3(-m_fX, -m_fX, -m_fX);
}

CSfmathVector3 CSfmathVector3::operator*(float k) const
{
	return CSfmathVector3(m_fX * k, m_fY * k, m_fZ * k);
}

CSfmathVector3 CSfmathVector3::operator/(float k) const
{
	return *this * (1.0f / k);
}

void CSfmathVector3::Set(float fX, float fY, float fZ)
{
	m_fX=fX;
	m_fY=fY;
	m_fZ=fZ;
}

void CSfmathVector3::SetX(float fX)
{
	m_fX = fX;
}

void CSfmathVector3::SetY(float fY)
{
	m_fY = fY;
}

void CSfmathVector3::SetZ(float fZ)
{
	m_fZ = fZ;
}

CSfmathVector3 CSfmathVector3::CrossProduct(const CSfmathVector3& vtOther) const
{
	return CSfmathVector3(m_fY * vtOther.m_fZ - m_fZ * vtOther.m_fY,
		m_fZ * vtOther.m_fX - m_fX * vtOther.m_fZ,
		m_fX * vtOther.m_fY - m_fY * vtOther.m_fX);
}

float CSfmathVector3::DotProduct(const CSfmathVector3& vtOther) const
{
	return m_fX * vtOther.m_fX + m_fY * vtOther.m_fY + m_fZ * vtOther.m_fZ;
}

CSfmathVector3 CSfmathVector3::Normalize() const
{
	return *this * rsqrt(this->DotProduct(*this));
}
