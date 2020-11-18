#pragma once
#include <memory>
#include "GameObject.h"
#include "GameEngine.h"
#include "Physics.h"
#include "Scene.h"

class AbstractLevel
{
protected:
	/// <summary>
	/// Creates a new entity.
	/// </summary>
	/// <param name="gameEngine">The game engine.</param>
	/// <param name="extensions">The extensions which this game object will use.</param>
	/// <param name="textureKey">The texture we want to use.</param>
	/// <param name="x">The x-coordinate.</param>
	/// <param name="y">The y-coordinate.</param>
	/// <param name="width">The object width.</param>
	/// <param name="height">The object height.</param>
	/// <returns>The created entity.</returns>
	shared_ptr<GameObject> createEntity(GameEngine gameEngine, vector<string> extensions, map<int, std::string> textures, float x, float y, float width, float height);
	/// <summary>
	/// Creates a new non ridgid.
	/// </summary>
	/// <param name="gameEngine">The game engine.</param>
	/// <param name="extensions">The extensions which this game object will use.</param>
	/// <param name="textureKey">The texture we want to use.</param>
	/// <param name="x">The x-coordinate.</param>
	/// <param name="y">The y-coordinate.</param>
	/// <param name="width">The object width.</param>
	/// <param name="height">The object height.</param>
	/// <returns>The created portal.</returns>
	shared_ptr<GameObject> createNonRigidBody(GameEngine gameEngine, vector<string> extensions, map<int, std::string> textures, float x, float y, float width, float height, std::string userDataType);
	/// <summary>
	/// Creates a new game object.
	/// </summary>
	/// <param name="gameEngine">The game engine.</param>
	/// <param name="extensions">The extensions which this game object will use.</param>
	/// <param name="textureKey">The texture we want to use.</param>
	/// <param name="x">The x-coordinate.</param>
	/// <param name="y">The y-coordinate.</param>
	/// <param name="width">The object width.</param>
	/// <param name="height">The object height.</param>
	/// <param name="friction">The friction value.</param>
	/// <param name="fixed">If this object should use fixtures.</param>
	/// <param name="fixedRotation"></param>
	/// <returns>The created game object.</returns>
	shared_ptr<GameObject> createGameObject(GameEngine gameEngine, vector<string> extensions, map<int, std::string> textures, float x, float y, float width, float height, float friction, bool fixed, bool fixedRotation);

public:
	/// <summary>
	/// Create the level.
	/// </summary>
	/// <param name="gameEngine">The game engine</param>
	virtual void createLevel(GameEngine gameEngine) = 0;
};
