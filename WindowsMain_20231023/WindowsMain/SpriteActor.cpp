#include "stdafx.h"
#include "SpriteActor.h"


void SpriteActor::Init()
{
	//부모클래스 기본적인 처리
	Super::Init();
}
void SpriteActor::Render(HDC hdc)
{
	if (_isActive == false) return;

	static Gdiplus::Graphics* g = nullptr;
	static HDC lastHdc = {};

	if (lastHdc != hdc)
	{
		//이미 Graphics가 존재하면, 지워주고 다시만든다.
		SAFE_DELETE(g);
		g = new Gdiplus::Graphics(hdc);
		g->SetInterpolationMode(Gdiplus::InterpolationModeNearestNeighbor);
		lastHdc = hdc;
	}

	if (_sprite)
	{
		//Gdiplus 에서 그리는건 되게 무거워요. (PNG, JPG, BMP, GIF)
		//무거운 프레임워크
		// CPU 그리고있는데
		//PNG ==> GPU (그래픽카드) (X)
		// => DirectX (2D)
		
		//해결방법 :
		// 1. DirectX 를 적용한다. (Gdiplus는 사용하지 않는다.)
		// [v]2. 1024*1024 => 우리가 쓸만큼으로 줄인다.
		// [v]3. gdiplus의 자체 속도업 옵션을 킨다. 
		//  - g.SetInterpolationMode(Gdiplus::InterpolationModeNearestNeighbor);
		// [v]4. 코드자체 최적화 (Graphics를 매프레임 만들었다가, 삭제)
		// 5. ★★ 고속복사 BitBlt를 사용한 그리기
		//  ==> 고속복사라서 PNG는안돼요. (BMP밖에 사용불가능) (BMP은 이미지에 투명도가 불가능함)

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

	//부모클래스 기본적인 처리
	Super::Render(hdc);
}
void SpriteActor::Update()
{
	if (_isActive == false) return;
	//부모클래스 기본적인 처리
	Super::Update();

}
void SpriteActor::Release() 
{
	//부모클래스 기본적인 처리
	Super::Release();

}

void SpriteActor::SetSprite(const WCHAR* filePath, CenterRect body)
{
	_sprite = Gdiplus::Image::FromFile(filePath);
	_body = body;
}