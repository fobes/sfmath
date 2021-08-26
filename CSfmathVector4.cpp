#include "stdafx.h"
#include "CSfmathVector4.h"
#include <cmath>

CSfmathVector4::CSfmathVector4() noexcept
{

}
CSfmathVector4::CSfmathVector4(const CSfmathVector4& other) noexcept 
	:m{ other.m[0], other.m[1], other.m[2], other.m[3] }
{

}
CSfmathVector4::CSfmathVector4(const CSfmathVector3& other, float fW) noexcept
	:m{ other.m[0], other.m[1], other.m[2], fW }
{

}
CSfmathVector4::CSfmathVector4(float fX, float fY, float fZ, float fW) noexcept
	: m{ fX, fY , fZ, fW }
{

}

CSfmathVector4::CSfmathVector4(const float* pArr) noexcept
{
	m[0] = pArr[0];
	m[1] = pArr[1];
	m[2] = pArr[2];
	m[3] = pArr[3];
}

CSfmathVector4::operator const float* () const noexcept
{
	return &m[0];
}

const CSfmathVector4& CSfmathVector4::operator+=(const CSfmathVector4& other) noexcept
{
	m[0] += other.m[0];
	m[1] += other.m[1];
	m[2] += other.m[2];
	m[3] += other.m[3];

	return *this;
}
const CSfmathVector4& CSfmathVector4::operator-=(const CSfmathVector4& other) noexcept
{
	m[0] -= other.m[0];
	m[1] -= other.m[1];
	m[2] -= other.m[2];
	m[3] -= other.m[3];

	return *this;
}

CSfmathVector4 CSfmathVector4::operator+(const CSfmathVector4& vtOther) const noexcept
{
	return CSfmathVector4(m[0] + vtOther.m[0], m[1] + vtOther.m[1], m[2] + vtOther.m[2], m[3] + vtOther.m[3]);
}
CSfmathVector4 CSfmathVector4::operator-(const CSfmathVector4& vtOther) const noexcept
{
	return CSfmathVector4(m[0] - vtOther.m[0], m[1] - vtOther.m[1], m[2] - vtOther.m[2], m[3] - vtOther.m[3]);
}

CSfmathVector4 CSfmathVector4::operator*(float k) const noexcept
{
	return CSfmathVector4(m[0] * k, m[1] * k, m[2] * k, m[3] * k);
}
CSfmathVector4 CSfmathVector4::operator/(float k) const noexcept
{
	return *this * (1.0f / k);
}

CSfmathVector4 CSfmathVector4::operator-() const noexcept
{
	return CSfmathVector4(-m[0], -m[1], -m[2], -m[3]);
}

CSfmathVector4 CSfmathVector4::Normalize() const noexcept
{
	return *this / Length();
}
float CSfmathVector4::Square() const noexcept
{
	return m[0] * m[0] + m[1] * m[1] + m[2] * m[2] + m[3] * m[3];
}
float CSfmathVector4::Length() const noexcept
{
	return std::sqrt(Square());
}
