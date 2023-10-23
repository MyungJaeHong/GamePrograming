#pragma once
#include "SpriteActor.h"
class Actor;
class Monster : public SpriteActor
{
private:
	Vector2 _direction;
	Vector2 _originDirection;
	float _speed;
	float _trackingRadian;
	Vector2 _originPos;

	Actor* _targetActor = nullptr;
public:
	void Move(Vector2 direction);
	void SetMonsterInfo(float trackingRadian, float speed, Vector2 spawnPos, Vector2 direction);
	void SetTargetActor(Actor* targetActor) { _targetActor = targetActor; }
	bool IsInTrackingRange();
public:
	using Super = SpriteActor;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
};

