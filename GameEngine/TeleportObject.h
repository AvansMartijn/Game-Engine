#pragma once
struct TeleportObject
{
public:
	shared_ptr<GameObject> obj;
	b2Vec2 newPosition;
};

