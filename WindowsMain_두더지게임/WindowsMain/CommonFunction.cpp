#include "stdafx.h"
#include "CommonFunction.h"



namespace Collision
{

	bool PtInRect(CenterRect rect, POINT pt)
	{
		//rect안에 점이있는지? 없는지 판별

		/*
		*/
		if (rect.x - rect.width / 2 <= pt.x && pt.x <= rect.x + rect.width / 2  //가로 체크
			&& rect.y - rect.height / 2 <= pt.y && pt.y <= rect.y + rect.height / 2)	//세로체크
		{
			return true;
		}

		return false;
	}


	bool RectInRect(CenterRect rect1, CenterRect rect2)
	{
		POINT pt1 = { rect2.x - rect2.width / 2, rect2.y - rect2.height / 2 };
		POINT pt2 = { rect2.x + rect2.width / 2, rect2.y - rect2.height / 2 };
		POINT pt3 = { rect2.x - rect2.width / 2, rect2.y + rect2.height / 2 };
		POINT pt4 = { rect2.x + rect2.width / 2, rect2.y + rect2.height / 2 };

		if (PtInRect(rect1, pt1))
		{
			return true;
		}
		else if (PtInRect(rect1, pt2))
		{
			return true;
		}
		else if (PtInRect(rect1, pt3))
		{
			return true;
		}
		else if (PtInRect(rect1, pt4))
		{
			return true;
		}


		return false;
	}
}