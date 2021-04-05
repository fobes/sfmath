#pragma once
#include "CVector3.h"
#include "Export.h"

class MATHS_API CQuaternion
{
public:
	CQuaternion();
	CQuaternion(const CVector3& vt, float fAngleDegree);

public:
	const CQuaternion Inverted() const;
	const CQuaternion operator*(const CQuaternion& q) const;
	const CVector3 operator*(const CVector3& V) const;

public:
	float m_fW;
	CVector3 m_vtAxis;
};
