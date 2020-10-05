#pragma once
#include "AbstractGameObjectExtension.h"
#include <vector>
#include "PhysicalBody.h"

class GameObject
{
private:
	std::vector<AbstractGameObjectExtension> _gameObjectExtensions;

public:
	PhysicalBody physicalBody;
};

