#pragma once
class Game
{
private:

public:
	void Init();
	void Update();
	void Render();
	void Release();


//---------------------------------------
//	## Gdiplus 관련
//---------------------------------------
private:
	ULONG_PTR _gdiPlusToken;


//---------------------------------------
//	## 더블버퍼링 관련
//---------------------------------------
private:
	HDC _hdc;
	HDC _hdcBack;
	HBITMAP _bmpBack;

};

