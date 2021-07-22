#pragma once
#include "CSfmathVector3.h"

class MATHS_API CSfmathVector4
{
public:
	CSfmathVector4() noexcept;
	CSfmathVector4(const CSfmathVector4& vt) noexcept;
	CSfmathVector4(const CSfmathVector3& vt,float fW) noexcept;
	CSfmathVector4(float fX, float fY, float fZ, float fW) noexcept;

	operator const float* () const noexcept;
	CSfmathVector4 operator*(float k) const noexcept;

public:
	void Set(const CSfmathVector4& vt) noexcept;
	void Set(const CSfmathVector3& vt, float fW) noexcept;
	void Set(float fX, float fY, float fZ, float fW) noexcept;

public:
	float m[4];
};
