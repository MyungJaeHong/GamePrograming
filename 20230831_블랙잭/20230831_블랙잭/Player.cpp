#include "main.h"
#include "Player.h"

void Player::Initialize()
{
	_gold = 10000;
	_sumCardNum = 0;
	_aceCardCount = 0;
}

void Player::Release()
{
	_gold = 0;
	_sumCardNum = 0;
	_aceCardCount = 0;
}

int Player::GetPlayerGold()
{
	return _gold;
}

void Player::SubtractGold(int subtractGold)
{
	_gold -= subtractGold;
}

void Player::PlusGold(int plusGold)
{
	_gold += plusGold;
}

void Player::ReceiveCard(Card receiveCard)
{
	_card.push_back(receiveCard);
	
	if (receiveCard.GetCardNum() == 1)
	{
		_sumCardNum += 11;
		_aceCardCount++;
	}
	else if (10 < receiveCard.GetCardNum())
	{
		_sumCardNum += 10;
	}
	else
	{
		_sumCardNum += receiveCard.GetCardNum();
	}
}

int Player::GetCardCount()
{
	return _card.size();
}

void Player::PrintCard(int index)
{
	_card[index].PrintCard();
}

int Player::GetSumCardNum()
{
	return _sumCardNum;
}

int Player::GetAceCardCount()
{
	return _aceCardCount;
}

void Player::ReleaseCard()
{
	int size = _card.size();
	for (int i = 0; i < size; i++)
	{
		_card.pop_back();
	}
	_sumCardNum = 0;
	_aceCardCount = 0;
}
