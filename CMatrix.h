#pragma once
#include "CTransform.h"

#ifdef EXPORT_API
#define MATHS_API __declspec(dllexport)
#else
#define MATHS_API __declspec(dllimport)
#endif

class MATHS_API CMatrix
{
public:
	CMatrix();
	CMatrix(const CTransform& other);

public:
	void Set(const CRotation& rotation, const CVector3& vtTranslation, float fScale);
	void SetIdentity();

public:
	static const CMatrix& Perspective(CMatrix* pDest, float fYFOV, float fAspect, float fNear, float fFar);
	static const CMatrix& Mul(CMatrix* pAtoC, const CMatrix& AtoB, const CMatrix& BtoC);
	static const CVector3& Mul(CVector3* pOut, const CVector3& AA, const CMatrix& M);

public:
	float m11, m12, m13, m14;
	float m21, m22, m23, m24;
	float m31, m32, m33, m34;
	float m41, m42, m43, m44;
};

