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


	//�������δ� �ַ� ���� ����ҋ� ���̾��δ�.
	//A Dot B = A.x * B.x + A.y * B.y
	//A Dot B = |A||B|cos(theta) 
	//  -> A B �Ѵ� ���̰� 1�̸� cos(theta)�� ���´�.
	//  -> cos(theta)�� �κ��Ͱ� �̷�� ������ ��Ÿ����.
	//  -> �� �κ��Ͱ� �̷�� ������ ���Ҷ� ������ ����Ѵ�.
	//  Tip1. 
	//   -  cos �׷�����
	//   -  0�� �϶� 1, 90�� �϶� 0, 180�� �϶� -1 �̴�.
	//  Tip2. 
	//   - �������� 180�� �Ѵ� ������ ������ �� ����.
	//  Tip3.
	//   - other ���Ͱ� �� �ڿ� �ִ��� Ȯ���Ϸ���
	//   - ������ 0���� ������ �� �ڿ� �ִ�. (90���� �Ѿ��)

	float Dot(Vector2 other)
	{
		return x * other.x + y * other.y;
	}

	// 2D�� ������ �� �� ����.
	// ������ �� Vector �� ���� Vector�� ���Ҷ� ����Ѵ�.


	//������ �ݻ�
	// 1. �������Ϳ� ������ ���Ѵ�.
	// 2. ������ ���Ѱ��� 2�� ���Ѵ�.
	// 3. 2���� ���Ѱ��� ���� ���Ϳ��� ����.

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