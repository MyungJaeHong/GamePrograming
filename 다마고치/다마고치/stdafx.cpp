#include "stdafx.h"

#ifndef COMPLIED_CONSOLE
#define COMPLIED_CONSOLE

#include "TConsole.h"
tvision::TConsole tvision::TConsole::theInstance;

#endif

void PrintString(int x, int y, string str)
{
	CustomConsole.GotoXY(x, y);
	cout << str;
}
