#include "GameScreen.h"
#include <GameEngine.h>
#include "CollisionResolutionPortalExtension.h"


GameScreen::GameScreen() {}

void GameScreen::onInit() {
	GameEngine gameEngine;

	//// Player
	vector<string> extensionNames = { "MoveExtension", "CheckPhysicsExtension", "CollisionResolutionDefaultExtension" };
	_player = createEntity(gameEngine, extensionNames, "Dummy_cropped",
		5, 5, 0.8f, 2.0f);
	gameObjects.push_back(_player);

	shared_ptr<GameObject> floor = createGameObject(gameEngine, { "CheckPhysicsExtension" }, "Tile_Interior_Ground_Center",
		5, 10, 21.6f, 5, 5, true, true);
	gameObjects.push_back(floor);

	shared_ptr<GameObject> crate = createGameObject(gameEngine, { "CheckPhysicsExtension" }, "Crate_Metal",
		5, 5, 1, 1, 0.3f, false, false);
	gameObjects.push_back(crate);

	shared_ptr<GameObject> crate2 = createGameObject(gameEngine, { "CheckPhysicsExtension" }, "Crate_Metal",
		5, 5, 1, 1, 0.3f, false, false);
	gameObjects.push_back(crate2);

	shared_ptr<GameObject> crate3 = createGameObject(gameEngine, { "CheckPhysicsExtension" }, "Crate_Metal",
		5, 5, 1, 1, 0.3f, false, false);
	gameObjects.push_back(crate3);

	shared_ptr<GameObject> portal1 = createGameObject(gameEngine, { "CheckPhysicsExtension", "CollisionResolutionPortalExtension" }, "Mystical_Crystal_Flipped",
		18, 10, 3, 1, 0.3f, true, true);
	gameObjects.push_back(portal1);

	shared_ptr<GameObject> portal2 = createGameObject(gameEngine, { "CheckPhysicsExtension", "CollisionResolutionPortalExtension" }, "Mystical_Crystal_Flipped",
		18, 1.5, 3, 1, 0.3f, true, true);
	gameObjects.push_back(portal2);

	dynamic_pointer_cast<CollisionResolutionPortalExtension>(portal1->getExtension(typeid(AbstractCollisionResolutionExtension)))->link(portal2);
	dynamic_pointer_cast<CollisionResolutionPortalExtension>(portal2->getExtension(typeid(AbstractCollisionResolutionExtension)))->link(portal1);
}

void GameScreen::onTick() {
	float timeStep = 1.0f / 60.0f;



	Physics::getInstance().step(timeStep, 6, 2);

	handlePlayerControls();
	

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

void GameScreen::handlePlayerControls() {
	b2Vec2 vel = _player->body.b2body->GetLinearVelocity();
	const Uint8* keystate = SDL_GetKeyboardState(NULL);

	//continuous-response keys
	if (keystate[SDL_SCANCODE_A] || keystate[SDL_SCANCODE_LEFT])
		vel.x = -5;

	if (keystate[SDL_SCANCODE_D] || keystate[SDL_SCANCODE_RIGHT])
		vel.x = 5;

	if (keystate[SDL_SCANCODE_SPACE] || keystate[SDL_SCANCODE_W])
		if (Physics::getInstance().playerCanJump())
			vel.y = vel.y - 5;

	_player->body.b2body->SetLinearVelocity(vel);
}

void GameScreen::handleKeyboardInput(SDL_KeyboardEvent e) {
	switch (e.keysym.sym)
	{
	case SDLK_ESCAPE:
		_game->switchScreen(Screens::Pause);

		break;
	default:
		break;
	}
}

void GameScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}

void GameScreen::handleMouseClickInput(SDL_MouseButtonEvent e) {}