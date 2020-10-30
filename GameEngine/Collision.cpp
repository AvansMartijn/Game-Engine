#include "pch.h"
#include "Collision.h"


std::vector<shared_ptr<GameObject>> Collision::getCollisions(shared_ptr<GameObject> objectA, const std::vector<shared_ptr<GameObject>>& objectList)
{
	std::vector<shared_ptr<GameObject>> collisions;
	for (int i = 0; i < objectList.size(); i++)
		if (isColliding(objectA, objectList[i]))
			collisions.push_back(objectList[i]);

	return collisions;
}

bool Collision::isColliding(shared_ptr<GameObject> objectA, shared_ptr<GameObject> objectB)
{
	Manifold m = Manifold(objectA->physicalBody, objectB->physicalBody);
	m.PolygontoPolygon();
	if (m.contact_count > 0) {
		return true;
	}
	return false;
	//if (objectA == objectB) {
	//	return false;
	//}
	//Shape shapeA = objectA->physicalBody.shape;
	//Shape shapeB = objectB->physicalBody.shape;
	//if (shapeA.max.x < shapeB.min.x || shapeA.min.x > shapeB.max.x)
	//	return false;


	//if (shapeA.max.y < shapeB.min.y || shapeA.min.y > shapeB.max.y)
	//	return false;

	//// No separating axis found, therefor there is at least one overlapping axis
	//return true;
}

void Collision::resolveCollision(shared_ptr<GameObject> objectA, shared_ptr<GameObject> objectB) {
	Manifold m = Manifold(objectA->physicalBody, objectB->physicalBody);
	m.PolygontoPolygon();
	if (m.contact_count > 0) {
		//intregrate forces
		objectA->physicalBody.body.IntegrateForces();
		objectB->physicalBody.body.IntegrateForces();
		//initialize collision
		m.Initialize();
		//solve collision
		m.ApplyImpulse();
		//integrate velocities
		objectA->physicalBody.body.IntegrateVelocity();
		objectB->physicalBody.body.IntegrateVelocity();
		//correct positions
		m.PositionalCorrection();
		//clear all forces
		objectA->physicalBody.body.force.Set(0, 0);
		objectA->physicalBody.body.torque = 0;

		objectB->physicalBody.body.force.Set(0, 0);
		objectB->physicalBody.body.torque = 0;
	}
	/*if (m.AABBvsAABB())
		m.ApplyImpulse();*/


}

