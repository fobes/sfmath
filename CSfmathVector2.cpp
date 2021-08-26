#include "stdafx.h"
#include "CSfmathVector2.h"
#include <cmath>

CSfmathVector2::CSfmathVector2() noexcept
{

}
CSfmathVector2::CSfmathVector2(const CSfmathVector2& other) noexcept 
	:m{other.m[0], other.m[1] }
{

}
CSfmathVector2::CSfmathVector2(float fX, float fY) noexcept
	: m{ fX, fY }
{

}
CSfmathVector2::CSfmathVector2(const float* pArr) noexcept
{
	m[0] = pArr[0];
	m[1] = pArr[1];
}

CSfmathVector2::operator const float* () const noexcept
{
	return &m[0];
}

const CSfmathVector2& CSfmathVector2::operator+=(const CSfmathVector2& other) noexcept
{
	m[0] += other.m[0];
	m[1] += other.m[1];

	return *this;
}
const CSfmathVector2& CSfmathVector2::operator-=(const CSfmathVector2& other) noexcept
{
	m[0] -= other.m[0];
	m[1] -= other.m[1];

	return *this;
}

CSfmathVector2 CSfmathVector2::operator+(const CSfmathVector2& vtOther) const noexcept
{
	return CSfmathVector2(m[0] + vtOther.m[0], m[1] + vtOther.m[1]);
}
CSfmathVector2 CSfmathVector2::operator-(const CSfmathVector2& vtOther) const noexcept
{
	return CSfmathVector2(m[0] - vtOther.m[0], m[1] - vtOther.m[1]);
}

CSfmathVector2 CSfmathVector2::operator*(float k) const noexcept
{
	return CSfmathVector2(m[0] * k, m[1] * k);
}
CSfmathVector2 CSfmathVector2::operator/(float k) const noexcept
{
	return *this * (1.0f / k);
}

CSfmathVector2 CSfmathVector2::operator-() const noexcept
{
	return CSfmathVector2(-m[0], -m[1]);
}

CSfmathVector2 CSfmathVector2::Normalize() const noexcept
{
	return *this / Length();
}
float CSfmathVector2::Square() const noexcept
{
	return m[0] * m[0] + m[1] * m[1];
}
float CSfmathVector2::Length() const noexcept
{
	return std::sqrt(Square());
}
