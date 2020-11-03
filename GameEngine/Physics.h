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
	
	//TODO: COMMENTAAR VERDER
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
	/// <param name="obj"></param>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="width"></param>
	/// <param name="height"></param>
	void addPlayer(shared_ptr<GameObject> obj, float x, float y, float width, float height);
	void addPortal(shared_ptr<GameObject> obj, float x, float y, float width, float height);
	void increaseCanJumpCounter();
	void decreaseCanJumpCounter();
	bool playerCanJump();
	void addGameObject(int index, shared_ptr<GameObject> obj);
	void reset();

	shared_ptr<GameObject> getGameObject(int index);
	void addBody(shared_ptr<GameObject> obj, float x, float y, float width, float height, float friction, bool fixed, bool fixedRotation);
	bool isMovingLeft(Body body);
	void executeTeleportQueue();
	vector<TeleportObject> teleportQueue;
};

#endif