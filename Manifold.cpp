#include "Manifold.h"

Manifold::Manifold(PhysicalBody bodyA, PhysicalBody bodyB) {
	_bodyA = bodyA;
	_bodyB = bodyB;
}

void Manifold::ApplyImpulse()
{
	//calc relative velocity
	Vec2 rv = _bodyA.body.velocity - _bodyB.body.velocity;

	//calc relative velocity in terms of normal direction
	float velAlongNormal = Dot(rv, normal);

	//do not resolve if velocities are seperating
	if (velAlongNormal > 0)
		return;

	// Calculate restitution
	float e = std::min(_bodyA.body.restitution, _bodyA.body.restitution);

	// Calculate impulse scalar
	float j = -(1 + e) * velAlongNormal;
	j /= 1 / _bodyA.body.m + 1 / _bodyB.body.m;

	// Apply impulse
	Vec2 impulse = j * normal;
	_bodyA.body.velocity -= 1 / _bodyA.body.m * impulse;
	_bodyB.body.velocity += 1 / _bodyB.body.m * impulse;
}
