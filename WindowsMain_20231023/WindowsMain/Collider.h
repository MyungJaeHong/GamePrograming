#pragma once
#include "Component.h"
class Collider : public Component
{
protected:
	ColliderType _colliderType = ColliderType::None;
	//����׿����� �浹���� �׸��� �׷��ٰ��ΰ�.
	bool _showDebug
#if _DEBUG
		= true;
#else 
		= false;
#endif

public: // �����ӿ�ũ�ܿ� ����� ����
	unordered_set<Collider*> _collisionMap;

public:
	using Super = Component;

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	//other�� ���� collider�� �浹�ϸ� true �߻�.
	virtual bool CheckCollision(Collider* other);
	ColliderType GetColliderType() { return _colliderType; }


public:
	Collider(ColliderType colliderType) { _colliderType = colliderType; }
	virtual ~Collider() {}
};

