#pragma once
#include "Card.h"
#include "Player.h"
#include "Dealer.h"

enum eHitStand { HITSTAND_HIT, HITSTAND_STAND, HITSTAND_END };
enum eGameStage { GAMESTAGE_BETTINGSTAGE, GAMESTAGE_PLAYINGSTAGE, GAMESTAGE_CARDRESET, GAMESTAGE_END };

class MainGame
{
private:
	Player* _player;
	Dealer* _dealer;
	int _gameStage;
	vector<Card> _card;
	int _hitStand;
	int _betGold;
	int _currentCardIndex;
public:
	void Initialize();
	void Release();
	void UpdateGame();
	bool IsGameEnd();
	int GetGameStage();
	void ChangeGameStage();
	void ShuffleCard();
	void InitDrawCard();
	Card DrawCard();
	void BetGold();
	void ShowCardSituation(bool onDealerCard);
	int CalculateFinalSum(int sumCardNum, int aceCardCount);
	void PrintResult();
	void ResetCard();
};