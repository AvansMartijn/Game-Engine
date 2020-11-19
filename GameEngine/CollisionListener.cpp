#include "CollisionListener.h"
#include "pch.h"
#include "Physics.h"
#include "EntityCategory.h"
#include "CollisionResolutionPortalExtension.h"


void CollisionListener::BeginContact(b2Contact* contact) {
	b2Fixture* fixtureA = contact->GetFixtureA();
	b2Fixture* fixtureB = contact->GetFixtureB();

	b2Body* bodyA = fixtureA->GetBody();
	b2Body* bodyB = fixtureB->GetBody();

	CustomUserData* valA = (CustomUserData*)fixtureA->GetUserData().pointer;
	CustomUserData* valB = (CustomUserData*)fixtureB->GetUserData().pointer;

	CustomUserData* objA = (CustomUserData*)bodyA->GetUserData().pointer;
	CustomUserData* objB = (CustomUserData*)bodyB->GetUserData().pointer;

	shared_ptr<GameObject> gameObjectA = Scene::getInstance().getGameObject(objA->index);
	shared_ptr<GameObject> gameObjectB = Scene::getInstance().getGameObject(objB->index);


	if (valA != nullptr) {
		checkJumpSensor(*valA);
	}

	if (valB != nullptr) {
		checkJumpSensor(*valB);
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

	if (valA != nullptr) {
		if (valA->type == "jumpSensor")
			Scene::getInstance().getPlayerMoveExtension()->jumpCounter--;
	}

	if (valB != nullptr) {
		if (valB->type == "jumpSensor")
			Scene::getInstance().getPlayerMoveExtension()->jumpCounter--;
	}
}

void CollisionListener::checkJumpSensor(const CustomUserData& val) {
	if (val.type == "jumpSensor")
		Scene::getInstance().getPlayerMoveExtension()->jumpCounter++;
}

void CollisionListener::checkExitSensor(const CustomUserData& valA, const CustomUserData& valB) {
	if (valA.type == "exitSensor") {
			if (valB.type == "playerFixture")
				Scene::getInstance().gameOver = true;
	}
}

void CollisionListener::checkPickupSensor(const CustomUserData& valA, const CustomUserData& valB, shared_ptr<GameObject> gameObjectA, shared_ptr<GameObject> gameObjectB) {
	if (valA.type == "pickupSensor") {
		if (valB.type == "playerFixture") {
			if (gameObjectA->hasExtension(typeid(PickupExtension)))
				dynamic_pointer_cast<PickupExtension>(gameObjectA->getExtension(typeid(PickupExtension)))->onEntityCollision(gameObjectB);
		}
	}
}

void CollisionListener::checkGlueBullet(CustomUserData& valA, const CustomUserData& valB, shared_ptr<GameObject> gameObject, const CustomUserData& objA, b2Fixture& fixtureA) {
	if (valA.type == "glueBullet") {
		if (valB.type == "portalSensor") {
			Physics::getInstance().deleteQueue.push_back(objA.index);
		}
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

void CollisionListener::checkTeleport(shared_ptr<GameObject> gameObjectA, shared_ptr<GameObject> gameObjectB, const CustomUserData& valB) {
	if (gameObjectA->hasExtension(typeid(AbstractCollisionResolutionExtension))) {
		shared_ptr<AbstractCollisionResolutionExtension> resolution = dynamic_pointer_cast<AbstractCollisionResolutionExtension>(gameObjectA->getExtension(typeid(AbstractCollisionResolutionExtension)));
		if (!resolution->isDefault()) {
			if (gameObjectB->body.b2body->GetType() == b2_dynamicBody && valB.type != "portalABullet" && valB.type != "portalBbullet" && valB.type != "glueBullet")
				resolution->resolveCollision(gameObjectB);
		}
	}
}

void CollisionListener::checkPortalBullet(const CustomUserData& valA, const CustomUserData& valB, const CustomUserData& objA, shared_ptr<GameObject> gameObjectA, shared_ptr<GameObject> gameObjectB) {
	//culling duplicate to prevent double operations
	auto objectLocation = std::find_if(Physics::getInstance().deleteQueue.begin(), Physics::getInstance().deleteQueue.end(), [objA](int id) {return id == objA.index; });
	if (objectLocation != Physics::getInstance().deleteQueue.end()) {
		return;
	}

	if (valA.type == "portalAbullet" || valA.type == "portalBbullet") {
		if (valB.type == "portalSensor" || valB.type == "glueBullet") {
			Physics::getInstance().deleteQueue.push_back(objA.index);
			return;
		}
		else if (valB.type == "fixture") {
			
			Physics::getInstance().deleteQueue.push_back(objA.index);

			float Aleft = gameObjectA->body.b2body->GetPosition().x - (gameObjectA->body.width / 2);
			float Aright = gameObjectA->body.b2body->GetPosition().x + (gameObjectA->body.width / 2);
			float Atop = gameObjectA->body.b2body->GetPosition().y - (gameObjectA->body.height / 2);
			float Abottom = gameObjectA->body.b2body->GetPosition().y + (gameObjectA->body.width / 2);

			float Bleft = gameObjectB->body.b2body->GetPosition().x - (gameObjectB->body.width / 2);
			float Bright = gameObjectB->body.b2body->GetPosition().x + (gameObjectB->body.width / 2);
			float Btop = gameObjectB->body.b2body->GetPosition().y - (gameObjectB->body.height / 2);
			float Bbottom = gameObjectB->body.b2body->GetPosition().y + (gameObjectB->body.height / 2);

			TeleportObject teleportObj;
			teleportObj.newPosition = gameObjectA->body.b2body->GetPosition();
			if (valA.type == "portalAbullet") {
				teleportObj.obj = Scene::getInstance().portalA;
			}
			else if (valA.type == "portalBbullet") {
				teleportObj.obj = Scene::getInstance().portalB;
			}
			
			auto extension = dynamic_pointer_cast<CollisionResolutionPortalExtension>(teleportObj.obj->getExtension(typeid(AbstractCollisionResolutionExtension)));
			float angle = 0;
			if (Aleft > Bleft && Aleft < Bright) {
				//A left is in between B left and right
				// it has to be bottom or top, check which one is closer
				if (abs(Abottom - gameObjectB->body.b2body->GetPosition().y) < abs(Atop - gameObjectB->body.b2body->GetPosition().y)) {
					// bottom is closer to object b
					// portal must be on top of object B
					extension->exitSide = "top";
					std::cout << "bottom" << "\n";
					angle = 180;
				}
				else {
					//top is closer
					extension->exitSide = "bottom";

					std::cout << "top" << "\n";
				}
			}
			else if (Aright > Bleft && Aright < Bright) {
				//A right is in between B left and right
				if (abs(Abottom - gameObjectB->body.b2body->GetPosition().y) < abs(Atop - gameObjectB->body.b2body->GetPosition().y)) {
					// bottom is closer to object b
					// portal must be on top of object B
					std::cout << "bottom" << "\n";
					extension->exitSide = "top";
					angle = 180;

				}
				else {
					//top is closer
					std::cout << "top" << "\n";
					extension->exitSide = "bottom";

				}
			}
			else if (Atop > Btop && Atop < Bbottom) {
				//A left is in between B left and right
				// it has to be bottom or top, check which one is closer
				if (abs(Aright - gameObjectB->body.b2body->GetPosition().x) < abs(Aleft - gameObjectB->body.b2body->GetPosition().x)) {
					//right is closer
					std::cout << "right" << "\n";
					extension->exitSide = "left";
					angle = 90;

				}
				else {
					//left is closer
					std::cout << "left" << "\n";
					extension->exitSide = "right";
					angle = -90;

				}
			}
			else if (Abottom > Btop && Abottom < Bbottom) {
				//A right is in between B left and right
				if (abs(Aright - gameObjectB->body.b2body->GetPosition().x) < abs(Aleft - gameObjectB->body.b2body->GetPosition().x)) {
					//right is closer
					std::cout << "right" << "\n";
					extension->exitSide = "left";
					angle = 90;

				}
				else {
					//left is closer
					std::cout << "left" << "\n";
					extension->exitSide = "right";
					angle = -90;

				}
			}
			//rotatequeue
			float angleRadians = angle * (M_PI / 180);
			//teleportObj.obj->body.b2body->SetTransform(teleportObj.obj->body.b2body->GetPosition(), angleRadians);*/
			RotateObj rotateObj{ teleportObj.obj, angleRadians };
			Physics::getInstance().rotateQueue.push_back(rotateObj);
			Physics::getInstance().teleportQueue.push_back(teleportObj);
		}
	}
}