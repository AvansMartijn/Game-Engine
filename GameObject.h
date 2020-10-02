#pragma once
#include "AbstractGameObjectExtension.h"
#include <vector>
class GameObject
{
private:
	std::vector<AbstractGameObjectExtension> _gameObjectExtensions;
};

