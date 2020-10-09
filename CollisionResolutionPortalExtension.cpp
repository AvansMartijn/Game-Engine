#include "CollisionResolutionPortalExtension.h"

CollisionResolutionPortalExtension::CollisionResolutionPortalExtension()
{
    type = "AbstractCollisionResolutionExtension";
}

bool CollisionResolutionPortalExtension::isDefault()
{
    return false;
}

void CollisionResolutionPortalExtension::resolveCollition(shared_ptr<GameObject> objectA, shared_ptr<GameObject> objectB)
{
}
