#pragma once
// ���� ���������, ���ֺ������ �ʴ� ������� ���ԵǴ� ���
// �����ӿ�ũ ������� �� ������Ͽ� ������ ��.

//===========================================
//    ## ��� ���� ���� ##
//===========================================

#include <Windows.h>
#include <windowsx.h>

//C++ ���� �Լ�
#include <iostream>
#include <algorithm>
//WinMain���� �����Ҷ�, ����ý������� Console�� ���ڴ�.
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console") 

//STL ���
#include <string>
#include <vector>
#include <format>

//�������� Common ��� ����
#include "CommonStruct.h"
#include "CommonFunction.h"

//�̱��� �������
#include "KeyManager.h"

//===========================================
//    ## ���ӽ����̽� ##
//===========================================
using namespace std;

//===========================================
//    ## Define ���� ##
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
//    ## ���� ���� ## 
//===========================================
//extern�� �ٿ��� �ٸ� cpp���Ͽ����� ��밡���ϴ�.
extern HINSTANCE _hInstance;
extern HWND _hWnd;
extern POINT _mousePos;