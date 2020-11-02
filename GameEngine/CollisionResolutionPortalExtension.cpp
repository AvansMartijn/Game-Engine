#include "pch.h"
#include "CollisionResolutionPortalExtension.h"
#include "Physics.h"
//#include "GameObject.h";

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
    TeleportObject tpObject;
    tpObject.from = otherObject;
    tpObject.to = linkedPortal;
    //std::cout << otherObject->textureKey;
    Physics::getInstance().teleportQueue.push_back(tpObject);
  // /* b2Vec2 pos = { 0, 0 };
  //  otherObject->body.b2body->SetTransform(pos, 0);*/
  //  TODO: update so newpos is outside of other portal
  ///*  Vec2 newPos = { 0, 0 };
  //  _physicsFacade.setPosition(otherObject, newPos);*/
}

