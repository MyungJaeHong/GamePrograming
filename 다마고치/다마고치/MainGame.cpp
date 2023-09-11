#include "stdafx.h"
#include "MainGame.h"

void MainGame::Initialize()
{
	CustomConsole.SetTitle("다마고치");
	CustomConsole.SetTextColor(WHITE);
	CustomConsole.SetBkColor(BLACK);
	CustomConsole.SetCursor(tvision::CURSOR_OFF);
	CustomConsole.SetWindowSize(84, 25);
	CustomConsole.SetScreenFufferSize(84, 25);
	_checkTime = GetTickCount64();
	_gameMinutes = 0;
	_gameSeconds = 0;
	_hungerStack = 0;
	_evolutionLevel = eEvolutionLevel::TAMAGOTCHI;
	_monster.push_back(new Monster());
	_monsterPreset.push_back(new Monster());
	_monsterPreset.push_back(new Monster());
	_monsterPreset.push_back(new Monster());
	_monsterPreset.push_back(new Monster());
	_monsterPreset.push_back(new Monster());
	_monsterPreset.push_back(new Monster());
	_monsterPreset.push_back(new Monster());
	_monsterPreset.push_back(new Monster());
	_ui.push_back(new UI());
	_monster[0]->Initialize();
	for (int i = 0; i < _monsterPreset.size(); i++)
	{
		_monsterPreset[0]->Initialize();
	}
	_ui[0]->Initialize();
	SettingMonsterPreset();
	_monster[0] = _monsterPreset[0];
}

void MainGame::Release()
{
	_checkTime = 0;
	_gameMinutes = 0;
	_gameSeconds = 0;
	_monster[0]->Release();
	_monster.clear();
	vector<Monster*>().swap(_monster);
	for (int i = 0; i < _monsterPreset.size(); i++)
	{
		_monsterPreset[i]->Release();
	}
	_monsterPreset.clear();
	vector<Monster*>().swap(_monsterPreset);
	_ui[0]->Release();
	_ui.clear();
	vector<UI*>().swap(_ui);
}

