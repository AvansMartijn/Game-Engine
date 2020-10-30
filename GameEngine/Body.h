#pragma once
#include <Box2D.h>
class Body
{
public:
	Body();

	b2Body* b2body;
	int width;
	int height;
};

