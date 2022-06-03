#pragma once
#include "CVector3.hpp"

namespace sfm
{
	class CVector4
	{
	public:
		CVector4() noexcept;
		CVector4(const CVector4& other) noexcept;
		CVector4(const CVector3& vt, float fW) noexcept;
		CVector4(float fX, float fY, float fZ, float fW) noexcept;
		CVector4(const float* pArr) noexcept;

		operator const float* () const noexcept;

		const CVector4& operator+=(const CVector4& other) noexcept;
		const CVector4& operator-=(const CVector4& other) noexcept;

		CVector4 operator+(const CVector4& vtOther) const noexcept;
		CVector4 operator-(const CVector4& vtOther) const noexcept;

		CVector4 operator*(float k) const noexcept;
		CVector4 operator/(float k) const noexcept;

		CVector4 operator-() const noexcept;

	public:
		CVector4 Normalize() const noexcept;

		float Square() const noexcept;
		float Length() const noexcept;

	public:
		float m[4];
	};

	inline CVector4::CVector4() noexcept
	{

	}

	inline CVector4::CVector4(const CVector4& other) noexcept
		:m{ other.m[0], other.m[1], other.m[2], other.m[3] }
	{

	}

	inline CVector4::CVector4(const CVector3& other, float fW) noexcept
		:m{ other.m[0], other.m[1], other.m[2], fW }
	{

	}

	inline CVector4::CVector4(float fX, float fY, float fZ, float fW) noexcept
		: m{ fX, fY , fZ, fW }
	{

	}

	inline CVector4::CVector4(const float* pArr) noexcept
	{
		m[0] = pArr[0];
		m[1] = pArr[1];
		m[2] = pArr[2];
		m[3] = pArr[3];
	}

	inline CVector4::operator const float* () const noexcept
	{
		return &m[0];
	}

	inline const CVector4& CVector4::operator+=(const CVector4& other) noexcept
	{
		m[0] += other.m[0];
		m[1] += other.m[1];
		m[2] += other.m[2];
		m[3] += other.m[3];

		return *this;
	}

	inline const CVector4& CVector4::operator-=(const CVector4& other) noexcept
	{
		m[0] -= other.m[0];
		m[1] -= other.m[1];
		m[2] -= other.m[2];
		m[3] -= other.m[3];

		return *this;
	}

	inline CVector4 CVector4::operator+(const CVector4& vtOther) const noexcept
	{
		return CVector4(m[0] + vtOther.m[0], m[1] + vtOther.m[1], m[2] + vtOther.m[2], m[3] + vtOther.m[3]);
	}

	inline CVector4 CVector4::operator-(const CVector4& vtOther) const noexcept
	{
		return CVector4(m[0] - vtOther.m[0], m[1] - vtOther.m[1], m[2] - vtOther.m[2], m[3] - vtOther.m[3]);
	}

	inline CVector4 CVector4::operator*(float k) const noexcept
	{
		return CVector4(m[0] * k, m[1] * k, m[2] * k, m[3] * k);
	}

	inline CVector4 CVector4::operator/(float k) const noexcept
	{
		return *this * (1.0f / k);
	}

	inline CVector4 CVector4::operator-() const noexcept
	{
		return CVector4(-m[0], -m[1], -m[2], -m[3]);
	}

	inline CVector4 CVector4::Normalize() const noexcept
	{
		return *this / Length();
	}

	inline float CVector4::Square() const noexcept
	{
		return m[0] * m[0] + m[1] * m[1] + m[2] * m[2] + m[3] * m[3];
	}

	inline float CVector4::Length() const noexcept
	{
		return std::sqrt(Square());
	}
}
