#include "CollisionResolutionPortalExtension.h"

CollisionResolutionPortalExtension::CollisionResolutionPortalExtension()
{
    type = "AbstractCollisionResolutionExtension";
}

bool CollisionResolutionPortalExtension::isDefault()
{
    return false;
}

void CollisionResolutionPortalExtension::resolveCollision(shared_ptr<GameObject> otherObject)
{

    //TODO: update so newpos is outside of other portal
    Vec2 newPos = { 0, 0 };
    _physicsFacade.setPosition(otherObject, newPos);
}
