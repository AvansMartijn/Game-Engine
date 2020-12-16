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
	std::unique_ptr<GameObject> _gameObject;
public:
	void buildGameObject();
	void addExtension(const std::vector<string>& extensions);
	unique_ptr<GameObject> getResult();
};

