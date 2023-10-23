#pragma once
#include "Scene.h"

class SpriteActor;
class Player;
class Dev1Scene : public Scene
{

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

private:
	float _monsterSpawnTime = 0;
	Actor* _playerActor = nullptr;
};

