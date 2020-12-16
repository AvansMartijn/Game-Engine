#pragma once
struct TeleportObject {
public:
	GameObject* obj;
	b2Vec2 newPosition;
	b2Vec2 newSpeed;
	bool hasSpeed = false;
};

