#pragma once
#include <Box2D.h>
class Body
{
public:
	Body();

	b2Body* b2body;
	float width;
	float height;
};

