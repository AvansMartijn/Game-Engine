#pragma once

#include "GameObjectBuilder.h"
#include "GameObjectExtensionFactory.h"


class GameObjectFacade
{
private:
	GameObjectBuilder builder;
public:
	shared_ptr<GameObject> CreateGameObject(vector<string> extensionNames);
};