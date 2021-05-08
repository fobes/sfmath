#include "stdafx.h"
#include "CSfmathTransform.h"

CSfmathRotation::CSfmathRotation()
{

}

CSfmathRotation::CSfmathRotation(const CSfmathRotation& other) :m_vtAxis(other.m_vtAxis), m_fAngle(other.m_fAngle)
{

}

CSfmathRotation::CSfmathRotation(const CSfmathVector3& vtAxis, float fAngle) : m_vtAxis(vtAxis), m_fAngle(fAngle)
{

}

const CSfmathVector3& CSfmathRotation::GetAxis()
{
	return m_vtAxis;
}

void CSfmathRotation::SetAxis(const CSfmathVector3& vtAxis)
{
	m_vtAxis = vtAxis;
}

float CSfmathRotation::GetAngle()
{
	return m_fAngle;
}

void CSfmathRotation::SetAngle(float fAngle)
{
	m_fAngle = fAngle;
}
