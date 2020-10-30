#include "pch.h"
#include "Manifold.h"

Manifold::Manifold(PhysicalBody bodyA, PhysicalBody bodyB) {
	_bodyA = bodyA;
	_bodyB = bodyB;
}

void Manifold::Initialize(void)
{
	Shape A = _bodyA.shape;
	Shape B = _bodyA.shape;
	// Calculate average restitution
	e = std::min(A.body.restitution, B.body.restitution);

	// Calculate static and dynamic friction
	sf = std::sqrt(A.body.staticFriction * A.body.staticFriction);
	df = std::sqrt(A.body.dynamicFriction * A.body.dynamicFriction);

	for (uint32 i = 0; i < contact_count; ++i)
	{
		// Calculate radii from COM to contact
		Vec2 ra = contacts[i] - A.body.position;
		Vec2 rb = contacts[i] - B.body.position;

		Vec2 rv = B.body.velocity + Cross(B.body.angularVelocity, rb) -
			A.body.velocity - Cross(A.body.angularVelocity, ra);


		// Determine if we should perform a resting collision or not
		// The idea is if the only thing moving this object is gravity,
		// then the collision should be performed without any restitution
		if (rv.LenSqr() < (dt * gravity).LenSqr() + EPSILON)
			e = 0.0f;
	}
}

void Manifold::ApplyImpulse(void)
{
	PhysicalBody A = _bodyA;
	PhysicalBody B = _bodyB;
	// Early out and positional correct if both objects have infinite mass
	if (Equal(A.body.im + B.body.im, 0))
	{
		InfiniteMassCorrection();
		return;
	}

	for (uint32 i = 0; i < contact_count; ++i)
	{
		// Calculate radii from COM to contact
		Vec2 ra = contacts[i] - A.body.position;
		Vec2 rb = contacts[i] - B.body.position;

		// Relative velocity
		Vec2 rv = B.body.velocity + Cross(B.body.angularVelocity, rb) -
			A.body.velocity - Cross(A.body.angularVelocity, ra);

		// Relative velocity along the normal
		real contactVel = Dot(rv, normal);

		// Do not resolve if velocities are separating
		if (contactVel > 0)
			return;

		real raCrossN = Cross(ra, normal);
		real rbCrossN = Cross(rb, normal);
		real invMassSum = A.body.im + B.body.im + Sqr(raCrossN) * A.body.iI + Sqr(rbCrossN) * B.body.iI;

		// Calculate impulse scalar
		real j = -(1.0f + e) * contactVel;
		j /= invMassSum;
		j /= (real)contact_count;

		// Apply impulse
		Vec2 impulse = normal * j;
		A.body.ApplyImpulse(-impulse, ra);
		B.body.ApplyImpulse(impulse, rb);

		// Friction impulse
		rv = B.body.velocity + Cross(B.body.angularVelocity, rb) -
			A.body.velocity - Cross(A.body.angularVelocity, ra);

		Vec2 t = rv - (normal * Dot(rv, normal));
		t.Normalize();

		// j tangent magnitude
		real jt = -Dot(rv, t);
		jt /= invMassSum;
		jt /= (real)contact_count;

		// Don't apply tiny friction impulses
		if (Equal(jt, 0.0f))
			return;

		// Coulumb's law
		Vec2 tangentImpulse;
		if (std::abs(jt) < j * sf)
			tangentImpulse = t * jt;
		else
			tangentImpulse = t * -j * df;

		// Apply friction impulse
		A.body.ApplyImpulse(-tangentImpulse, ra);
		B.body.ApplyImpulse(tangentImpulse, rb);
	}
}

void Manifold::PositionalCorrection()
{
	const real k_slop = 0.05f; // Penetration allowance
	const real percent = 0.4f; // Penetration percentage to correct
	Vec2 correction = (std::max(penetration - k_slop, 0.0f) / (_bodyA.body.im + _bodyB.body.im)) * normal * percent;
	_bodyA.body.position -= correction * _bodyA.body.im;
	_bodyB.body.position += correction * _bodyB.body.im;
}

