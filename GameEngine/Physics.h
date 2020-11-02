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
	static Physics instance;
	Physics();
	shared_ptr<GameObject> _player;
	int canJumpCounter;
	map<int, shared_ptr<GameObject>> _gameObjects;
	b2World* _world;
	b2Vec2 _gravity;
	CollisionListener _colListener;
public:
	static Physics& getInstance() { return instance; }

	// prohibit copy & move
	Physics(const Physics&) = delete;
	Physics(Physics&&) = delete;
	Physics& operator=(const Physics&) = delete;
	Physics& operator=(Physics&&) = delete;

	
	//void UpdatePositions();
	void step(float timeStep, int velocityIterations, int positionIterations);
	void addPlayer(shared_ptr<GameObject> obj, float x, float y, float width, float height);
	void increaseCanJumpCounter();
	void decreaseCanJumpCounter();
	bool playerCanJump();
	void addGameObject(int index, shared_ptr<GameObject> obj);

	shared_ptr<GameObject> getGameObject(int index);
	void addBody(shared_ptr<GameObject> obj, float x, float y, float width, float height, float friction, bool fixed, bool fixedRotation);
	bool isMovingLeft(Body body);
	void executeTeleportQueue();
	vector<TeleportObject> teleportQueue;
};

#endif