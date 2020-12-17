#include "pch.h"
#include "GameObjectFacade.h"

unique_ptr<GameObject> GameObjectFacade::createGameObject(vector<string> extensionNames) {
	_builder.buildGameObject();
	_builder.addExtension(extensionNames);
	return _builder.getResult();
}
