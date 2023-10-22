#pragma once
class Scene;
class SceneManager
{
	DECLARE_SINGLE(SceneManager)
public:
	void Init();
	void Render(HDC hdc);
	void Update();
	void Release();

private:
	Scene* _scene = nullptr;
	SceneType _sceneType = SceneType::None;

public:
	void ChangeScene(SceneType sceneType);
	Scene* GetCurrentScene() { return _scene; }
};

