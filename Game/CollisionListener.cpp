#include "CollisionListener.h"
#include "pch.h"
#include "Physics.h"
#include "EntityCategory.h"
#include "CollisionResolutionPortalExtension.h"
#include "IsPortalableExtension.h"
#include "HealthExtension.h"
#include "DoesDamageExtension.h"

void CollisionListener::BeginContact(b2Contact* contact) {
	b2Fixture* fixtureA = contact->GetFixtureA();
	b2Fixture* fixtureB = contact->GetFixtureB();

	b2Body* bodyA = fixtureA->GetBody();
	b2Body* bodyB = fixtureB->GetBody();

	CustomUserData* valA = (CustomUserData*)fixtureA->GetUserData().pointer;
	CustomUserData* valB = (CustomUserData*)fixtureB->GetUserData().pointer;

	CustomUserData* objA = (CustomUserData*)bodyA->GetUserData().pointer;
	CustomUserData* objB = (CustomUserData*)bodyB->GetUserData().pointer;

	GameObject* gameObjectA = Scene::getInstance().getGameObject(objA->index);
	GameObject* gameObjectB = Scene::getInstance().getGameObject(objB->index);


	if (valA != nullptr) {
		checkJumpSensor(*valA, *valB);
		checkLeftArmSensor(*valA, *bodyB);
		checkRightArmSensor(*valA, *bodyB);
	}

	if (valB != nullptr) {
		checkJumpSensor(*valB, *valA);
		//checkJumpSensor(*valB);
		checkLeftArmSensor(*valB, *bodyA);
		checkRightArmSensor(*valB, *bodyA);
	}

	if (valA != nullptr && valB != nullptr) {
		checkExitSensor(*valA, *valB);
		checkExitSensor(*valB, *valA);
		checkPickupSensor(*valA, *valB, gameObjectA, gameObjectB);
		checkPickupSensor(*valB, *valA, gameObjectB, gameObjectA);
		checkGlueBullet(*valA, *valB, gameObjectA, *objA, *fixtureA);
		checkGlueBullet(*valB, *valA, gameObjectB, *objB, *fixtureB);
		checkPortalBullet(*valA, *valB, *objA, gameObjectA, gameObjectB);
		checkPortalBullet(*valB, *valA, *objB, gameObjectB, gameObjectA);
	}

	if (gameObjectA != nullptr && gameObjectB != nullptr) {
		checkTeleport(gameObjectA, gameObjectB, *valA);
		checkTeleport(gameObjectB, gameObjectA, *valB);
		checkDamage(gameObjectB, gameObjectA);
	}

}

void CollisionListener::EndContact(b2Contact* contact) {
	b2Fixture* fixtureA = contact->GetFixtureA();
	b2Fixture* fixtureB = contact->GetFixtureB();

	b2Body* bodyA = fixtureA->GetBody();
	b2Body* bodyB = fixtureB->GetBody();

	CustomUserData* valA = (CustomUserData*)fixtureA->GetUserData().pointer;
	CustomUserData* valB = (CustomUserData*)fixtureB->GetUserData().pointer;

	GameObject* objA = (GameObject*)bodyA->GetUserData().pointer;
	GameObject* objB = (GameObject*)bodyB->GetUserData().pointer;

	if (valA != nullptr && valB != nullptr) {
		if (valA->type == "jumpSensor") {
			if (valB->type != "portalSensor")
				Scene::getInstance().getPlayer()->getExtension<MoveExtension>()->jumpCounter--;
		}

		if (valB->type == "jumpSensor") {
			if (valA->type != "portalSensor")
				Scene::getInstance().getPlayer()->getExtension<MoveExtension>()->jumpCounter--;
		}

		if (valA->type == "leftArmSensor" && bodyB->GetType() == b2_staticBody)
			Scene::getInstance().getPlayer()->getExtension<MoveExtension>()->leftArmCounter--;
	
		if (valB->type == "leftArmSensor" && bodyA->GetType() == b2_staticBody)
			Scene::getInstance().getPlayer()->getExtension<MoveExtension>()->leftArmCounter--;
	
		if (valA->type == "rightArmSensor" && bodyB->GetType() == b2_staticBody)
			Scene::getInstance().getPlayer()->getExtension<MoveExtension>()->rightArmCounter--;
	
		if (valB->type == "rightArmSensor" && bodyA->GetType() == b2_staticBody)
			Scene::getInstance().getPlayer()->getExtension<MoveExtension>()->rightArmCounter--;
	}
}

