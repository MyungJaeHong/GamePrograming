#include <iostream>
#include <Windows.h>

using namespace std;

enum eDrawType { DRAWTYPE_POINT, DRAWTYPE_LINE, DRAWTYPE_SQUARE, DRAWTYPE_CIRCLE};
enum eLineType { HORIZON, VERTICAL };

struct Point {
	int x;
	int y;
};

void main()
{
	char board[25][50] = {};

	// 출력된 내용 모두 지우기
	// system("cls");
	// 입력을 받을때까지 기다린다.
	// system("pause");

	while (true)
	{
		system("cls");
		for (int i = 0; i < 25; i++)
		{
			for (int j = 0; j < 50; j++)
			{
				cout << board[i][j];
			}
			cout << endl;
		}
		for (int i = 0; i < 25; i++)
		{
			for (int j = 0; j < 50; j++)
			{
				board[i][j] = ' ';
			}
		}
		cout << "그릴 유형을 선택해주세요. (0: 점, 1: 라인, 2: 네모, 3: 원)";
		int drawType = 0;
		cin >> drawType;

		Point point1;
		Point point2;
		int ray;
		int printX1;
		int printX2;
		int printY1;
		int printY2;
		switch (drawType)
		{
		case eDrawType::DRAWTYPE_POINT:
			cout << "그릴 x 좌표를 입력해주세요.";
			cin >> point1.x;
			cout << "그릴 y 좌표를 입력해주세요.";
			cin >> point1.y;
			board[point1.y][point1.x*2] = 'p';
			board[point1.y][point1.x * 2 + 1] = 'p';
			break;
		case eDrawType::DRAWTYPE_LINE:
			int lineType;
			cout << "라인 타입을 입력해주세요. (0: 가로, 1: 세로)";
			cin >> lineType;
			switch (lineType)
			{
			case eLineType::HORIZON:
				cout << "그릴 y 좌표를 입력해주세요.";
				cin >> point1.y;
				for (int i = 0; i < 25; i++)
				{
					board[point1.y][i * 2] = 'l';
					board[point1.y][i * 2 + 1] = 'l';
				}
				break;
			case eLineType::VERTICAL:
				cout << "그릴 x 좌표를 입력해주세요.";
				cin >> point1.x;
				for (int i = 0; i < 25; i++)
				{
					board[i][point1.x * 2] = 'l';
					board[i][point1.x * 2 + 1] = 'l';
				}
				break;
			default:
				break;
			}
			break;
		case eDrawType::DRAWTYPE_SQUARE:
			cout << "그릴 x 좌표를 입력해주세요.";
			cin >> point1.x;
			cout << "그릴 y 좌표를 입력해주세요.";
			cin >> point1.y;
			cout << "그릴 x 좌표를 입력해주세요.";
			cin >> point2.x;
			cout << "그릴 y 좌표를 입력해주세요.";
			cin >> point2.y;
			for (int i = point1.x; i <= point2.x; i++)
			{
				board[point1.y][i * 2] = 's';
				board[point1.y][i * 2 + 1] = 's';
				board[point2.y][i * 2] = 's';
				board[point2.y][i * 2 + 1] = 's';
			}
			for (int i = point1.y; i <= point2.y; i++)
			{
				board[i][point1.x * 2] = 's';
				board[i][point1.x * 2 + 1] = 's';
				board[i][point2.x * 2] = 's';
				board[i][point2.x * 2 + 1] = 's';
			}
			break;
		case eDrawType::DRAWTYPE_CIRCLE:
			cout << "그릴 x 좌표를 입력해주세요.";
			cin >> point1.x;
			cout << "그릴 y 좌표를 입력해주세요.";
			cin >> point1.y;
			cout << "반지름을 입력해주세요. (x, y 보다 작은 값 입력)";
			cin >> ray;

			printX1 = point1.x - ray;
			printX2 = point1.x + ray;
			printY1 = point1.y;
			printY2 = point1.y;

			for (int i = 0; i <= ray; i++)
			{
				board[printY1][(printX1 * 2)] = 'c';
				board[printY2][(printX1 * 2)] = 'c';
				board[printY1][(printX2 * 2)] = 'c';
				board[printY2][(printX2 * 2)] = 'c';
				printX1++;
				printX2--;
				printY1--;
				printY2++;
			}
			break;
		default:
			break;
		}

		system("pause");
	}
}