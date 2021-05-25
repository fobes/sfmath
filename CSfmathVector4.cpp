#include "stdafx.h"
#include "CSfmathVector4.h"

inline CSfmathVector4 operator *(const CSfmathVector4& V, float k)
{
	return CSfmathVector4(V.m[0] * k, V.m[1] * k, V.m[2] * k, V.m[3] * k);
}

CSfmathVector4::CSfmathVector4() noexcept
{

}

CSfmathVector4::CSfmathVector4(const CSfmathVector4& vt) noexcept
{
	Set(vt);
}

CSfmathVector4::CSfmathVector4(const CSfmathVector3& vt, float fW) noexcept
{
	Set(vt.m[0], vt.m[1], vt.m[2], fW);
}

CSfmathVector4::CSfmathVector4(float fX, float fY, float fZ, float fW) noexcept
{
	Set(fX, fY, fZ, fW);
}

CSfmathVector4::operator const float* () const noexcept
{
	return &m[0];
}

void CSfmathVector4::Set(const CSfmathVector4& vt) noexcept
{
	m[0] = vt.m[0]; m[1] = vt.m[1]; m[2] = vt.m[2]; m[3] = vt.m[3];
}

void CSfmathVector4::Set(const CSfmathVector3& vt, float fW) noexcept
{
	m[0] = vt.m[0]; m[1] = vt.m[1]; m[2] = vt.m[2]; m[3] = fW;
}

void CSfmathVector4::Set(float fX, float fY, float fZ, float fW) noexcept
{
	m[0] = fX; m[1] = fY; m[2] = fZ; m[3] = fW;
}
