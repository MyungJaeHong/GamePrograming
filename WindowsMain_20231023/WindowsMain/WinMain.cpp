//============================================
//		## 헤더파일 선언 ##
//============================================
#include "stdafx.h"
#include "Game.h"

//============================================
//		## 전역변수 선언 ##
//============================================
//전역변수 선언은 변수명 앞에 _ 를 붙여서 사용한다.
HINSTANCE _hInstance;
HWND _hWnd;
POINT _mousePos = {};



//============================================
//		## 함수 전방 선언 ##
//============================================
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
void SetWindowSize(int x, int y, int width, int height);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char* lpszCmdParam, int nCmdShow)
{
	//HINSTANCE hInstance : 프로그램 인스터스 핸들
	//HINSTANCE hPrevInstance : Preview 인스턴스 핸들 (이전에 실행된 인스턴스 핸들) (게임에서는 사용안함)
	//char* lpszCmdParam : 명령행으로 입력된 프로그램 인수 (게임에서는 사용안함)
	//int nCmdShow : 프로그램이 시작될 형태 (최소화, 보통크기) (게임에서는 사용안함)

	_hInstance = hInstance;
	//-------------------------------
	// ## 1. 윈도우 등록 ## 
	//-------------------------------
	//RegisterClass : 윈도우 등록해주는 함수
	//int RegisterClassA(WNDCLASSA * lpWndClass);
	//WNDCLASS : 윈도우 구조체 (윈도우를 구성해주기 위해 쓰일 변수들)
	WNDCLASS wndClass{};

	wndClass.cbClsExtra = 0;											//클래스 여분 메모리 (게임에선 사용안함)
	wndClass.cbWndExtra = 0;											//윈도우 여분 메모리 (게임에선 사용안함)
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		//백그라운드 색
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);						//커서
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);					//아이콘
	wndClass.hInstance = _hInstance;									//인스턴스 핸들
	wndClass.lpfnWndProc = (WNDPROC)WndProc;							//윈도우 프로시저
	wndClass.lpszClassName = WINNAME;									//클래스 이름
	wndClass.lpszMenuName = NULL;										//메뉴 이름
	wndClass.style = CS_HREDRAW | CS_VREDRAW;							//윈도우 스타일

	RegisterClass(&wndClass);


	//-------------------------------
	// ## 2. 윈도우 생성 ## 
	//-------------------------------
	/*HWND CreateWindow(LPCSTR lpClassName, LPCSTR lpWindowName, DWORD dwStyle, int X,  int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);*/
	_hWnd = CreateWindow(
		WINNAME							//lpClassName
		, WINNAME						//lpWindowsName
		, WS_CAPTION | WS_SYSMENU		//dwStyle
		, WIN_START_X					//x
		, WIN_START_Y					//y
		, WIN_SIZE_WIDTH				//width
		, WIN_SIZE_HEIGHT				//height
		, NULL							//부모 윈도우
		, NULL							//메뉴 핸들
		, _hInstance					//사용할 인스턴스 핸들
		, NULL							//부모가 나를생성했을때, 어떤 인자로 생성했는지
	);

	SetWindowSize(0, 0, WIN_SIZE_WIDTH, WIN_SIZE_HEIGHT);

	//-------------------------------
	// ## 3. 윈도우 출력 ## 
	//-------------------------------
	ShowWindow(_hWnd, nCmdShow);


	//-------------------------------
	// ## 4. 메세지 루프 ## 
	//-------------------------------
	Game game;
	MSG message;
	// 윈도우 프로시저 => 이벤트가 왔을때 어떻게 이벤트를 처리할지 결정해주는 내용
	// GetMessage  => 윈도우 이벤트가 왔을떄만 작동
	// PeekMessage => 윈도우 이벤트가 안와도 작동
	
	game.Init();

	while (true)
	{
		if (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		else
		{
			//게임로직 
			game.Render();
			game.Update();
		}
		
	}

	return 0;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_MOUSEMOVE:
	{
		//Windows API에서 값을 확인하고 싶을때
		//1번째 확인 방법 : 디버깅으로 확인
		//2번째 확인 방법 : 콘솔창을 띄워서 확인
		_mousePos.x = GET_X_LPARAM(lParam);
		_mousePos.y = GET_Y_LPARAM(lParam);

		break;
	}

	//윈도우 종료 메세지를 받을때 (정상종료)
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
}

void SetWindowSize(int x, int y, int width, int height)
{
	RECT rc;
	rc.left = 0;
	rc.top = 0;
	rc.right = width;
	rc.bottom = height;

	//실제 윈도우 크기 조정 (rc에 담아준다)
	AdjustWindowRect(&rc, WS_CAPTION | WS_SYSMENU, false);

	//rc를 기반으로 윈도우 사이즈 세팅
	SetWindowPos(_hWnd, NULL, x, y, rc.right - rc.left, rc.bottom - rc.top, SWP_NOZORDER | SWP_NOMOVE);
}