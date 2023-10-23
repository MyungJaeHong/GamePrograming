#include "stdafx.h"
#include "Bullet.h"
#include "Collider.h"

void Bullet::Init()
{
	//부모클래스 기본적인 처리
	Super::Init();
	this->SetName("Bullet");
}
void Bullet::Render(HDC hdc)
{
	if (_isActive == false) return;
	//부모클래스 기본적인 처리
	Super::Render(hdc);

}
void Bullet::Update()
{
	if (_isActive == false) return;
	//부모클래스 기본적인 처리
	Super::Update();

	this->Move();
}
void Bullet::Release()
{
	//부모클래스 기본적인 처리
	Super::Release();

}

void Bullet::Move()
{
	_direction.Normalize();
	this->_body.x += _direction.x * DeltaTime * _speed;
	this->_body.y += _direction.y * DeltaTime * _speed;
}

void Bullet::SetBulletInfo(Vector2 direction, float speed, Vector2 spawnPos)
{
	_direction = direction;
	_speed = speed;
	_body = Rect::MakeCenterRect(spawnPos.x, spawnPos.y, 50, 50);
	this->SetSprite(L"../Resources/mjh_fireball.png", _body);
}

void Bullet::OnComponentBeginOverlap(Collider* collider, Collider* other)
{
	if (other->GetOwner()->GetName() == "Monster")
	{
		other->GetOwner()->SetActive(false);
		SetActive(false);
		//GET_SINGLE(SceneManager)->GetCurrentScene()->DespawnActor(other->GetOwner());
	}
}

void Bullet::OnComponentEndOverlap(Collider* collider, Collider* other)
{
}