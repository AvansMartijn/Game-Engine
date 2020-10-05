#pragma once

#include "Physics.h"
#include "Gameobject.h"
#include "IEMath.h"
#include "Manifold.h"
#include <vector>

class Collision
{
public:
	std::vector<GameObject> getCollisions(GameObject objectA, std::vector<GameObject> objectList);
	void resolveCollision(GameObject objectA, GameObject objectB);

private: 
	bool isColliding(GameObject objectA, GameObject objectB);
	
	
};

