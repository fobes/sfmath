#pragma once
#include "CVector3.h"

#ifdef EXPORT_API
#define MATHS_API __declspec(dllexport)
#else
#define MATHS_API __declspec(dllimport)
#endif

class MATHS_API CRotation
{
public:
	CRotation();
	CRotation(const CRotation& other);
	CRotation(const CVector3& vtAxis, float fAngle);

public:
	const CVector3& GetAxis();
	void SetAxis(const CVector3& vtAxis);

	float GetAngle();
	void SetAngle(float fAngle);

public:
	CVector3 m_vtAxis;
	float m_fAngle;
};

struct MATHS_API CTransform
{
	CRotation m_rotation;
	CVector3 m_vtTranslation;
	float m_fScale;
};

