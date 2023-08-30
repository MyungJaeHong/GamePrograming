#include "Player.h"

void Player::Initialize()
{
	_gold = 10000;
}

void Player::Release()
{
	_gold = 0;
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
