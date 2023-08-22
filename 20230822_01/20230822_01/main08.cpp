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

	// ��µ� ���� ��� �����
	// system("cls");
	// �Է��� ���������� ��ٸ���.
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
		cout << "�׸� ������ �������ּ���. (0: ��, 1: ����, 2: �׸�, 3: ��)";
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
			cout << "�׸� x ��ǥ�� �Է����ּ���.";
			cin >> point1.x;
			cout << "�׸� y ��ǥ�� �Է����ּ���.";
			cin >> point1.y;
			board[point1.y][point1.x*2] = 'p';
			board[point1.y][point1.x * 2 + 1] = 'p';
			break;
		case eDrawType::DRAWTYPE_LINE:
			int lineType;
			cout << "���� Ÿ���� �Է����ּ���. (0: ����, 1: ����)";
			cin >> lineType;
			switch (lineType)
			{
			case eLineType::HORIZON:
				cout << "�׸� y ��ǥ�� �Է����ּ���.";
				cin >> point1.y;
				for (int i = 0; i < 25; i++)
				{
					board[point1.y][i * 2] = 'l';
					board[point1.y][i * 2 + 1] = 'l';
				}
				break;
			case eLineType::VERTICAL:
				cout << "�׸� x ��ǥ�� �Է����ּ���.";
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
			cout << "�׸� x ��ǥ�� �Է����ּ���.";
			cin >> point1.x;
			cout << "�׸� y ��ǥ�� �Է����ּ���.";
			cin >> point1.y;
			cout << "�׸� x ��ǥ�� �Է����ּ���.";
			cin >> point2.x;
			cout << "�׸� y ��ǥ�� �Է����ּ���.";
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
			cout << "�׸� x ��ǥ�� �Է����ּ���.";
			cin >> point1.x;
			cout << "�׸� y ��ǥ�� �Է����ּ���.";
			cin >> point1.y;
			cout << "�������� �Է����ּ���. (x, y ���� ���� �� �Է�)";
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