#pragma once

#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_Physics __declspec(dllexport)
#else
#define GAMEENGINE_Physics __declspec(dllimport)
#endif

#ifndef Physics_h
#define Physics_h


#include <Box2D.h>
#include <memory>
#include "GameObject.h"
#include "CollisionListener.h"
#include "CustomUserData.h"
#include "TeleportObject.h"

class CollisionListener;
class GAMEENGINE_Physics Physics
{
private:
	Physics();
	static Physics instance;

	shared_ptr<GameObject> _player;
	int _canJumpCounter;
	b2World* _world;
	b2Vec2 _gravity;
	CollisionListener _colListener;
	std::map<int, shared_ptr<GameObject>> _gameObjects;
public:
	static Physics& getInstance() { return instance; }

	// prohibit copy & move
	Physics(const Physics&) = delete;
	Physics(Physics&&) = delete;
	Physics& operator=(const Physics&) = delete;
	Physics& operator=(Physics&&) = delete;
	
	vector<TeleportObject> teleportQueue;

	/// <summary>
	/// Executes a step in the wordl.
	/// </summary>
	/// <param name="timeStep">The time step we want to use.</param>
	/// <param name="velocityIterations">The amount of velocity iterations.</param>
	/// <param name="positionIterations">The amount of position iterations.</param>
	void step(float timeStep, int velocityIterations, int positionIterations);

	/// <summary>
	/// Adds a player to the world.
	/// </summary>
	/// <param name="obj">The player.</param>
	/// <param name="x">The x-coordinate.</param>
	/// <param name="y">The y-coordinate.</param>
	/// <param name="width">The width</param>
	/// <param name="height">The height.</param>
	void addPlayer(shared_ptr<GameObject> obj, float x, float y, float width, float height);

	/// <summary>
	/// Adds a portal to the world.
	/// </summary>
	/// <param name="obj">The player.</param>
	/// <param name="x">The x-coordinate.</param>
	/// <param name="y">The y-coordinate.</param>
	/// <param name="width">The width</param>
	/// <param name="height">The height.</param>
	void addPortal(shared_ptr<GameObject> obj, float x, float y, float width, float height);

	/// <summary>
	/// Adds a body to the world.
	/// </summary>
	/// <param name="obj">The player.</param>
	/// <param name="x">The x-coordinate.</param>
	/// <param name="y">The y-coordinate.</param>
	/// <param name="width">The width</param>
	/// <param name="height">The height.</param>
	/// <param name="friction">The friction.</param>
	/// <param name="fixed">If this body should be affected by collisions.</param>
	/// <param name="fixedRotation">If the rotation should be effected by collisions.</param>
	void addBody(shared_ptr<GameObject> obj, float x, float y, float width, float height, float friction, bool fixed, bool fixedRotation);

	/// <summary>
	/// Increase the jump counter.
	/// </summary>
	void increaseCanJumpCounter();

	/// <summary>
	/// Decrease the jump counter.
	/// </summary>
	void decreaseCanJumpCounter();

	/// <summary>
	/// Checks if the player can jump.
	/// </summary>
	/// <returns>If the player can jump.</returns>
	bool playerCanJump();

	/// <summary>
	/// Adds a game object to the registry.
	/// </summary>
	/// <param name="index">The index in the registry.</param>
	/// <param name="obj">The object we want to register.</param>
	void addGameObject(int index, shared_ptr<GameObject> obj);

	/// <summary>
	/// Reset the physics.
	/// </summary>
	void reset();

	/// <summary>
	/// Get's a gameobject from the registry.
	/// </summary>
	/// <param name="index">The id of the gameobject</param>
	/// <returns>The game object.</returns>
	shared_ptr<GameObject> getGameObject(int index);

	/// <summary>
	/// Checks if a body is faced to the left.
	/// </summary>
	/// <param name="body">The body we want to check.</param>
	/// <returns>If the body is faced to the left.</returns>
	bool isMovingLeft(Body body);

	/// <summary>
	/// Executes the queued teleports.
	/// </summary>
	void executeTeleportQueue();
};

#endif