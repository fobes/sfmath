#pragma once
#include <minwindef.h>

#ifdef EXPORT_API
#define MATHS_API __declspec(dllexport)
#else
#define MATHS_API __declspec(dllimport)
#endif

//�������
struct MATHS_API CSfmathVertexP
{
	float m_fX, m_fY, m_fZ;
};

//�������, �������
struct MATHS_API CSfmathVertexPN
{
	float m_fX, m_fY, m_fZ;
	float m_fNX, m_fNY, m_fNZ;
};

//�������, �������, ��������
struct MATHS_API CSfmathVertexPNT
{
	float m_fX, m_fY, m_fZ;
	float m_fNX, m_fNY, m_fNZ;
	float m_fU, m_fV;
};

//�������, �������, ��������, ����(RGBA)
struct MATHS_API CSfmathVertexPNTC
{
	float m_fX, m_fY, m_fZ;
	float m_fNX, m_fNY, m_fNZ;
	float m_fU, m_fV;
	DWORD m_nColor;
};