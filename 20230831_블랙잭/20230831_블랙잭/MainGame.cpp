#include "main.h"
#include "MainGame.h"
#include "Card.h"

void MainGame::Initialize()
{
	for (int i = 0; i < 52; i++)
	{
		_card.emplace_back();
		_card[i].Initialize(i);
	}
	_player = new Player();
	_player->Initialize();
	_dealer = new Dealer();
	_dealer->Initialize();
	_gameStage = eGameStage::GAMESTAGE_BETTINGSTAGE;
	_hitStand = eHitStand::HITSTAND_END;
	_betGold = 0;
	_currentCardIndex = 0;
}

void MainGame::Release()
{
	delete _player;
	_player = nullptr;
	delete _dealer;
	_dealer = nullptr;
	_gameStage = eGameStage::GAMESTAGE_END;
	_hitStand = eHitStand::HITSTAND_END;
	_betGold = 0;
	_currentCardIndex = 0;
}

void MainGame::UpdateGame()
{
	system("cls");

	ShowCardSituation(false);

	cout << "��Ʈ �Ǵ� ���ĵ带 ����ּ���. (0: ��Ʈ, 1: ���ĵ�) :" << endl;
	cin >> _hitStand;

	switch (_hitStand)
	{
	case eHitStand::HITSTAND_HIT:
		_player->ReceiveCard(DrawCard());
		if (21 < CalculateFinalSum(_player->GetSumCardNum(), _player->GetAceCardCount()))
		{
			system("cls");
			ShowCardSituation(false);
			cout << "�÷��̾� ����Ʈ!! �й��ϼ̽��ϴ�!" << endl;
			system("pause");
			ChangeGameStage();
		}
		break;
	case eHitStand::HITSTAND_STAND:
		while (_dealer->GetSumCardNum() < 17 )
		{
			_dealer->ReceiveCard(DrawCard());
		}
		system("cls");
		ShowCardSituation(true);
		if (21 < CalculateFinalSum(_dealer->GetSumCardNum(), _dealer->GetAceCardCount()))
		{
			cout << "���� ����Ʈ!! �¸��ϼ̽��ϴ�!" << endl;
			system("pause");
			ChangeGameStage();
		}
		else
		{
			PrintResult();
			ChangeGameStage();
		}
		break;
	default:
		break;
	}
}

bool MainGame::IsGameEnd()
{
	return _currentCardIndex == 52 || _player->GetPlayerGold() <= 0;
}

int MainGame::GetGameStage()
{
	return _gameStage;
}

void MainGame::ChangeGameStage()
{
	switch (_gameStage)
	{
	case eGameStage::GAMESTAGE_BETTINGSTAGE:
		_gameStage = eGameStage::GAMESTAGE_PLAYINGSTAGE;
		break;
	case eGameStage::GAMESTAGE_PLAYINGSTAGE:
		_gameStage = eGameStage::GAMESTAGE_CARDRESET;
		break;
	case eGameStage::GAMESTAGE_CARDRESET:
		_gameStage = eGameStage::GAMESTAGE_BETTINGSTAGE;
		break;
	default:
		break;
	}
}

void MainGame::ShuffleCard()
{
	for (int i = 0; i < 100000; i++)
	{
		int num1 = rand() % 52;
		int num2 = rand() % 52;
		Card tempCard = _card[num1];
		_card[num1] = _card[num2];
		_card[num2] = tempCard;
	}
}

void MainGame::InitDrawCard()
{
	_player->ReceiveCard(DrawCard());
	_player->ReceiveCard(DrawCard());
	_dealer->ReceiveCard(DrawCard());
	_dealer->ReceiveCard(DrawCard());
}

Card MainGame::DrawCard()
{
	return _card[_currentCardIndex++];
}

void MainGame::BetGold()
{
	system("cls");
	cout << "�÷��̾� ���� ��� : " << _player->GetPlayerGold() << endl;

	cout << "���� �ݾ��� �������ּ��� : " << endl;
	cin >> _betGold;

	if (_player->GetPlayerGold() < _betGold)
	{
		_betGold = _player->GetPlayerGold();
	}
	//�����Ѹ�ŭ �� ����
	_player->SubtractGold(_betGold);
	ChangeGameStage();
}

void MainGame::ShowCardSituation(bool onDealerCard)
{
	cout << "[������ ī��]" << endl;
	for (int i = 0; i < _dealer->GetCardCount() - 1; i++)
	{
		_dealer->PrintCard(i);
		cout << "\t";
	}
	if (onDealerCard)
	{
		_dealer->PrintCard(_dealer->GetCardCount() - 1);
		cout << endl;
	}
	else
	{
		cout << "??" << endl;;
	}

	cout << "[�÷��̾��� ī��]" << endl;
	for (int i = 0; i < _player->GetCardCount(); i++)
	{
		_player->PrintCard(i);
		cout << "\t";
	}
	cout << endl;;
}

int MainGame::CalculateFinalSum(int sumCardNum, int aceCardCount)
{
	if (21 < sumCardNum)
	{
		if (0 < aceCardCount)
		{
			while (aceCardCount != 0 || 21 < sumCardNum)
			{
				sumCardNum -= 10;
				aceCardCount--;
			}
		}
	}

	return sumCardNum;
}

void MainGame::PrintResult()
{
	cout << "[���� ����]" << endl;
	cout << CalculateFinalSum(_dealer->GetSumCardNum(), _dealer->GetAceCardCount()) << endl;
	cout << "[�÷��̾� ����]" << endl;
	cout << CalculateFinalSum(_player->GetSumCardNum(), _player->GetAceCardCount()) << endl;
	if (CalculateFinalSum(_dealer->GetSumCardNum(), _dealer->GetAceCardCount()) < CalculateFinalSum(_player->GetSumCardNum(), _player->GetAceCardCount()))
	{
		cout << "�¸��ϼ̽��ϴ�!!" << endl;
		_player->PlusGold(_betGold * 2);
	}
	else if (CalculateFinalSum(_player->GetSumCardNum(), _player->GetAceCardCount()) < CalculateFinalSum(_dealer->GetSumCardNum(), _dealer->GetAceCardCount()))
	{
		cout << "�й��ϼ̽��ϴ�!!" << endl;
	}
	else
	{
		cout << "���º��Դϴ�!!" << endl;
	}
	system("pause");
}

void MainGame::ResetCard()
{
	_player->ReleaseCard();
	_dealer->ReleaseCard();
	for (int i = 0; i < 52; i++)
	{
		_card[i].Initialize(i);
	}
	ShuffleCard();
	InitDrawCard();
	ChangeGameStage();
	_currentCardIndex = 0;
}
