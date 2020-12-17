#pragma once

#include "GameObjectBuilder.h"
#include "GameObjectExtensionFactory.h"

class GameObjectFacade{
private:
	GameObjectBuilder _builder;
public:
	/// <summary>
	/// Creates a game object with the given extension names.
	/// </summary>
	/// <param name="extensionNames">The extensions we want to add.</param>
	/// <returns>The created game object.</returns>
	unique_ptr<GameObject> createGameObject(vector<string> extensionNames);
};