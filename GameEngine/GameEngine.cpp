#include "pch.h"
#include "GameEngine.h"

shared_ptr<GameObject> GameEngine::CreateGameObject(vector<string> extensionNames)
{
	return gameObjectFacde.CreateGameObject(extensionNames);
}