void Manifold::PolygontoPolygon()
{

	Shape A = _bodyA.shape;
	Shape B = _bodyB.shape;
	//PolygonShape* B = reinterpret_cast<PolygonShape*>(b->shape);
	contact_count = 0;

	// Check for a separating axis with A's face planes
	uint32 faceA;
	real penetrationA = FindAxisLeastPenetration(&faceA);
	if (penetrationA >= 0.0f)
		return;

	// Check for a separating axis with B's face planes
	uint32 faceB;
	real penetrationB = FindAxisLeastPenetration(&faceB);
	if (penetrationB >= 0.0f)
		return;

	uint32 referenceIndex;
	bool flip; // Always point from a to b

	Shape *RefPoly; // Reference
	Shape *IncPoly; // Incident

	// Determine which shape contains reference face
	if (BiasGreaterThan(penetrationA, penetrationB))
	{
		RefPoly = &A;
		IncPoly = &B;
		referenceIndex = faceA;
		flip = false;
	}

	else
	{
		RefPoly = &B;
		IncPoly = &A;
		referenceIndex = faceB;
		flip = true;
	}

	// World space incident face
	Vec2 incidentFace[2];
	FindIncidentFace(incidentFace, RefPoly, IncPoly, referenceIndex);

	//        y
	//        ^  ->n       ^
	//      +---c ------posPlane--
	//  x < | i |\
    //      +---+ c-----negPlane--
	//             \       v
	//              r
	//
	//  r : reference face
	//  i : incident poly
	//  c : clipped point
	//  n : incident normal

	// Setup reference face vertices
	Vec2 v1 = RefPoly->m_vertices[referenceIndex];
	referenceIndex = referenceIndex + 1 == RefPoly->m_vertexCount ? 0 : referenceIndex + 1;
	Vec2 v2 = RefPoly->m_vertices[referenceIndex];

	// Transform vertices to world space
	v1 = RefPoly->u * v1 + RefPoly->body.position;
	v2 = RefPoly->u * v2 + RefPoly->body.position;

	// Calculate reference face side normal in world space
	Vec2 sidePlaneNormal = (v2 - v1);
	sidePlaneNormal.Normalize();

	// Orthogonalize
	Vec2 refFaceNormal(sidePlaneNormal.y, -sidePlaneNormal.x);

	// ax + by = c
	// c is distance from origin
	real refC = Dot(refFaceNormal, v1);
	real negSide = -Dot(sidePlaneNormal, v1);
	real posSide = Dot(sidePlaneNormal, v2);

	// Clip incident face to reference face side planes
	if (Clip(-sidePlaneNormal, negSide, incidentFace) < 2)
		return; // Due to floating point error, possible to not have required points

	if (Clip(sidePlaneNormal, posSide, incidentFace) < 2)
		return; // Due to floating point error, possible to not have required points

	  // Flip
	normal = flip ? -refFaceNormal : refFaceNormal;

	// Keep points behind reference face
	uint32 cp = 0; // clipped points behind reference face
	real separation = Dot(refFaceNormal, incidentFace[0]) - refC;
	if (separation <= 0.0f)
	{
		contacts[cp] = incidentFace[0];
		penetration = -separation;
		++cp;
	}
	else
		penetration = 0;

	separation = Dot(refFaceNormal, incidentFace[1]) - refC;
	if (separation <= 0.0f)
	{
		contacts[cp] = incidentFace[1];

		penetration += -separation;
		++cp;

		// Average penetration
		penetration /= (real)cp;
	}

	contact_count = cp;
}

int32 Manifold::Clip(Vec2 n, real c, Vec2* face)
{
	uint32 sp = 0;
	Vec2 out[2] = {
	  face[0],
	  face[1]
	};

	// Retrieve distances from each endpoint to the line
	// d = ax + by - c
	real d1 = Dot(n, face[0]) - c;
	real d2 = Dot(n, face[1]) - c;

	// If negative (behind plane) clip
	if (d1 <= 0.0f) out[sp++] = face[0];
	if (d2 <= 0.0f) out[sp++] = face[1];

	// If the points are on different sides of the plane
	if (d1 * d2 < 0.0f) // less than to ignore -0.0f
	{
		// Push interesection point
		real alpha = d1 / (d1 - d2);
		out[sp] = face[0] + alpha * (face[1] - face[0]);
		++sp;
	}

	// Assign our new converted values
	face[0] = out[0];
	face[1] = out[1];

	assert(sp != 3);

	return sp;
}

