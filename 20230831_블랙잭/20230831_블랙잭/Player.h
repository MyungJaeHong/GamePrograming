#pragma once
#include "Card.h"
class Player
{
private:
	int _gold;
	vector<Card> _card;
	int _sumCardNum;
	int _aceCardCount;
public:
	void Initialize();
	void Release();
	int GetPlayerGold();
	void SubtractGold(int subtractGold);
	void PlusGold(int plusGold);
	void ReceiveCard(Card receiveCard);
	int GetCardCount();
	void PrintCard(int index);
	int GetSumCardNum();
	int GetAceCardCount();
	void ReleaseCard();
};