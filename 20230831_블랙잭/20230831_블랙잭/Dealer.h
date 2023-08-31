#pragma once
#include "Card.h"
class Dealer
{
private:
	vector<Card> _card;
	int _sumCardNum;
	int _aceCardCount;
public:
	void Initialize();
	void Release();
	void ReceiveCard(Card receiveCard);
	int GetCardCount();
	void PrintCard(int index);
	int GetSumCardNum();
	int GetAceCardCount();
	void ReleaseCard();
};

