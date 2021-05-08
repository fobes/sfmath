#include "stdafx.h"
#include "CSfmathVector4.h"

inline CSfmathVector4 operator *(const CSfmathVector4& V, float k)
{
	return CSfmathVector4(V.m_fX * k, V.m_fY * k, V.m_fZ * k, V.m_fW * k);
}

CSfmathVector4::CSfmathVector4()
{

}

CSfmathVector4::CSfmathVector4(const CSfmathVector4& vt)
{
	Set(vt);
}

CSfmathVector4::CSfmathVector4(const CSfmathVector3& vt, float fW)
{
	Set(vt.m_fX, vt.m_fY, vt.m_fZ, fW);
}

CSfmathVector4::CSfmathVector4(float fX, float fY, float fZ, float fW)
{
	Set(fX, fY, fZ, fW);
}

CSfmathVector4::operator const float* () const
{
	return &m_fX;
}

void CSfmathVector4::Set(const CSfmathVector4& vt)
{
	m_fX = vt.m_fX; m_fY = vt.m_fY; m_fZ = vt.m_fZ; m_fW = vt.m_fW;
}

void CSfmathVector4::Set(const CSfmathVector3& vt, float fW)
{
	m_fX = vt.m_fX; m_fY = vt.m_fY; m_fZ = vt.m_fZ; m_fW = fW;
}

void CSfmathVector4::Set(float fX, float fY, float fZ, float fW)
{
	m_fX = fX; m_fY = fY; m_fZ = fZ; m_fW = fW;
}
