#pragma once
// Component들을 가질 수있다.
// Component => 각각 기능
//  Collider Component => 충돌체크를해주는 기능
// 
class Component;
class Collider;
class Actor
{
protected:
	vector<Component*> _components;
	CenterRect _body = {};	//Draw 영역 (가운데가 Actor Position)
	string _name;

	bool _isActive = true;

public:
	//충돌시작 함수
	//Unreal
	virtual void OnComponentBeginOverlap(Collider* collider, Collider* other);
	//Unity
	//virtual void OnTriggerEnter(Collider* collider, Collider* other);

	//충돌끝 함수
	//Unreal
	virtual void OnComponentEndOverlap(Collider* collider, Collider* other);
	//Unity
	//virtual void OnTriggerExit(Collider* collider, Collider* other);

public:
	void AddComponent(Component* component);
	void RemoveComponent(Component* component);

	CenterRect GetBody() { return _body; }
	void SetBody(CenterRect body) { _body = body; }

	string GetName() { return _name; }
	void SetName(string name) { _name = name; }

	bool GetActive() { return _isActive; }
	void SetActive(bool active) { _isActive = active; }
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();
};

