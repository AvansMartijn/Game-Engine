#pragma once
#include "GameObjectExtensionFactory.h"
#include <memory>

class GameObjectBuilder
{
protected:
	std::unique_ptr<GameObjectExtensionFactory> _gameObjectExtensionFactory;
	std::shared_ptr<GameObject> _gameObject;

public:
	GameObjectBuilder();

	void buildGameObject();
	void addExtension(std::vector<string> extensions);
	GameObject getResult();
};

