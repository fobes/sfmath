#pragma once
#include <cmath>

namespace sfm
{
	class CVector2
	{
	public:
		CVector2() noexcept;
		CVector2(const CVector2& other) noexcept;
		CVector2(float fX, float fY) noexcept;
		CVector2(const float* pArr) noexcept;

		operator const float* () const noexcept;

		const CVector2& operator+=(const CVector2& other) noexcept;
		const CVector2& operator-=(const CVector2& other) noexcept;

		CVector2 operator+(const CVector2& vtOther) const noexcept;
		CVector2 operator-(const CVector2& vtOther) const noexcept;

		CVector2 operator*(float k) const noexcept;
		CVector2 operator/(float k) const noexcept;

		CVector2 operator-() const noexcept;

	public:
		CVector2 Normalize() const noexcept;

		float Square() const noexcept;
		float Length() const noexcept;

	public:
		float m[2];
	};

	inline CVector2::CVector2() noexcept
	{

	}

	inline CVector2::CVector2(const CVector2& other) noexcept
		:m{ other.m[0], other.m[1] }
	{

	}

	inline CVector2::CVector2(float fX, float fY) noexcept
		: m{ fX, fY }
	{

	}

	inline CVector2::CVector2(const float* pArr) noexcept
	{
		m[0] = pArr[0];
		m[1] = pArr[1];
	}

	inline CVector2::operator const float* () const noexcept
	{
		return &m[0];
	}

	inline const CVector2& CVector2::operator+=(const CVector2& other) noexcept
	{
		m[0] += other.m[0];
		m[1] += other.m[1];

		return *this;
	}

	inline const CVector2& CVector2::operator-=(const CVector2& other) noexcept
	{
		m[0] -= other.m[0];
		m[1] -= other.m[1];

		return *this;
	}

	inline CVector2 CVector2::operator+(const CVector2& vtOther) const noexcept
	{
		return CVector2(m[0] + vtOther.m[0], m[1] + vtOther.m[1]);
	}

	inline CVector2 CVector2::operator-(const CVector2& vtOther) const noexcept
	{
		return CVector2(m[0] - vtOther.m[0], m[1] - vtOther.m[1]);
	}

	inline CVector2 CVector2::operator*(float k) const noexcept
	{
		return CVector2(m[0] * k, m[1] * k);
	}

	inline CVector2 CVector2::operator/(float k) const noexcept
	{
		return (*this) * (1.0f / k);
	}

	inline CVector2 CVector2::operator-() const noexcept
	{
		return CVector2(-m[0], -m[1]);
	}

	inline CVector2 CVector2::Normalize() const noexcept
	{
		return (*this) / Length();
	}

	inline float CVector2::Square() const noexcept
	{
		return m[0] * m[0] + m[1] * m[1];
	}

	inline float CVector2::Length() const noexcept
	{
		return std::sqrt(Square());
	}
}