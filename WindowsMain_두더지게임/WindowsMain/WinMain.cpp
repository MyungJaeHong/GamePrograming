//============================================
//		## ������� ���� ##
//============================================
#include "stdafx.h"

//============================================
//		## �������� ���� ##
//============================================
//�������� ������ ������ �տ� _ �� �ٿ��� ����Ѵ�.
HINSTANCE _hInstance;
HWND _hWnd;
POINT _mousePos = {};

//============================================
//		## �Լ� ���� ���� ##
//============================================
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char* lpszCmdParam, int nCmdShow)
{
	//HINSTANCE hInstance : ���α׷� �ν��ͽ� �ڵ�
	//HINSTANCE hPrevInstance : Preview �ν��Ͻ� �ڵ� (������ ����� �ν��Ͻ� �ڵ�) (���ӿ����� ������)
	//char* lpszCmdParam : ��������� �Էµ� ���α׷� �μ� (���ӿ����� ������)
	//int nCmdShow : ���α׷��� ���۵� ���� (�ּ�ȭ, ����ũ��) (���ӿ����� ������)

	_hInstance = hInstance;
	//-------------------------------
	// ## 1. ������ ��� ## 
	//-------------------------------
	//RegisterClass : ������ ������ִ� �Լ�
	//int RegisterClassA(WNDCLASSA * lpWndClass);
	//WNDCLASS : ������ ����ü (�����츦 �������ֱ� ���� ���� ������)
	WNDCLASS wndClass{};

	wndClass.cbClsExtra = 0;											//Ŭ���� ���� �޸� (���ӿ��� ������)
	wndClass.cbWndExtra = 0;											//������ ���� �޸� (���ӿ��� ������)
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		//��׶��� ��
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);						//Ŀ��
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);					//������
	wndClass.hInstance = _hInstance;									//�ν��Ͻ� �ڵ�
	wndClass.lpfnWndProc = (WNDPROC)WndProc;							//������ ���ν���
	wndClass.lpszClassName = WINNAME;									//Ŭ���� �̸�
	wndClass.lpszMenuName = NULL;										//�޴� �̸�
	wndClass.style = CS_HREDRAW | CS_VREDRAW;							//������ ��Ÿ��

	RegisterClass(&wndClass);


	//-------------------------------
	// ## 2. ������ ���� ## 
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
		, NULL							//�θ� ������
		, NULL							//�޴� �ڵ�
		, _hInstance					//����� �ν��Ͻ� �ڵ�
		, NULL							//�θ� ��������������, � ���ڷ� �����ߴ���
	);

	//-------------------------------
	// ## 3. ������ ��� ## 
	//-------------------------------
	ShowWindow(_hWnd, nCmdShow);

	//-------------------------------
	// ## 4. �޼��� ���� ## 
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
		//ȭ�� �ٽ� �׸��� Ÿ�̸�
		SetTimer(hWnd,             // handle to main window 
			0,						// timer identifier 
			1000 / 60,                 // 1�ʿ� 60��
			(TIMERPROC)NULL);     // no timer callback 

		//���� �δ��� ���� Ÿ�̸�
		SetTimer(hWnd,             // handle to main window 
			1,						// timer identifier 
			500,                 // 0.5��
			(TIMERPROC)NULL);     // no timer callback 
		
		break;
	}
	case WM_TIMER:
	{
		switch (wParam)
		{
			//UPDATE
		case 0:

			//ȭ�� �ٽñ׸��� (WM_PAINT �̺�Ʈ�� ������.)
			RECT rc;
			GetClientRect(_hWnd, &rc);
			InvalidateRect(_hWnd, &rc, true);
			return 0;

		case 1:
		{
			//���� ������ 1~100�� 71���� ������
			if (Random::GetInt(1, 100) < 71)
			{
				//0~8�� ������ ����
				int num = Random::GetInt(0, 8);
				//_active �迭�� ������ �ε����� 0�̸� 1�� ���� �� Ÿ�̸� ����
				if (_active[num] == 0)
				{
					_active[num] = 1;
					SetTimer(hWnd,             // handle to main window 
						3000 + num,						// timer identifier 
						3000,                 // 1�ʿ� 60��
						(TIMERPROC)NULL);     // no timer callback 
				}
			}
			break;
		}
		//_active �迭�� 1�� ����� �� ���۵� Ÿ�̸Ӱ� ������ �迭�� 0���� ���� �� Ÿ�̸� ����
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
		//Ű�� �������� �����е尡 ��������
		//�ش� ��ġ�� �ε��� ������ _active �迭�� 1�̸� ���� 0���� ���� �� ųŸ�̸� ȣ��, ���ھ� +1
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


		//ȭ���� �׸���
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		//���ھ� ������ ���
		string str = "���� ���� : " + to_string(_score);
		TextOutA(hdc, 600, 50, str.c_str(), str.size());

		//���ھ� 20 �޼��� ���� ���� �ȳ� ��� �� ���� ���� ȣ��
		if (_score == 20)
		{
			str = "�����մϴ�! 20���� �޼��ϼ̽��ϴ�. 5�� �� ������ ����˴ϴ�!";
			TextOutA(hdc, 200, 200, str.c_str(), str.size());
			Sleep(5000);
			SendMessage(_hWnd, WM_CLOSE, 0, 0);
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				//�׸�(�δ��� ��) ���
				Draw::Rect(hdc, Rect::MakeCenterRect(150 + (j * 240), 200 + (i * 200), 150, 150));
				//��(�δ���)�� _active �迭�� �ε��� ���� 1�϶��� ���
				if (_active[j + (i * 3)] == 1)
				{
					Draw::Circle(hdc, Rect::MakeCenterRect(150 + (j * 240), 200 + (i * 200), 100, 100));
					cout << "���� �׸���" << endl;
				}
			}
		}

		EndPaint(hWnd, &ps);
		break;
	}

	// ���콺 ���ʹ�ư�� ��������.
	case WM_LBUTTONDOWN:
	{


		break;
	}

	// ���콺 ������ ��ư�� ��������
	case WM_RBUTTONDOWN:
	{
		break;
	}

	case WM_MOUSEMOVE:
	{
		//Windows API���� ���� Ȯ���ϰ� ������
		//1��° Ȯ�� ��� : ��������� Ȯ��
		//2��° Ȯ�� ��� : �ܼ�â�� ����� Ȯ��
		_mousePos.x = GET_X_LPARAM(lParam);
		_mousePos.y = GET_Y_LPARAM(lParam);

		break;
	}

	//������ ���� �޼����� ������ (��������)
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
}