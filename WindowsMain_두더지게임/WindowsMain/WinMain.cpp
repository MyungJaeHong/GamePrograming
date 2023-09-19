//============================================
//		## 헤더파일 선언 ##
//============================================
#include "stdafx.h"

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

	//-------------------------------
	// ## 3. 윈도우 출력 ## 
	//-------------------------------
	ShowWindow(_hWnd, nCmdShow);

	//-------------------------------
	// ## 4. 메세지 루프 ## 
	//-------------------------------
	MSG message;
	while (GetMessage(&message, nullptr, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return 0;
}

int _score = 0;
bool _active[9]{};

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
	{
		srand(time(NULL));
		//화면 다시 그리기 타이머
		SetTimer(hWnd,             // handle to main window 
			0,						// timer identifier 
			1000 / 60,                 // 1초에 60번
			(TIMERPROC)NULL);     // no timer callback 

		//랜덤 두더지 생성 타이머
		SetTimer(hWnd,             // handle to main window 
			1,						// timer identifier 
			500,                 // 0.5초
			(TIMERPROC)NULL);     // no timer callback 
		
		break;
	}
	case WM_TIMER:
	{
		switch (wParam)
		{
			//UPDATE
		case 0:

			//화면 다시그리기 (WM_PAINT 이벤트를 보낸다.)
			RECT rc;
			GetClientRect(_hWnd, &rc);
			InvalidateRect(_hWnd, &rc, true);
			return 0;

		case 1:
		{
			//만약 랜덤값 1~100이 71보다 작으면
			if (Random::GetInt(1, 100) < 71)
			{
				//0~8의 랜덤수 저장
				int num = Random::GetInt(0, 8);
				//_active 배열의 랜덤수 인덱스가 0이면 1로 변경 후 타이머 설정
				if (_active[num] == 0)
				{
					_active[num] = 1;
					SetTimer(hWnd,             // handle to main window 
						3000 + num,						// timer identifier 
						3000,                 // 1초에 60번
						(TIMERPROC)NULL);     // no timer callback 
				}
			}
			break;
		}
		//_active 배열이 1로 변경될 때 시작된 타이머가 들어오면 배열값 0으로 변경 후 타이머 종료
		case MOLE_TIMER0:
			_active[0] = 0;
			KillTimer(hWnd, 3000);
			break;
		case MOLE_TIMER1:
			_active[1] = 0;
			KillTimer(hWnd, 3001);
			break;
		case MOLE_TIMER2:
			_active[2] = 0;
			KillTimer(hWnd, 3002);
			break;
		case MOLE_TIMER3:
			_active[3] = 0;
			KillTimer(hWnd, 3003);
			break;
		case MOLE_TIMER4:
			_active[4] = 0;
			KillTimer(hWnd, 3004);
			break;
		case MOLE_TIMER5:
			_active[5] = 0;
			KillTimer(hWnd, 3005);
			break;
		case MOLE_TIMER6:
			_active[6] = 0;
			KillTimer(hWnd, 3006);
			break;
		case MOLE_TIMER7:
			_active[7] = 0;
			KillTimer(hWnd, 3007);
			break;
		case MOLE_TIMER8:
			_active[8] = 0;
			KillTimer(hWnd, 3008);
			break;
		}
		break;
	}

	case WM_KEYDOWN:
	{
		//키가 눌렸을때 숫자패드가 눌렸으면
		//해당 위치의 인덱스 값으로 _active 배열이 1이면 값을 0으로 변경 및 킬타이머 호출, 스코어 +1
		switch (wParam)
		{
		case MOLE_BOARD0:
			if (_active[0] == 1)
			{
				_active[0] = 0;
				KillTimer(hWnd, 3000);
				_score++;
			}
			break;
		case MOLE_BOARD1:
			if (_active[1] == 1)
			{
				_active[1] = 0;
				KillTimer(hWnd, 3001);
				_score++;
			}
			break;
		case MOLE_BOARD2:
			if (_active[2] == 1)
			{
				_active[2] = 0;
				KillTimer(hWnd, 3002);
				_score++;
			}
			break;
		case MOLE_BOARD3:
			if (_active[3] == 1)
			{
				_active[3] = 0;
				KillTimer(hWnd, 3003);
				_score++;
			}
			break;
		case MOLE_BOARD4:
			if (_active[4] == 1)
			{
				_active[4] = 0;
				KillTimer(hWnd, 3004);
				_score++;
			}
			break;
		case MOLE_BOARD5:
			if (_active[5] == 1)
			{
				_active[5] = 0;
				KillTimer(hWnd, 3005);
				_score++;
			}
			break;
		case MOLE_BOARD6:
			if (_active[6] == 1)
			{
				_active[6] = 0;
				KillTimer(hWnd, 3006);
				_score++;
			}
			break;
		case MOLE_BOARD7:
			if (_active[7] == 1)
			{
				_active[7] = 0;
				KillTimer(hWnd, 3007);
				_score++;
			}
			break;
		case MOLE_BOARD8:
			if (_active[8] == 1)
			{
				_active[8] = 0;
				KillTimer(hWnd, 3008);
				_score++;
			}
			break;
		default:
			break;
		}
		break;
	}


		//화면을 그릴때
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		//스코어 전광판 출력
		string str = "현재 점수 : " + to_string(_score);
		TextOutA(hdc, 600, 50, str.c_str(), str.size());

		//스코어 20 달성시 게임 종료 안내 출력 및 게임 종료 호출
		if (_score == 20)
		{
			str = "축하합니다! 20점을 달성하셨습니다. 5초 뒤 게임이 종료됩니다!";
			TextOutA(hdc, 200, 200, str.c_str(), str.size());
			Sleep(5000);
			SendMessage(_hWnd, WM_CLOSE, 0, 0);
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				//네모(두더지 판) 출력
				Draw::Rect(hdc, Rect::MakeCenterRect(150 + (j * 240), 200 + (i * 200), 150, 150));
				//원(두더지)은 _active 배열의 인덱스 값이 1일때만 출력
				if (_active[j + (i * 3)] == 1)
				{
					Draw::Circle(hdc, Rect::MakeCenterRect(150 + (j * 240), 200 + (i * 200), 100, 100));
					cout << "원을 그린다" << endl;
				}
			}
		}

		EndPaint(hWnd, &ps);
		break;
	}

	// 마우스 왼쪽버튼을 눌렀을때.
	case WM_LBUTTONDOWN:
	{


		break;
	}

	// 마우스 오른쪽 버튼을 눌렀을때
	case WM_RBUTTONDOWN:
	{
		break;
	}

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