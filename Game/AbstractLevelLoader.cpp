#include "AbstractLevelLoader.h"


shared_ptr<GameObject> AbstractLevelLoader::createEntity(GameEngine gameEngine, vector<string> extensions, map<int, std::string> textures, float x, float y, float width, float height) {
	return createGameObject(gameEngine, extensions, textures, x, y, width, height, -1, false, false);
}

shared_ptr<GameObject> AbstractLevelLoader::createGameObject(GameEngine gameEngine, vector<string> extensions, map<int, std::string> textures, float x, float y, float width, float height, float friction, bool fixed, bool fixedRotation) {
	shared_ptr<GameObject> gameObject = gameEngine.CreateGameObject(extensions);
	gameObject->textures = textures;
	gameObject->id = Scene::getInstance().getNextAvailableId();

	if (friction == -1 && !fixed && !fixedRotation)
		Physics::getInstance().addPlayer(gameObject, x, y, width, height);
	else
		Physics::getInstance().addBody(gameObject, x, y, width, height, friction, fixed, fixedRotation);

	Scene::getInstance().addGameObject(gameObject);

	return gameObject;
}

shared_ptr<GameObject> AbstractLevelLoader::createNonRigidBody(GameEngine gameEngine, vector<string> extensions, map<int, std::string> textures, float x, float y, float width, float height, std::string userDataType = NULL) {
	shared_ptr<GameObject> gameObject = gameEngine.CreateGameObject(extensions);
	gameObject->textures = textures;
	gameObject->id = Scene::getInstance().getNextAvailableId();

	Physics::getInstance().addNonRigidBody(gameObject, x, y, width, height, userDataType);

	Scene::getInstance().addGameObject(gameObject);
	return gameObject;
}