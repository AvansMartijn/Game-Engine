#include "Collision.h"


std::vector<GameObject> Collision::getCollisions(GameObject objectA, std::vector<GameObject> objectList)
{
	std::vector<GameObject> collisions;
	for (int i = 0; i < objectList.size(); i++) {
		if (AABBvsAABB(objectA, objectList[i])) {
			collisions.push_back(objectList[i]);
		}
	}
}

bool Collision::AABBvsAABB(GameObject objectA, GameObject objectB)
{
	Shape shapeA = objectA.physicalBody.shape;
	Shape shapeB = objectB.physicalBody.shape;
	if (shapeA.max.x < shapeB.min.x || shapeA.min.x > shapeB.max.x) {
		return false;
	}

	if (shapeA.max.y < shapeB.min.y || shapeA.min.y > shapeB.max.y) {
		return false;
	}

	// No separating axis found, therefor there is at least one overlapping axis
	return true;
}

void Collision::resolveCollision(GameObject objectA, GameObject objectB) {
	Manifold *m = new Manifold(&objectA.physicalBody, &objectB.physicalBody);
	
}
