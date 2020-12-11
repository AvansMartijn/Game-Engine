#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_GameObjectBuilder __declspec(dllexport)
#else
#define GAMEENGINE_GameObjectBuilder __declspec(dllimport)
#endif
#include "GameObjectExtensionFactory.h"
#include <memory>

class GAMEENGINE_GameObjectBuilder GameObjectBuilder {
protected:
	std::shared_ptr<GameObject> _gameObject;
public:
	void buildGameObject();
	void addExtension(const std::vector<string>& extensions);
	shared_ptr<GameObject> getResult();
};

