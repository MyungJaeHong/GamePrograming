#include "main.h"
#include "MainGame.h"
#include "Card.h"

void MainGame::Initialize()
{
	for (int i = 0; i < 52; i++)
	{
		_card[i] = new Card();
		_card[i]->Initialize(i);
		//_card.push_back({ (i / 13), (i % 13 + 1) });
	}
	_player = new Player();
	_player->Initialize();
	_betGold = 0;
	_betType = eBetType::END;
	_currentCardIndex = 4;
}

void MainGame::Release()
{
	delete[] _card;
	delete _player;
	_player = nullptr;
	_betGold = 0;
	_betType = eBetType::END;
	_currentCardIndex = 4;
}

void MainGame::UpdateGame()
{
	system("cls");

	cout << "������ ī�� : ";
	for (int i = 4; i >= 1; i--)
	{
		_card[_currentCardIndex - i]->PrintCard();
		cout << "\t";
	}
	cout << "??" << endl;

	cout << "�÷��̾� ���� ��� : " << _player->GetPlayerGold() << endl;

	cout << "����Ÿ���� �����ּ���. (0:����, 1:�ο�, 2:����) :" << endl;
	cin >> _betType;

	cout << "���� �ݾ��� �������ּ��� : " << endl;
	cin >> _betGold;

	if (_player->GetPlayerGold() < _betGold)
	{
		_betGold = _player->GetPlayerGold();
	}

	//�����Ѹ�ŭ �� ����
	_player->SubtractGold(_betGold);

	cout << "�̹� ī�� : ";
	_card[_currentCardIndex]->PrintCard();
	cout << endl;

	if (_card[_currentCardIndex]->GetCardNum() == 7 && _betType == eBetType::SEVEN)
	{
		cout << "### �����մϴ�. ###" << endl;
		_player->PlusGold(_betGold * 10);
	}
	else if (_card[_currentCardIndex]->GetCardNum() < 7 && _betType == eBetType::LOW)
	{
		cout << "�����մϴ�." << endl;
		_player->PlusGold(_betGold * 2);
	}
	else if (7 < _card[_currentCardIndex]->GetCardNum() && _betType == eBetType::HIGH)
	{
		cout << "�����մϴ�." << endl;
		_player->PlusGold(_betGold * 2);
	}
	else
	{
		cout << "�ƽ��׿� �Ф�" << endl;
	}
	_currentCardIndex++;

	system("pause");
}

bool MainGame::IsGameEnd()
{
	return _currentCardIndex == 52 || _player->GetPlayerGold() <= 0;
}

void MainGame::CardShuffle()
{
	for (int i = 0; i < 100000; i++)
	{
		int num1 = rand() % 52;
		int num2 = rand() % 52;
		Card tempCard = *_card[num1];
		*_card[num1] = *_card[num2];
		*_card[num2] = tempCard;
	}
}
