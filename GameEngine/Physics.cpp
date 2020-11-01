#include "pch.h"
#include "Physics.h"
#include "CollisionListener.h"


Physics Physics::instance;

Physics::Physics(){
    gravity = { 0.0f, 10.0f };
    world = new b2World(gravity);
    world->SetContactListener(&colListener);

}


void Physics::AddPlayer(shared_ptr<GameObject> obj, int x, int y, float width, float height) {
    obj->body.width = width;
    obj->body.height = height;

    b2BodyDef bodyDef;
    bodyDef.position.Set(x, y);
    bodyDef.type = b2_dynamicBody;
    bodyDef.fixedRotation = true;

    b2Body* body = world->CreateBody(&bodyDef);
    obj->body.b2body = body;
    
    b2PolygonShape box;
    box.SetAsBox(obj->body.width / 2, obj->body.height / 2);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &box;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);

    box.SetAsBox(obj->body.width / 4, obj->body.height / 2, b2Vec2(0, -2), 0);
    fixtureDef.isSensor = true;



    fixtureDef.userData.pointer = reinterpret_cast<uintptr_t>((void*)3);
    body->CreateFixture(&fixtureDef);


}

void Physics::AddBody(shared_ptr<GameObject> obj, int x, int y, float width, float height, float friction, bool fixed, bool fixedRotation) {
    obj->body.width = width;
    obj->body.height = height;
    

    b2BodyDef bodyDef;
    bodyDef.position.Set(x, y);
    //bodyDef.userData = obj.get();

    if(!fixed)
        bodyDef.type = b2_dynamicBody;

    if (fixedRotation)
        bodyDef.fixedRotation = true;

    b2Body* body = world->CreateBody(&bodyDef);
    obj->body.b2body = body;

    b2PolygonShape box;
    box.SetAsBox(obj->body.width / 2, obj->body.height / 2);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &box;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = friction;

    body->CreateFixture(&fixtureDef);
    
}

bool Physics::IsMovingLeft(Body body) {
    if (body.b2body->GetLinearVelocity().x < -2) {
        return true;
    }
    return false;
}

//void Physics::UpdatePositions() {
//    for (shared_ptr<GameObject>& obj : updatePositionList) {
//        obj->body.b2body->SetTransform({ 0, 0 }, 0);
//    }
//}

