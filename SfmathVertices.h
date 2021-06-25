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
	CSfmathVector3 m_pos;
};

//�������, �������
struct MATHS_API CSfmathVertexPN
{
	CSfmathVector3 m_pos;
	CSfmathVector3 m_nor;
};

//�������, �������, ��������
struct MATHS_API CSfmathVertexPNT
{
	CSfmathVector3 m_pos;
	CSfmathVector3 m_nor;
	float m_tex[2];
};

//�������, �������, ��������, ����(RGBA)
struct MATHS_API CSfmathVertexPNTC
{
	CSfmathVector3 m_pos;
	CSfmathVector3 m_nor;
	float m_tex[2];
	DWORD m_nColor;
};