#pragma once
#include "Collider.h"
class BoxCollider : public Collider
{
public:
	using Super = Collider;

private:
	CenterRect _collision;

public:
	CenterRect GetCollision();
	void SetCollision(CenterRect collision) { _collision = collision; }

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	//other와 현재 collider가 충돌하면 true 발생.
	virtual bool CheckCollision(Collider* other);

public:
	BoxCollider();
	virtual ~BoxCollider();
};