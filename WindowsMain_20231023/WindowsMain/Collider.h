#pragma once
#include "Component.h"
class Collider : public Component
{
protected:
	ColliderType _colliderType = ColliderType::None;
	//디버그용으로 충돌영역 그림을 그려줄것인가.
	bool _showDebug
#if _DEBUG
		= true;
#else 
		= false;
#endif

public: // 프레임워크단에 사용할 변수
	unordered_set<Collider*> _collisionMap;

public:
	using Super = Component;

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	//other와 현재 collider가 충돌하면 true 발생.
	virtual bool CheckCollision(Collider* other);
	ColliderType GetColliderType() { return _colliderType; }


public:
	Collider(ColliderType colliderType) { _colliderType = colliderType; }
	virtual ~Collider() {}
};

