#pragma once
#include <minwindef.h>

#ifdef EXPORT_API
#define MATHS_API __declspec(dllexport)
#else
#define MATHS_API __declspec(dllimport)
#endif

//Позиция
struct MATHS_API CVertexP
{
	float m_fX, m_fY, m_fZ;
};

//Позиция, нормаль
struct MATHS_API CVertexPN
{
	float m_fX, m_fY, m_fZ;
	float m_fNX, m_fNY, m_fNZ;
};

//Позиция, нормаль, текстура
struct MATHS_API CVertexPNT
{
	float m_fX, m_fY, m_fZ;
	float m_fNX, m_fNY, m_fNZ;
	float m_fU, m_fV;
};

//Позиция, нормаль, текстура, цвет(RGBA)
struct MATHS_API CVertexPNTC
{
	float m_fX, m_fY, m_fZ;
	float m_fNX, m_fNY, m_fNZ;
	float m_fU, m_fV;
	DWORD m_nColor;
};