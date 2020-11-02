#include "GameScreen.h"
#include <GameEngine.h>
#include "CollisionResolutionPortalExtension.h"


GameScreen::GameScreen() {}

void GameScreen::onInit() {
	cout << "GAME\n";
	std::cout << "Started \n";

	GameEngine gameEngine;

	//// Player
	vector<string> extensionNames{ "MoveExtension", "CheckPhysicsExtension", "CollisionResolutionDefaultExtension" };
	_player = gameEngine.CreateGameObject(extensionNames);
	_player->textureKey = "Dummy_cropped";
	Physics::getInstance().addPlayer(_player, 5, 5, 0.8f, 2.0f);
	gameObjects.push_back(_player);

	extensionNames = {"CheckPhysicsExtension" };
	shared_ptr<GameObject> floor = gameEngine.CreateGameObject(extensionNames);
	floor->textureKey = "Tile_Interior_Ground_Center";
	Physics::getInstance().addBody(floor, 5, 10, 21.6f, 5.0f, 5.0f, true, true);
	gameObjects.push_back(floor);

	extensionNames = { "CheckPhysicsExtension" };
	shared_ptr<GameObject> crate = gameEngine.CreateGameObject(extensionNames);
	crate->textureKey = "Crate_Metal";
	Physics::getInstance().addBody(crate, 5, 5, 1.0f, 1.0f, 0.3f, false, false);
	gameObjects.push_back(crate);

	extensionNames = { "CheckPhysicsExtension" };
	shared_ptr<GameObject> crate2 = gameEngine.CreateGameObject(extensionNames);
	crate2->textureKey = "Crate_Metal";
	Physics::getInstance().addBody(crate2, 10, 5, 1.0f, 1.0f, 0.3f, false, false);
	gameObjects.push_back(crate2);

	extensionNames = { "CheckPhysicsExtension" };
	shared_ptr<GameObject> crate3 = gameEngine.CreateGameObject(extensionNames);
	crate3->textureKey = "Crate_Metal";
	Physics::getInstance().addBody(crate3, 10, 5, 1.0f, 1.0f, 0.3f, false, false);
	gameObjects.push_back(crate3);

	extensionNames = { "CheckPhysicsExtension", "CollisionResolutionPortalExtension" };
	shared_ptr<GameObject> portal1 = gameEngine.CreateGameObject(extensionNames);
	portal1->textureKey = "Mystical_Crystal_Flipped";
	Physics::getInstance().addBody(portal1, 18, 10, 3.0f, 1.0f, 0.3f, true, true);
	gameObjects.push_back(portal1);

	extensionNames = { "CheckPhysicsExtension", "CollisionResolutionPortalExtension" };
	shared_ptr<GameObject> portal2 = gameEngine.CreateGameObject(extensionNames);
	portal2->textureKey = "Mystical_Crystal_Flipped";
	Physics::getInstance().addBody(portal2, 18, 1.5f, 3.0f, 1.0f, 0.3f, true, true);
	gameObjects.push_back(portal2);

	dynamic_pointer_cast<CollisionResolutionPortalExtension>(portal1->getExtension(typeid(AbstractCollisionResolutionExtension)))->linkedPortal = portal2;
	dynamic_pointer_cast<CollisionResolutionPortalExtension>(portal2->getExtension(typeid(AbstractCollisionResolutionExtension)))->linkedPortal = portal1;


	//extensionNames = { "CheckPhysicsExtension" };
	//shared_ptr<GameObject> floor2 = gameEngine.CreateGameObject(extensionNames);
	//floor2->textureKey = "Krool";
	//physics.AddBody(floor2, 400, 200, 250, 5, true);
	//gameObjects.push_back(floor2);


	//extensionNames = { "CheckPhysicsExtension" };
	//shared_ptr<GameObject> floor3 = gameEngine.CreateGameObject(extensionNames);
	//floor3->textureKey = "Krool";
	//physics.AddBody(floor3, 400, 200, 250, 5, true);
	//gameObjects.push_back(floor3);

	//extensionNames = { "CheckPhysicsExtension", "CollisionResolutionPortalExtension" };
	//shared_ptr<GameObject> floor4 = gameEngine.CreateGameObject(extensionNames);
	//floor4->textureKey = "Krool";
	//physics.AddBody(floor4, 500, 200, 50, 500, false);
	//gameObjects.push_back(floor4);

	//extensionNames = {"CheckPhysicsExtension", "CollisionResolutionPortalExtension"};
	//extensionNames = {};
	//shared_ptr<GameObject> portal = gameEngine.CreateGameObject(extensionNames);
	//portal->textureKey = "Krool";
	//physics.AddBody(portal, 760, 500, 500, 50, true);
	//gameObjects.push_back(portal);

	//// Moving
	//shared_ptr<GameObject> obj1;
	//extensionNames = { "MoveExtension", "CollisionResolutionDefaultExtension", "CheckPhysicsExtension" };
	//obj1 = gameEngine.CreateGameObject(extensionNames);

	//newPos.x = 0;
	//newPos.y = 0;
	//newVel.x = 0;
	//newVel.y = 0;

	//obj1->physicalBody.shape.min = newPos;
	//obj1->physicalBody.shape.max = newPos + 50;
	//obj1->physicalBody.body.position = newPos;
	//obj1->physicalBody.body.velocity = newVel;
	//obj1->textureKey = "Krool";

	//gameObjects.push_back(obj1);

	//// Portal
	//shared_ptr<GameObject> obj2;
	//extensionNames = { "CollisionResolutionPortalExtension" };
	//obj2 = gameEngine.CreateGameObject(extensionNames);

	//newPos.x = 0;
	//newPos.y = 700;
	//newVel.x = 0;
	//newVel.y = 0;

	//obj2->physicalBody.shape.min = newPos;
	//obj2->physicalBody.shape.max.x = 1080;
	//obj2->physicalBody.shape.max.y = 720;
	//obj2->physicalBody.body.position = newPos;
	//obj2->physicalBody.body.velocity = newVel;
	//obj2->textureKey = "Krool";

	//gameObjects.push_back(obj2);
}

