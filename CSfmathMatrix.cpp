#include "stdafx.h"
#include "CSfmathMatrix.h"
#include <math.h>

CSfmathMatrix::CSfmathMatrix() noexcept
{
}

CSfmathMatrix::CSfmathMatrix(const CSfmathTransform& other) noexcept
{
	Set(other.m_rotation, other.m_vtTranslation, other.m_fScale);
}

CSfmathMatrix::CSfmathMatrix(const CSfmathRotation& other) noexcept
{
	Set(other);
}

void CSfmathMatrix::Set(const CSfmathRotation& rotation, const CSfmathVector3& vtTranslation, float fScale) noexcept
{
	float fCos = cosf(rotation.m_fAngle);
	float fSin = sinf(rotation.m_fAngle);

	float omc = 1.0f - fCos;

	float lx = rotation.m_vtAxis.m[0];
	float ly = rotation.m_vtAxis.m[1];
	float lz = rotation.m_vtAxis.m[2];

	float lxlxomc = lx * lx * omc;
	float lxlyomc = lx * ly * omc;
	float lxlzomc = lx * lz * omc;
	float lylyomc = ly * ly * omc;
	float lylzomc = ly * lz * omc;
	float lzlzomc = lz * lz * omc;

	float lxs = lx * fSin;
	float lys = ly * fSin;
	float lzs = lz * fSin;

	m1[0] = fScale * (lxlxomc + fCos); m1[1] = fScale * (lxlyomc + lzs);  m1[2] = fScale * (lxlzomc - lys);	 m1[3] = vtTranslation.m[0];
	m2[0] = fScale * (lxlyomc - lzs);	 m2[1] = fScale * (lylyomc + fCos); m2[2] = fScale * (lylzomc + lxs);	 m2[3] = vtTranslation.m[1];
	m3[0] = fScale * (lxlzomc + lys);	 m3[1] = fScale * (lylzomc - lxs);  m3[2] = fScale * (lzlzomc + fCos);	 m3[3] = vtTranslation.m[2],
	m4[0] = 0.0f;						 m4[1] = 0.0f;					  m4[2] = 0.0f;						 m4[3] = 1.0f;
}

void CSfmathMatrix::Set(const CSfmathRotation& rotation) noexcept
{
	float fCos = cosf(rotation.m_fAngle);
	float fSin = sinf(rotation.m_fAngle);

	float omc = 1.0f - fCos;

	float lx = rotation.m_vtAxis.m[0];
	float ly = rotation.m_vtAxis.m[1];
	float lz = rotation.m_vtAxis.m[2];

	float lxlxomc = lx * lx * omc;
	float lxlyomc = lx * ly * omc;
	float lxlzomc = lx * lz * omc;
	float lylyomc = ly * ly * omc;
	float lylzomc = ly * lz * omc;
	float lzlzomc = lz * lz * omc;

	float lxs = lx * fSin;
	float lys = ly * fSin;
	float lzs = lz * fSin;

	m1[0] = (lxlxomc + fCos); m1[1] = (lxlyomc + lzs);	m1[2] = (lxlzomc - lys);  m1[3] = 0;
	m2[0] = (lxlyomc - lzs);	m2[1] = (lylyomc + fCos); m2[2] = (lylzomc + lxs);  m2[3] = 0;
	m3[0] = (lxlzomc + lys);	m3[1] = (lylzomc - lxs);	m3[2] = (lzlzomc + fCos); m3[3] = 0;
	m4[0] = 0.0f;				m4[1] = 0.0f;				m4[2] = 0.0f;				m4[3] = 1.0f;
}

void CSfmathMatrix::Set(const CSfmathVector3& ptOrigin, const CSfmathVector3& vtX, const CSfmathVector3& vtY, const CSfmathVector3& vtZ) noexcept
{
	m1[0] = vtX.m[0];
	m1[1] = vtY.m[0];
	m1[2] = vtZ.m[0];
	m1[3] = ptOrigin.m[0];

	m2[0] = vtX.m[1];
	m2[1] = vtY.m[1];
	m2[2] = vtZ.m[1];
	m2[3] = ptOrigin.m[1];

	m3[0] = vtX.m[2];
	m3[1] = vtY.m[2];
	m3[2] = vtZ.m[2];
	m3[3] = ptOrigin.m[2];

	m4[0] = 0;
	m4[1] = 0;
	m4[2] = 0;
	m4[3] = 1;
}

void CSfmathMatrix::SetIdentity() noexcept
{
	m1[1] = m1[2] = m1[3] = m2[0] = m2[2] = m2[3] = m3[0] = m3[1] = m3[3] = m4[0] = m4[1] = m4[2] = 0.0f;
	m1[0] = m2[1] = m3[2] = m4[3] = 1.0f;
}

