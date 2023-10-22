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
#include <unordered_set>


//gdiplus 관련
#include <gdiplus.h>				
#pragma comment(lib, "gdiplus.lib")	
//using namespace Gdiplus;


#include "Types.h"
#include "Enums.h"
#include "Defines.h"

//내가만든 Common 헤더 파일
#include "CommonStruct.h"
#include "CommonFunction.h"

//싱글톤 헤더파일
#include "KeyManager.h"
#include "TimeManager.h"
#include "SceneManager.h"
#include "CollisionManager.h"
#include "TargetingManager.h"

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

//===========================================
//    ## 전역 변수 ## 
//===========================================
//extern을 붙여야 다른 cpp파일에서도 사용가능하다.
extern HINSTANCE _hInstance;
extern HWND _hWnd;
extern POINT _mousePos;