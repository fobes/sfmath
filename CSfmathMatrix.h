#pragma once
#include "CSfmathTransform.h"
#include "CSfmathVector4.h"
#include "Export.h"

class MATHS_API CSfmathMatrix
{
public:
	CSfmathMatrix();
	CSfmathMatrix(const CSfmathTransform& other);
	CSfmathMatrix(const CSfmathRotation& other);

public:
	void Set(const CSfmathRotation& rotation, const CSfmathVector3& vtTranslation, float fScale);
	void Set(const CSfmathRotation& rotation);
	void SetIdentity();

public:
	static const CSfmathMatrix& Perspective(CSfmathMatrix* pDest, float fYFOV, float fAspect, float fNear, float fFar);
	static const CSfmathMatrix& Mul(CSfmathMatrix* pAtoC, const CSfmathMatrix& AtoB, const CSfmathMatrix& BtoC);
	static const CSfmathVector3& Mul(CSfmathVector3* pOut, const CSfmathVector3& AA, const CSfmathMatrix& M);
	static const CSfmathVector4& Mul(CSfmathVector4* pRes, const CSfmathVector3& A, const CSfmathMatrix& M);


public:
	float m11, m12, m13, m14;
	float m21, m22, m23, m24;
	float m31, m32, m33, m34;
	float m41, m42, m43, m44;
};

