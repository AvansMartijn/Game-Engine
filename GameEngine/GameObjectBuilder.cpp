#include "pch.h"
#include "GameObjectBuilder.h"

void GameObjectBuilder::buildGameObject() {
	_gameObject.reset(new GameObject());
}

void GameObjectBuilder::addExtension(const std::vector<string>& extensionNames) {
	for (const string& extensionName : extensionNames) {
		shared_ptr<AbstractGameObjectExtension> extension(GameObjectExtensionFactory::get()->createExtension(extensionName));
		if (extension) {
			extension->registerSubject(_gameObject);

			_gameObject->addExtension(extension);
		}
	}
}

shared_ptr<GameObject> GameObjectBuilder::getResult() {
	return _gameObject;
}
