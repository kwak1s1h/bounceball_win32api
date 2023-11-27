#pragma once
#include<assert.h>
class Vec2
{
public:
	Vec2();
	~Vec2();
	Vec2(float _x, float _y);
	Vec2(int _x, int _y);
	Vec2(POINT _pt);
	Vec2(const Vec2& _vec);
public:
	float Length() { return (float)(sqrt(pow(abs(x), 2) + pow(abs(y), 2))); }
	Vec2& Normalize()
	{
		float fLen = Length();
		// 0¿Ã∏È æ»µ≈.
		assert(fLen !=0.f);
		x /= fLen;
		y /= fLen;
		return *this;
	}
	Vec2 operator + (Vec2 _vOther)
	{
		return Vec2(x + _vOther.x, y + _vOther.y);
	}
	Vec2 operator - (Vec2 _vOther)
	{
		return Vec2(x - _vOther.x, y - _vOther.y);
	}
	Vec2 operator * (Vec2 _vOther)
	{
		return Vec2(x * _vOther.x, y * _vOther.y);
	}
	Vec2 operator / (Vec2 _vOther)
	{
		assert(!(0.f == _vOther.x || 0.f == _vOther.y));
		return Vec2(x / _vOther.x, y / _vOther.y);
	}
	Vec2 operator / (float _fOther)
	{
		assert(!(0.f == _fOther));
		return Vec2(x / _fOther, y / _fOther);
	}
	Vec2 operator * (float _i)
	{
		return Vec2(x * (float)_i, y * (float)_i);
	}
	Vec2& operator += (const Vec2& _vOther)
	{
		Vec2 result = *this;
		result.x = x + _vOther.x;
		result.y = y + _vOther.y;
		return result;
	}
public:
	float x;
	float y;
};

