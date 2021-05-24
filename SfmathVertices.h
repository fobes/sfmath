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
	float m_pos[3];
};

//�������, �������
struct MATHS_API CSfmathVertexPN
{
	float m_pos[3];
	float m_nor[3];
};

//�������, �������, ��������
struct MATHS_API CSfmathVertexPNT
{
	float m_pos[3];
	float m_nor[3];
	float m_tex[2];
};

//�������, �������, ��������, ����(RGBA)
struct MATHS_API CSfmathVertexPNTC
{
	float m_pos[3];
	float m_nor[3];
	float m_tex[2];
	DWORD m_nColor;
};