#pragma once
class Player
{
private:
	int _gold;
public:
	void Initialize();
	void Release();
	int GetPlayerGold();
	void SubtractGold(int subtractGold);
	void PlusGold(int plusGold);
};

