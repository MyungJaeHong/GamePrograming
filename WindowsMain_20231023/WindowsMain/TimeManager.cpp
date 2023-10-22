#include "stdafx.h"
#include "TimeManager.h"

void TimeManager::Init()
{
	//초정밀 타이머
	QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&_frequency));
	QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&_prevCount));
}

void TimeManager::Release()
{
}

void TimeManager::Update()
{
	//long tick = GetTickCount64();
	//_deltaTime = tick - prevTick

	//GetTickCount64()
	// => 편하게쓸수있는 대신에 정밀도면에서 떨어짐 (옛날함수)

	//8바이트짜리 양의 정수 자료형
	unsigned long long currentCount;
	QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currentCount));

	_deltaTime = (currentCount - _prevCount) / static_cast<float>(_frequency);
	_prevCount = currentCount;

	//FPS, FrameCount구하기

	//FrameCount => 화면전환이 몇번되는가? (높을수록 부드럽게) 
	//FPS => Frame Per Seconds (1초에 화면전환이 몇번 되었는가?)
	// (게임 60, 144, 240, 제한없음) (영화, 비디오 24, 30)

	_frameTime += _deltaTime;
	_frameCount++;
	if (_frameTime >= 1.0f)
	{
		_fps = static_cast<unsigned int>(_frameCount / _frameTime);

		_frameTime = 0.0f;
		_frameCount = 0;
	}
}
