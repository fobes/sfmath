#include "stdafx.h"
#include "CVector4.h"

inline CVector4 operator *(const CVector4& V, float k)
{
	return CVector4(V.m_fX * k, V.m_fY * k, V.m_fZ * k, V.m_fW * k);
}

CVector4::CVector4()
{

}

CVector4::CVector4(const CVector4& vt)
{
	Set(vt);
}

CVector4::CVector4(const CVector3& vt, float fW)
{
	Set(vt.m_fX, vt.m_fY, vt.m_fZ, fW);
}

CVector4::CVector4(float fX, float fY, float fZ, float fW)
{
	Set(fX, fY, fZ, fW);
}

CVector4::operator const float* () const
{
	return &m_fX;
}

void CVector4::Set(const CVector4& vt)
{
	m_fX = vt.m_fX; m_fY = vt.m_fY; m_fZ = vt.m_fZ; m_fW = vt.m_fW;
}

void CVector4::Set(const CVector3& vt, float fW)
{
	m_fX = vt.m_fX; m_fY = vt.m_fY; m_fZ = vt.m_fZ; m_fW = fW;
}

void CVector4::Set(float fX, float fY, float fZ, float fW)
{
	m_fX = fX; m_fY = fY; m_fZ = fZ; m_fW = fW;
}
