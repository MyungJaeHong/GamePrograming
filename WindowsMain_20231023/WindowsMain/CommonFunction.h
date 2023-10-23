#pragma once
//===========================================
//    ## 자주 사용하는 함수 정의 ##
//		(직접 추가해서 사용함)
//===========================================

// 사각형 관련된 함수
namespace Rect
{
	//x, y를 기준으로  width height를 만든다.
	inline RECT MakeRect(int x, int y, int width, int height)
	{
		RECT rc;
		rc.left = x;
		rc.top = y;
		rc.right = x + width;
		rc.bottom = y + height;

		return rc;
	}

	//x, y를 센터라고 가정했을때  width height로 사각형을 만든다.
	inline CenterRect MakeCenterRect(float x, float y, float width, float height)
	{
		CenterRect rc;
		rc.x = x;
		rc.y = y;
		rc.width = width;
		rc.height = height;

		return rc;
	}
}

namespace Draw
{
	inline void Rect(HDC hdc, RECT rc)
	{
		Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
	}

	inline void Rect(HDC hdc, CenterRect rc)
	{
		Rectangle(hdc,
			static_cast<int>(rc.x - rc.width / 2),	//left
			static_cast<int>(rc.y - rc.height / 2),	//top
			static_cast<int>(rc.x + rc.width / 2),	//right
			static_cast<int>(rc.y + rc.height / 2)	//bottom
		);
	}

	inline void Circle(HDC hdc, RECT rc)
	{
		Ellipse(hdc, rc.left, rc.top, rc.right, rc.bottom);
	}

	inline void Circle(HDC hdc, CenterRect rc)
	{
		Ellipse(hdc,
			static_cast<int>(rc.x - rc.width / 2),	//left
			static_cast<int>(rc.y - rc.height / 2),	//top
			static_cast<int>(rc.x + rc.width / 2),	//right
			static_cast<int>(rc.y + rc.height / 2)	//bottom
		);
	}

	inline void Line(HDC hdc, Vector2 startPos, Vector2 endPos)
	{
		MoveToEx(hdc, static_cast<int>(startPos.x), static_cast<int>(startPos.y), (LPPOINT)NULL);
		LineTo(hdc, static_cast<int>(endPos.x), static_cast<int>(endPos.y));
	}

}

namespace Random
{
	//from ~ to까지 랜덤생성해주는 함수 (from 은 나올수도있음, to는 안나옴)
	inline int GetInt(int fromInclude, int toExclude)
	{
		return fromInclude + rand() % (toExclude - fromInclude);
	}

	//from ~ to까지 랜덤생성해주는 함수 (from 은 나올수도있음, to는 안나옴)
	inline float GetFloat(float fromInclude, float toExclude)
	{
		//0 ~ 1까지의 숫자
		float random = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
		//0 ~ 500 까지의 랜덤한 실수 숫자
		//random * 500
		return fromInclude + (random * (toExclude - fromInclude));
	}
}

namespace Collision
{
	bool PtInRect(CenterRect rect, POINT pt);
	bool RectInRect(CenterRect rect1, CenterRect rect2);
}