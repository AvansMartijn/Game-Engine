#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_Scene __declspec(dllexport)
#else
#define GAMEENGINE_Scene __declspec(dllimport)
#endif

#include <vector>
#include <memory>
#include "GameObject.h"
#include "AbstractManageableItem.h"
#include "CanWieldExtension.h"
#include "TextUiElement.h"
#include "IEMath.h"

class GAMEENGINE_Scene Scene {
private:
	Scene();
	static Scene instance;

	map<int, shared_ptr<GameObject>> _gameObjects;
	std::vector<int> _entities;
	map<std::string, shared_ptr<AbstractManageableItem>> _items;
	map<int, std::string> _keyRegistry;
	std::vector<shared_ptr<TextUiElement>> _textElements;

	shared_ptr<GameObject> _player;

	bool preRender = false;

public:
	float tickRate = 60.0;
	float refreshRate = 60.0;
	shared_ptr<GameObject> portalA;
	shared_ptr<GameObject> portalB;
	static Scene& getInstance() { return instance; }

	Scene(const Scene&) = delete;
	Scene(Scene&&) = delete;
	Scene& operator=(const Scene&) = delete;
	Scene& operator=(Scene&&) = delete;

	bool isLocked;
	int score;
	bool gameOver;
	bool hasCheated = false;
	std::vector<std::string> activatedCheats;
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
	/// Ad an UI element to the scene.
	/// </summary>
	/// <param name="obj"></param>
	void addTextUiElement(shared_ptr<TextUiElement> obj);

	/// <summary>
	/// Add an entity to the registry.
	/// </summary>
	/// <param name="obj">The entity we want to register.</param>
	void addEntity(shared_ptr<GameObject> obj);

	/// <summary>
	/// Get's a gameobject from the registry.
	/// </summary>
	/// <param name="id">The id of the gameobject</param>
	/// <returns>The game object.</returns>
	shared_ptr<GameObject> getGameObject(int id);

	/// <summary>
	/// Get's the game objects in the current scene.
	/// </summary>
	/// <returns>The game objects in the current scene.</returns>
	map<int, shared_ptr<GameObject>> getGameObjects();

	/// <summary>
	/// Get's the index at the given index.
	/// </summary>
	/// <param name="index">The entity index.</param>
	/// <returns>The correct game object.</returns>
	shared_ptr<GameObject> getEntityAtIndex(int index);

	/// <summary>
	/// Get's the size of the entities vector.
	/// </summary>
	/// <returns>The size of the entities vector.</returns>
	size_t getEntitiesSize();

	/// <summary>
	/// Removes a game object from the scene.
	/// </summary>
	/// <param name="index">The game object index.</param>
	void removeGameObject(int index);

	/// <summary>
	/// Removes an entity from the scene.
	/// </summary>
	/// <param name="id">The entity ID.</param>
	void removeEntity(int id);

	/// <summary>
	/// Get's the next available id.
	/// </summary>
	/// <returns>The next available id.</returns>
	int getNextAvailableId();

	/// <summary>
	/// Adds a item to the scene.
	/// </summary>
	/// <param name="name">The name.</param>
	/// <param name="item">The item.</param>
	void addItem(std::string name, shared_ptr<AbstractManageableItem> item);

	/// <summary>
	/// Get's the item with the given index.
	/// </summary>
	/// <param name="index">The index of the item.</param>
	/// <returns>The item on the given index.</returns>
	shared_ptr<AbstractManageableItem> getItem(int index);

	/// <summary>
	/// Get's the item with the given name.
	/// </summary>
	/// <param name="name">The name of the item.</param>
	/// <returns>The item with the given name.</returns>
	shared_ptr<AbstractManageableItem> getItem(std::string name);

	/// <summary>
	/// Get's an item from the scene.
	/// </summary>
	/// <typeparam name="T">The type of item.</typeparam>
	/// <param name="name">The item name.</param>
	/// <returns>The item.</returns>
	template<typename T>
	std::shared_ptr<T> getItem(std::string name) {
		std::shared_ptr<AbstractManageableItem> item = getItem(name);

		if (item == nullptr)
			return nullptr;

		return dynamic_pointer_cast<T>(item);
	}

	/// <summary>
	/// Set's the player.
	/// </summary>
	/// <param name="player">The player</param>
	void setPlayer(shared_ptr<GameObject> player);

	/// <summary>
	/// Get's the player.
	/// </summary>
	/// <returns>The player.</returns>
	shared_ptr<GameObject> getPlayer();

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

	/// <summary>
	/// Get's the wield extension.
	/// </summary>
	/// <returns>The wield extension.</returns>
	shared_ptr<CanWieldExtension> getWieldExtension();

	/// <summary>
	/// convert meters to pixels
	/// </summary>
	/// <param name="meters"></param>
	/// <returns>amount of pixels</returns>
	float metersToPixels(float meters);

	/// <summary>
	/// convert pixels to meters
	/// </summary>
	/// <param name="pixels"></param>
	/// <returns>amount of meters</returns>
	float pixelsToMeters(float pixels);

};

