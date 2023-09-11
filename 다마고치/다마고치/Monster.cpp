#include "stdafx.h"
#include "Monster.h"

void Monster::Initialize()
{
	_hp = 0;
	_maxHp = 0;
	_hunger = 0;
	_maxHunger = 0;
	_fatigue = 0;
	_maxFatigue = 0;
}

void Monster::Release()
{
	_hp = 0;
	_maxHp = 0;
	_hunger = 0;
	_maxHunger = 0;
	_fatigue = 0;
	_maxFatigue = 0;
	_monsterDot.clear();
	vector<string>().swap(_monsterDot);
}

void Monster::SettingMonsterInfo(int hp, int hunger, int fatigue)
{
	_hp = hp;
	_maxHp = hp;
	_hunger = hunger;
	_maxHunger = hunger;
	_fatigue = 0;
	_maxFatigue = fatigue;
}

void Monster::SettingMonsterDot(string str)
{
	_monsterDot.push_back(str);
}

void Monster::PrintMonster()
{
	int x = 4;
	int y = 2;
	for (int i = 0; i < _monsterDot.size(); i++)
	{
		CustomConsole.GotoXY(x, y++);
		cout << _monsterDot[i] << endl;
	}
}

void Monster::PrintStatus()
{
	int x = 65;
	int y = 2;
	CustomConsole.GotoXY(x, y++);
	cout << "     HP : ";
	cout.width(2);
	cout.fill(' ');
	cout << _hp;
	cout << "/" << _maxHp;
	CustomConsole.GotoXY(x, y++);
	cout << " HUNGER : ";
	cout.width(2);
	cout.fill(' ');
	cout << _hunger;
	cout << "/" << _maxHunger;
	CustomConsole.GotoXY(x, y++);
	cout << "FATIGUE : ";
	cout.width(2);
	cout.fill(' ');
	cout << _fatigue;
	cout << "/" << _maxFatigue;
}

void Monster::ReduceHunger()
{
	_hunger--;
	if (_hunger < 0)
	{
		_hunger = 0;
	}
}

void Monster::ReduceHp()
{
	_hp--;
	if (_hp < 0)
	{
		_hp = 0;
	}
}

void Monster::IncreaseHunger()
{
	_hunger++;
	if (_hunger > _maxHunger)
	{
		_hunger = _maxHunger;
	}
}

void Monster::IncreaseHp()
{
	_hp++;
	if (_hp > _maxHp)
	{
		_hp = _maxHp;
	}
}

int Monster::GetHunger()
{
	return _hunger;
}

int Monster::GetHp()
{
	return _hp;
}
