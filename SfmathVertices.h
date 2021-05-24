#pragma once
#include <minwindef.h>

#ifdef EXPORT_API
#define MATHS_API __declspec(dllexport)
#else
#define MATHS_API __declspec(dllimport)
#endif

//Позиция
struct MATHS_API CSfmathVertexP
{
	float m_pos[3];
};

//Позиция, нормаль
struct MATHS_API CSfmathVertexPN
{
	float m_pos[3];
	float m_nor[3];
};

//Позиция, нормаль, текстура
struct MATHS_API CSfmathVertexPNT
{
	float m_pos[3];
	float m_nor[3];
	float m_tex[2];
};

//Позиция, нормаль, текстура, цвет(RGBA)
struct MATHS_API CSfmathVertexPNTC
{
	float m_pos[3];
	float m_nor[3];
	float m_tex[2];
	DWORD m_nColor;
};