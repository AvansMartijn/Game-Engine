#include "GameObjectBuilder.h"


void GameObjectBuilder::buildGameObject()
{
	_gameObject.reset(new GameObject());
}

void GameObjectBuilder::addExtension(std::vector<string> extensionNames)
{
	for (string& extensionName : extensionNames)
	{
		shared_ptr<AbstractGameObjectExtension> extension(GameObjectExtensionFactory::get()->createExtension(extensionName));
		if (extension)
			_gameObject->addExtension(extension);
	}
}

shared_ptr<GameObject> GameObjectBuilder::getResult() {
	return _gameObject;
}