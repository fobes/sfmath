#include "stdafx.h"
#include "CMatrix.h"
#include <math.h>

#define MTXSET(M, _m11,_m12,_m13,_m14, _m21,_m22,_m23,_m24, _m31,_m32,_m33,_m34, _m41,_m42,_m43,_m44 ) do{ \
		(M).m11=(_m11); (M).m12=(_m12); (M).m13=(_m13); (M).m14=(_m14);	\
		(M).m21=(_m21); (M).m22=(_m22); (M).m23=(_m23); (M).m24=(_m24);	\
		(M).m31=(_m31); (M).m32=(_m32); (M).m33=(_m33); (M).m34=(_m34);	\
		(M).m41=(_m41); (M).m42=(_m42); (M).m43=(_m43); (M).m44=(_m44);	\
	} while(0)

CMatrix::CMatrix()
{
}

CMatrix::CMatrix(const CTransform& other)
{
	Set(other.m_rotation, other.m_vtTranslation, other.m_fScale);
}

CMatrix::CMatrix(const CRotation& other)
{
	Set(other);
}

void CMatrix::Set(const CRotation& rotation, const CVector3& vtTranslation, float fScale)
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

	MTXSET(*this,	
		fScale * (lxlxomc + fCos),		fScale * (lxlyomc + lzs),	fScale * (lxlzomc - lys),	vtTranslation.m_fX,
		fScale* (lxlyomc - lzs),		fScale * (lylyomc + fCos),	fScale * (lylzomc + lxs),	vtTranslation.m_fY,
		fScale* (lxlzomc + lys),		fScale * (lylzomc - lxs),	fScale * (lzlzomc + fCos),	vtTranslation.m_fZ,
		0.0f, 0.0f, 0.0f, 1.0f);
}

void CMatrix::Set(const CRotation& rotation)
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

	MTXSET(*this,
		(lxlxomc + fCos),	(lxlyomc + lzs),	(lxlzomc - lys),	0,
		(lxlyomc - lzs),	(lylyomc + fCos),	(lylzomc + lxs),	0,
		(lxlzomc + lys),	(lylzomc - lxs),	(lzlzomc + fCos),	0,
		0.0f, 0.0f, 0.0f, 1.0f);
}

void CMatrix::SetIdentity()
{
	m12 = m13 = m14 = m21 = m23 = m24 = m31 = m32 = m34 = m41 = m42 = m43 = 0.0f;
	m11 = m22 = m33 = m44 = 1.0f;
}

const CMatrix& CMatrix::Perspective(CMatrix* pDest, float fYFOV, float fAspect, float fNear, float fFar)
{
	float fTanHalfFov = tanf(fYFOV * 0.5f);

	float fScaleY = 1.0f / fTanHalfFov;
	float fScaleX = fScaleY / fAspect;

	MTXSET(*pDest,
		fScaleX,	0.0f,		0.0f,					0.0f,
		0.0f,		fScaleY,	0.0f,					0.0f,
		0.0f,		0.0f,		fFar / (fFar - fNear),		-fNear * fFar / (fFar - fNear),
		0.0f,		0.0f,		1.0f,					0.0f);

	return *pDest;
}

const CMatrix& CMatrix::Mul(CMatrix* pAtoC, const CMatrix& AtoB, const CMatrix& BtoC)
{
	MTXSET(*pAtoC,
		AtoB.m11 * BtoC.m11 + AtoB.m21 * BtoC.m12 + AtoB.m31 * BtoC.m13 + AtoB.m41 * BtoC.m14,
		AtoB.m12 * BtoC.m11 + AtoB.m22 * BtoC.m12 + AtoB.m32 * BtoC.m13 + AtoB.m42 * BtoC.m14,
		AtoB.m13 * BtoC.m11 + AtoB.m23 * BtoC.m12 + AtoB.m33 * BtoC.m13 + AtoB.m43 * BtoC.m14,
		AtoB.m14 * BtoC.m11 + AtoB.m24 * BtoC.m12 + AtoB.m34 * BtoC.m13 + AtoB.m44 * BtoC.m14,

		AtoB.m11 * BtoC.m21 + AtoB.m21 * BtoC.m22 + AtoB.m31 * BtoC.m23 + AtoB.m41 * BtoC.m24,
		AtoB.m12 * BtoC.m21 + AtoB.m22 * BtoC.m22 + AtoB.m32 * BtoC.m23 + AtoB.m42 * BtoC.m24,
		AtoB.m13 * BtoC.m21 + AtoB.m23 * BtoC.m22 + AtoB.m33 * BtoC.m23 + AtoB.m43 * BtoC.m24,
		AtoB.m14 * BtoC.m21 + AtoB.m24 * BtoC.m22 + AtoB.m34 * BtoC.m23 + AtoB.m44 * BtoC.m24,

		AtoB.m11 * BtoC.m31 + AtoB.m21 * BtoC.m32 + AtoB.m31 * BtoC.m33 + AtoB.m41 * BtoC.m34,
		AtoB.m12 * BtoC.m31 + AtoB.m22 * BtoC.m32 + AtoB.m32 * BtoC.m33 + AtoB.m42 * BtoC.m34,
		AtoB.m13 * BtoC.m31 + AtoB.m23 * BtoC.m32 + AtoB.m33 * BtoC.m33 + AtoB.m43 * BtoC.m34,
		AtoB.m14 * BtoC.m31 + AtoB.m24 * BtoC.m32 + AtoB.m34 * BtoC.m33 + AtoB.m44 * BtoC.m34,

		AtoB.m11 * BtoC.m41 + AtoB.m21 * BtoC.m42 + AtoB.m31 * BtoC.m43 + AtoB.m41 * BtoC.m44,
		AtoB.m12 * BtoC.m41 + AtoB.m22 * BtoC.m42 + AtoB.m32 * BtoC.m43 + AtoB.m42 * BtoC.m44,
		AtoB.m13 * BtoC.m41 + AtoB.m23 * BtoC.m42 + AtoB.m33 * BtoC.m43 + AtoB.m43 * BtoC.m44,
		AtoB.m14 * BtoC.m41 + AtoB.m24 * BtoC.m42 + AtoB.m34 * BtoC.m43 + AtoB.m44 * BtoC.m44
	);

	return *pAtoC;
}

const CVector3& CMatrix::Mul(CVector3* pOut, const CVector3& AA, const CMatrix& M)
{
	CVector3 A(AA);

	pOut->Set(M.m11 * A.m_fX + M.m12 * A.m_fY + M.m13 * A.m_fZ + M.m14,
		M.m21 * A.m_fX + M.m22 * A.m_fY + M.m23 * A.m_fZ + M.m24,
		M.m31 * A.m_fX + M.m32 * A.m_fY + M.m33 * A.m_fZ + M.m34);

	return *pOut;
}

const CVector4& CMatrix::Mul(CVector4* pRes, const CVector3& A, const CMatrix& M)
{
	pRes->m_fX = M.m11 * A.m_fX + M.m12 * A.m_fY + M.m13 * A.m_fZ + M.m14;
	pRes->m_fY = M.m21 * A.m_fX + M.m22 * A.m_fY + M.m23 * A.m_fZ + M.m24;
	pRes->m_fZ = M.m31 * A.m_fX + M.m32 * A.m_fY + M.m33 * A.m_fZ + M.m34;
	pRes->m_fW = M.m41 * A.m_fX + M.m42 * A.m_fY + M.m43 * A.m_fZ + M.m44;

	return *pRes;
}

