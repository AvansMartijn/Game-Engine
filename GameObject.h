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

	//std::vector<AbstractGameObjectExtension> _gameObjectExtensions;


	float _width;
	float _height;

	int _gridPositionX;
	int _gridPositionY;


	/*void addExtension();
	bool hasExtension();
	AbstractGameObjectExtension getExtension();*/


};