void MainGame::SettingMonsterPreset()
{
	_monsterPreset[0]->SettingMonsterInfo(10, 10, 10);
	_monsterPreset[0]->SettingMonsterDot("                                ");
	_monsterPreset[0]->SettingMonsterDot("                                ");
	_monsterPreset[0]->SettingMonsterDot("                                ");
	_monsterPreset[0]->SettingMonsterDot("                                ");
	_monsterPreset[0]->SettingMonsterDot("              ■■■■■        ");
	_monsterPreset[0]->SettingMonsterDot("            ■■■      ■      ");
	_monsterPreset[0]->SettingMonsterDot("          ■■■■    ■■■    ");
	_monsterPreset[0]->SettingMonsterDot("        ■■■■      ■■■■  ");
	_monsterPreset[0]->SettingMonsterDot("        ■            ■■■■  ");
	_monsterPreset[0]->SettingMonsterDot("      ■    ■          ■■■■");
	_monsterPreset[0]->SettingMonsterDot("      ■    ■■          ■■■");
	_monsterPreset[0]->SettingMonsterDot("      ■    ■■■            ■");
	_monsterPreset[0]->SettingMonsterDot("      ■      ■■    ■■■  ■");
	_monsterPreset[0]->SettingMonsterDot("        ■■        ■■■■■  ");
	_monsterPreset[0]->SettingMonsterDot("          ■■      ■■■■    ");
	_monsterPreset[0]->SettingMonsterDot("            ■■■■■■■      ");

	_monsterPreset[1]->SettingMonsterInfo(20, 20, 20);
	_monsterPreset[1]->SettingMonsterDot("                                ");
	_monsterPreset[1]->SettingMonsterDot("                                ");
	_monsterPreset[1]->SettingMonsterDot("                                ");
	_monsterPreset[1]->SettingMonsterDot("                                ");
	_monsterPreset[1]->SettingMonsterDot("                                ");
	_monsterPreset[1]->SettingMonsterDot("                                ");
	_monsterPreset[1]->SettingMonsterDot("                                ");
	_monsterPreset[1]->SettingMonsterDot("                                ");
	_monsterPreset[1]->SettingMonsterDot("                                ");
	_monsterPreset[1]->SettingMonsterDot("                                ");
	_monsterPreset[1]->SettingMonsterDot("                    ■    ■    ");
	_monsterPreset[1]->SettingMonsterDot("                  ■■■■■■  ");
	_monsterPreset[1]->SettingMonsterDot("                  ■  ■■  ■  ");
	_monsterPreset[1]->SettingMonsterDot("                  ■■■■■■  ");
	_monsterPreset[1]->SettingMonsterDot("                ■■■    ■■■");
	_monsterPreset[1]->SettingMonsterDot("                ■■■■■■■■");

	_monsterPreset[2]->SettingMonsterInfo(30, 30, 30);
	_monsterPreset[2]->SettingMonsterDot("                                ");
	_monsterPreset[2]->SettingMonsterDot("                                ");
	_monsterPreset[2]->SettingMonsterDot("                                ");
	_monsterPreset[2]->SettingMonsterDot("                                ");
	_monsterPreset[2]->SettingMonsterDot("                                ");
	_monsterPreset[2]->SettingMonsterDot("                                ");
	_monsterPreset[2]->SettingMonsterDot("                                ");
	_monsterPreset[2]->SettingMonsterDot("                                ");
	_monsterPreset[2]->SettingMonsterDot("              ■■      ■■    ");
	_monsterPreset[2]->SettingMonsterDot("              ■  ■■■  ■    ");
	_monsterPreset[2]->SettingMonsterDot("            ■              ■  ");
	_monsterPreset[2]->SettingMonsterDot("          ■    ■      ■    ■");
	_monsterPreset[2]->SettingMonsterDot("          ■    ■      ■    ■");
	_monsterPreset[2]->SettingMonsterDot("          ■        ■        ■");
	_monsterPreset[2]->SettingMonsterDot("          ■                  ■");
	_monsterPreset[2]->SettingMonsterDot("            ■■■■■■■■■  ");

	_monsterPreset[3]->SettingMonsterInfo(100, 100, 100);
	_monsterPreset[3]->SettingMonsterDot("                                ");
	_monsterPreset[3]->SettingMonsterDot("            ■■■■■■        ");
	_monsterPreset[3]->SettingMonsterDot("          ■            ■      ");
	_monsterPreset[3]->SettingMonsterDot("    ■■■        ■■    ■    ");
	_monsterPreset[3]->SettingMonsterDot("  ■                ■■  ■    ");
	_monsterPreset[3]->SettingMonsterDot("  ■              ■■■  ■    ");
	_monsterPreset[3]->SettingMonsterDot("  ■        ■■          ■    ");
	_monsterPreset[3]->SettingMonsterDot("    ■■■■              ■    ");
	_monsterPreset[3]->SettingMonsterDot("    ■          ■■    ■      ");
	_monsterPreset[3]->SettingMonsterDot("      ■■■■■  ■■  ■      ");
	_monsterPreset[3]->SettingMonsterDot("    ■    ■    ■        ■    ");
	_monsterPreset[3]->SettingMonsterDot("    ■■■■    ■■■■  ■    ");
	_monsterPreset[3]->SettingMonsterDot("          ■■        ■    ■  ");
	_monsterPreset[3]->SettingMonsterDot("      ■■    ■■■■      ■  ");
	_monsterPreset[3]->SettingMonsterDot("    ■  ■    ■  ■  ■  ■  ■");
	_monsterPreset[3]->SettingMonsterDot("    ■■■■■■  ■■■■■■■");

	_monsterPreset[4]->SettingMonsterInfo(200, 200, 200);
	_monsterPreset[4]->SettingMonsterDot("          ■■■■■    ■■■  ");
	_monsterPreset[4]->SettingMonsterDot("■■    ■■■■■■■■■■■  ");
	_monsterPreset[4]->SettingMonsterDot("■■■■■■■    ■■■■■    ");
	_monsterPreset[4]->SettingMonsterDot("■■■■■■    ■■■■■      ");
	_monsterPreset[4]->SettingMonsterDot("■■■■■■■■■■■■        ");
	_monsterPreset[4]->SettingMonsterDot("■■■■  ■■■      ■        ");
	_monsterPreset[4]->SettingMonsterDot("  ■                    ■      ");
	_monsterPreset[4]->SettingMonsterDot("    ■■■■■          ■      ");
	_monsterPreset[4]->SettingMonsterDot("        ■          ■  ■■    ");
	_monsterPreset[4]->SettingMonsterDot("    ■■        ■■      ■    ");
	_monsterPreset[4]->SettingMonsterDot("  ■  ■      ■          ■■■");
	_monsterPreset[4]->SettingMonsterDot("  ■  ■      ■      ■  ■  ■");
	_monsterPreset[4]->SettingMonsterDot("    ■■        ■■■    ■  ■");
	_monsterPreset[4]->SettingMonsterDot("  ■■  ■          ■      ■  ");
	_monsterPreset[4]->SettingMonsterDot("■  ■    ■■■■■  ■  ■  ■");
	_monsterPreset[4]->SettingMonsterDot("■■■■■■■      ■■■■■■");

	_monsterPreset[5]->SettingMonsterInfo(1000, 1000, 1000);
	_monsterPreset[5]->SettingMonsterDot("          ■■■■■    ■■■  ");
	_monsterPreset[5]->SettingMonsterDot("■■    ■■■■■■■■■■■  ");
	_monsterPreset[5]->SettingMonsterDot("■■■■■■      ■■■■■    ");
	_monsterPreset[5]->SettingMonsterDot("■■■■■      ■■■■■  ■  ");
	_monsterPreset[5]->SettingMonsterDot("■■■■■■■■■■■  ■  ■  ");
	_monsterPreset[5]->SettingMonsterDot("■■■■■■■■■  ■  ■  ■  ");
	_monsterPreset[5]->SettingMonsterDot("  ■        ■■      ■      ■");
	_monsterPreset[5]->SettingMonsterDot("    ■■■■          ■      ■");
	_monsterPreset[5]->SettingMonsterDot("        ■        ■  ■  ■  ■");
	_monsterPreset[5]->SettingMonsterDot("    ■■      ■■      ■■  ■");
	_monsterPreset[5]->SettingMonsterDot("  ■  ■    ■    ■    ■■  ■");
	_monsterPreset[5]->SettingMonsterDot("  ■  ■    ■    ■  ■■  ■■");
	_monsterPreset[5]->SettingMonsterDot("    ■■      ■■■■    ■  ■");
	_monsterPreset[5]->SettingMonsterDot("  ■■  ■          ■      ■  ");
	_monsterPreset[5]->SettingMonsterDot("■  ■    ■■■■■  ■  ■  ■");
	_monsterPreset[5]->SettingMonsterDot("■■■■■■        ■■■■■■");

	_monsterPreset[6]->SettingMonsterInfo(1500, 1500, 1500);
	_monsterPreset[6]->SettingMonsterDot("    ■■                ■■    ");
	_monsterPreset[6]->SettingMonsterDot("    ■  ■  ■■■■■■  ■    ");
	_monsterPreset[6]->SettingMonsterDot("    ■  ■■■■■■      ■    ");
	_monsterPreset[6]->SettingMonsterDot("      ■■■■    ■■■■      ");
	_monsterPreset[6]->SettingMonsterDot("    ■■■■    ■■■■        ");
	_monsterPreset[6]->SettingMonsterDot("■■■■■■■■■■■■■■■■");
	_monsterPreset[6]->SettingMonsterDot("■  ■■■■■■■    ■      ■");
	_monsterPreset[6]->SettingMonsterDot("  ■  ■            ■      ■  ");
	_monsterPreset[6]->SettingMonsterDot("■  ■■■■■■■■  ■■■  ■");
	_monsterPreset[6]->SettingMonsterDot("■    ■■    ■        ■    ■");
	_monsterPreset[6]->SettingMonsterDot("■  ■■■■■  ■■■■  ■■  ");
	_monsterPreset[6]->SettingMonsterDot("  ■■  ■            ■  ■  ■");
	_monsterPreset[6]->SettingMonsterDot("■    ■  ■■■■■■  ■    ■");
	_monsterPreset[6]->SettingMonsterDot("■■■■■  ■    ■  ■■■■■");
	_monsterPreset[6]->SettingMonsterDot("    ■  ■  ■■■■■  ■  ■  ");
	_monsterPreset[6]->SettingMonsterDot("    ■■■■■■  ■■■■■■  ");

	_monsterPreset[7]->SettingMonsterInfo(3000, 3000, 3000);
	_monsterPreset[7]->SettingMonsterDot("  ■■■  ■■■■■  ■■■■  ");
	_monsterPreset[7]->SettingMonsterDot("  ■    ■■        ■      ■  ");
	_monsterPreset[7]->SettingMonsterDot("    ■    ■          ■  ■    ");
	_monsterPreset[7]->SettingMonsterDot("    ■■■      ■■  ■■      ");
	_monsterPreset[7]->SettingMonsterDot("    ■        ■■    ■■■    ");
	_monsterPreset[7]->SettingMonsterDot("  ■■                ■    ■  ");
	_monsterPreset[7]->SettingMonsterDot("  ■  ■  ■■■  ■■■    ■■");
	_monsterPreset[7]->SettingMonsterDot("  ■    ■      ■    ■■■  ■");
	_monsterPreset[7]->SettingMonsterDot("    ■■■■■■■■■■■    ■");
	_monsterPreset[7]->SettingMonsterDot("  ■■  ■    ■      ■      ■");
	_monsterPreset[7]->SettingMonsterDot("■      ■■■■■■■■      ■");
	_monsterPreset[7]->SettingMonsterDot("■    ■■  ■    ■    ■  ■  ");
	_monsterPreset[7]->SettingMonsterDot("■■■■■■  ■  ■  ■■■    ");
	_monsterPreset[7]->SettingMonsterDot("    ■■    ■■■■■    ■■  ");
	_monsterPreset[7]->SettingMonsterDot("  ■    ■    ■■■    ■    ■");
	_monsterPreset[7]->SettingMonsterDot("  ■■■■■■■  ■■■■■■■");
}

