#include "stdafx.h"
#include "CSfmathMatrix.h"
#include <math.h>

CSfmathMatrix::CSfmathMatrix()
{
}

CSfmathMatrix::CSfmathMatrix(const CSfmathTransform& other)
{
	Set(other.m_rotation, other.m_vtTranslation, other.m_fScale);
}

CSfmathMatrix::CSfmathMatrix(const CSfmathRotation& other)
{
	Set(other);
}

void CSfmathMatrix::Set(const CSfmathRotation& rotation, const CSfmathVector3& vtTranslation, float fScale)
{
	float fCos = cosf(rotation.m_fAngle);
	float fSin = sinf(rotation.m_fAngle);

	float omc = 1.0f - fCos;

	float lx = rotation.m_vtAxis.m_fX;
	float ly = rotation.m_vtAxis.m_fY;
	float lz = rotation.m_vtAxis.m_fZ;

	float lxlxomc = lx * lx * omc;
	float lxlyomc = lx * ly * omc;
	float lxlzomc = lx * lz * omc;
	float lylyomc = ly * ly * omc;
	float lylzomc = ly * lz * omc;
	float lzlzomc = lz * lz * omc;

	float lxs = lx * fSin;
	float lys = ly * fSin;
	float lzs = lz * fSin;

	m11 = fScale * (lxlxomc + fCos); m12 = fScale * (lxlyomc + lzs);  m13 = fScale * (lxlzomc - lys);	 m14 = vtTranslation.m_fX;
	m21 = fScale * (lxlyomc - lzs);	 m22 = fScale * (lylyomc + fCos); m23 = fScale * (lylzomc + lxs);	 m24 = vtTranslation.m_fY;
	m31 = fScale * (lxlzomc + lys);	 m32 = fScale * (lylzomc - lxs);  m33 = fScale * (lzlzomc + fCos);	 m34 = vtTranslation.m_fZ,
	m41 = 0.0f;						 m42 = 0.0f;					  m43 = 0.0f;						 m44 = 1.0f;
}

void CSfmathMatrix::Set(const CSfmathRotation& rotation)
{
	float fCos = cosf(rotation.m_fAngle);
	float fSin = sinf(rotation.m_fAngle);

	float omc = 1.0f - fCos;

	float lx = rotation.m_vtAxis.m_fX;
	float ly = rotation.m_vtAxis.m_fY;
	float lz = rotation.m_vtAxis.m_fZ;

	float lxlxomc = lx * lx * omc;
	float lxlyomc = lx * ly * omc;
	float lxlzomc = lx * lz * omc;
	float lylyomc = ly * ly * omc;
	float lylzomc = ly * lz * omc;
	float lzlzomc = lz * lz * omc;

	float lxs = lx * fSin;
	float lys = ly * fSin;
	float lzs = lz * fSin;

	m11 = (lxlxomc + fCos); m12 = (lxlyomc + lzs);	m13 = (lxlzomc - lys);  m14 = 0;
	m21 = (lxlyomc - lzs);	m22 = (lylyomc + fCos); m23 = (lylzomc + lxs);  m24 = 0;
	m31 = (lxlzomc + lys);	m32 = (lylzomc - lxs);	m33 = (lzlzomc + fCos); m34 = 0;
	m41 = 0.0f;				m42 = 0.0f;				m43 = 0.0f;				m44 = 1.0f;
}

void CSfmathMatrix::Set(const CSfmathVector3& ptOrigin, const CSfmathVector3& vtX, const CSfmathVector3& vtY, const CSfmathVector3& vtZ)
{
	m11 = vtX.m_fX;
	m12 = vtY.m_fX;
	m13 = vtZ.m_fX;
	m14 = ptOrigin.m_fX;

	m21 = vtX.m_fY;
	m22 = vtY.m_fY;
	m23 = vtZ.m_fY;
	m24 = ptOrigin.m_fY;

	m31 = vtX.m_fZ;
	m32 = vtY.m_fZ;
	m33 = vtZ.m_fZ;
	m34 = ptOrigin.m_fZ;

	m41 = 0;
	m42 = 0;
	m43 = 0;
	m44 = 1;
}

void CSfmathMatrix::SetIdentity()
{
	m12 = m13 = m14 = m21 = m23 = m24 = m31 = m32 = m34 = m41 = m42 = m43 = 0.0f;
	m11 = m22 = m33 = m44 = 1.0f;
}

