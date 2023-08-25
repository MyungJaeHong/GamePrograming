#include <iostream>
#include <time.h>
#include <Windows.h>
using namespace std;

enum eTurn { PLAYER, COMPUTER, NONE };

struct BingGoSpace {
	int _bingGoNum;
	bool _active;
};

struct BingGoBoard {
	BingGoSpace* _bingGo[25]{};

	void Init()
	{
		int num = 1;
		for (int i = 0; i < 25; i++)
		{
			_bingGo[i] = new BingGoSpace();
			_bingGo[i]->_bingGoNum = num;
			_bingGo[i]->_active = false;
			num++;
		}
	}

	void Release()
	{
		delete _bingGo;
	}

	void ShuffleBingGoBoard()
	{
		for (int i = 0; i < 100000; i++)
		{
			int temp;
			int num1 = rand() % 25;
			int num2 = rand() % 25;

			temp = _bingGo[num1]->_bingGoNum;
			_bingGo[num1]->_bingGoNum = _bingGo[num2]->_bingGoNum;
			_bingGo[num2]->_bingGoNum = temp;
		}
	}

	void PrintBingGoBoard()
	{
		for (int i = 0; i < 25; i++)
		{
			if (_bingGo[i]->_active)
			{
				cout << " #";
			}
			else
			{
				if (_bingGo[i]->_bingGoNum < 10)
				{
					cout << " ";
				}
				cout << _bingGo[i]->_bingGoNum;
			}
			if (i % 5 == 4)
			{
				cout << endl;
			}
			else
			{
				cout << "  ";
			}
		}
	}
};

struct Player {
	BingGoBoard* _bingGoBoard;

	void Init()
	{
		_bingGoBoard = new BingGoBoard;
		_bingGoBoard->Init();
	}

	void Release()
	{
		_bingGoBoard->Release();
		delete _bingGoBoard;
		_bingGoBoard = nullptr;
	}

	int InputNum()
	{
		int num;
		cout << "빙고 번호를 선택해주세요.";
		cin >> num;
		return num;
	}

	bool CheckBingo()
	{
		int bingGo;
		//가로빙고
		for (int i = 0; i < 5; i++)
		{
			bingGo = 0;
			for (int j = 0; j < 5; j++)
			{
				if (_bingGoBoard->_bingGo[(i * 5) + j]->_active == true)
				{
					bingGo++;
				}
				if (bingGo == 5)
				{
					return true;
				}
			}
		}

		//세로빙고
		for (int i = 0; i < 5; i++)
		{
			bingGo = 0;
			for (int j = 0; j < 5; j++)
			{
				if (_bingGoBoard->_bingGo[i + (j * 5)]->_active == true)
				{
					bingGo++;
				}
				if (bingGo == 5)
				{
					return true;
				}
			}
		}

		//대각선
		bingGo = 0;
		for (int i = 0; i < 25; i+=6)
		{
			if (_bingGoBoard->_bingGo[i]->_active == true)
			{
				bingGo++;
			}
			if (bingGo == 5)
			{
				return true;
			}
		}
		bingGo = 0;
		for (int i = 20; i > 3; i -= 4)
		{
			if (_bingGoBoard->_bingGo[i]->_active == true)
			{
				bingGo++;
			}
			if (bingGo == 5)
			{
				return true;
			}
		}
	}
};

struct Computer {
	BingGoBoard* _bingGoBoard;

	void Init()
	{
		_bingGoBoard = new BingGoBoard;
		_bingGoBoard->Init();
	}

	void Release()
	{
		_bingGoBoard->Release();
		delete _bingGoBoard;
		_bingGoBoard = nullptr;
	}

	int SelectNum()
	{
		int num = rand() % 25;
		return num;
	}

