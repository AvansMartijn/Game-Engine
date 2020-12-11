#pragma once
struct TeleportObject
{
public:
	shared_ptr<GameObject> obj;
	b2Vec2 newPosition;
	b2Vec2 newSpeed;
	bool hasSpeed = false;
};