void CollisionListener::checkJumpSensor(const CustomUserData& valA, const CustomUserData& valB) {
	if (valA.type == "jumpSensor") {
		if (valB.type != "portalSensor")
			Scene::getInstance().getPlayer()->getExtension<MoveExtension>()->jumpCounter++;
	}
}

void CollisionListener::checkLeftArmSensor(const CustomUserData& valA, b2Body& bodyB) {
	if (valA.type == "leftArmSensor" && bodyB.GetType() == b2_staticBody)
		Scene::getInstance().getPlayer()->getExtension<MoveExtension>()->leftArmCounter++;
}

void CollisionListener::checkRightArmSensor(const CustomUserData& valA, b2Body& bodyB) {
	if (valA.type == "rightArmSensor" && bodyB.GetType() == b2_staticBody)
		Scene::getInstance().getPlayer()->getExtension<MoveExtension>()->rightArmCounter++;
}

void CollisionListener::checkExitSensor(const CustomUserData& valA, const CustomUserData& valB) {
	if (valA.type == "exitSensor") {
		if (valB.type == "playerFixture")
			Scene::getInstance().gameOver = true;
	}
}

void CollisionListener::checkPickupSensor(const CustomUserData& valA, const CustomUserData& valB, GameObject* gameObjectA, GameObject* gameObjectB) {
	if (valA.type == "pickupSensor") {
		if (valB.type == "playerFixture") {
			if (gameObjectA->hasExtension(typeid(PickupExtension)))
				gameObjectA->getExtension<PickupExtension>()->onEntityCollision(gameObjectB);
		}
	}
}

void CollisionListener::checkGlueBullet(CustomUserData& valA, const CustomUserData& valB, GameObject* gameObject, const CustomUserData& objA, b2Fixture& fixtureA) {
	if (valA.type == "glueBullet") {
		if (valB.type == "portalSensor")
			Physics::getInstance().deleteQueue.push_back(objA.index);
		else if (valB.type == "glueFixture" || valB.type == "fixture") {
			valA.type = "glueFixture";
			b2Filter filter = fixtureA.GetFilterData();
			filter.categoryBits = SCENERY;
			filter.maskBits = -1;
			fixtureA.SetFilterData(filter);

			Physics::getInstance().setStaticQueue.push_back(gameObject);
		}
	}
}

void CollisionListener::checkTeleport(GameObject* gameObjectA, GameObject* gameObjectB, const CustomUserData& valB) {
	if (gameObjectA->hasExtension(typeid(AbstractCollisionResolutionExtension))) {
		AbstractCollisionResolutionExtension* resolution = gameObjectA->getExtension<AbstractCollisionResolutionExtension>();
		if (!resolution->isDefault()) {
			if (gameObjectB->body.b2body->GetType() == b2_dynamicBody && valB.type != "portalABullet" && valB.type != "portalBbullet" && valB.type != "glueBullet")
				resolution->resolveCollision(gameObjectB);
		}
	}
}

void CollisionListener::checkDamage(GameObject* gameObjectA, GameObject* gameObjectB) {
	if (gameObjectA->hasExtension(typeid(HealthExtension))) {
		if (gameObjectB->hasExtension(typeid(DoesDamageExtension))) {
			HealthExtension* healthExtension = gameObjectA->getExtension<HealthExtension>();
			DoesDamageExtension* damageExtension = gameObjectB->getExtension<DoesDamageExtension>();
			healthExtension->reduceHealth(damageExtension->damage);
		}
	}
}