void GameScreen::onTick() {
	float timeStep = 1.0f / 60.0f;

	Physics::getInstance().step(timeStep, 6, 2);

	//b2Contact* contactList = physics.world->GetContactList();
	//for (b2Contact* c = physics.world->GetContactList(); c; c = c->GetNext())
	//{
	//	auto fix = c->GetFixtureA();
	//	auto bod = fix->GetBody();

	//	// process c
	//	GameObject* objA = (GameObject*)c->GetFixtureA()->GetBody()->GetUserData();
	//	GameObject* objB = (GameObject*)c->GetFixtureA()->GetBody()->GetUserData();
	//	if (objA->hasExtension(typeid(AbstractCollisionResolutionExtension))) {
	//		objB->body.b2body->SetTransform({ 0, 0 }, 0);
	//	}
	//	else if (objB->hasExtension(typeid(AbstractCollisionResolutionExtension))) {
	//		objA->body.b2body->SetTransform({ 0, 0 }, 0);

	//	}
	//}

	//std::cout << "x: " <<  _player->body.b2body->GetPosition().x << " Y: " << _player->body.b2body->GetPosition().y << "\n";
	//for (shared_ptr<GameObject>& obj : gameObjects)
	//{
	//	/*if (obj->hasExtension(typeid(MoveExtension))) {
	//		shared_ptr<MoveExtension> moveExtenstion = dynamic_pointer_cast<MoveExtension>(obj->getExtension(typeid(MoveExtension)));
	//		moveExtenstion->move();
	//	}*/
	//	
	//	/*if (obj->hasExtension(typeid(CheckPhysicsExtension))) {
	//		shared_ptr<CheckPhysicsExtension> checkPhysicsExtension = dynamic_pointer_cast<CheckPhysicsExtension>(obj->getExtension(typeid(CheckPhysicsExtension)));
	//		checkPhysicsExtension->doPhysics();
	//	}*/
	//}
}

void GameScreen::onScreenShowed() {}

void GameScreen::handleKeyboardInput(SDL_KeyboardEvent e) {
	//PhysicsFacade physicsFacade = PhysicsFacade{};
	//Vec2 pos = _player->physicalBody.body.position;
	b2Vec2 vel = _player->body.b2body->GetLinearVelocity();


	switch (e.keysym.sym)
	{
	case SDLK_w:
		if (Physics::getInstance().playerCanJump()) {
			vel.y = vel.y - 5;
		}
		break;
	case SDLK_s:
		//pos.y += 5;
		//vel.y = vel.y + 50;
		break;
	case SDLK_a:
		//pos.x -= 5;
		vel.x = -5;
		break;
	case SDLK_d:
		//pos.x += 5;
		vel.x = 5;
		break;
	case SDLK_ESCAPE:
		_game->switchScreen(Screens::Pause);

		break;
	default:
		break;
	}

	_player->body.b2body->SetLinearVelocity(vel);
	//physicsFacade.setPosition(_player, pos);

}

void GameScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}

void GameScreen::handleMouseClickInput(SDL_MouseButtonEvent e) {}
