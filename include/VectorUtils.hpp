#pragma once
#include "CVector3.hpp"

namespace sfm
{
	class CVectorUtils
	{
	public:
		static CVector3 Lerp(const CVector3& vtA, const CVector3& vtB, float t) noexcept;
		static CVector3 SLerp(const CVector3& vtA, const CVector3& vtB, float t) noexcept;
		static CVector3 OrthoGramSсhmidt(const CVector3& vtA, const CVector3& vtB) noexcept;
	};
	
	inline CVector3 CVectorUtils::Lerp(const sfm::CVector3& vtA, const sfm::CVector3& vtB, float t) noexcept
	{
		CVector3 vtRes;

		if (t <= 0.0f)
		{
			vtRes = vtA;
		}
		else
		{
			if (t >= 1.0f)
			{
				vtRes = vtB;
			}
			else
			{
				vtRes = vtA + (vtB - vtA) * t;
			}
		}

		return vtRes;
	}
	inline CVector3 CVectorUtils::SLerp(const CVector3& vtA, const CVector3& vtB, float t) noexcept
	{
		float omega, cos, sinom, scale0, scale1;

		CVector3 vtRes;
		CVector3 vtAn = vtA.Normalize();
		CVector3 vtBn = vtB.Normalize();

		if (t <= 0.0f)
		{
			vtRes = vtAn;
		}
		else
		{
			if (t >= 1.0f)
			{
				vtRes = vtBn;
			}
			else
			{
				cos = vtAn.DotProduct(vtBn);
				if (cos < 0.0f)
					cos = -cos;

				if ((1.0f - cos) > 0.999f)
				{
					omega = acosf(cos);
					sinom = 1.0f / sinf(omega);
					scale0 = sinf((1.0f - t) * omega) * sinom;
					scale1 = sinf(t * omega) * sinom;
				}
				else
				{
					scale0 = 1.0f - t;
					scale1 = t;
				}

				vtRes = vtAn * scale0 + vtBn * scale1;
			}
		}

		return vtRes;
	}
	inline CVector3 CVectorUtils::OrthoGramSсhmidt(const CVector3& vtA, const CVector3& vtB) noexcept
	{
		CVector3 vtAn = vtA.Normalize();
		CVector3 vtBn = vtB.Normalize();

		float dot = vtBn.DotProduct(vtAn);

		CVector3 vtTmp(dot * vtAn.m[0], dot * vtAn.m[1], dot * vtAn.m[2]);
		CVector3 vtRes = vtBn - vtTmp;

		return vtRes.Normalize();
	}
}