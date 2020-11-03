#pragma once
struct TeleportObject
{
public:
	shared_ptr<GameObject> from;
	shared_ptr<GameObject> to;
};

