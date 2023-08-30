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

	cout << "펼쳐진 카드 : ";
	for (int i = 4; i >= 1; i--)
	{
		_card[_currentCardIndex - i]->PrintCard();
		cout << "\t";
	}
	cout << "??" << endl;

	cout << "플레이어 현재 골드 : " << _player->GetPlayerGold() << endl;

	cout << "베팅타입을 정해주세요. (0:하이, 1:로우, 2:세븐) :" << endl;
	cin >> _betType;

	cout << "베팅 금액을 설정해주세요 : " << endl;
	cin >> _betGold;

	if (_player->GetPlayerGold() < _betGold)
	{
		_betGold = _player->GetPlayerGold();
	}

	//베팅한만큼 돈 차감
	_player->SubtractGold(_betGold);

	cout << "이번 카드 : ";
	_card[_currentCardIndex]->PrintCard();
	cout << endl;

	if (_card[_currentCardIndex]->GetCardNum() == 7 && _betType == eBetType::SEVEN)
	{
		cout << "### 축하합니다. ###" << endl;
		_player->PlusGold(_betGold * 10);
	}
	else if (_card[_currentCardIndex]->GetCardNum() < 7 && _betType == eBetType::LOW)
	{
		cout << "축하합니다." << endl;
		_player->PlusGold(_betGold * 2);
	}
	else if (7 < _card[_currentCardIndex]->GetCardNum() && _betType == eBetType::HIGH)
	{
		cout << "축하합니다." << endl;
		_player->PlusGold(_betGold * 2);
	}
	else
	{
		cout << "아쉽네요 ㅠㅠ" << endl;
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
