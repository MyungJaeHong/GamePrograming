#pragma once
#include "SpriteActor.h"
class Monster : public SpriteActor
{
private:
	float _speed;
	Vector2 _forwardVector = { 0 , 1 };
	Vector2 _targetVector = {};
	float _viewingDirection;

public:
	void Move(Vector2 direction);
	void SetTargetVector(Vector2 targetVector);
public: 
	void SetMonsterInfo(CenterRect body, float speed, const WCHAR* spritePath);
public:
	using Super = SpriteActor;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
};

