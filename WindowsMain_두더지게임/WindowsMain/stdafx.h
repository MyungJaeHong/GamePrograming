#pragma once
// 자주 사용하지만, 자주변경되지 않는 내용들이 포함되는 헤더
// 프레임워크 내용들은 이 헤더파일에 정의할 것.

//===========================================
//    ## 헤더 파일 정의 ##
//===========================================

#include <Windows.h>
#include <windowsx.h>

//C++ 관련 함수
#include <iostream>
#include <algorithm>
//WinMain으로 시작할때, 서브시스템으로 Console을 띄우겠다.
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console") 

//STL 헤더
#include <string>
#include <vector>
#include <format>

//내가만든 Common 헤더 파일
#include "CommonStruct.h"
#include "CommonFunction.h"

//싱글톤 헤더파일
#include "KeyManager.h"

//===========================================
//    ## 네임스페이스 ##
//===========================================
using namespace std;

//===========================================
//    ## Define 정의 ##
//===========================================
#define WINNAME "SBS_ACADEMY"
#define WIN_START_X 0
#define WIN_START_Y 0
#define WIN_SIZE_WIDTH 800
#define WIN_SIZE_HEIGHT 800
#define WIN_STYLE (WS_CAPTION | WS_SYSMENU)

#define SAFE_DELETE(p) {if((p)) delete (p); (p) = NULL;}
#define SAFE_DELETE_ARRAY(p) {if((p)) delete[] (p); (p) = NULL;}

#define MOLE_TIMER0 3000
#define MOLE_TIMER1 3001
#define MOLE_TIMER2 3002
#define MOLE_TIMER3 3003
#define MOLE_TIMER4 3004
#define MOLE_TIMER5 3005
#define MOLE_TIMER6 3006
#define MOLE_TIMER7 3007
#define MOLE_TIMER8 3008

#define MOLE_BOARD0 VK_NUMPAD7
#define MOLE_BOARD1 VK_NUMPAD8
#define MOLE_BOARD2 VK_NUMPAD9
#define MOLE_BOARD3 VK_NUMPAD4
#define MOLE_BOARD4 VK_NUMPAD5
#define MOLE_BOARD5 VK_NUMPAD6
#define MOLE_BOARD6 VK_NUMPAD1
#define MOLE_BOARD7 VK_NUMPAD2
#define MOLE_BOARD8 VK_NUMPAD3

//===========================================
//    ## 전역 변수 ## 
//===========================================
//extern을 붙여야 다른 cpp파일에서도 사용가능하다.
extern HINSTANCE _hInstance;
extern HWND _hWnd;
extern POINT _mousePos;