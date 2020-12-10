#pragma once
#include <Box2D.h>
#include "GameObject.h"
#include "AbstractCollisionResolutionExtension.h"
#include "MoveExtension.h"
#include "CustomUserData.h"
#include "PickupExtension.h"
#include "AbstractContactListener.h"

class Physics;
class CollisionListener : public AbstractContactListener
{
public:
	void BeginContact(b2Contact* contact);

	void EndContact(b2Contact* contact);

	void checkJumpSensor(const CustomUserData& val);
	void checkLeftArmSensor(const CustomUserData& val);
	void checkRightArmSensor(const CustomUserData& val);
	void checkExitSensor(const CustomUserData& valA, const CustomUserData& valB);
	void checkPickupSensor(const CustomUserData& valA, const CustomUserData& valB, shared_ptr<GameObject> gameObjectA, shared_ptr<GameObject> gameObjectB);
	void checkGlueBullet(CustomUserData& valA, const CustomUserData& valB, shared_ptr<GameObject> gameObject, const CustomUserData& objA, b2Fixture& fixtureA);
	void checkPortalBullet(const CustomUserData& valA, const CustomUserData& valB, const CustomUserData& objA, shared_ptr<GameObject> gameObjectA, shared_ptr<GameObject> gameObjectB);
	void checkTeleport(shared_ptr<GameObject> gameObjectA, shared_ptr<GameObject> gameObjectB, const CustomUserData& valB);
	void checkDamage(shared_ptr<GameObject> gameObjectA, shared_ptr<GameObject> gameObjectB);
};
