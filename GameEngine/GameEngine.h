#pragma once

#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_API __declspec(dllexport)
#else
#define GAMEENGINE_API __declspec(dllimport)
#endif

#include <string>
#include "GameObject.h"
#include "GameObjectFacade.h"

class GAMEENGINE_API GameEngine{
private:
	GameObjectFacade _gameObjectFacde;
public:
	/// <summary>
	/// Creates a game object with the given extensions.
	/// </summary>
	/// <param name="extensionNames">The extension we want to create.</param>
	/// <returns>The game object with the given extensions.</returns>
	shared_ptr<GameObject> createGameObject(vector<string> extensionNames);
};