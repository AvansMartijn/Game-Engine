#pragma once

#include "Physics.h"
#include "Gameobject.h"
#include "IEMath.h"
#include "Manifold.h"
#include <vector>
/// <summary>
/// Collision detection and resolution
/// </summary>
class Collision
{
public:
	std::vector<shared_ptr<GameObject>> getCollisions(shared_ptr<GameObject> objectA, std::vector<shared_ptr<GameObject>> objectList);
	/// <summary>
	/// Resolve collision between 2 game objects.
	/// </summary>
	/// <param name="objectA">GameObjectA</param>
	/// <param name="objectB">GameObjectB</param>
	void resolveCollision(shared_ptr<GameObject> objectA, shared_ptr<GameObject> objectB);

private: 
	/// <summary>
	/// Check for collision between 2 game Objects
	/// </summary>
	/// <param name="objectA">GameObjectA</param>
	/// <param name="objectB">GameOBjectB</param>
	/// <returns></returns>
	bool isColliding(shared_ptr<GameObject> objectA, shared_ptr<GameObject> objectB);
	
	
};