	bool CheckBingo()
	{
		int bingGo;
		//가로빙고
		for (int i = 0; i < 5; i++)
		{
			bingGo = 0;
			for (int j = 0; j < 5; j++)
			{
				if (_bingGoBoard->_bingGo[(i * 5) + j]->_active == true)
				{
					bingGo++;
				}
				if (bingGo == 5)
				{
					return true;
				}
			}
		}

		//세로빙고
		for (int i = 0; i < 5; i++)
		{
			bingGo = 0;
			for (int j = 0; j < 5; j++)
			{
				if (_bingGoBoard->_bingGo[i + (j * 5)]->_active == true)
				{
					bingGo++;
				}
				if (bingGo == 5)
				{
					return true;
				}
			}
		}

		//대각선
		bingGo = 0;
		for (int i = 0; i < 25; i += 6)
		{
			if (_bingGoBoard->_bingGo[i]->_active == true)
			{
				bingGo++;
			}
			if (bingGo == 5)
			{
				return true;
			}
		}
		bingGo = 0;
		for (int i = 20; i > 3; i -= 4)
		{
			if (_bingGoBoard->_bingGo[i]->_active == true)
			{
				bingGo++;
			}
			if (bingGo == 5)
			{
				return true;
			}
		}
	}
};

struct MainGame {
	Player* _player;
	Computer* _computer;
	eTurn _turn;
	bool _gamePlaying;
	int _selectNum;

	void Init()
	{
		_player = new Player();
		_computer = new Computer();
		_turn = PLAYER;
		_gamePlaying = true;
		_selectNum = 0;

		_player->Init();
		_computer->Init();
	}

	void Release()
	{
		_player->Release();
		delete _player;
		_player = nullptr;
		_computer->Release();
		delete _computer;
		_computer = nullptr;
	}

	void GameLoop()
	{
		cout << "[플레이어 빙고판]" << endl;
		_player->_bingGoBoard->PrintBingGoBoard();
		cout << endl;
		cout << "[컴퓨터 빙고판]" << endl;
		_computer->_bingGoBoard->PrintBingGoBoard();

		DecideBingoNum();

		ActiveBingGoNum();
		
		if (_computer->CheckBingo())
		{
			PrintComputerWin();
			_gamePlaying = false;
		}
		else if (_player->CheckBingo())
		{
			PrintPlayerWin();
			_gamePlaying = false;
		}

		ChangeTurn();

		system("cls");
	}

	void ChangeTurn()
	{
		switch (_turn)
		{
		case PLAYER:
			_turn = COMPUTER;
			break;
		case COMPUTER:
			_turn = PLAYER;
			break;
		default:
			_turn = NONE;
			break;
		}
	}

	void DecideBingoNum()
	{
		switch (_turn)
		{
		case PLAYER:
			_selectNum = _player->InputNum();
			break;
		case COMPUTER:
			_selectNum = _computer->SelectNum();
			break;
		default:
			break;
		}
		CheckDuplication();
	}

	void CheckDuplication()
	{
		for (int i = 0; i < 25; i++)
		{
			if (_player->_bingGoBoard->_bingGo[i]->_bingGoNum == _selectNum)
			{
				if (_player->_bingGoBoard->_bingGo[i]->_active)
				{
					DecideBingoNum();
				}
			}
		}
	}

	void ActiveBingGoNum()
	{
		cout << "선택 번호는 " << _selectNum << " 입니다!" << endl;
		for (int i = 0; i < 25; i++)
		{
			if (_player->_bingGoBoard->_bingGo[i]->_bingGoNum == _selectNum)
			{
				_player->_bingGoBoard->_bingGo[i]->_active = true;
			}
		}

		for (int i = 0; i < 25; i++)
		{
			if (_computer->_bingGoBoard->_bingGo[i]->_bingGoNum == _selectNum)
			{
				_computer->_bingGoBoard->_bingGo[i]->_active = true;
			}
		}
	}

	void PrintComputerWin()
	{
		cout << "컴퓨터가 1BingGo를 완성하여 승리했습니다!!!" << endl;
	}

	void PrintPlayerWin()
	{
		cout << "플레이어가 1BingGo를 완성하여 승리했습니다!!!" << endl;
	}
};

void main()
{
	srand(time(NULL));

	MainGame* _mainGame = new MainGame();
	
	_mainGame->Init();

	_mainGame->_player->_bingGoBoard->ShuffleBingGoBoard();
	_mainGame->_computer->_bingGoBoard->ShuffleBingGoBoard();

	while (_mainGame->_gamePlaying)
	{
		_mainGame->GameLoop();
	}
}