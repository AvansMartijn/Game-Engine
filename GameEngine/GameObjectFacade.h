#pragma once

#include "GameObjectBuilder.h"
#include "GameObjectExtensionFactory.h"


class GameObjectFacade
{
private:
	GameObjectBuilder _builder;
public:
	shared_ptr<GameObject> createGameObject(vector<string> extensionNames);
};