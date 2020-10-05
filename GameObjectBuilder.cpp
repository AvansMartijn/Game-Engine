#include "GameObjectBuilder.h"

GameObjectBuilder::GameObjectBuilder()
{
	_gameObjectExtensionFactory.reset(GameObjectExtensionFactory::Get());
}

void GameObjectBuilder::buildGameObject()
{
	_gameObject.reset(new GameObject());
}

void GameObjectBuilder::addExtension(std::vector<string> extensionName) 
{
	for (string& extensionName : extensionName)
	{
		shared_ptr<AbstractGameObjectExtension> extension = make_shared<AbstractGameObjectExtension>(GameObjectExtensionFactory::Get()->CreateExtension(extensionName));
		if(extension)
			_gameObject->addExtension(extension);
	}
