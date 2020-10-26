#include "pch.h"
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

void Manifold::PositionalCorrection()
{
	const real k_slop = 0.05f; // Penetration allowance
	const real percent = 0.4f; // Penetration percentage to correct
	Vec2 correction = (std::max(penetration - k_slop, 0.0f) / (_bodyA.body.im + _bodyB.body.im)) * normal * percent;
	_bodyA.body.position -= correction * _bodyA.body.im;
	_bodyB.body.position += correction * _bodyB.body.im;
}

bool Manifold::AABBvsAABB()
{
	Vec2 n = _bodyB.body.position - _bodyA.body.position;

	// Calculate half extents along x axis for each object
	float aExtent = (_bodyA.shape.max.x - _bodyA.shape.min.x) / 2;
	float bExtent = (_bodyB.shape.max.x - _bodyB.shape.min.x) / 2;

	// Calculate overlap on x axis
	float xOverlap = aExtent + bExtent - abs(n.x);

	//if collision on x axis (overlap)
	if (xOverlap > 0) {
		float aExtent = (_bodyA.shape.max.y - _bodyA.shape.min.y) / 2;
		float bExtent = (_bodyB.shape.max.y - _bodyB.shape.min.y) / 2;

		//calculate overlap on x axis
		float test = abs(n.y);
		float yOverlap = aExtent + bExtent - abs(n.y);
		//if collision on y axis (overlap)
		if (yOverlap > 0) {
			//find axis of least penetration
			if (xOverlap > yOverlap) {
				// Point toward B knowing that n points from B to A

				if (n.x < 0)
					normal = Vec2(-1, 0);

				else {
					normal = Vec2(0, 0);
					penetration = xOverlap;
					return true;
				}
			}
			else {
				// Point toward B knowing that n points from A to B
				if (n.y < 0)
					normal = Vec2(0, -1);

				else {
					normal = Vec2(0, 1);
					penetration = yOverlap;
					return true;
				}
			}
		}
	}
	return false;
}



