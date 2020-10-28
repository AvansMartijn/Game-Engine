#pragma once

#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_API __declspec(dllexport)
#else
#define GAMEENGINE_API __declspec(dllimport)
#endif

#include <string>
#include "GameObject.h"
#include "GameObjectFacade.h"



class GAMEENGINE_API GameEngine
{
private:
	GameObjectFacade gameObjectFacde;
public:
	shared_ptr<GameObject> CreateGameObject(vector<string> extensionNames);

};