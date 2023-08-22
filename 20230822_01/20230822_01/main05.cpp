#include <iostream>
#include <time.h>

using namespace std;

void CreateAnswer(int answer[]);
void InputNum(int playerNum[]);
int CountBall(int answer[], int playerNum[]);
int CountStrike(int answer[], int playerNum[]);
void PrintResult(int ball, int strike, bool* gamePlaying);

void main()
{
	srand(time(NULL));
	int answer[4]{};

	CreateAnswer(answer);

	bool gamePlaying = 1;

	for (int i = 0; i < 4; i++)
	{
		cout << answer[i];
	}
	cout << endl;

	while (gamePlaying)
	{
		int playerNum[4];
		InputNum(playerNum);

		int ball;
		int strike;

		ball = CountBall(answer, playerNum);
		strike = CountStrike(answer, playerNum);

		PrintResult(ball, strike, &gamePlaying);
		cout << endl;
	}
}

void CreateAnswer(int answer[])
{
	do
	{
		for (int i = 0; i < 4; i++)
		{
			answer[i] = rand() % 10;
		}
	} while (answer[0] == answer[1] || answer[0] == answer[2] || answer[0] == answer[3] || answer[1] == answer[2] || answer[1] == answer[3] || answer[2] == answer[3]);
}

void InputNum(int playerNum[])
{
	int num = 0;
	cout << "숫자를 입력해주세요." << endl;
	cin >> num;

	playerNum[0] = num / 1000;
	playerNum[1] = (num % 1000) / 100;
	playerNum[2] = (num % 100) / 10;
	playerNum[3] = num % 10;
}

int CountBall(int answer[], int playerNum[])
{
	int ball = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i != j)
			{
				if (answer[i] == playerNum[j])
				{
					ball++;
				}
			}
		}
	}

	return ball;
}

int CountStrike(int answer[], int playerNum[])
{
	int strike = 0;
	for (int i = 0; i < 4; i++)
	{
		if (answer[i] == playerNum[i])
		{
			strike++;
		}
	}

	return strike;
}

void PrintResult(int ball, int strike, bool* gamePlaying)
{
	if (ball == 0 && strike == 0)
	{
		cout << "결과는 OUT! 입니다" << endl;
	}
	else if (strike == 4)
	{
		cout << "정답입니다!!" << endl;
		*gamePlaying = 0;
	}
	else
	{
		cout << "결과는 " << ball << "B" << strike << "S" << " 입니다." << endl;
	}
}