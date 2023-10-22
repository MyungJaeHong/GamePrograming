#include "stdafx.h"
#include "ItemBox.h"

void ItemBox::Init()
{
	//부모클래스 기본적인 처리
	Super::Init();

	this->SetName("ItemBox");

}
void ItemBox::Render(HDC hdc)
{
	if (_isActive == false) return;
	//부모클래스 기본적인 처리
	Super::Render(hdc);

}
void ItemBox::Update()
{
	if (_isActive == false) return;
	//부모클래스 기본적인 처리
	Super::Update();

}
void ItemBox::Release()
{
	//부모클래스 기본적인 처리
	Super::Release();

}

void ItemBox::OnComponentBeginOverlap(Collider* collider, Collider* other)
{

}

void ItemBox::OnComponentEndOverlap(Collider* collider, Collider* other)
{
}

void ItemBox::SetItemBoxInfo(ItemBoxType type, CenterRect body)
{
	_itemBoxType = type;

	switch (_itemBoxType)
	{
	case ItemBoxType::None:
		break;
	case ItemBoxType::HpItemBox:
		this->SetSprite(L"../Resources/Items/hp_item_box.png", body);
		break;
	case ItemBoxType::MissileItemBox:
		this->SetSprite(L"../Resources/Items/missile_item_box.png", body);
		break;
	default:
		break;
	}
}