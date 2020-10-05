#pragma once
#include "AbstractGameObjectExtension.h"
#include <vector>
#include "PhysicalBody.h"

class GameObject
{
private:
	//std::vector<AbstractGameObjectExtension> _gameObjectExtensions;
	PhysicalBody _physicalBody;

	float _width;
	float _height;

	int _gridPositionX;
	int _gridPositionY;

public:
	/*void addExtension();
	bool hasExtension();
	AbstractGameObjectExtension getExtension();*/

};

