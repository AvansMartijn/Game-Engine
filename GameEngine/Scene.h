#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_Scene __declspec(dllexport)
#else
#define GAMEENGINE_Scene __declspec(dllimport)
#endif

#include <vector>
#include <memory>
#include "GameObject.h"

class GAMEENGINE_Scene Scene
{
private:
	Scene();
	static Scene instance;

	map<int, shared_ptr<GameObject>> _gameObjects;
public:
	static Scene& getInstance() { return instance; }

	Scene(const Scene&) = delete;
	Scene(Scene&&) = delete;
	Scene& operator=(const Scene&) = delete;
	Scene& operator=(Scene&&) = delete;

	shared_ptr<GameObject> player;
	int score;
	bool gameOver;
	float zoom = 40.0f;

	/// <summary>
	/// Adds a game object to the registry.
	/// </summary>
	/// <param name="index">The index in the registry.</param>
	/// <param name="obj">The object we want to register.</param>
	void addGameObject(int index, shared_ptr<GameObject> obj);

	/// <summary>
	/// Adds a game object to the registry.
	/// </summary>
	/// <param name="obj">The object we want to register.</param>
	void addGameObject(shared_ptr<GameObject> obj);

	/// <summary>
	/// Get's a gameobject from the registry.
	/// </summary>
	/// <param name="index">The id of the gameobject</param>
	/// <returns>The game object.</returns>
	shared_ptr<GameObject> getGameObject(int index);

	/// <summary>
	/// Get's the next available id.
	/// </summary>
	/// <returns>The next available id.</returns>
	int getNextAvailableId();

	/// <summary>
	/// Resets the scene.
	/// </summary>
	void reset();

	/// <summary>
	/// Renders all the objects on the screen.
	/// </summary>
	/// <param name="window">The window.</param>
	void render(const unique_ptr<Window>& window);

	/// <summary>
	/// Get's the move extension for the player.
	/// </summary>
	/// <returns>The move extension for the player.</returns>
	shared_ptr<MoveExtension> getPlayerMoveExtension();
};

