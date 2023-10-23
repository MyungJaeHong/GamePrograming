#include "stdafx.h"
#include "SpriteActor.h"


void SpriteActor::Init()
{
	//�θ�Ŭ���� �⺻���� ó��
	Super::Init();
}
void SpriteActor::Render(HDC hdc)
{
	if (_isActive == false) return;

	static Gdiplus::Graphics* g = nullptr;
	static HDC lastHdc = {};

	if (lastHdc != hdc)
	{
		//�̹� Graphics�� �����ϸ�, �����ְ� �ٽø����.
		SAFE_DELETE(g);
		g = new Gdiplus::Graphics(hdc);
		g->SetInterpolationMode(Gdiplus::InterpolationModeNearestNeighbor);
		lastHdc = hdc;
	}

	if (_sprite)
	{
		//Gdiplus ���� �׸��°� �ǰ� ���ſ���. (PNG, JPG, BMP, GIF)
		//���ſ� �����ӿ�ũ
		// CPU �׸����ִµ�
		//PNG ==> GPU (�׷���ī��) (X)
		// => DirectX (2D)
		
		//�ذ��� :
		// 1. DirectX �� �����Ѵ�. (Gdiplus�� ������� �ʴ´�.)
		// [v]2. 1024*1024 => �츮�� ����ŭ���� ���δ�.
		// [v]3. gdiplus�� ��ü �ӵ��� �ɼ��� Ų��. 
		//  - g.SetInterpolationMode(Gdiplus::InterpolationModeNearestNeighbor);
		// [v]4. �ڵ���ü ����ȭ (Graphics�� �������� ������ٰ�, ����)
		// 5. �ڡ� ��Ӻ��� BitBlt�� ����� �׸���
		//  ==> ��Ӻ���� PNG�¾ȵſ�. (BMP�ۿ� ���Ұ���) (BMP�� �̹����� ������ �Ұ�����)

		if (false == (abs(_roationRadian) < EPSILON))
		{
			{
				Gdiplus::Matrix matrix;
				matrix.RotateAt(Rad2Deg(_roationRadian), Gdiplus::PointF(_body.x, _body.y));
				g->SetTransform(&matrix);
			}
			g->DrawImage(_sprite, _body.ToGdiRect());
			{
				Gdiplus::Matrix matrix;
				g->SetTransform(&matrix);
			}
		}
		else
		{
			g->DrawImage(_sprite, _body.ToGdiRect());
		}
	}

	//�θ�Ŭ���� �⺻���� ó��
	Super::Render(hdc);
}
void SpriteActor::Update()
{
	if (_isActive == false) return;
	//�θ�Ŭ���� �⺻���� ó��
	Super::Update();

}
void SpriteActor::Release() 
{
	//�θ�Ŭ���� �⺻���� ó��
	Super::Release();

}

void SpriteActor::SetSprite(const WCHAR* filePath, CenterRect body)
{
	_sprite = Gdiplus::Image::FromFile(filePath);
	_body = body;
}