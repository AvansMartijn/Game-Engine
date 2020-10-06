#pragma once
#include "PhysicalBody.h"
class Manifold
{
private:
	PhysicalBody _bodyA;
	PhysicalBody _bodyB;


public:
	Manifold(PhysicalBody bodyA, PhysicalBody bodyB);
	real penetration;     // Depth of penetration from collision
	Vec2 normal;          // From A to B
	Vec2 contacts[2];     // Points of contact during collision
	uint32 contact_count; // Number of contacts that occured during collision
	real e;               // Mixed restitution
	real df;              // Mixed dynamic friction
	real sf;              // Mixed static friction
	void ApplyImpulse();
	void PositionalCorrection();
	bool AABBvsAABB();

};

