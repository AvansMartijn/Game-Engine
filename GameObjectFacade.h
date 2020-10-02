#pragma once
#include "GameObjectBuilder.h"
#include "GameObjectFactory.h"
class GameObjectFacade
{
private:
	GameObjectBuilder _gameObjectBuilder;
	GameObjectFactory _gameObjectFactory;
};
