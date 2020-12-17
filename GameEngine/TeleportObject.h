#pragma once
struct TeleportObject {
public:
	GameObject* obj;
	Vec2 newPosition;
	Vec2 newSpeed;
	bool hasSpeed = false;
};

