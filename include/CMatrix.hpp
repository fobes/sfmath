#pragma once
#include "CVector4.hpp"
#include <xmmintrin.h>

namespace sfm
{
#define SHUFFLE_PARAM(x,y,z,w) ((x) |(y) <<2 | ((z) <<4) | ((w)<<6))
#define _mm_replicate_x_ps(v) _mm_shuffle_ps((v),(v),SHUFFLE_PARAM(0,0,0,0))
#define _mm_replicate_y_ps(v) _mm_shuffle_ps((v),(v),SHUFFLE_PARAM(1,1,1,1))
#define _mm_replicate_z_ps(v) _mm_shuffle_ps((v),(v),SHUFFLE_PARAM(2,2,2,2))
#define _mm_replicate_w_ps(v) _mm_shuffle_ps((v),(v),SHUFFLE_PARAM(3,3,3,3))
#define _mm_madd_ps(a, b, c) _mm_add_ps(_mm_mul_ps((a), (b)), (c))

	class CMatrix
	{
	public:
		CMatrix() noexcept;

	public:
		void Set(const CVector3& ptOrigin, const CVector3& vtX, const CVector3& vtY, const CVector3& vtZ) noexcept;
		void SetIdentity() noexcept;

		bool Invert(CMatrix& dest) const noexcept;
		void Transpose(CMatrix& dest) const noexcept;

	public:
		static const CMatrix& Multiplication(CMatrix* pMtxAtoC, const CMatrix& mtxAtoB, const CMatrix& mtxBtoC) noexcept;
		static const CVector3& Multiplication(CVector3* pVtOut, const CVector3& vt, const CMatrix& mtx) noexcept;
		static const CVector4& Multiplication(CVector4* pVtOut, const CVector4& vt, const CMatrix& mtx) noexcept;

	public:
		float m1[4];
		float m2[4];
		float m3[4];
		float m4[4];
	};

	inline CMatrix::CMatrix() noexcept
	{
	}

	inline void CMatrix::Set(const CVector3& ptOrigin, const CVector3& vtX, const CVector3& vtY, const CVector3& vtZ) noexcept
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

	inline void CMatrix::SetIdentity() noexcept
	{
		m1[1] = m1[2] = m1[3] = m2[0] = m2[2] = m2[3] = m3[0] = m3[1] = m3[3] = m4[0] = m4[1] = m4[2] = 0.0f;
		m1[0] = m2[1] = m3[2] = m4[3] = 1.0f;
	}

