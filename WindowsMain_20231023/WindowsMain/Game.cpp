#include "stdafx.h"
#include "Game.h"

void Game::Init()
{
	//---------------------------------------
	//	## 더블버퍼링 관련
	//---------------------------------------
	_hdc = GetDC(_hWnd);
	_hdcBack = CreateCompatibleDC(_hdc);
	_bmpBack = CreateCompatibleBitmap(_hdc, WIN_SIZE_WIDTH, WIN_SIZE_HEIGHT);
	HBITMAP prevBmp = (HBITMAP)SelectObject(_hdcBack, _bmpBack);
	DeleteObject(prevBmp);

	//---------------------------------------
	//	## Gdiplus 관련 ==> 이미지 관련된 라이브러리
	//---------------------------------------
	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	Gdiplus::GdiplusStartup(&this->_gdiPlusToken, &gdiplusStartupInput, NULL);


	//---------------------------------------
	//	## 싱글톤 관련
	//---------------------------------------
	GET_SINGLE(TimeManager)->Init();
	GET_SINGLE(SceneManager)->Init();
	GET_SINGLE(KeyManager)->Init();
	GET_SINGLE(CollisionManager)->Init();
	GET_SINGLE(TargetingManager)->Init();

	//---------------------------------------
	//	## 게임플레이 관련
	//---------------------------------------
	GET_SINGLE(SceneManager)->ChangeScene(SceneType::Dev1Scene);
}
void Game::Update()
{
	//---------------------------------------
	//	## 싱글톤 관련
	//---------------------------------------
	GET_SINGLE(TimeManager)->Update();
	GET_SINGLE(CollisionManager)->Update();
	GET_SINGLE(SceneManager)->Update();
}
void Game::Render()
{
	GET_SINGLE(SceneManager)->Render(_hdcBack);


	//프레임 출력
	unsigned int fps = GET_SINGLE(TimeManager)->GetFps();
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();
	char str[250];
	sprintf_s(str, "FPS(%d), DT(%f)", fps, deltaTime);
	TextOutA(_hdcBack, 0, 0, str, strlen(str));


	//---------------------------------------
	//	## 더블버퍼링 관련
	//---------------------------------------
	//Blt => 고속복사
	//BitBlt => DC간 고속복사
	BitBlt(_hdc, 0, 0, WIN_SIZE_WIDTH, WIN_SIZE_HEIGHT, _hdcBack, 0, 0, SRCCOPY);

	//PatBlt => 어떤색으로 얼마나 칠할건지
	PatBlt(_hdcBack, 0, 0, WIN_SIZE_WIDTH, WIN_SIZE_HEIGHT, WHITENESS);
}
void Game::Release()
{
	//---------------------------------------
	//	## 싱글톤 관련
	//---------------------------------------
	GET_SINGLE(TimeManager)->Release();
	GET_SINGLE(SceneManager)->Release();
	GET_SINGLE(KeyManager)->Release();
	GET_SINGLE(TargetingManager)->Release();
}