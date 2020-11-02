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
//class CollisionListener;
class GAMEENGINE_Physics Physics
{

private:
	static Physics instance;
	Physics();
	shared_ptr<GameObject> _player;
	int canJumpCounter;
public:
	static Physics& getInstance() {
		return instance;
	};
	// prohibit copy & move
	Physics(const Physics&) = delete;
	Physics(Physics&&) = delete;
	Physics& operator=(const Physics&) = delete;
	Physics& operator=(Physics&&) = delete;

	b2World* world;
	b2Vec2 gravity;
	CollisionListener colListener;
	vector<shared_ptr<GameObject>> updatePositionList;
	
	//void UpdatePositions();
	void AddPlayer(shared_ptr<GameObject> obj, int x, int y, float width, float height);
	void IncreaseCanJumpCounter();
	void DecreaseCanJumpCounter();
	bool PlayerCanJump();
	void AddBody(shared_ptr<GameObject> obj, int x, int y, float width, float height, float friction, bool fixed, bool fixedRotation);
	bool IsMovingLeft(Body body);
};

#endif