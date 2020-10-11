#include "GameScreen.h"
#include <iostream>
#include "GameObjectBuilder.h"
#include "MoveExtension.h"
#include "CheckPhysicsExtension.h"
#include "AbstractGame.h"
using namespace std;

GameScreen::GameScreen() {}

void GameScreen::init() {

	cout << "GAME\n";
	std::cout << "Started \n";

	GameObjectBuilder builder;

	// Player
	builder.buildGameObject();
	vector<string> extensionNames{ "InputExtension" };
	builder.addExtension(extensionNames);
	_player = builder.getResult();

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
	gameObjects.push_back(_player);

	// Moving
	shared_ptr<GameObject> obj1;
	builder.buildGameObject();
	extensionNames = { "MoveExtension", "CollisionResolutionDefaultExtension", "CheckPhysicsExtension" };
	builder.addExtension(extensionNames);

	obj1 = builder.getResult();

	newPos.x = 0;
	newPos.y = 0;
	newVel.x = 0;
	newVel.y = 0;

	obj1->physicalBody.shape.min = newPos;
	obj1->physicalBody.shape.max = newPos + 50;
	obj1->physicalBody.body.position = newPos;
	obj1->physicalBody.body.velocity = newVel;

	gameObjects.push_back(obj1);

	// Portal
	shared_ptr<GameObject> obj2;
	builder.buildGameObject();
	extensionNames = { "CollisionResolutionPortalExtension" };
	builder.addExtension(extensionNames);

	obj2 = builder.getResult();

	newPos.x = 0;
	newPos.y = 700;
	newVel.x = 0;
	newVel.y = 0;

	obj2->physicalBody.shape.min = newPos;
	obj2->physicalBody.shape.max.x = 1080;
	obj2->physicalBody.shape.max.y = 720;
	obj2->physicalBody.body.position = newPos;
	obj2->physicalBody.body.velocity = newVel;

	gameObjects.push_back(obj2);
}

void GameScreen::tick() {

	for (auto& obj : gameObjects)
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

void GameScreen::handleKeyboardInput(SDL_KeyboardEvent e) {
	PhysicsFacade facade = PhysicsFacade{};
	Vec2 pos = _player->physicalBody.body.position;

	switch (e.keysym.sym)
	{
	case SDLK_w:
		cout << "w\n";
		pos.y -= 5;
		break;
	case SDLK_s:
		cout << "s\n";
		pos.y += 5;

		break;
	case SDLK_a:
		cout << "a\n";
		pos.x -= 5;

		break;
	case SDLK_d:
		cout << "D\n";
		pos.x += 5;

		break;
	case SDLK_ESCAPE:
		cout << "ESCAPE\n";
		_game->switchScreen(1);

		break;
	default:
		break;
	}
	facade.setPosition(_player, pos);

}

void GameScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {

}

void GameScreen::handleMouseClickInput(SDL_MouseButtonEvent e) {

}