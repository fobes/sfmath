#include "stdafx.h"
#include "CSfmathMatrix.h"
#include <math.h>
#include <xmmintrin.h>

// Shuffle Parameters
#define SHUFFLE_PARAM(x,y,z,w) ((x) |(y) <<2 | ((z) <<4) | ((w)<<6))
#define _mm_replicate_x_ps(v) _mm_shuffle_ps((v),(v),SHUFFLE_PARAM(0,0,0,0))
#define _mm_replicate_y_ps(v) _mm_shuffle_ps((v),(v),SHUFFLE_PARAM(1,1,1,1))
#define _mm_replicate_z_ps(v) _mm_shuffle_ps((v),(v),SHUFFLE_PARAM(2,2,2,2))
#define _mm_replicate_w_ps(v) _mm_shuffle_ps((v),(v),SHUFFLE_PARAM(3,3,3,3))
#define _mm_madd_ps(a, b, c) _mm_add_ps(_mm_mul_ps((a), (b)), (c))

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

const CSfmathMatrix& CSfmathMatrix::Multiplication(CSfmathMatrix* pMtxAtoC, const CSfmathMatrix& mtxAtoB, const CSfmathMatrix& mtxBtoC) noexcept
{
	const __m128 m1_row_0 = _mm_loadu_ps(mtxAtoB.m1);
	const __m128 m1_row_1 = _mm_loadu_ps(mtxAtoB.m2);
	const __m128 m1_row_2 = _mm_loadu_ps(mtxAtoB.m3);
	const __m128 m1_row_3 = _mm_loadu_ps(mtxAtoB.m4);

	const __m128 m2_row_0 = _mm_loadu_ps(mtxBtoC.m1);
	const __m128 m2_row_1 = _mm_loadu_ps(mtxBtoC.m2);
	const __m128 m2_row_2 = _mm_loadu_ps(mtxBtoC.m3);
	const __m128 m2_row_3 = _mm_loadu_ps(mtxBtoC.m4);

	__m128 out0 = _mm_mul_ps(m1_row_0, _mm_replicate_x_ps(m2_row_0));
	__m128 out1 = _mm_mul_ps(m1_row_0, _mm_replicate_x_ps(m2_row_1));
	__m128 out2 = _mm_mul_ps(m1_row_0, _mm_replicate_x_ps(m2_row_2));
	__m128 out3 = _mm_mul_ps(m1_row_0, _mm_replicate_x_ps(m2_row_3));

	out0 = _mm_madd_ps(m1_row_1, _mm_replicate_y_ps(m2_row_0), out0);
	out1 = _mm_madd_ps(m1_row_1, _mm_replicate_y_ps(m2_row_1), out1);
	out2 = _mm_madd_ps(m1_row_1, _mm_replicate_y_ps(m2_row_2), out2);
	out3 = _mm_madd_ps(m1_row_1, _mm_replicate_y_ps(m2_row_3), out3);

	out0 = _mm_madd_ps(m1_row_2, _mm_replicate_z_ps(m2_row_0), out0);
	out1 = _mm_madd_ps(m1_row_2, _mm_replicate_z_ps(m2_row_1), out1);
	out2 = _mm_madd_ps(m1_row_2, _mm_replicate_z_ps(m2_row_2), out2);
	out3 = _mm_madd_ps(m1_row_2, _mm_replicate_z_ps(m2_row_3), out3);

	out0 = _mm_madd_ps(m1_row_3, _mm_replicate_w_ps(m2_row_0), out0);
	out1 = _mm_madd_ps(m1_row_3, _mm_replicate_w_ps(m2_row_1), out1);
	out2 = _mm_madd_ps(m1_row_3, _mm_replicate_w_ps(m2_row_2), out2);
	out3 = _mm_madd_ps(m1_row_3, _mm_replicate_w_ps(m2_row_3), out3);

	_mm_store_ps(pMtxAtoC->m1, out0);
	_mm_store_ps(pMtxAtoC->m2, out1);
	_mm_store_ps(pMtxAtoC->m3, out2);
	_mm_store_ps(pMtxAtoC->m4, out3);

	return *pMtxAtoC;
}

const CSfmathVector3& CSfmathMatrix::Multiplication(CSfmathVector3* pVtOut, const CSfmathVector3& vt, const CSfmathMatrix& M) noexcept
{
	const __m128& vector = _mm_setr_ps(vt.m[0], vt.m[1], vt.m[2], 0.f);

	const __m128& m_row_0 = _mm_loadu_ps(M.m1);
	const __m128& m_row_1 = _mm_loadu_ps(M.m2);
	const __m128& m_row_2 = _mm_loadu_ps(M.m3);

	__m128 out0 = _mm_mul_ps(_mm_replicate_x_ps(m_row_0), _mm_replicate_x_ps(vector));
	out0 = _mm_add_ps(out0, _mm_mul_ps(_mm_replicate_y_ps(m_row_0), _mm_replicate_y_ps(vector)));
	out0 = _mm_add_ps(out0, _mm_mul_ps(_mm_replicate_z_ps(m_row_0), _mm_replicate_z_ps(vector)));
	out0 = _mm_add_ps(out0, _mm_replicate_w_ps(m_row_0));

	__m128 out1 = _mm_mul_ps(_mm_replicate_x_ps(m_row_1), _mm_replicate_x_ps(vector));
	out1 = _mm_add_ps(out1, _mm_mul_ps(_mm_replicate_y_ps(m_row_1), _mm_replicate_y_ps(vector)));
	out1 = _mm_add_ps(out1, _mm_mul_ps(_mm_replicate_z_ps(m_row_1), _mm_replicate_z_ps(vector)));
	out1 = _mm_add_ps(out1, _mm_replicate_w_ps(m_row_1));

	__m128 out2 = _mm_mul_ps(_mm_replicate_x_ps(m_row_2), _mm_replicate_x_ps(vector));
	out2 = _mm_add_ps(out2, _mm_mul_ps(_mm_replicate_y_ps(m_row_2), _mm_replicate_y_ps(vector)));
	out2 = _mm_add_ps(out2, _mm_mul_ps(_mm_replicate_z_ps(m_row_2), _mm_replicate_z_ps(vector)));
	out2 = _mm_add_ps(out2, _mm_replicate_w_ps(m_row_2));

	_mm_store_ss(&pVtOut->m[0], out0);
	_mm_store_ss(&pVtOut->m[1], out1);
	_mm_store_ss(&pVtOut->m[2], out2);

	return *pVtOut;
}
