#include "GameScreen.h"
#include <GameEngine.h>

GameScreen::GameScreen() {}

void GameScreen::onInit() {

	cout << "GAME\n";
	std::cout << "Started \n";

	//GameObjectBuilder builder;

	GameEngine gameEngine;

	//// Player
	vector<string> extensionNames{ "InputExtension" };
	_player = gameEngine.CreateGameObject(extensionNames);

	Vec2 newPos;
	newPos.x = 100;
	newPos.y = 0;
	Vec2 newVel;
	newVel.x = 0;
	newVel.y = 0;

	_player->physicalBody.shape.min = newPos;
	_player->physicalBody.shape.max = newPos + 50;
	_player->physicalBody.body.position = newPos;
	_player->physicalBody.body.velocity = newVel;
	_player->textureKey = "Krool";
	gameObjects.push_back(_player);

	// Moving
	shared_ptr<GameObject> obj1;
	extensionNames = { "MoveExtension", "CollisionResolutionDefaultExtension", "CheckPhysicsExtension" };
	obj1 = gameEngine.CreateGameObject(extensionNames);

	newPos.x = 0;
	newPos.y = 0;
	newVel.x = 0;
	newVel.y = 0;

	obj1->physicalBody.shape.min = newPos;
	obj1->physicalBody.shape.max = newPos + 50;
	obj1->physicalBody.body.position = newPos;
	obj1->physicalBody.body.velocity = newVel;
	obj1->textureKey = "Krool";

	gameObjects.push_back(obj1);

	// Portal
	shared_ptr<GameObject> obj2;
	extensionNames = { "CollisionResolutionPortalExtension" };
	obj2 = gameEngine.CreateGameObject(extensionNames);

	newPos.x = 0;
	newPos.y = 700;
	newVel.x = 0;
	newVel.y = 0;

	obj2->physicalBody.shape.min = newPos;
	obj2->physicalBody.shape.max.x = 1080;
	obj2->physicalBody.shape.max.y = 720;
	obj2->physicalBody.body.position = newPos;
	obj2->physicalBody.body.velocity = newVel;
	obj2->textureKey = "Krool";

	gameObjects.push_back(obj2);
}

void GameScreen::onTick() {
	for (shared_ptr<GameObject>& obj : gameObjects)
	{
		if (obj->hasExtension(typeid(MoveExtension))) {
			shared_ptr<MoveExtension> moveExtenstion = dynamic_pointer_cast<MoveExtension>(obj->getExtension(typeid(MoveExtension)));
			moveExtenstion->move();
		}
		if (obj->hasExtension(typeid(CheckPhysicsExtension))) {
			shared_ptr<CheckPhysicsExtension> checkPhysicsExtension = dynamic_pointer_cast<CheckPhysicsExtension>(obj->getExtension(typeid(CheckPhysicsExtension)));
			checkPhysicsExtension->doPhysics(gameObjects);
		}
	}
}

void GameScreen::onScreenShowed() {}

void GameScreen::handleKeyboardInput(SDL_KeyboardEvent e) {
	PhysicsFacade physicsFacade = PhysicsFacade{};
	Vec2 pos = _player->physicalBody.body.position;

	switch (e.keysym.sym)
	{
	case SDLK_w:
		pos.y -= 5;
		break;
	case SDLK_s:
		pos.y += 5;

		break;
	case SDLK_a:
		pos.x -= 5;

		break;
	case SDLK_d:
		pos.x += 5;

		break;
	case SDLK_ESCAPE:
		_game->switchScreen(Screens::Pause);

		break;
	default:
		break;
	}

	physicsFacade.setPosition(_player, pos);

}

void GameScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}

void GameScreen::handleMouseClickInput(SDL_MouseButtonEvent e) {}
