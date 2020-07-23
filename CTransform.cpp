#include "stdafx.h"
#include "CTransform.h"

CRotation::CRotation()
{

}

CRotation::CRotation(const CRotation& other) :m_vtAxis(other.m_vtAxis), m_fAngle(other.m_fAngle)
{

}

CRotation::CRotation(const CVector3& vtAxis, float fAngle) : m_vtAxis(vtAxis), m_fAngle(fAngle)
{

}

const CVector3& CRotation::GetAxis()
{
	return m_vtAxis;
}

void CRotation::SetAxis(const CVector3& vtAxis)
{
	m_vtAxis = vtAxis;
}

float CRotation::GetAngle()
{
	return m_fAngle;
}

void CRotation::SetAngle(float fAngle)
{
	m_fAngle = fAngle;
}
