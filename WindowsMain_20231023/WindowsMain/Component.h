#pragma once
class Actor;
class Component
{
protected:
	Actor* _owner = nullptr;

public:
	void SetOwner(Actor* owner) { _owner = owner; }
	Actor* GetOwner() { return _owner; }

public:
	virtual void Init() {}
	virtual void Render(HDC hdc) {}
	virtual void Update() {}
	virtual void Release() {}

public:
	Component() {}
	virtual ~Component() {}
};