const CSfmathMatrix& CSfmathMatrix::Multiplication(CSfmathMatrix* pAtoC, const CSfmathMatrix& AtoB, const CSfmathMatrix& BtoC)
{
	pAtoC->m11 = AtoB.m11 * BtoC.m11 + AtoB.m21 * BtoC.m12 + AtoB.m31 * BtoC.m13 + AtoB.m41 * BtoC.m14;
	pAtoC->m12 = AtoB.m12 * BtoC.m11 + AtoB.m22 * BtoC.m12 + AtoB.m32 * BtoC.m13 + AtoB.m42 * BtoC.m14;
	pAtoC->m13 = AtoB.m13 * BtoC.m11 + AtoB.m23 * BtoC.m12 + AtoB.m33 * BtoC.m13 + AtoB.m43 * BtoC.m14;
	pAtoC->m14 = AtoB.m14 * BtoC.m11 + AtoB.m24 * BtoC.m12 + AtoB.m34 * BtoC.m13 + AtoB.m44 * BtoC.m14;

	pAtoC->m21 = AtoB.m11 * BtoC.m21 + AtoB.m21 * BtoC.m22 + AtoB.m31 * BtoC.m23 + AtoB.m41 * BtoC.m24;
	pAtoC->m22 = AtoB.m12 * BtoC.m21 + AtoB.m22 * BtoC.m22 + AtoB.m32 * BtoC.m23 + AtoB.m42 * BtoC.m24;
	pAtoC->m23 = AtoB.m13 * BtoC.m21 + AtoB.m23 * BtoC.m22 + AtoB.m33 * BtoC.m23 + AtoB.m43 * BtoC.m24;
	pAtoC->m24 = AtoB.m14 * BtoC.m21 + AtoB.m24 * BtoC.m22 + AtoB.m34 * BtoC.m23 + AtoB.m44 * BtoC.m24;

	pAtoC->m31 = AtoB.m11 * BtoC.m31 + AtoB.m21 * BtoC.m32 + AtoB.m31 * BtoC.m33 + AtoB.m41 * BtoC.m34;
	pAtoC->m32 = AtoB.m12 * BtoC.m31 + AtoB.m22 * BtoC.m32 + AtoB.m32 * BtoC.m33 + AtoB.m42 * BtoC.m34;
	pAtoC->m33 = AtoB.m13 * BtoC.m31 + AtoB.m23 * BtoC.m32 + AtoB.m33 * BtoC.m33 + AtoB.m43 * BtoC.m34;
	pAtoC->m34 = AtoB.m14 * BtoC.m31 + AtoB.m24 * BtoC.m32 + AtoB.m34 * BtoC.m33 + AtoB.m44 * BtoC.m34;

	pAtoC->m41 = AtoB.m11 * BtoC.m41 + AtoB.m21 * BtoC.m42 + AtoB.m31 * BtoC.m43 + AtoB.m41 * BtoC.m44;
	pAtoC->m42 = AtoB.m12 * BtoC.m41 + AtoB.m22 * BtoC.m42 + AtoB.m32 * BtoC.m43 + AtoB.m42 * BtoC.m44;
	pAtoC->m43 = AtoB.m13 * BtoC.m41 + AtoB.m23 * BtoC.m42 + AtoB.m33 * BtoC.m43 + AtoB.m43 * BtoC.m44;
	pAtoC->m44 = AtoB.m14 * BtoC.m41 + AtoB.m24 * BtoC.m42 + AtoB.m34 * BtoC.m43 + AtoB.m44 * BtoC.m44;

	return *pAtoC;
}

const CSfmathVector3& CSfmathMatrix::Multiplication(CSfmathVector3* pOut, const CSfmathVector3& AA, const CSfmathMatrix& M)
{
	CSfmathVector3 A(AA);

	pOut->Set(M.m11 * A.m_fX + M.m12 * A.m_fY + M.m13 * A.m_fZ + M.m14,
		M.m21 * A.m_fX + M.m22 * A.m_fY + M.m23 * A.m_fZ + M.m24,
		M.m31 * A.m_fX + M.m32 * A.m_fY + M.m33 * A.m_fZ + M.m34);

	return *pOut;
}

const CSfmathVector4& CSfmathMatrix::Multiplication(CSfmathVector4* pRes, const CSfmathVector3& A, const CSfmathMatrix& M)
{
	pRes->m_fX = M.m11 * A.m_fX + M.m12 * A.m_fY + M.m13 * A.m_fZ + M.m14;
	pRes->m_fY = M.m21 * A.m_fX + M.m22 * A.m_fY + M.m23 * A.m_fZ + M.m24;
	pRes->m_fZ = M.m31 * A.m_fX + M.m32 * A.m_fY + M.m33 * A.m_fZ + M.m34;
	pRes->m_fW = M.m41 * A.m_fX + M.m42 * A.m_fY + M.m43 * A.m_fZ + M.m44;

	return *pRes;
}

