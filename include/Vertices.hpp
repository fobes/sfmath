#pragma once
#include "CVector3.hpp"

namespace sfm
{
	struct CVertexP
	{
		CVector3 m_pos;
	};

	struct CVertexPN
	{
		CVector3 m_pos;
		CVector3 m_nor;
	};
	
	struct CVertexPT
	{
		CVector3 m_pos;
		CVector2 m_tex;
	};

	struct CVertexPNT
	{
		CVector3 m_pos;
		CVector3 m_nor;
		CVector2 m_tex;
	};
}