#include "stdafx.h"
#include "UI.h"

void UI::Initialize()
{
	_uiX = 0;
	_uiY = 0;
	InitFrame();
}

void UI::Release()
{
	_uiX = 0;
	_uiY = 0;
}

void UI::InitFrame()
{
	PrintString(_uiX, _uiY++, "﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥");
	PrintString(_uiX, _uiY++, "﹥                                                                                ﹥");
	PrintString(_uiX, _uiY++, "﹥                                                                                ﹥");
	PrintString(_uiX, _uiY++, "﹥                                                                                ﹥");
	PrintString(_uiX, _uiY++, "﹥                                                                                ﹥");
	PrintString(_uiX, _uiY++, "﹥                                                                                ﹥");
	PrintString(_uiX, _uiY++, "﹥                                                                                ﹥");
	PrintString(_uiX, _uiY++, "﹥                                                                                ﹥");
	PrintString(_uiX, _uiY++, "﹥                                                                                ﹥");
	PrintString(_uiX, _uiY++, "﹥                                                                                ﹥");
	PrintString(_uiX, _uiY++, "﹥                                                                                ﹥");
	PrintString(_uiX, _uiY++, "﹥                                                                                ﹥");
	PrintString(_uiX, _uiY++, "﹥                                                                                ﹥");
	PrintString(_uiX, _uiY++, "﹥                                                                                ﹥");
	PrintString(_uiX, _uiY++, "﹥                                                                                ﹥");
	PrintString(_uiX, _uiY++, "﹥                                                                                ﹥");
	PrintString(_uiX, _uiY++, "﹥                                                                                ﹥");
	PrintString(_uiX, _uiY++, "﹥                                                                                ﹥");
	PrintString(_uiX, _uiY++, "﹥                                                                                ﹥");
	PrintString(_uiX, _uiY++, "﹥                                                                                ﹥");
	PrintString(_uiX, _uiY++, "﹥                                                                                ﹥");
	PrintString(_uiX, _uiY++, "﹥                                                                                ﹥");
	PrintString(_uiX, _uiY++, "﹥                                                                                ﹥");
	PrintString(_uiX, _uiY++, "﹥                                                                                ﹥");
	PrintString(_uiX, _uiY++, "﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥");

	_uiX = 2;
	_uiY = 18;

	PrintString(_uiX, _uiY++, "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
	PrintString(_uiX, _uiY++, "弛                                                                             弛");
	PrintString(_uiX, _uiY++, "弛                                                                             弛");
	PrintString(_uiX, _uiY++, "弛                                                                             弛");
	PrintString(_uiX, _uiY++, "弛                                                                             弛");
	PrintString(_uiX, _uiY++, "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");

	_uiX = 63;
	_uiY = 1;

	PrintString(_uiX, _uiY++, "忙式式式式式式式式式式式式式式式式忖");
	PrintString(_uiX, _uiY++, "弛                弛");
	PrintString(_uiX, _uiY++, "弛                弛");
	PrintString(_uiX, _uiY++, "弛                弛");
	PrintString(_uiX, _uiY++, "戌式式式式式式式式式式式式式式式式戎");
}
