#pragma once
#include "PhysicalBody.h"
class Manifold
{
private:
	PhysicalBody _bodyA;
	PhysicalBody _bodyB;


public:
	Manifold(PhysicalBody bodyA, PhysicalBody bodyB);
	Vec2 normal;          // From A to B
	void ApplyImpulse();

};