void Manifold::FindIncidentFace(Vec2* v, Shape *RefPoly, Shape *IncPoly, uint32 referenceIndex)
{
	Vec2 referenceNormal = RefPoly->m_normals[referenceIndex];

	// Calculate normal in incident's frame of reference
	referenceNormal = RefPoly->u * referenceNormal; // To world space
	referenceNormal = IncPoly->u.Transpose() * referenceNormal; // To incident's model space

	// Find most anti-normal face on incident polygon
	int32 incidentFace = 0;
	real minDot = FLT_MAX;
	for (uint32 i = 0; i < IncPoly->m_vertexCount; ++i)
	{
		real dot = Dot(referenceNormal, IncPoly->m_normals[i]);
		if (dot < minDot)
		{
			minDot = dot;
			incidentFace = i;
		}
	}

	// Assign face vertices for incidentFace
	v[0] = IncPoly->u * IncPoly->m_vertices[incidentFace] + IncPoly->body.position;
	incidentFace = incidentFace + 1 >= (int32)IncPoly->m_vertexCount ? 0 : incidentFace + 1;
	v[1] = IncPoly->u * IncPoly->m_vertices[incidentFace] + IncPoly->body.position;
}

real Manifold::FindAxisLeastPenetration(uint32* faceIndex)
{
	real bestDistance = -FLT_MAX;
	uint32 bestIndex;

	Shape A = _bodyA.shape;
	Shape B = _bodyB.shape;

	for (uint32 i = 0; i < A.m_vertexCount; ++i)
	{
		// Retrieve a face normal from A
		Vec2 n = A.m_normals[i];
		Vec2 nw = A.u * n;

		// Transform face normal into B's model space
		Mat2 buT = B.u.Transpose();
		n = buT * nw;

		// Retrieve support point from B along -n
		Vec2 s = B.GetSupport(-n);

		// Retrieve vertex on face from A, transform into
		// B's model space
		Vec2 v = A.m_vertices[i];
		v = A.u * v + A.body.position;
		v -= B.body.position;
		v = buT * v;

		// Compute penetration distance (in B's model space)
		real d = Dot(n, s - v);

		// Store greatest distance
		if (d > bestDistance)
		{
			bestDistance = d;
			bestIndex = i;
		}
	}

	*faceIndex = bestIndex;
	return bestDistance;
}

void Manifold::InfiniteMassCorrection(void)
{
	_bodyA.body.velocity.Set(0, 0);
	_bodyB.body.velocity.Set(0, 0);
}



//bool Manifold::AABBvsAABB()
//{
//	Vec2 n = _bodyB.body.position - _bodyA.body.position;
//
//	// Calculate half extents along x axis for each object
//	float aExtent = (_bodyA.shape.max.x - _bodyA.shape.min.x) / 2;
//	float bExtent = (_bodyB.shape.max.x - _bodyB.shape.min.x) / 2;
//
//	// Calculate overlap on x axis
//	float xOverlap = aExtent + bExtent - abs(n.x);
//
//	//if collision on x axis (overlap)
//	if (xOverlap > 0) {
//		float aExtent = (_bodyA.shape.max.y - _bodyA.shape.min.y) / 2;
//		float bExtent = (_bodyB.shape.max.y - _bodyB.shape.min.y) / 2;
//
//		//calculate overlap on x axis
//		float test = abs(n.y);
//		float yOverlap = aExtent + bExtent - abs(n.y);
//		//if collision on y axis (overlap)
//		if (yOverlap > 0) {
//			//find axis of least penetration
//			if (xOverlap > yOverlap) {
//				// Point toward B knowing that n points from B to A
//
//				if (n.x < 0)
//					normal = Vec2(-1, 0);
//
//				else {
//					normal = Vec2(0, 0);
//					penetration = xOverlap;
//					return true;
//				}
//			}
//			else {
//				// Point toward B knowing that n points from A to B
//				if (n.y < 0)
//					normal = Vec2(0, -1);
//
//				else {
//					normal = Vec2(0, 1);
//					penetration = yOverlap;
//					return true;
//				}
//			}
//		}
//	}
//	return false;
//}



