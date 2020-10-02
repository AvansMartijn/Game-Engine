#pragma once
#include "GameObject.h"
#include "AbstractGameObjectExtension.h"
#include <vector>


class GameObjectFactory
{
private:
	GameObject _gameObject;
	std::vector<AbstractGameObjectExtension> _gameObjectExtensions;
};

