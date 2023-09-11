#pragma once

class Monster
{
private:
	int _hp;
	int _maxHp;
	int _hunger;
	int _maxHunger;
	int _fatigue;
	int _maxFatigue;
	vector<string> _monsterDot;
public:
	void Initialize();
	void Release();
	void SettingMonsterInfo(int hp, int hunger, int fatigue);
	void SettingMonsterDot(string str);
	void PrintMonster();
	void PrintStatus();
	void ReduceHunger();
	void ReduceHp();
	void IncreaseHunger();
	void IncreaseHp();
	int GetHunger();
	int GetHp();
};

