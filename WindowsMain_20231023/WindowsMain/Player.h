#pragma once
#include "SpriteActor.h"
class Player : public SpriteActor
{
private:
	float _speed;

public:
	void Move(Vector2 direction);

public:
	void SetPlayerInfo(CenterRect body, float speed, const WCHAR* spritePath);
public:
	using Super = SpriteActor;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:

	virtual void OnComponentBeginOverlap(Collider* collider, Collider* other) override;
	virtual void OnComponentEndOverlap(Collider* collider, Collider* other) override;
};

