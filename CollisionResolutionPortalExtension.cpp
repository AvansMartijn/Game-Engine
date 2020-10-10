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
    PhysicsFacade physics;

    //!!!!update so newpos is outside of portal
    Vec2 newPos = { 0, 0 };
    physics.setPosition(otherObject, newPos);
}
