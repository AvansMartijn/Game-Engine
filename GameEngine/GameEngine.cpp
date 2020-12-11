#include "pch.h"
#include "GameEngine.h"
#include "AbstractManageableItem.h"

shared_ptr<GameObject> GameEngine::createGameObject(vector<string> extensionNames) {
	return _gameObjectFacde.createGameObject(extensionNames);
}