void CollisionListener::checkPortalBullet(const CustomUserData& valA, const CustomUserData& valB, const CustomUserData& objA, GameObject* gameObjectA, GameObject* gameObjectB) {
	//culling duplicate to prevent double operations
	auto objectLocation = std::find_if(Physics::getInstance().deleteQueue.begin(), Physics::getInstance().deleteQueue.end(), [objA](int id) {return id == objA.index; });
	if (objectLocation != Physics::getInstance().deleteQueue.end())
		return;

	if (valA.type == "portalAbullet" || valA.type == "portalBbullet") {
		if (!gameObjectB->hasExtension(typeid(IsPortalableExtension)) && valB.type != "glueFixture") {
			Physics::getInstance().deleteQueue.push_back(objA.index);
			return;
		}
		else if (gameObjectB->hasExtension(typeid(IsPortalableExtension))) {
			Physics::getInstance().deleteQueue.push_back(objA.index);

			float aLeft = gameObjectA->body.b2body->GetPosition().x - (gameObjectA->body.width / 2);
			float aRight = gameObjectA->body.b2body->GetPosition().x + (gameObjectA->body.width / 2);
			float aTop = gameObjectA->body.b2body->GetPosition().y - (gameObjectA->body.height / 2);
			float aBottom = gameObjectA->body.b2body->GetPosition().y + (gameObjectA->body.width / 2);

			float bLeft = gameObjectB->body.b2body->GetPosition().x - (gameObjectB->body.width / 2);
			float bRight = gameObjectB->body.b2body->GetPosition().x + (gameObjectB->body.width / 2);
			float bTop = gameObjectB->body.b2body->GetPosition().y - (gameObjectB->body.height / 2);
			float bBottom = gameObjectB->body.b2body->GetPosition().y + (gameObjectB->body.height / 2);

			TeleportObject teleportObj;
			teleportObj.newPosition = gameObjectA->body.b2body->GetPosition();
			if (valA.type == "portalAbullet")
				teleportObj.obj = Scene::getInstance().portalA;
			else if (valA.type == "portalBbullet")
				teleportObj.obj = Scene::getInstance().portalB;

			CollisionResolutionPortalExtension* extension = teleportObj.obj->getExtension<CollisionResolutionPortalExtension, AbstractCollisionResolutionExtension>();
			float angle = 0;
			if (aLeft > bLeft && aLeft < bRight) {
				//A left is in between B left and right
				// it has to be bottom or top, check which one is closer
				if (abs(aBottom - gameObjectB->body.b2body->GetPosition().y) < abs(aTop - gameObjectB->body.b2body->GetPosition().y)) {
					// bottom is closer to object b
					// portal must be on top of object B
					extension->exitSide = "top";

					angle = 180;
				}
				else {
					//top is closer
					extension->exitSide = "bottom";
				}
			}
			else if (aRight > bLeft && aRight < bRight) {
				//A right is in between B left and right
				if (abs(aBottom - gameObjectB->body.b2body->GetPosition().y) < abs(aTop - gameObjectB->body.b2body->GetPosition().y)) {
					// bottom is closer to object b
					// portal must be on top of object B
					extension->exitSide = "top";
					angle = 180;
				}
				else {
					//top is closer
					extension->exitSide = "bottom";
				}
			}
			else if (aTop > bTop && aTop < bBottom) {
				//A left is in between B left and right
				// it has to be bottom or top, check which one is closer
				if (abs(aRight - gameObjectB->body.b2body->GetPosition().x) < abs(aLeft - gameObjectB->body.b2body->GetPosition().x)) {
					//right is closer
					extension->exitSide = "left";
					angle = 90;
				}
				else {
					//left is closer
					extension->exitSide = "right";
					angle = -90;
				}
			}
			else if (aBottom > bTop && aBottom < bBottom) {
				//A right is in between B left and right
				if (abs(aRight - gameObjectB->body.b2body->GetPosition().x) < abs(aLeft - gameObjectB->body.b2body->GetPosition().x)) {
					//right is closer
					extension->exitSide = "left";
					angle = 90;
				}
				else {
					//left is closer
					extension->exitSide = "right";
					angle = -90;
				}
			}

			//rotatequeue
			float angleRadians = angle * ((float)M_PI / 180.0f);
			//teleportObj.obj->body.b2body->SetTransform(teleportObj.obj->body.b2body->GetPosition(), angleRadians);*/
			RotateObj rotateObj{ teleportObj.obj, angleRadians };
			Physics::getInstance().rotateQueue.push_back(rotateObj);
			Physics::getInstance().teleportQueue.push_back(teleportObj);
			extension->isActive = true;
		}
	}
}