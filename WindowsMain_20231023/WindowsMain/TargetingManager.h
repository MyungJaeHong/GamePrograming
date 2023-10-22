#pragma once
class TargetingManager
{
	DECLARE_SINGLE(TargetingManager)

	void Init();
	void Release();
	void Update();

private:
	Vector2 _targetVector = {};
public:
	void SetTargetVector(float x, float y);
	Vector2 GetTargetVector() { return _targetVector; }
};

