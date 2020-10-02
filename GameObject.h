#pragma once
#include "AbstractGameObjectExtension.h"
#include <vector>
#include "PhysicalBody.h"

class GameObject
{
private:
	std::vector<AbstractGameObjectExtension> _gameObjectExtensions;
	PhysicalBody _physicalBody;
};

