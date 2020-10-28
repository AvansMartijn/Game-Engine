#pragma once
#include "PhysicalBody.h"
/// <summary>
/// Calculation for collision resolution between game objects
/// </summary>
class Manifold
{
private:
	PhysicalBody _bodyA;
	PhysicalBody _bodyB;


public:
	/// <summary>
	/// Constructor: set pointers for both physicalbodies
	/// </summary>
	/// <param name="bodyA">PhysicalBody A</param>
	/// <param name="bodyB">PhysicalBody B</param>
	Manifold(PhysicalBody bodyA, PhysicalBody bodyB);
	real penetration;     // Depth of penetration from collision
	Vec2 normal;          // From A to B
	Vec2 contacts[2];     // Points of contact during collision
	uint32 contact_count; // Number of contacts that occured during collision
	real e;               // Mixed restitution
	real df;              // Mixed dynamic friction
	real sf;              // Mixed static friction
	/// <summary>
	/// Calculate and apply new velocities for both physical bodies.
	/// </summary>
	void ApplyImpulse();
	/// <summary>
	/// Correct position deviation introduced by floating point errors.
	/// </summary>
	void PositionalCorrection();
	/// <summary>
	/// Check for overlap and update manifold with penetration and normal.
	/// </summary>
	/// <returns>True if a collision occured. False if not.</returns>
	bool AABBvsAABB();

};

