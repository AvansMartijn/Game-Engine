#include "AbstractLevel.h"

shared_ptr<GameObject> AbstractLevel::createEntity(GameEngine gameEngine, vector<string> extensions, std::string texture, float x, float y, float width, float height) {
	return createGameObject(gameEngine, extensions, texture, x, y, width, height, -1, false, false);
}

shared_ptr<GameObject> AbstractLevel::createGameObject(GameEngine gameEngine, vector<string> extensions, std::string texture, float x, float y, float width, float height, float friction, bool fixed, bool fixedRotation) {
	if (friction == -1 && !fixed && !fixedRotation)
		extensions.push_back("PlayerTextureExtension");
	else
		extensions.push_back("EnemyTextureExtension");

	shared_ptr<GameObject> gameObject = gameEngine.createGameObject(extensions);
	gameObject->texture = texture;
	gameObject->id = Scene::getInstance().getNextAvailableId();

	if (friction == -1 && !fixed && !fixedRotation)
		Physics::getInstance().addPlayer(gameObject, x, y, width, height);
	else
		Physics::getInstance().addBody(gameObject, x, y, width, height, friction, fixed, fixedRotation);

	if (std::find(extensions.begin(), extensions.end(), "AiExtension") != extensions.end())
		Scene::getInstance().addEntity(gameObject);
	else
		Scene::getInstance().addGameObject(gameObject);

	return gameObject;
}

shared_ptr<GameObject> AbstractLevel::createPlayer(GameEngine gameEngine, vector<string> extensions, std::string texture, float x, float y, float width, float height) {
	extensions.push_back("AnimationExtension");
	extensions.push_back("PlayerTextureExtension");

	shared_ptr<GameObject> gameObject = gameEngine.createGameObject(extensions);
	gameObject->texture = texture;
	gameObject->id = Scene::getInstance().getNextAvailableId();

	Physics::getInstance().addPlayer(gameObject, x, y, width, height);

	Scene::getInstance().addGameObject(gameObject);

	return gameObject;
}

shared_ptr<GameObject> AbstractLevel::createEnemy(GameEngine gameEngine, vector<string> extensions, std::string texture, float x, float y, float width, float height) {
	extensions.push_back("AnimationExtension");
	extensions.push_back("EnemyTextureExtension");

	shared_ptr<GameObject> gameObject = gameEngine.createGameObject(extensions);
	gameObject->texture = texture;
	gameObject->id = Scene::getInstance().getNextAvailableId();

	Physics::getInstance().addEntity(gameObject, x, y, width, height);

	if (std::find(extensions.begin(), extensions.end(), "AiExtension") != extensions.end())
		Scene::getInstance().addEntity(gameObject);
	else
		Scene::getInstance().addGameObject(gameObject);

	return gameObject;
}

shared_ptr<GameObject> AbstractLevel::createNonRigidBody(GameEngine gameEngine, vector<string> extensions, std::string texture, float x, float y, float width, float height, std::string userDataType = NULL) {
	shared_ptr<GameObject> gameObject = gameEngine.createGameObject(extensions);
	gameObject->texture = texture;
	gameObject->id = Scene::getInstance().getNextAvailableId();

	Physics::getInstance().addNonRigidBody(gameObject, x, y, width, height, userDataType);

	Scene::getInstance().addGameObject(gameObject);
	return gameObject;
}