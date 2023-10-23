#include "stdafx.h"
#include "Monster.h"
#include "Scene.h"

void Monster::Init()
{
	//�θ�Ŭ���� �⺻���� ó��
	Super::Init();

	this->SetName("Monster");

}
void Monster::Render(HDC hdc)
{
	if (_isActive == false) return;
	//�θ�Ŭ���� �⺻���� ó��
	Super::Render(hdc);

	Vector2 forwardDirection = _direction.Normalize();
	Vector2 leftDirection = Vector2(-forwardDirection.y, forwardDirection.x);
	Vector2 rightDirection = Vector2(forwardDirection.y, -forwardDirection.x);

	Vector2 leftEndPos = Vector2(_body.x, _body.y) + (forwardDirection * cos(_trackingRadian / 2) + leftDirection * sin(_trackingRadian / 2)) * 200;
	Vector2 rightEndPos = Vector2(_body.x, _body.y) + (forwardDirection * cos(_trackingRadian / 2) + rightDirection * sin(_trackingRadian / 2)) * 200;

	Draw::Line(hdc, Vector2(_body.x, _body.y), leftEndPos);
	Draw::Line(hdc, Vector2(_body.x, _body.y), rightEndPos);
}
void Monster::Update()
{
	if (_isActive == false) return;
	//�θ�Ŭ���� �⺻���� ó��
	Super::Update();

	//�����ڵ�
	/*
	���� ���� ���� �����ڵ�

	if (_targetActor) then
		if ( �÷��̾ ���� �������� �ȿ� ��ġ ) then
			���Ͱ� �÷��̾� �������� �̵��Ѵ�
		else then
			�ƹ��͵� ���Ѵ�. (���ڸ��� ���ư���.)
	*/

	if (_targetActor)
	{
		if (IsInTrackingRange())
		{
			Vector2 moveVec = (_targetActor->GetBody().Position() - this->GetBody().Position()).Normalize();
			this->_direction = moveVec;
			this->Move(moveVec);
		}
		else
		{
			//�����ڸ��� ���ư���.
			Vector2 toTarget = (_originPos - this->GetBody().Position());
			if (toTarget.Length() > 2.0f)
			{
				Vector2 moveVec = toTarget.Normalize();
				this->_direction = moveVec;
				this->Move(moveVec);
			}
			else
			{
				this->_direction = _originDirection;
			}
		}
	}

	_roationRadian = Vector2::Down().SignedAngle(this->_direction);
}
void Monster::Release()
{
	//�θ�Ŭ���� �⺻���� ó��
	Super::Release();

}

void Monster::Move(Vector2 direction)
{
	direction.Normalize();
	this->_body.x += direction.x * _speed * DeltaTime;
	this->_body.y += direction.y * _speed * DeltaTime;
}

void Monster::SetMonsterInfo(float trackingRadian, float speed, Vector2 spawnPos, Vector2 direction)
{
	_trackingRadian = trackingRadian;
	_speed = speed;
	_direction = direction;
	_originDirection = direction;
	_originPos = spawnPos;

	this->SetBody(CenterRect{ spawnPos.x, spawnPos.y, 80, 80 });
	this->SetSprite(L"../Resources/mjh_monster.png", this->GetBody());
}

bool Monster::IsInTrackingRange()
{
	// _targetActor�� ���� �������� �ȿ� ��ġ���ִٸ�,,,

	// �������� : Angle + Distance

	float distance = (_targetActor->GetBody().Position() - this->_body.Position()).Length();

	if (distance < 200)
	{
		// ����
		Vector2 toTarget = _targetActor->GetBody().Position() - this->_body.Position();
		Vector2 forwardDirection = _direction;

		toTarget.Normalize();
		forwardDirection.Normalize();

		float signedAngle = forwardDirection.SignedAngle(toTarget);

		if (abs(signedAngle) < this->_trackingRadian / 2)
		{
			return true;
		}
	}

	return false;
}