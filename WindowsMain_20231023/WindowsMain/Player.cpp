#include "stdafx.h"
#include "Player.h"
#include "Scene.h"
#include "Bullet.h"
#include "BoxCollider.h"

void Player::Init()
{
	//�θ�Ŭ���� �⺻���� ó��
	Super::Init();


	this->SetName("Player");

}
void Player::Render(HDC hdc)
{
	if (_isActive == false) return;
	//�θ�Ŭ���� �⺻���� ó��
	Super::Render(hdc);

}
void Player::Update()
{
	if (_isActive == false) return;
	//�θ�Ŭ���� �⺻���� ó��
	Super::Update();

	Vector2 direction = {};
	if (GET_SINGLE(KeyManager)->GetKey('W'))
	{
		direction = direction + Vector2(0, -1);
	}

	if (GET_SINGLE(KeyManager)->GetKey('A'))
	{
		direction = direction + Vector2(-1, 0);
	}

	if (GET_SINGLE(KeyManager)->GetKey('S'))
	{
		direction = direction + Vector2(0, 1);
	}

	if (GET_SINGLE(KeyManager)->GetKey('D'))
	{
		direction = direction + Vector2(1, 0);
	}
	if (GET_SINGLE(KeyManager)->GetKeyDown(VK_SPACE))
	{
		Bullet* playerBullet = new Bullet();
		Vector2 dircetion;
		dircetion.x = _mousePos.x - _body.x;
		dircetion.y = _mousePos.y - _body.y;
		playerBullet->SetBulletInfo(dircetion, 500, Vector2(_body.x, _body.y));
		{
			BoxCollider* collider = new BoxCollider();
			collider->SetCollision(Rect::MakeCenterRect(0, 0, 40, 40));
			playerBullet->AddComponent(collider);
		}
		playerBullet->Init();
		GET_SINGLE(SceneManager)->GetCurrentScene()->SpawnActor(playerBullet);
	}

	direction.Normalize();
	this->Move(direction);
}
void Player::Release()
{
	//�θ�Ŭ���� �⺻���� ó��
	Super::Release();

}

void Player::OnComponentBeginOverlap(Collider* collider, Collider* other)
{
	if (other->GetOwner()->GetName() == "ItemBox")
	{
		cout << "������ �ڽ� �Ծ���." << endl;
		other->GetOwner()->SetActive(false);
		//GET_SINGLE(SceneManager)->GetCurrentScene()->DespawnActor(other->GetOwner());
	}
}

void Player::OnComponentEndOverlap(Collider* collider, Collider* other)
{
	cout << "�÷��̾��� �浹 ��!" << endl;
}

void Player::Move(Vector2 direction)
{
	direction.Normalize();
	this->_body.x += direction.x * _speed * DeltaTime;
	this->_body.y += direction.y * _speed * DeltaTime;
}

void Player::SetPlayerInfo(CenterRect body, float speed, const WCHAR * spritePath)
{
	_body = body;
	_speed = speed;
	this->SetSprite(spritePath, _body);
}