#include "stdafx.h"
#include "CSfmathTransform.h"

CSfmathRotation::CSfmathRotation() noexcept
{

}

CSfmathRotation::CSfmathRotation(const CSfmathRotation& other) noexcept :m_vtAxis(other.m_vtAxis), m_fAngle(other.m_fAngle)
{

}

CSfmathRotation::CSfmathRotation(const CSfmathVector3& vtAxis, float fAngle) noexcept : m_vtAxis(vtAxis), m_fAngle(fAngle)
{

}

const CSfmathVector3& CSfmathRotation::GetAxis() noexcept
{
	return m_vtAxis;
}

void CSfmathRotation::SetAxis(const CSfmathVector3& vtAxis) noexcept
{
	m_vtAxis = vtAxis;
}

float CSfmathRotation::GetAngle() noexcept
{
	return m_fAngle;
}

void CSfmathRotation::SetAngle(float fAngle) noexcept
{
	m_fAngle = fAngle;
}
