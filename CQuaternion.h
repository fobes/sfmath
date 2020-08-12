#pragma once
#include "CVector3.h"

#ifdef EXPORT_API
#define MATHS_API __declspec(dllexport)
#else
#define MATHS_API __declspec(dllimport)
#endif

class MATHS_API CQuaternion
{
public:
	CQuaternion() {};
	CQuaternion(const CVector3& n, float fAngleDegree);

public:
	const CQuaternion Inverted() const;
	const CQuaternion operator*(const CQuaternion& q) const;
	const CVector3 operator*(const CVector3& V) const;

public:
	float m_fW;
	CVector3 m_vtAxis;
};
