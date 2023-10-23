#pragma once
#include "SpriteActor.h"
class Bullet : public SpriteActor
{
protected:
	Vector2 _direction;
	float _speed;
public:
	void Move();
	void SetBulletInfo(Vector2 direction, float speed, Vector2 spawnPos);

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

