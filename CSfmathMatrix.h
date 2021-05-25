#pragma once
#include "CSfmathTransform.h"
#include "CSfmathVector4.h"
#include "Export.h"

class MATHS_API CSfmathMatrix
{
public:
	CSfmathMatrix() noexcept;
	CSfmathMatrix(const CSfmathTransform& other) noexcept;
	CSfmathMatrix(const CSfmathRotation& other) noexcept;

public:
	void Set(const CSfmathRotation& rotation, const CSfmathVector3& vtTranslation, float fScale) noexcept;
	void Set(const CSfmathRotation& rotation) noexcept;
	void Set(const CSfmathVector3& ptOrigin, const CSfmathVector3& vtX, const CSfmathVector3& vtY, const CSfmathVector3& vtZ) noexcept;
	void SetIdentity() noexcept;

public:
	static const CSfmathMatrix& Multiplication(CSfmathMatrix* pAtoC, const CSfmathMatrix& AtoB, const CSfmathMatrix& BtoC) noexcept;
	static const CSfmathVector3& Multiplication(CSfmathVector3* pOut, const CSfmathVector3& AA, const CSfmathMatrix& M) noexcept;
	static const CSfmathVector4& Multiplication(CSfmathVector4* pRes, const CSfmathVector3& A, const CSfmathMatrix& M) noexcept;

public:
	float m1[4];
	float m2[4];
	float m3[4];
	float m4[4];
};

