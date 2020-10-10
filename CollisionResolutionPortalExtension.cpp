#include "CollisionResolutionPortalExtension.h"

CollisionResolutionPortalExtension::CollisionResolutionPortalExtension()
{
    type = "AbstractCollisionResolutionExtension";
}

bool CollisionResolutionPortalExtension::isDefault()
{
    return false;
}

void CollisionResolutionPortalExtension::resolveCollision(shared_ptr<GameObject> objectA, shared_ptr<GameObject> objectB)
{
    PhysicsFacade physics;

    //!!!!update so newpos is outside of portal
    Vec2 newPos = objectA->physicalBody.body.position;
    physics.setPosition(objectB, newPos);
}
