#pragma once
#include "Monster.h"
#include "UI.h"

enum eEvolutionLevel { TAMAGOTCHI, BABYLEVEL, TRAININGLEVEL, ROOKIELEVEL, CHAMPIONLEVEL, ULTIMATELEVEL, SUPERULTIMATELEVEL };

class MainGame
{
private:
	int _checkTime;
	int _gameMinutes;
	int _gameSeconds;
	int _evolutionLevel;
	int _hungerStack;
	vector<Monster*> _monster;
	vector<Monster*> _monsterPreset;
	vector<UI*> _ui;
public:
	void Initialize();
	void Release();

	void SettingMonsterPreset();
	bool IsGamePlaying();
	void RunningGame();
	void PrintMonster();
	void CalculationPlayTime();
	void PrintPlayTime();
	void ReduceHunger();
	void EvolutionCheck();
};

