#pragma once

using int8 = __int8;
using int16 = __int16;
using int32 = __int32;
using int64 = __int64;
using uint8 = unsigned __int8;
using uint16 = unsigned __int16;
using uint32 = unsigned __int32;
using uint64 = unsigned __int64;

struct Vector2
{
	float x, y;

	Vector2 operator-(const POINT pt) const
	{
		return Vector2{ static_cast<float>(x - pt.x),  static_cast<float>(y - pt.y)};
	}

	Vector2 operator-(const Vector2 other) const
	{
		return Vector2{ x - other.x, y - other.y };
	}

	Vector2 operator-=(const Vector2 other)
	{
		x -= other.x;
		y -= other.y;
	}

	Vector2 operator+(const Vector2 other) const
	{
		return Vector2{ x + other.x, y + other.y };
	}

	Vector2 operator+=(const Vector2 other)
	{
		x += other.x;
		y += other.y;
	}

	Vector2 operator*(const float other) const
	{
		return Vector2{ x * other, y * other };
	}

	Vector2 operator*=(const float other)
	{
		x *= other;
		y *= other;
	}

	Vector2 operator/(const float other) const
	{
		return Vector2{ x / other, y / other };
	}
	Vector2 operator/=(const float other)
	{
		x /= other;
		y /= other;
	}

	float LengthSquared()
	{
		return x * x + y * y;
	}

	float Length()
	{
		return ::sqrt(LengthSquared());
	}

	Vector2 Normalize()
	{
		float length = Length();
		if (length > EPSILON)
		{
			x /= length;
			y /= length;
		}

		return *this;
	}


	//내적으로는 주로 각도 계산할떄 많이쓰인다.
	//A Dot B = A.x * B.x + A.y * B.y
	//A Dot B = |A||B|cos(theta) 
	//  -> A B 둘다 길이가 1이면 cos(theta)가 나온다.
	//  -> cos(theta)는 두벡터가 이루는 각도를 나타낸다.
	//  -> 즉 두벡터가 이루는 각도를 구할때 내적을 사용한다.
	//  Tip1. 
	//   -  cos 그래프는
	//   -  0도 일때 1, 90도 일때 0, 180도 일때 -1 이다.
	//  Tip2. 
	//   - 내적으로 180가 넘는 각도는 존재할 수 없다.
	//  Tip3.
	//   - other 벡터가 내 뒤에 있는지 확인하려면
	//   - 내적이 0보다 작으면 내 뒤에 있다. (90도가 넘어갔음)

	float Dot(Vector2 other)
	{
		return x * other.x + y * other.y;
	}

	// 2D는 외적을 할 수 없다.
	// 외적은 두 Vector 의 수직 Vector를 구할때 사용한다.


	//벡터의 반사
	// 1. 법선벡터와 내적을 구한다.
	// 2. 내적을 구한값에 2를 곱한다.
	// 3. 2에서 구한값을 원래 벡터에서 뺀다.

	/*
	Original Vector
		  ^
		  |
		  /
		 /
		/      Normal
	   /      /
	  +------->
	  \
	   \
		\
		 \  Reflected Vector
		  \
		   V

	*/

	Vector2 Reflect(Vector2 normal)
	{
		normal.Normalize();
		Vector2 original = *this;
		original.Normalize();

		return original - normal * 2 * this->Dot(normal);
	}

	float SignedAngle(Vector2 other) const
	{
		other.Normalize();
		Vector2 original = *this;
		original.Normalize();

		float dotValue = original.Dot(other);
		if (abs(dotValue - 1.0f) < EPSILON)
		{
			return 0;
		}

		float angle = ::acos(dotValue);
		float sign = original.x * other.y - original.y * other.x;

		if (sign < 0)
		{
			angle = -angle;
		}
		return angle;
	}

	static Vector2 Zero()
	{
		return Vector2{ 0, 0 };
	}

	static Vector2 Up()
	{
		return Vector2{ 0, -1 };
	}

	static Vector2 Down()
	{
		return Vector2{ 0, 1 };
	}

	static Vector2 Right()
	{
		return Vector2{ 1, 0 };
	}

	static Vector2 Left()
	{
		return Vector2{ -1, 0 };
	}

	Vector2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
	Vector2()
	{
		this->x = 0;
		this->y = 0;
	}
};