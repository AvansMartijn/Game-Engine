#pragma once
#include <Box2D.h>
class Body {
public:
	Body();

	// TODO: DEZE WEG WERKEN.
	b2Body* b2body;
	float width;
	float height;
	int canJump;
};

