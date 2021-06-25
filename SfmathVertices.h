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
	CSfmathVector3 m_pos;
};

//Позиция, нормаль
struct MATHS_API CSfmathVertexPN
{
	CSfmathVector3 m_pos;
	CSfmathVector3 m_nor;
};

//Позиция, нормаль, текстура
struct MATHS_API CSfmathVertexPNT
{
	CSfmathVector3 m_pos;
	CSfmathVector3 m_nor;
	float m_tex[2];
};

//Позиция, нормаль, текстура, цвет(RGBA)
struct MATHS_API CSfmathVertexPNTC
{
	CSfmathVector3 m_pos;
	CSfmathVector3 m_nor;
	float m_tex[2];
	DWORD m_nColor;
};