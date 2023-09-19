#include "stdafx.h"
#include "CommonStruct.h"
#include "CommonFunction.h"

RECT CenterRect::ToRect()
{
	RECT rc = Rect::MakeRect(x - width / 2, y - height / 2, width, height);

	return rc;
}

CenterRect CenterRect::FromRect(RECT rect)
{
	CenterRect centerRect = {};
	centerRect.x = (rect.left + rect.right) / 2;
		// rect.left + (rect.right - rect.left) / 2;
	centerRect.y = (rect.top + rect.bottom) / 2;
		// rect.top + (rect.bottom -rect.top) / 2;
	centerRect.width = rect.right - rect.left;
	centerRect.height = rect.bottom - rect.top;

	return centerRect;
}
