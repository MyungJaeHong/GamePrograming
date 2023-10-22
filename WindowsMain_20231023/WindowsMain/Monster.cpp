#include "stdafx.h"
#include "Monster.h"
#include "Scene.h"

void Monster::Init()
{
	//부모클래스 기본적인 처리
	Super::Init();

	this->SetName("Monster");

}
void Monster::Render(HDC hdc)
{
	if (_isActive == false) return;
	//부모클래스 기본적인 처리
	Super::Render(hdc);

}
void Monster::Update()
{
	if (_isActive == false) return;
	//부모클래스 기본적인 처리
	Super::Update();

	Vector2 targetVector = GET_SINGLE(TargetingManager)->GetTargetVector();

	targetVector.x -= _body.x;
	targetVector.y -= _body.y;
	
	targetVector.Normalize();

	double dotProduct = (_forwardVector.x * targetVector.x) + (_forwardVector.y * targetVector.y);
	double PI = 3.1415926;

	Vector2 direction = {};

	if (cos(PI / 6) < dotProduct)
	{
		direction = targetVector;
	}

	direction.Normalize();
	this->Move(direction);
}
void Monster::Release()
{
	//부모클래스 기본적인 처리
	Super::Release();

}

void Monster::Move(Vector2 direction)
{
	direction.Normalize();
	this->_body.x += direction.x * _speed * DeltaTime;
	this->_body.y += direction.y * _speed * DeltaTime;
}

void Monster::SetTargetVector(Vector2 targetVector)
{
	_targetVector = targetVector;
}

void Monster::SetMonsterInfo(CenterRect body, float speed, const WCHAR* spritePath)
{
	_body = body;
	_speed = speed;
	this->SetSprite(spritePath, _body);
}