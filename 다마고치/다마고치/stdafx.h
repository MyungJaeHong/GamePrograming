#pragma once

#include <iostream>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <string>
#include <vector>

using namespace std;

#include "TConsole.h"
#define CustomConsole tvision::TConsole::GetConsole()

void PrintString(int x, int y, string str);