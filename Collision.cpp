#include "Collision.h"


std::vector<shared_ptr<GameObject>> Collision::getCollisions(shared_ptr<GameObject> objectA, std::vector<shared_ptr<GameObject>> objectList)
{
	std::vector<shared_ptr<GameObject>> collisions;
	for (int i = 0; i < objectList.size(); i++) 
		if (isColliding(objectA, objectList[i])) 
			collisions.push_back(objectList[i]);
		
	
	return collisions;
}

bool Collision::isColliding(shared_ptr<GameObject> objectA, shared_ptr<GameObject> objectB)
{
	Shape shapeA = objectA->physicalBody.shape;
	Shape shapeB = objectB->physicalBody.shape;
	if (shapeA.max.x < shapeB.min.x || shapeA.min.x > shapeB.max.x)
		return false;
	

	if (shapeA.max.y < shapeB.min.y || shapeA.min.y > shapeB.max.y)
		return false;
	

	// No separating axis found, therefor there is at least one overlapping axis
	return true;
}

void Collision::resolveCollision(shared_ptr<GameObject> objectA, shared_ptr<GameObject> objectB) {
	Manifold *m = new Manifold(objectA->physicalBody, objectB->physicalBody);
	if (m->AABBvsAABB()) 
		m->ApplyImpulse();
	
	
}