	inline bool CMatrix::Invert(CMatrix& dest) const noexcept
	{
		float inv[16]{};

		inv[0] = m2[1] * m3[2] * m4[3] - m2[1] * m3[3] * m4[2] - m3[1] * m2[2] * m4[3] +
			m3[1] * m2[3] * m4[2] + m4[1] * m2[2] * m3[3] - m4[1] * m2[3] * m3[2];

		inv[4] = -m2[0] * m3[2] * m4[3] + m2[0] * m3[3] * m4[2] + m3[0] * m2[2] * m4[3] -
			m3[0] * m2[3] * m4[2] - m4[0] * m2[2] * m3[3] + m4[0] * m2[3] * m3[2];

		inv[8] = m2[0] * m3[1] * m4[3] - m2[0] * m3[3] * m4[1] - m3[0] * m2[1] * m4[3] +
			m3[0] * m2[3] * m4[1] + m4[0] * m2[1] * m3[3] - m4[0] * m2[3] * m3[1];

		inv[12] = -m2[0] * m3[1] * m4[2] + m2[0] * m3[2] * m4[1] + m3[0] * m2[1] * m4[2] -
			m3[0] * m2[2] * m4[1] - m4[0] * m2[1] * m3[2] + m4[0] * m2[2] * m3[1];

		inv[1] = -m1[1] * m3[2] * m4[3] + m1[1] * m3[3] * m4[2] + m3[1] * m1[2] * m4[3] -
			m3[1] * m1[3] * m4[2] - m4[1] * m1[2] * m3[3] + m4[1] * m1[3] * m3[2];

		inv[5] = m1[0] * m3[2] * m4[3] - m1[0] * m3[3] * m4[2] - m3[0] * m1[2] * m4[3] +
			m3[0] * m1[3] * m4[2] + m4[0] * m1[2] * m3[3] - m4[0] * m1[3] * m3[2];

		inv[9] = -m1[0] * m3[1] * m4[3] + m1[0] * m3[3] * m4[1] + m3[0] * m1[1] * m4[3] -
			m3[0] * m1[3] * m4[1] - m4[0] * m1[1] * m3[3] + m4[0] * m1[3] * m3[1];

		inv[13] = m1[0] * m3[1] * m4[2] - m1[0] * m3[2] * m4[1] - m3[0] * m1[1] * m4[2] +
			m3[0] * m1[2] * m4[1] + m4[0] * m1[1] * m3[2] - m4[0] * m1[2] * m3[1];

		inv[2] = m1[1] * m2[2] * m4[3] - m1[1] * m2[3] * m4[2] - m2[1] * m1[2] * m4[3] +
			m2[1] * m1[3] * m4[2] + m4[1] * m1[2] * m2[3] - m4[1] * m1[3] * m2[2];

		inv[6] = -m1[0] * m2[2] * m4[3] + m1[0] * m2[3] * m4[2] + m2[0] * m1[2] * m4[3] -
			m2[0] * m1[3] * m4[2] - m4[0] * m1[2] * m2[3] + m4[0] * m1[3] * m2[2];

		inv[10] = m1[0] * m2[1] * m4[3] - m1[0] * m2[3] * m4[1] - m2[0] * m1[1] * m4[3] +
			m2[0] * m1[3] * m4[1] + m4[0] * m1[1] * m2[3] - m4[0] * m1[3] * m2[1];

		inv[14] = -m1[0] * m2[1] * m4[2] + m1[0] * m2[2] * m4[1] + m2[0] * m1[1] * m4[2] -
			m2[0] * m1[2] * m4[1] - m4[0] * m1[1] * m2[2] + m4[0] * m1[2] * m2[1];

		inv[3] = -m1[1] * m2[2] * m3[3] + m1[1] * m2[3] * m3[2] + m2[1] * m1[2] * m3[3] -
			m2[1] * m1[3] * m3[2] - m3[1] * m1[2] * m2[3] + m3[1] * m1[3] * m2[2];

		inv[7] = m1[0] * m2[2] * m3[3] - m1[0] * m2[3] * m3[2] - m2[0] * m1[2] * m3[3] +
			m2[0] * m1[3] * m3[2] + m3[0] * m1[2] * m2[3] - m3[0] * m1[3] * m2[2];

		inv[11] = -m1[0] * m2[1] * m3[3] + m1[0] * m2[3] * m3[1] + m2[0] * m1[1] * m3[3] -
			m2[0] * m1[3] * m3[1] - m3[0] * m1[1] * m2[3] + m3[0] * m1[3] * m2[1];

		inv[15] = m1[0] * m2[1] * m3[2] - m1[0] * m2[2] * m3[1] - m2[0] * m1[1] * m3[2] +
			m2[0] * m1[2] * m3[1] + m3[0] * m1[1] * m2[2] - m3[0] * m1[2] * m2[1];

		float det = m1[0] * inv[0] + m1[1] * inv[4] + m1[2] * inv[8] + m1[3] * inv[12];
		if (det == 0)
			return false;

		det = 1.0f / det;

		dest.m1[0] = inv[0] * det; dest.m2[0] = inv[4] * det; dest.m3[0] = inv[8]  * det; dest.m4[0] = inv[12] * det;
		dest.m1[1] = inv[1] * det; dest.m2[1] = inv[5] * det; dest.m3[1] = inv[9]  * det; dest.m4[1] = inv[13] * det;
		dest.m1[2] = inv[2] * det; dest.m2[2] = inv[6] * det; dest.m3[2] = inv[10] * det; dest.m4[2] = inv[14] * det;
		dest.m1[3] = inv[3] * det; dest.m2[3] = inv[7] * det; dest.m3[3] = inv[11] * det; dest.m4[3] = inv[15] * det;

		return true;
	}

	inline void CMatrix::Transpose(CMatrix& dest) const noexcept
	{
		dest.m1[0] = m1[0]; dest.m2[0] = m1[1]; dest.m3[0] = m1[2]; dest.m4[0] = m1[3];
		dest.m1[1] = m2[0]; dest.m2[1] = m2[1]; dest.m3[1] = m2[2]; dest.m4[1] = m2[3];
		dest.m1[2] = m3[0]; dest.m2[2] = m3[1]; dest.m3[2] = m3[2]; dest.m4[2] = m3[3];
		dest.m1[3] = m4[0]; dest.m2[3] = m4[1]; dest.m3[3] = m4[2]; dest.m4[3] = m4[3];
	}

	inline const CMatrix& CMatrix::Multiplication(CMatrix* pMtxAtoC, const CMatrix& mtxAtoB, const CMatrix& mtxBtoC) noexcept
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

	inline const CVector3& CMatrix::Multiplication(CVector3* pVtOut, const CVector3& vt, const CMatrix& M) noexcept
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

	inline const CVector4& CMatrix::Multiplication(CVector4* pVtOut, const CVector4& vt, const CMatrix& M) noexcept
	{
		const __m128& vector = _mm_setr_ps(vt.m[0], vt.m[1], vt.m[2], vt.m[3]);

		const __m128& m_row_0 = _mm_loadu_ps(M.m1);
		const __m128& m_row_1 = _mm_loadu_ps(M.m2);
		const __m128& m_row_2 = _mm_loadu_ps(M.m3);
		const __m128& m_row_3 = _mm_loadu_ps(M.m4);

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

		__m128 out3 = _mm_mul_ps(_mm_replicate_x_ps(m_row_3), _mm_replicate_x_ps(vector));
		out3 = _mm_add_ps(out3, _mm_mul_ps(_mm_replicate_y_ps(m_row_3), _mm_replicate_y_ps(vector)));
		out3 = _mm_add_ps(out3, _mm_mul_ps(_mm_replicate_z_ps(m_row_3), _mm_replicate_z_ps(vector)));
		out3 = _mm_add_ps(out3, _mm_replicate_w_ps(m_row_3));

		_mm_store_ss(&pVtOut->m[0], out0);
		_mm_store_ss(&pVtOut->m[1], out1);
		_mm_store_ss(&pVtOut->m[2], out2);
		_mm_store_ss(&pVtOut->m[3], out3);

		return *pVtOut;
	}
}