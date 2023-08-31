#include "main.h"
#include "Dealer.h"

void Dealer::Initialize()
{
	_sumCardNum = 0;
	_aceCardCount = 0;
}

void Dealer::Release()
{
	_sumCardNum = 0;
	_aceCardCount = 0;
}

void Dealer::ReceiveCard(Card receiveCard)
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

int Dealer::GetCardCount()
{
	return _card.size();
}

void Dealer::PrintCard(int index)
{
	_card[index].PrintCard();
}

int Dealer::GetSumCardNum()
{
	return _sumCardNum;
}

int Dealer::GetAceCardCount()
{
	return _aceCardCount;
}

void Dealer::ReleaseCard()
{
	int size = _card.size();
	for (int i = 0; i < size; i++)
	{
		_card.pop_back();
	}
	_sumCardNum = 0;
	_aceCardCount = 0;
}
