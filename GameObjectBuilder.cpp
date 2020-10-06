#include "GameObjectBuilder.h"

GameObjectBuilder::GameObjectBuilder()
{
	//_gameObjectExtensionFactory.reset(GameObjectExtensionFactory::Get());
	//_gameObject = NULL;
}

void GameObjectBuilder::buildGameObject()
{
	_gameObject.reset(new GameObject());
}

void GameObjectBuilder::addExtension(std::vector<string> extensionNames)
{
	for (string& extensionName : extensionNames)
	{
		shared_ptr<AbstractGameObjectExtension> extension(GameObjectExtensionFactory::Get()->CreateExtension(extensionName));

		if (extension)
		{
			_gameObject->addExtension(extension);
		}
	}
}

shared_ptr<GameObject> GameObjectBuilder::getResult() {
	return _gameObject;
}