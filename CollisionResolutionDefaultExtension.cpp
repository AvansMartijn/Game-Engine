#include "CollisionResolutionDefaultExtension.h"

CollisionResolutionDefaultExtension::CollisionResolutionDefaultExtension()
{
	type = "AbstractCollisionResolutionExtension";
}

bool CollisionResolutionDefaultExtension::isDefault()
{
	return true;
}

void CollisionResolutionDefaultExtension::resolveCollition(shared_ptr<GameObject> objectA, shared_ptr<GameObject> objectB)
{
}
