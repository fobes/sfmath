#pragma once
#include "CSfmathVector3.h"
#include "Export.h"

class MATHS_API CSfmathQuaternion
{
public:
	CSfmathQuaternion();
	CSfmathQuaternion(const CSfmathVector3& vt, float fAngleDegree);

public:
	const CSfmathQuaternion Inverted() const;
	const CSfmathQuaternion operator*(const CSfmathQuaternion& q) const;
	const CSfmathVector3 operator*(const CSfmathVector3& V) const;

public:
	float m_fW;
	CSfmathVector3 m_vtAxis;
};
