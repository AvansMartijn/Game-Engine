#include "CollisionResolutionDefaultExtension.h"

CollisionResolutionDefaultExtension::CollisionResolutionDefaultExtension()
{
	type = "AbstractCollisionResolutionExtension";
}

bool CollisionResolutionDefaultExtension::isDefault()
{
	return true;
}

void CollisionResolutionDefaultExtension::resolveCollision(shared_ptr<GameObject> otherObject)
{
	PhysicsFacade physics;
	physics.resolveCollision(_subject, otherObject);
}
