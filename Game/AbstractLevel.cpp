#include "AbstractLevel.h"

GameObject* AbstractLevel::createEntity(GameEngine& gameEngine, vector<string> extensions, std::string texture, float x, float y, float width, float height) {
	return createGameObject(gameEngine, extensions, texture, x, y, width, height, -1, false, false);
}

GameObject* AbstractLevel::createGameObject(GameEngine& gameEngine, vector<string> extensions, std::string texture, float x, float y, float width, float height, float friction, bool fixed, bool fixedRotation) {
	unique_ptr<GameObject> gameObject = gameEngine.createGameObject(extensions);
	gameObject->texture = texture;
	gameObject->id = Scene::getInstance().getNextAvailableId();
	int id = gameObject->id;

	if (friction == -1 && !fixed && !fixedRotation)
		Physics::getInstance().addPlayer(gameObject.get(), x, y, width, height);
	else
		Physics::getInstance().addBody(gameObject.get(), x, y, width, height, friction, fixed, fixedRotation);

	if (std::find(extensions.begin(), extensions.end(), "AiExtension") != extensions.end())
		Scene::getInstance().addEntity(std::move(gameObject));
	else
		Scene::getInstance().addGameObject(std::move(gameObject));

	return Scene::getInstance().getGameObject(id);
}

GameObject* AbstractLevel::createPlayer(GameEngine& gameEngine, vector<string> extensions, std::string texture, float x, float y, float width, float height) {
	extensions.push_back("AnimationExtension");

	unique_ptr<GameObject> gameObject = gameEngine.createGameObject(extensions);
	gameObject->texture = texture;
	gameObject->id = Scene::getInstance().getNextAvailableId();
	int id = gameObject->id;

	Physics::getInstance().addPlayer(gameObject.get(), x, y, width, height);

	Scene::getInstance().addGameObject(std::move(gameObject));

	return Scene::getInstance().getGameObject(id);
}

GameObject* AbstractLevel::createEnemy(GameEngine& gameEngine, vector<string> extensions, std::string texture, float x, float y, float width, float height) {
	extensions.push_back("AnimationExtension");

	unique_ptr<GameObject> gameObject = gameEngine.createGameObject(extensions);
	gameObject->texture = texture;
	gameObject->id = Scene::getInstance().getNextAvailableId();
	int id = gameObject->id;

	Physics::getInstance().addEntity(gameObject.get(), x, y, width, height);

	if (std::find(extensions.begin(), extensions.end(), "AiExtension") != extensions.end())
		Scene::getInstance().addEntity(std::move(gameObject));
	else
		Scene::getInstance().addGameObject(std::move(gameObject));

	return Scene::getInstance().getGameObject(id);
}

GameObject* AbstractLevel::createNonRigidBody(GameEngine& gameEngine, vector<string> extensions, std::string texture, float x, float y, float width, float height, std::string userDataType = NULL) {
	unique_ptr<GameObject> gameObject = gameEngine.createGameObject(extensions);
	gameObject->texture = texture;
	gameObject->id = Scene::getInstance().getNextAvailableId();
	int id = gameObject->id;

	Physics::getInstance().addNonRigidBody(gameObject.get(), x, y, width, height, userDataType);

	Scene::getInstance().addGameObject(std::move(gameObject));

	return Scene::getInstance().getGameObject(id);
}