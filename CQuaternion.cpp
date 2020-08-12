#include "stdafx.h"
#include "CQuaternion.h"
#include <cmath>

#define M_PI 3.14159265358979323846

CQuaternion::CQuaternion(const CVector3& n, float fAngleDegree)
{
	fAngleDegree = fAngleDegree / 360 * (float)M_PI * 2;

	m_fW = cos(fAngleDegree / 2);
	m_vtAxis = n * sin(fAngleDegree / 2);
}

const CQuaternion CQuaternion::Inverted() const
{
	return CQuaternion(-m_vtAxis, m_fW);
}

const CQuaternion CQuaternion::operator*(const CQuaternion& q) const
{
	return CQuaternion(m_vtAxis * q.m_fW + q.m_vtAxis * m_fW + m_vtAxis.CrossProduct(q.m_vtAxis),
		m_fW * q.m_fW + m_vtAxis.DotProduct(q.m_vtAxis));
}

const CVector3 CQuaternion::operator*(const CVector3& V) const
{
	CQuaternion p;
	p.m_fW = 0;
	p.m_vtAxis = V;

	CVector3 vcV = m_vtAxis.CrossProduct(V);
	return V + vcV * (2 * m_fW) + m_vtAxis.CrossProduct(vcV) * 2;
}
