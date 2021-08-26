#include "stdafx.h"
#include "CSfmathVector3.h"
#include <cmath>

CSfmathVector3::CSfmathVector3() noexcept
{

}
CSfmathVector3::CSfmathVector3(const CSfmathVector3& other) noexcept 
	:m{ other.m[0], other.m[1], other.m[2] }
{

}
CSfmathVector3::CSfmathVector3(const CSfmathVector2& other, float fZ) noexcept
	:m{ other.m[0], other.m[1], fZ }
{

}
CSfmathVector3::CSfmathVector3(float fX, float fY, float fZ) noexcept 
	: m{ fX, fY , fZ }
{

}

CSfmathVector3::CSfmathVector3(const float* pArr) noexcept
{
	m[0] = pArr[0];
	m[1] = pArr[1];
	m[2] = pArr[2];
}

CSfmathVector3::operator const float* () const noexcept
{
	return &m[0];
}

const CSfmathVector3& CSfmathVector3::operator+=(const CSfmathVector3& other) noexcept
{
	m[0] += other.m[0];
	m[1] += other.m[1];
	m[2] += other.m[2];

	return *this;
}
const CSfmathVector3& CSfmathVector3::operator-=(const CSfmathVector3& other) noexcept
{
	m[0] -= other.m[0];
	m[1] -= other.m[1];
	m[2] -= other.m[2];

	return *this;
}

CSfmathVector3 CSfmathVector3::operator+(const CSfmathVector3& vtOther) const noexcept
{
	return CSfmathVector3(m[0] + vtOther.m[0], m[1] + vtOther.m[1], m[2] + vtOther.m[2]);
}
CSfmathVector3 CSfmathVector3::operator-(const CSfmathVector3& vtOther) const noexcept
{
	return CSfmathVector3(m[0] - vtOther.m[0], m[1] - vtOther.m[1], m[2] - vtOther.m[2]);
}

CSfmathVector3 CSfmathVector3::operator*(float k) const noexcept
{
	return CSfmathVector3(m[0] * k, m[1] * k, m[2] * k);
}
CSfmathVector3 CSfmathVector3::operator/(float k) const noexcept
{
	return *this * (1.0f / k);
}

CSfmathVector3 CSfmathVector3::operator-() const noexcept
{
	return CSfmathVector3(-m[0], -m[1], -m[2]);
}

CSfmathVector3 CSfmathVector3::Normalize() const noexcept
{
	return *this / Length();
}
float CSfmathVector3::Square() const noexcept
{
	return m[0] * m[0] + m[1] * m[1] + m[2] * m[2];
}
float CSfmathVector3::Length() const noexcept
{
	return std::sqrt(Square());
}

CSfmathVector3 CSfmathVector3::CrossProduct(const CSfmathVector3& vtOther) const noexcept
{
	return CSfmathVector3(
		m[1] * vtOther.m[2] - m[2] * vtOther.m[1], 
		m[2] * vtOther.m[0] - m[0] * vtOther.m[2],
		m[0] * vtOther.m[1] - m[1] * vtOther.m[0]
	);
}

float CSfmathVector3::DotProduct(const CSfmathVector3& vtOther) const noexcept
{
	return m[0] * vtOther.m[0] + m[1] * vtOther.m[1] + m[2] * vtOther.m[2];
}
