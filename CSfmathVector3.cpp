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

CSfmathVector3::CSfmathVector3(const CSfmathVector3& other) :m{ other.m[0], other.m[1], other.m[2] }
{

}

CSfmathVector3::CSfmathVector3(float fX, float fY, float fZ) : m{ fX, fY , fZ }
{

}

const CSfmathVector3& CSfmathVector3::operator+=(const CSfmathVector3& other)
{
	m[0] += other.m[0];
	m[1] += other.m[1];
	m[2] += other.m[2];

	return *this;
}

CSfmathVector3 CSfmathVector3::operator+(const CSfmathVector3& vtOther) const
{
	return CSfmathVector3(m[0] + vtOther.m[0], m[1] + vtOther.m[1], m[2] + vtOther.m[2]);
}

const CSfmathVector3& CSfmathVector3::operator-=(const CSfmathVector3& other)
{
	m[0] -= other.m[0];
	m[1] -= other.m[1];
	m[2] -= other.m[2];

	return *this;
}

CSfmathVector3 CSfmathVector3::operator-(const CSfmathVector3& vtOther) const
{
	return CSfmathVector3(m[0] - vtOther.m[0], m[1] - vtOther.m[1], m[2] - vtOther.m[2]);
}

CSfmathVector3 CSfmathVector3::operator-() const
{
	return CSfmathVector3(-m[0], -m[0], -m[0]);
}

CSfmathVector3 CSfmathVector3::operator*(float k) const
{
	return CSfmathVector3(m[0] * k, m[1] * k, m[2] * k);
}

CSfmathVector3 CSfmathVector3::operator/(float k) const
{
	return *this * (1.0f / k);
}

void CSfmathVector3::Set(float fX, float fY, float fZ)
{
	m[0]=fX;
	m[1]=fY;
	m[2]=fZ;
}

void CSfmathVector3::SetX(float fX)
{
	m[0] = fX;
}

void CSfmathVector3::SetY(float fY)
{
	m[1] = fY;
}

void CSfmathVector3::SetZ(float fZ)
{
	m[2] = fZ;
}

CSfmathVector3 CSfmathVector3::CrossProduct(const CSfmathVector3& vtOther) const
{
	return CSfmathVector3(
		m[1] * vtOther.m[2] - m[2] * vtOther.m[1], 
		m[2] * vtOther.m[0] - m[0] * vtOther.m[2],
		m[0] * vtOther.m[1] - m[1] * vtOther.m[0]
	);
}

float CSfmathVector3::DotProduct(const CSfmathVector3& vtOther) const
{
	return m[0] * vtOther.m[0] + m[1] * vtOther.m[1] + m[2] * vtOther.m[2];
}

CSfmathVector3 CSfmathVector3::Normalize() const
{
	return *this * rsqrt(this->DotProduct(*this));
}
