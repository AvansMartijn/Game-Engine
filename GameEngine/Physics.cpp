#include "pch.h"
#include "Physics.h"

Physics::Physics(){
    gravity = { 0.0f, 10.0f };
    world = new b2World(gravity);
}

void Physics::AddBody(shared_ptr<GameObject> obj, int x, int y, float32 width, float32 height, bool fixed) {
    obj->body.width = width;
    obj->body.height = height;

    b2BodyDef bodyDef;
    bodyDef.position.Set((float32)x, (float32)y);

    if(!fixed)
        bodyDef.type = b2_dynamicBody;

    b2Body* body = world->CreateBody(&bodyDef);
    obj->body.b2body = body;

    if (fixed) {
        b2PolygonShape box;
        box.SetAsBox(obj->body.width/ 2, obj->body.height / 2);
        obj->body.b2body->CreateFixture(&box, 0.0f);

    }
    else {
        b2PolygonShape dynamicBox;
        dynamicBox.SetAsBox(obj->body.width / 2, obj->body.height / 2);
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &dynamicBox;
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.3f;
        body->CreateFixture(&fixtureDef);
    }
}

