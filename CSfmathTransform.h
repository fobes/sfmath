#pragma once
#include "CSfmathVector3.h"
#include "Export.h"

class MATHS_API CSfmathRotation
{
public:
	CSfmathRotation() noexcept;
	CSfmathRotation(const CSfmathRotation& other) noexcept;
	CSfmathRotation(const CSfmathVector3& vtAxis, float fAngle) noexcept;

public:
	const CSfmathVector3& GetAxis() noexcept;
	void SetAxis(const CSfmathVector3& vtAxis) noexcept;

	float GetAngle() noexcept;
	void SetAngle(float fAngle) noexcept;

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