const CSfmathMatrix& CSfmathMatrix::Multiplication(CSfmathMatrix* pAtoC, const CSfmathMatrix& AtoB, const CSfmathMatrix& BtoC) noexcept
{
	pAtoC->m1[0] = AtoB.m1[0] * BtoC.m1[0] + AtoB.m2[0] * BtoC.m1[1] + AtoB.m3[0] * BtoC.m1[2] + AtoB.m4[0] * BtoC.m1[3];
	pAtoC->m1[1] = AtoB.m1[1] * BtoC.m1[0] + AtoB.m2[1] * BtoC.m1[1] + AtoB.m3[1] * BtoC.m1[2] + AtoB.m4[1] * BtoC.m1[3];
	pAtoC->m1[2] = AtoB.m1[2] * BtoC.m1[0] + AtoB.m2[2] * BtoC.m1[1] + AtoB.m3[2] * BtoC.m1[2] + AtoB.m4[2] * BtoC.m1[3];
	pAtoC->m1[3] = AtoB.m1[3] * BtoC.m1[0] + AtoB.m2[3] * BtoC.m1[1] + AtoB.m3[3] * BtoC.m1[2] + AtoB.m4[3] * BtoC.m1[3];

	pAtoC->m2[0] = AtoB.m1[0] * BtoC.m2[0] + AtoB.m2[0] * BtoC.m2[1] + AtoB.m3[0] * BtoC.m2[2] + AtoB.m4[0] * BtoC.m2[3];
	pAtoC->m2[1] = AtoB.m1[1] * BtoC.m2[0] + AtoB.m2[1] * BtoC.m2[1] + AtoB.m3[1] * BtoC.m2[2] + AtoB.m4[1] * BtoC.m2[3];
	pAtoC->m2[2] = AtoB.m1[2] * BtoC.m2[0] + AtoB.m2[2] * BtoC.m2[1] + AtoB.m3[2] * BtoC.m2[2] + AtoB.m4[2] * BtoC.m2[3];
	pAtoC->m2[3] = AtoB.m1[3] * BtoC.m2[0] + AtoB.m2[3] * BtoC.m2[1] + AtoB.m3[3] * BtoC.m2[2] + AtoB.m4[3] * BtoC.m2[3];

	pAtoC->m3[0] = AtoB.m1[0] * BtoC.m3[0] + AtoB.m2[0] * BtoC.m3[1] + AtoB.m3[0] * BtoC.m3[2] + AtoB.m4[0] * BtoC.m3[3];
	pAtoC->m3[1] = AtoB.m1[1] * BtoC.m3[0] + AtoB.m2[1] * BtoC.m3[1] + AtoB.m3[1] * BtoC.m3[2] + AtoB.m4[1] * BtoC.m3[3];
	pAtoC->m3[2] = AtoB.m1[2] * BtoC.m3[0] + AtoB.m2[2] * BtoC.m3[1] + AtoB.m3[2] * BtoC.m3[2] + AtoB.m4[2] * BtoC.m3[3];
	pAtoC->m3[3] = AtoB.m1[3] * BtoC.m3[0] + AtoB.m2[3] * BtoC.m3[1] + AtoB.m3[3] * BtoC.m3[2] + AtoB.m4[3] * BtoC.m3[3];

	pAtoC->m4[0] = AtoB.m1[0] * BtoC.m4[0] + AtoB.m2[0] * BtoC.m4[1] + AtoB.m3[0] * BtoC.m4[2] + AtoB.m4[0] * BtoC.m4[3];
	pAtoC->m4[1] = AtoB.m1[1] * BtoC.m4[0] + AtoB.m2[1] * BtoC.m4[1] + AtoB.m3[1] * BtoC.m4[2] + AtoB.m4[1] * BtoC.m4[3];
	pAtoC->m4[2] = AtoB.m1[2] * BtoC.m4[0] + AtoB.m2[2] * BtoC.m4[1] + AtoB.m3[2] * BtoC.m4[2] + AtoB.m4[2] * BtoC.m4[3];
	pAtoC->m4[3] = AtoB.m1[3] * BtoC.m4[0] + AtoB.m2[3] * BtoC.m4[1] + AtoB.m3[3] * BtoC.m4[2] + AtoB.m4[3] * BtoC.m4[3];

	return *pAtoC;
}

const CSfmathVector3& CSfmathMatrix::Multiplication(CSfmathVector3* pOut, const CSfmathVector3& AA, const CSfmathMatrix& M) noexcept
{
	CSfmathVector3 A(AA);

	pOut->Set(M.m1[0] * A.m[0] + M.m1[1] * A.m[1] + M.m1[2] * A.m[2] + M.m1[3],
		M.m2[0] * A.m[0] + M.m2[1] * A.m[1] + M.m2[2] * A.m[2] + M.m2[3],
		M.m3[0] * A.m[0] + M.m3[1] * A.m[1] + M.m3[2] * A.m[2] + M.m3[3]);

	return *pOut;
}

const CSfmathVector4& CSfmathMatrix::Multiplication(CSfmathVector4* pRes, const CSfmathVector3& A, const CSfmathMatrix& M) noexcept
{
	pRes->m[0] = M.m1[0] * A.m[0] + M.m1[1] * A.m[1] + M.m1[2] * A.m[2] + M.m1[3];
	pRes->m[1] = M.m2[0] * A.m[0] + M.m2[1] * A.m[1] + M.m2[2] * A.m[2] + M.m2[3];
	pRes->m[2] = M.m3[0] * A.m[0] + M.m3[1] * A.m[1] + M.m3[2] * A.m[2] + M.m3[3];
	pRes->m[3] = M.m4[0] * A.m[0] + M.m4[1] * A.m[1] + M.m4[2] * A.m[2] + M.m4[3];

	return *pRes;
}

