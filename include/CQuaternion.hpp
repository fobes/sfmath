#pragma once

#define _USE_MATH_DEFINES
#include <cmath>
#include "CVector3.hpp"

namespace sfm
{
	class CQuaternion
	{
	public:
		CQuaternion() noexcept;
		CQuaternion(const CVector3& vt, float fAngleDegree) noexcept;

	public:
		const CQuaternion Inverted() const noexcept;
		const CQuaternion operator*(const CQuaternion& q) const noexcept;
		const CVector3 operator*(const CVector3& V) const noexcept;

	public:
		float m_fW;
		CVector3 m_vtAxis;
	};

	inline CQuaternion::CQuaternion(const CVector3& vt, float fAngleDegree) noexcept
	{
		fAngleDegree = fAngleDegree / 360.0f * static_cast<float>(M_PI * 2);

		m_fW = cos(fAngleDegree * 0.5f);
		m_vtAxis = vt * sin(fAngleDegree * 0.5f);
	}

	inline CQuaternion::CQuaternion() noexcept:
		m_fW(0.0f),
		m_vtAxis()
	{
	}

	inline const CQuaternion CQuaternion::Inverted() const noexcept
	{
		return CQuaternion(-m_vtAxis, m_fW);
	}

	inline const CQuaternion CQuaternion::operator*(const CQuaternion& q) const noexcept
	{
		return CQuaternion(m_vtAxis * q.m_fW + q.m_vtAxis * m_fW + m_vtAxis.CrossProduct(q.m_vtAxis),
			m_fW * q.m_fW + m_vtAxis.DotProduct(q.m_vtAxis));
	}

	inline const CVector3 CQuaternion::operator*(const CVector3& V) const noexcept
	{
		CQuaternion p;
		p.m_fW = 0;
		p.m_vtAxis = V;

		CVector3 vcV = m_vtAxis.CrossProduct(V);
		return V + vcV * (2 * m_fW) + m_vtAxis.CrossProduct(vcV) * 2;
	}
}