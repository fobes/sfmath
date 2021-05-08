#pragma once
#include "CSfmathVector3.h"
#include "Export.h"

class MATHS_API CSfmathRotation
{
public:
	CSfmathRotation();
	CSfmathRotation(const CSfmathRotation& other);
	CSfmathRotation(const CSfmathVector3& vtAxis, float fAngle);

public:
	const CSfmathVector3& GetAxis();
	void SetAxis(const CSfmathVector3& vtAxis);

	float GetAngle();
	void SetAngle(float fAngle);

public:
	CSfmathVector3 m_vtAxis;
	float m_fAngle;
};

struct MATHS_API CSfmathTransform
{
	CSfmathRotation m_rotation;
	CSfmathVector3 m_vtTranslation;
	float m_fScale;
};

