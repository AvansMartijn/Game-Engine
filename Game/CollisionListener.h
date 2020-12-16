#pragma once
#include <Box2D.h>
#include "GameObject.h"
#include "AbstractCollisionResolutionExtension.h"
#include "MoveExtension.h"
#include "CustomUserData.h"
#include "PickupExtension.h"
#include "AbstractContactListener.h"

class Physics;
class CollisionListener : public AbstractContactListener {
public:
	void BeginContact(b2Contact* contact);

	void EndContact(b2Contact* contact);

	void checkJumpSensor(const CustomUserData& val, const CustomUserData& valB);
	void checkLeftArmSensor(const CustomUserData& val, b2Body& bodyB);
	void checkRightArmSensor(const CustomUserData& val, b2Body& bodyB);
	void checkExitSensor(const CustomUserData& valA, const CustomUserData& valB);
	void checkPickupSensor(const CustomUserData& valA, const CustomUserData& valB, GameObject* gameObjectA, GameObject* gameObjectB);
	void checkGlueBullet(CustomUserData& valA, const CustomUserData& valB, GameObject* gameObject, const CustomUserData& objA, b2Fixture& fixtureA);
	void checkPortalBullet(const CustomUserData& valA, const CustomUserData& valB, const CustomUserData& objA, GameObject* gameObjectA, GameObject* gameObjectB);
	void checkTeleport(GameObject* gameObjectA, GameObject* gameObjectB, const CustomUserData& valB);
	void checkDamage(GameObject* gameObjectA, GameObject* gameObjectB);
};
