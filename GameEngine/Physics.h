#pragma once

#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_Physics __declspec(dllexport)
#else
#define GAMEENGINE_Physics __declspec(dllimport)
#endif

#include <Box2D/Box2D.h>
#include <memory>
#include "GameObject.h"
#include "CollisionListener.h"

class GAMEENGINE_Physics Physics
{
public:
	b2World* world;
	b2Vec2 gravity;
	CollisionListener colListener;
	vector<shared_ptr<GameObject>> updatePositionList;
	Physics();
	//void UpdatePositions();
	void AddBody(shared_ptr<GameObject> obj, int x, int y, float32 width, float32 height, bool fixed);
	
};

