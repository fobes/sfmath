#pragma once
#include "CSfmathVector3.h"

class MATHS_API CSfmathVector4
{
public:
	CSfmathVector4();
	CSfmathVector4(const CSfmathVector4& vt);
	CSfmathVector4(const CSfmathVector3& vt,float fW);
	CSfmathVector4(float fX, float fY, float fZ, float fW);

	operator const float*() const;

public:
	void Set(const CSfmathVector4& vt);
	void Set(const CSfmathVector3& vt, float fW);
	void Set(float fX, float fY, float fZ, float fW);

public:
	float m[4];
};

CSfmathVector4 operator *(const CSfmathVector4& V, float k);
