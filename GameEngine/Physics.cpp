#include "pch.h"
#include "Physics.h"
#include "CollisionListener.h"

Physics::Physics(){
    gravity = { 0.0f, 10.0f };
    world = new b2World(gravity);
    world->SetContactListener(&colListener);

}

void Physics::AddBody(shared_ptr<GameObject> obj, int x, int y, float width, float height, bool fixed) {
    obj->body.width = width;
    obj->body.height = height;
    

    b2BodyDef bodyDef;
    bodyDef.position.Set(x, y);
    bodyDef.userData = obj.get();

    if(!fixed)
        bodyDef.type = b2_dynamicBody;

    b2Body* body = world->CreateBody(&bodyDef);
    obj->body.b2body = body;

    b2PolygonShape box;
    box.SetAsBox(obj->body.width / 2, obj->body.height / 2);
    if (fixed)
        obj->body.b2body->CreateFixture(&box, 0.0f);
    else {
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &box;
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.3f;
        body->CreateFixture(&fixtureDef);
    }
}

//void Physics::UpdatePositions() {
//    for (shared_ptr<GameObject>& obj : updatePositionList) {
//        obj->body.b2body->SetTransform({ 0, 0 }, 0);
//    }
//}

