#include "stdafx.h"
#include "CollisionManager.h"
#include "Collider.h"
#include "Actor.h"
void CollisionManager::Init()
{
}

void CollisionManager::Update()
{
	//실질적인 충돌처리!!
	
	//
	// 모든 Collider를 한번씩 비교한다. (CheckCollision)
	// 충돌되었으면, 충돌Map에 넣어준다. (함수실행!)
	// 충돌 안되었으면, 충돌Map에서 있다면 꺼내준다. (함수실행!)
	//	* 충돌맵 : _collisionMap
	// 

	//_colliders
	for (int i = 0; i < _colliders.size(); i++)
	{
		Collider* c1 = _colliders[i];
		if (c1->GetOwner()->GetActive() == false) continue;

		for (int j = i + 1; j < _colliders.size(); j++)
		{
			Collider* c2 = _colliders[j];
			if (c2->GetOwner()->GetActive() == false) continue;

			//충돌 되었으면.
			if (c1->CheckCollision(c2))
			{
				//충돌Map에 넣어준다
				// 이미 c1과 c2가 충돌해서, 충돌맵에 없다면
				if (false == c1->_collisionMap.contains(c2))
				{
					//함수실행!
					c1->GetOwner()->OnComponentBeginOverlap(c1, c2);
					c2->GetOwner()->OnComponentBeginOverlap(c2, c1);
					c1->_collisionMap.insert(c2);
					c2->_collisionMap.insert(c1);
				}
			}
			else
			{
				//충돌맵에 있는데, 충돌이 안된상태!
				if (c1->_collisionMap.contains(c2))
				{
					c1->GetOwner()->OnComponentEndOverlap(c1, c2);
					c2->GetOwner()->OnComponentEndOverlap(c2, c1);
					c1->_collisionMap.erase(c2);
					c2->_collisionMap.erase(c1);
				}
			}
		}
	}

}

void CollisionManager::AddCollider(Collider* collider)
{
	_colliders.push_back(collider);
}

void CollisionManager::RemoveCollider(Collider* collider)
{
	auto findIt = find(_colliders.begin(), _colliders.end(), collider);

	if (findIt != _colliders.end())
	{
		_colliders.erase(findIt);
	}
}
