#include "pch.h"
#include "CollisionResolutionDefaultExtension.h"

// TODO: WAT HIER MEE DOEN?
CollisionResolutionDefaultExtension::CollisionResolutionDefaultExtension() {
	type = "AbstractCollisionResolutionExtension";
}

bool CollisionResolutionDefaultExtension::isDefault(){
	return true;
}
 
void CollisionResolutionDefaultExtension::resolveCollision(shared_ptr<GameObject> otherObject){
	//_physicsFacade.resolveCollision(_subject, otherObject);
}
