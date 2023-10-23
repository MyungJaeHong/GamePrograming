#include "stdafx.h"
#include "Dev1Scene.h"
#include "Actor.h"
#include "SpriteActor.h"
#include "Player.h"
#include "BoxCollider.h"
#include "ItemBox.h"
#include "Monster.h"

void Dev1Scene::Init()
{
	SpriteActor* backgroundActor = new SpriteActor();
	backgroundActor->Init();
	backgroundActor->SetSprite(L"../Resources/mjh_background.png", Rect::MakeCenterRect(WIN_SIZE_WIDTH / 2, WIN_SIZE_HEIGHT / 2, WIN_SIZE_WIDTH, WIN_SIZE_HEIGHT));
	this->SpawnActor(backgroundActor);

	//Colldier* c = new Collider()

	{
		Player* player = new Player();
		player->SetPlayerInfo(Rect::MakeCenterRect(WIN_SIZE_WIDTH / 2, WIN_SIZE_HEIGHT / 2, 100, 100), 200, L"../Resources/mjh_charactor.png");
		{
			//컴포넌트 추가
			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Rect::MakeCenterRect(0, 0, 50, 80));
			player->AddComponent(collider);
		}
		this->SpawnActor(player);
	}

	/*
	{
		ItemBox* itemBox = new ItemBox();
		itemBox->SetItemBoxInfo(ItemBoxType::MissileItemBox, Rect::MakeCenterRect(400, 200, 50, 50));
		{
			//컴포넌트 추가
			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Rect::MakeCenterRect(0, 0, 50, 50));
			itemBox->AddComponent(collider);
		}
		this->SpawnActor(itemBox);
	}
	*/
}

void Dev1Scene::Render(HDC hdc)
{
	for (int i = 0; i < _actors.size(); i++)
	{
		_actors[i]->Render(hdc);
	}

	char str[250];
	sprintf_s(str, "Dev1Scene");
	TextOutA(hdc, 0, WIN_SIZE_HEIGHT - 50, str, strlen(str));
}

void Dev1Scene::Update()
{
	for (int i = 0; i < _actors.size(); i++)
	{
		_actors[i]->Update();
	}

	_monsterSpawnTime += DeltaTime;
	{
		if (_monsterSpawnTime > 3.0f)
		{
			Monster* monster = new Monster();
			monster->SetMonsterInfo(Rect::MakeCenterRect(Random::GetInt(0, WIN_SIZE_WIDTH), Random::GetInt(0, WIN_SIZE_HEIGHT), 80, 80), 100, L"../Resources/mjh_monster.png");
			{
				//컴포넌트 추가
				BoxCollider* collider = new BoxCollider();
				collider->SetCollision(Rect::MakeCenterRect(1, -3, 45, 43));
				monster->AddComponent(collider);
			}
			this->SpawnActor(monster);
			_monsterSpawnTime = 0;
		}
	}


}

void Dev1Scene::Release()
{
	for (int i = 0; i < _actors.size(); i++)
	{
		_actors[i]->Release();
		SAFE_DELETE(_actors[i]);
	}
	_actors.clear();
}