#pragma once
#include "GameObjectExtensionFactory.h"
#include <memory>

class GameObjectBuilder
{
protected:
	std::shared_ptr<GameObject> _gameObject;
public:
	void buildGameObject();
	void addExtension(const std::vector<string>& extensions);
	shared_ptr<GameObject> getResult();
};

