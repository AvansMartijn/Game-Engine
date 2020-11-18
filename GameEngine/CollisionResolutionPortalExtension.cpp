#include "pch.h"
#include "CollisionResolutionPortalExtension.h"

CollisionResolutionPortalExtension::CollisionResolutionPortalExtension()
{
    type = "AbstractCollisionResolutionExtension";
}

bool CollisionResolutionPortalExtension::isDefault()
{
    return false;
}

void CollisionResolutionPortalExtension::link(shared_ptr<GameObject> linkedPortal) 
{
    _linkedPortal = linkedPortal;
}

void CollisionResolutionPortalExtension::resolveCollision(shared_ptr<GameObject> inputObject)
{
    Physics::getInstance().teleportQueue.push_back({ inputObject, {_linkedPortal->body.b2body->GetPosition().x, _linkedPortal->body.b2body->GetPosition().y} });
}

