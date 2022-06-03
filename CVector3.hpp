#pragma once
#include "CVector2.hpp"

namespace sfm
{
	class CVector3
	{
	public:
		CVector3() noexcept;
		CVector3(const CVector3& other) noexcept;
		CVector3(const CVector2& other, float fZ) noexcept;
		CVector3(float fX, float fY, float fZ) noexcept;
		CVector3(const float* pArr) noexcept;

		operator const float* () const noexcept;

		const CVector3& operator+=(const CVector3& other) noexcept;
		const CVector3& operator-=(const CVector3& other) noexcept;

		CVector3 operator+(const CVector3& vtOther) const noexcept;
		CVector3 operator-(const CVector3& vtOther) const noexcept;

		CVector3 operator*(float k) const noexcept;
		CVector3 operator/(float k) const noexcept;

		CVector3 operator-() const noexcept;

	public:
		CVector3 Normalize() const noexcept;

		float Square() const noexcept;
		float Length() const noexcept;

	public:
		CVector3 CrossProduct(const CVector3& vtOther) const noexcept;
		float DotProduct(const CVector3& vtOther) const noexcept;

	public:
		float m[3];
	};

	inline CVector3::CVector3() noexcept
	{

	}

	inline CVector3::CVector3(const CVector3& other) noexcept
		:m{ other.m[0], other.m[1], other.m[2] }
	{

	}

	inline CVector3::CVector3(const CVector2& other, float fZ) noexcept
		:m{ other.m[0], other.m[1], fZ }
	{

	}

	inline CVector3::CVector3(float fX, float fY, float fZ) noexcept
		: m{ fX, fY , fZ }
	{

	}

	inline CVector3::CVector3(const float* pArr) noexcept
	{
		m[0] = pArr[0];
		m[1] = pArr[1];
		m[2] = pArr[2];
	}

	inline CVector3::operator const float* () const noexcept
	{
		return &m[0];
	}

	inline const CVector3& CVector3::operator+=(const CVector3& other) noexcept
	{
		m[0] += other.m[0];
		m[1] += other.m[1];
		m[2] += other.m[2];

		return *this;
	}

	inline const CVector3& CVector3::operator-=(const CVector3& other) noexcept
	{
		m[0] -= other.m[0];
		m[1] -= other.m[1];
		m[2] -= other.m[2];

		return *this;
	}

	inline CVector3 CVector3::operator+(const CVector3& vtOther) const noexcept
	{
		return CVector3(m[0] + vtOther.m[0], m[1] + vtOther.m[1], m[2] + vtOther.m[2]);
	}

	inline CVector3 CVector3::operator-(const CVector3& vtOther) const noexcept
	{
		return CVector3(m[0] - vtOther.m[0], m[1] - vtOther.m[1], m[2] - vtOther.m[2]);
	}

	inline CVector3 CVector3::operator*(float k) const noexcept
	{
		return CVector3(m[0] * k, m[1] * k, m[2] * k);
	}

	inline CVector3 CVector3::operator/(float k) const noexcept
	{
		return *this * (1.0f / k);
	}

	inline CVector3 CVector3::operator-() const noexcept
	{
		return CVector3(-m[0], -m[1], -m[2]);
	}

	inline CVector3 CVector3::Normalize() const noexcept
	{
		return *this / Length();
	}

	inline float CVector3::Square() const noexcept
	{
		return m[0] * m[0] + m[1] * m[1] + m[2] * m[2];
	}

	inline float CVector3::Length() const noexcept
	{
		return std::sqrt(Square());
	}

	inline CVector3 CVector3::CrossProduct(const CVector3& vtOther) const noexcept
	{
		return CVector3(
			m[1] * vtOther.m[2] - m[2] * vtOther.m[1],
			m[2] * vtOther.m[0] - m[0] * vtOther.m[2],
			m[0] * vtOther.m[1] - m[1] * vtOther.m[0]
		);
	}

	inline float CVector3::DotProduct(const CVector3& vtOther) const noexcept
	{
		return m[0] * vtOther.m[0] + m[1] * vtOther.m[1] + m[2] * vtOther.m[2];
	}
}