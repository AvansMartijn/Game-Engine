#include "CollisionResolutionDefaultExtension.h"

CollisionResolutionDefaultExtension::CollisionResolutionDefaultExtension()
{
	type = "AbstractCollisionResolutionExtension";
}

bool CollisionResolutionDefaultExtension::isDefault()
{
	return true;
}

void CollisionResolutionDefaultExtension::resolveCollision(shared_ptr<GameObject> objectA, shared_ptr<GameObject> objectB)
{
	PhysicsFacade physics;
	physics.resolveCollision(objectA, objectB);
}
