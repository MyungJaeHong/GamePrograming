#pragma once
#include "Card.h"
#include "Player.h"

enum eBetType { HIGH, LOW, SEVEN, END };

class MainGame
{
private:
	Player* _player;
	vector<Card> _card;
	int _betGold;
	int _betType;
	int _currentCardIndex;
public:
	void Initialize();
	void Release();
	void UpdateGame();
	bool IsGameEnd();
	void CardShuffle();
};

