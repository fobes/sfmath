#pragma once
#include "CSfmathVector3.h"
#include "Export.h"

class MATHS_API CSfmathQuaternion
{
public:
	CSfmathQuaternion() noexcept;
	CSfmathQuaternion(const CSfmathVector3& vt, float fAngleDegree) noexcept;

public:
	const CSfmathQuaternion Inverted() const noexcept;
	const CSfmathQuaternion operator*(const CSfmathQuaternion& q) const noexcept;
	const CSfmathVector3 operator*(const CSfmathVector3& V) const noexcept;

public:
	float m_fW;
	CSfmathVector3 m_vtAxis;
};
