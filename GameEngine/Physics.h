#pragma once

#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_Physics __declspec(dllexport)
#else
#define GAMEENGINE_Physics __declspec(dllimport)
#endif

#include <Box2D/Box2D.h>
#include <memory>
#include "GameObject.h"

class GAMEENGINE_Physics Physics
{
public:
	b2World* world;
	b2Vec2 gravity;
	Physics();
	void AddBody(shared_ptr<GameObject> obj, int x, int y, int width, int height, bool fixed);
	
};

