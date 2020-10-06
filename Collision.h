#pragma once

#include "Physics.h"
#include "Gameobject.h"
#include "IEMath.h"
#include "Manifold.h"
#include <vector>

class Collision
{
public:
	std::vector<shared_ptr<GameObject>> getCollisions(shared_ptr<GameObject> objectA, std::vector<shared_ptr<GameObject>> objectList);
	void resolveCollision(shared_ptr<GameObject> objectA, shared_ptr<GameObject> objectB);

private: 
	bool isColliding(shared_ptr<GameObject> objectA, shared_ptr<GameObject> objectB);
	
	
};

