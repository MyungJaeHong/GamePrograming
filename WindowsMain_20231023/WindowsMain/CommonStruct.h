#pragma once

struct CenterRect
{
	float x, y, width, height;

	RECT ToRect();
	Gdiplus::Rect ToGdiRect();

	static CenterRect FromRect(RECT rect);
};