bool MainGame::IsGamePlaying()
{
	if (_monster[0]->GetHp() == 0)
	{
		return false;
	}
	return true;
}

void MainGame::RunningGame()
{
	PrintMonster();
	_monster[0]->PrintStatus();
	CalculationPlayTime();
	PrintPlayTime();
	ReduceHunger();
	EvolutionCheck();
}

void MainGame::PrintMonster()
{
	_monster[0]->PrintMonster();
}

void MainGame::CalculationPlayTime()
{
	int time = GetTickCount64() - _checkTime;

	if (time > 1000)
	{
		_gameSeconds++;
		_checkTime = GetTickCount64();
	}

	if (_gameSeconds == 60)
	{
		_gameMinutes++;
		_gameSeconds = 0;
		_hungerStack++;
	}
}

void MainGame::PrintPlayTime()
{
	CustomConsole.GotoXY(40, 2);
	cout.width(2);
	cout.fill('0');
	cout << _gameMinutes;
	cout << ":";
	cout.width(2);
	//cout.fill('0');
	cout << _gameSeconds;
}

void MainGame::ReduceHunger()
{
	if (_hungerStack == 1)
	{
		if (_monster[0]->GetHunger() == 0)
		{
			_monster[0]->ReduceHp();
		}
		else
		{
			_monster[0]->ReduceHunger();
		}
		_hungerStack = 0;
	}
}

void MainGame::EvolutionCheck()
{
	switch (_evolutionLevel)
	{
	case eEvolutionLevel::TAMAGOTCHI:
		if (_gameMinutes == 5)
		{
			_evolutionLevel = eEvolutionLevel::BABYLEVEL;
			_monster[0] = _monsterPreset[1];
		}
		break;
	default:
		break;
	}
}
