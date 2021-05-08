#include "stdafx.h"
#include "CSfmathQuaternion.h"
#include <cmath>

#define M_PI 3.14159265358979323846

CSfmathQuaternion::CSfmathQuaternion(const CSfmathVector3& vt, float fAngleDegree)
{
	fAngleDegree = fAngleDegree / 360 * (float)M_PI * 2;

	m_fW = cos(fAngleDegree / 2);
	m_vtAxis = vt * sin(fAngleDegree / 2);
}

CSfmathQuaternion::CSfmathQuaternion()
{

}

const CSfmathQuaternion CSfmathQuaternion::Inverted() const
{
	return CSfmathQuaternion(-m_vtAxis, m_fW);
}

const CSfmathQuaternion CSfmathQuaternion::operator*(const CSfmathQuaternion& q) const
{
	return CSfmathQuaternion(m_vtAxis * q.m_fW + q.m_vtAxis * m_fW + m_vtAxis.CrossProduct(q.m_vtAxis),
		m_fW * q.m_fW + m_vtAxis.DotProduct(q.m_vtAxis));
}

const CSfmathVector3 CSfmathQuaternion::operator*(const CSfmathVector3& V) const
{
	CSfmathQuaternion p;
	p.m_fW = 0;
	p.m_vtAxis = V;

	CSfmathVector3 vcV = m_vtAxis.CrossProduct(V);
	return V + vcV * (2 * m_fW) + m_vtAxis.CrossProduct(vcV) * 2;
}
