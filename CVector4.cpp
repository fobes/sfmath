#include "stdafx.h"
#include "CVector4.h"

inline CVector4 operator *(const CVector4& V, float k)
{
	return CVector4(V.m_fX * k, V.m_fY * k, V.m_fZ * k, V.m_fW * k);
}
