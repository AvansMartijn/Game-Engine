#pragma once
#include <box2d/box2d.h>
class Body
{
public:
	Body();

	b2Body* b2body;
	float width;
	float height;
};

