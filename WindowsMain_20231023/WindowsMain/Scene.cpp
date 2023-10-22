#include "stdafx.h"
#include "Scene.h"
#include "Actor.h"


void Scene::Init()
{
}
void Scene::Render(HDC hdc)
{
}
void Scene::Update()
{
}
void Scene::Release()
{
}


void Scene::SpawnActor(Actor* actor)
{
	actor->Init();
	_actors.push_back(actor);
}
void Scene::DespawnActor(Actor* actor)
{
	for (int i = 0; i < _actors.size(); i++)
	{
		if (_actors[i] == actor)
		{
			_actors[i]->Release();
			_actors.erase(_actors.begin() + i);
			return;
		}
	}
}