#include "stdafx.h"
#include "Actor.h"
#include "Component.h"
#include "Collider.h"

void Actor::OnComponentBeginOverlap(Collider* collider, Collider* other)
{
	cout << "충돌시작." << collider->GetOwner()->GetName() << ", " << other->GetOwner()->GetName() << endl;
}

void Actor::OnComponentEndOverlap(Collider* collider, Collider* other)
{
	cout << "충돌끝" << collider->GetOwner()->GetName() << ", " << other->GetOwner()->GetName() << endl;
}

void Actor::AddComponent(Component* component)
{
	if (component == nullptr) return;
	component->SetOwner(this);
	_components.push_back(component);
}
void Actor::RemoveComponent(Component* component)
{
	auto findIt = find(_components.begin(), _components.end(), component);

	//실제로 vector안에 있으면
	if (findIt != _components.end())
	{
		//삭제해준다.
		_components.erase(findIt);
	}
}

void Actor::Init()
{
	/*for (int i = 0; i < _components.size(); i++)
	{
		_components[i]->Init();
	}*/
	SetActive(true);
	for (Component* component : _components)
	{
		component->Init();
	}
}

void Actor::Render(HDC hdc)
{
	if (_isActive == false) return;

	for (Component* component : _components)
	{
		component->Render(hdc);
	}
}

void Actor::Update()
{
	if (_isActive == false) return;

	for (Component* component : _components)
	{
		component->Update();
	}
}

void Actor::Release()
{
	for (Component* component : _components)
	{
		component->Release();
		SAFE_DELETE(component);
	}
	_components.clear();
}
